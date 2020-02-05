#include <iostream>

template <class Comparable> class Set;
template<class Comparable> class const_iterator;
//template<class Comparable> class iterator;

template <typename Comparable_BinaryNode>
struct BinaryNode
{
    Comparable_BinaryNode element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode *parent;

    BinaryNode()
    {
        left = NULL, right = NULL;
        parent = NULL;
    }
    BinaryNode(const Comparable_BinaryNode &theElement)
    {
        element = theElement;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    BinaryNode(const Comparable_BinaryNode &theElement, BinaryNode *lt, BinaryNode *rt,
               BinaryNode *pt) : element(theElement), left(lt), right(rt), parent(pt) {}
    friend class Set<Comparable_BinaryNode>;
};

    template <typename Comparable>
    class Set
    {
    public:
        Set(){};
        Set(const Set &rhs) : root{nullptr}
        {
            root = clone(rhs.root);
        }
        Set(Set &&rhs);
        // destructor of the tree
        ~Set()
        {
            makeEmpty();
        }
        using iterator = const_iterator<Comparable>;
        const Comparable &findMin() const;
        const Comparable &findMax() const;
        bool contains(const Comparable &x) const
        {
            return contains(x, root);
        }
        bool isEmpty() const
        {
            if (root == nullptr)
                return true;
            else
                return false;
        }
        void printTree(std::ostream &out = std::cout) const
        {
            if (isEmpty())
                out << "Empty tree" << std::endl;
            else
                printTree(root, out);
        }
        Comparable findMin()
        {
            BinaryNode<Comparable> * temp = findMin(root);
            return temp->element;
        }
        Comparable findMax()
        {
            BinaryNode<Comparable> * temp = findMax(root);
            return temp->element;
        }

        void makeEmpty()
        {
            makeEmpty(root);
        }
        // the public insert
        iterator insert(const Comparable &x)
        {
            Size++;
            return insert(x, root, root);
        }

        //the public begin
        iterator begin()
        {
            BinaryNode<Comparable> *t = root;
            while (t->left)
                t = t->left;
            return iterator(t);
        }

        // void insert ( Comparable && x )
        // {
        //     insert(x,root);
        // }
        void remove(const Comparable &x)
        {
            remove(x, root);
        }

        Set &operator=(const Set &rhs);
        Set &operator=(Set &&rhs);

    private:
        BinaryNode<Comparable> *root = nullptr;
        void insert(const Comparable &x, BinaryNode<Comparable> *&t)
        {
            if (t == nullptr)
                t = new BinaryNode<Comparable>{x, nullptr, nullptr};
            else if (x < t->element)
                insert(x, t->left);
            else if (x > t->element)
                insert(x, t->right);
            else
                ; // Duplicate do nothing
        }
        void insert(Comparable &&x, BinaryNode<Comparable> *&t)
        { // t would be passed as reference
            if (t == nullptr)
                t = new BinaryNode<Comparable>{std::move(x), nullptr, nullptr};
            else if (x < t->element)
                insert(std::move(x), t->left);
            else if (t->element < x)
                insert(std::move(x), t->right);
            else
                ; // Duplicate; do nothing
        }
        void remove(const Comparable &x, BinaryNode<Comparable> *&t)
        {
            if (t == nullptr)
                return; //items not found; do nothing
            if (x < t->element)
                remove(x, t->left);
            else if (x > t->element)
                remove(x, t->right);
            else if (t->left != nullptr && t->right != nullptr) // two children
            {
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
            }
            else
            {
                BinaryNode<Comparable> *oldNode = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }
        }
        BinaryNode<Comparable> *findMin(BinaryNode<Comparable> *t) const
        {
            if (t == nullptr)
                return nullptr;
            if (t->left == nullptr)
                return t;
            return findMin(t->left);
        }
        BinaryNode<Comparable> *findMax(BinaryNode<Comparable> *t) const
        {
            if (t != nullptr)
                while (t->right != nullptr)
                    t = t->right;
            return t;
        }
        bool contains(const Comparable &x, BinaryNode<Comparable> *t) const
        {
            if (t == nullptr)
                return false;
            else if (x < t->element)
                return contains(x, t->left);
            else if (t->element < x)
                return contains(x, t->right);
            else
                return true; // Match
        }
        void makeEmpty(BinaryNode<Comparable> *&t)
        {
            if (t != nullptr)
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = nullptr;
        }
        void printTree(BinaryNode<Comparable> *t, std::ostream &out) const
        {
            if (t != nullptr)
            {
                printTree(t->left, out);
                out << t->element << std::endl;
                printTree(t->right, out);
            }
        }
        BinaryNode<Comparable> *clone(BinaryNode<Comparable> *t) const
        {
            if (t == nullptr)
                return nullptr;
            else
                return new BinaryNode<Comparable>{t->element, clone(t->left), clone(t->right)};
        }

        // this is the private insert
        iterator insert(const Comparable &x,
                        BinaryNode<Comparable> *&t,
                        BinaryNode<Comparable> *p) // parent node
        {
            if (t == NULL)
            {
                t = new BinaryNode<Comparable>(x, NULL, NULL, p);
                return iterator(t);
            }
            else if (x < t->element)
                return (insert(x, t->left, t));
            else if (t->element < x)
                return (insert(x, t->right, t));
            return iterator(t);
        }
        int Size;
    };

    template <class Comparable>
    class const_iterator
    {
    public:
        const_iterator() : current(NULL)
        {
        }
        const Comparable &operator*() const
        {
            return retrieve();
        }
        const_iterator &operator++()
        {
            BinaryNode<Comparable> *t;
            if (current->right)
            {
                t = current->right;
                while (t->left != NULL)
                    t = t->left;
                current = t;
            }
            else
            {
                t = current->parent;
                std::cout << "first parent is " << t->element << std::endl;
                while (t && t->element < current->element)
                    t = t->parent;
                current = t;
            }
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator *rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const
        {
            return !(*this == rhs);
        }
        friend class Set<Comparable>;

    protected:
        BinaryNode<Comparable> *current;
        Comparable &retrieve() const
        {
            return current->element;
        }
        const_iterator(BinaryNode<Comparable> *p) : current(p)
        {
        }
    };

    // template <class Comparable>
    // class iterator : public const_iterator<Comparable>
    // {
    // public:
    //     iterator()
    //     {
    //     }
    //     Comparable *operator*()
    //     {
    //         return const_iterator ::retrieve();
    //     }
    //     const Comparable &operator*() const
    //     {
    //         return const_iterator::operator*();
    //     }

    //     iterator &operator++()
    //     {
    //         BinaryNode<Comparable> *t;
    //         if (current->right)
    //         {
    //             t = current->right;
    //             while (t->left != NULL)
    //                 t = t->left;
    //             current = t;
    //         }
    //         else
    //         {
    //             t = current->parent;
    //             std::cout << "first parent is " << t->element << std::endl;
    //             while (t && t->element < current->element)
    //                 t = t->parent;
    //             current = t;
    //         }
    //         return *this;
    //     }
    //     iterator operator++(int)
    //     {
    //         const_iterator old = *this;
    //         ++(*this);
    //         return old;
    //     }
    //     iterator(BinaryNode<Comparable> *p) : const_iterator(p)
    //     {
    //     }
    //     friend class Set<Comparable>;
    // };
