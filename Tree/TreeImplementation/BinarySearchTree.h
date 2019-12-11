template <typename Comparable>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree & rhs);
        BinarySearchTree(BinarySearchTree && rhs);
        ~BinarySearchTree();

        const Comparable & findMin() const;
        const Comparable & findMax() const;
        bool contains(const Comparable & x) const;
        bool isEmpty() const;
        void printTree(ostream & out = cout const);
        
        void makeEmpty();
        /*
        Internal method to insert into a subtree
        x is the item to insert
        t is the node that roots the subtree
        set the new root of the subtree
        */
        void insert(const Comparable & x){
     
        }

        void insert ( Comparable && x )
        { 
        }
        void remove (const Comparable & x);

        BinarySearchTree & operator = (const BinarySearchTree & rhs );
        BinarySearchTree & operator = (BinarySearchTree && rhs);
    private:
        struct BinaryNode
        {
            Comparable element;
            BinaryNode * left;
            BinaryNode * right;
            BinaryNode (const Comparable & theElement, BinaryNode* lt, BinaryNode * rt)
            : element{theElement},left{lt},right{rt} {}
        };
        BinaryNode * root;

        void insert (const Comparable &x , BinaryNode * &t){
            if(t == nullptr)
                t = new BinaryNode {x, nullptr , nullptr};
            else if ( x < t->element )
                insert( x , t->left );
            else if ( x > t->element )
                insert( x , t->right);
            else 
                 ; // Duplicate do nothing 
        }
        void insert (Comparable && x, BinaryNode * &t){ // t would be passed as reference
            if ( t == nullptr)
                t = new BinaryNode{std::move(x), nullptr,nullptr};
            else if (x < t->element)
                insert(std::move(x), t->left);
            else if (t->element < x)
                insert(std::move(x), t->right);
            else 
                ; // Duplicate; do nothing
        }
        void remove (const Comparable &x , BinaryNode * &t);
        BinaryNode * findMin(BinaryNode *t) const
        {
                if (t == nullptr)
                    return nullptr;
                if (t->left == nullptr)
                    return t;
                return findMin(t->left);
        }
        BinaryNode * findMax(BinaryNode *t) const{
            if (t!= nullptr)
            while (t->right !=nullptr)
                t = t->right;
            return t;
        }
        bool contains (const Comparable & x, BinaryNode *t) const{
                if (t == nullptr)
                    return false;
                else if (x < t->element )
                    return contains(x, t->left);
                else if (t->element < x)
                    return contains(x,t->right);
                else 
                    return true;// Match
        }
        void makeEmpty(BinaryNode* &t);
        void printTree(BinaryNode *t , ostream &out) const ;
        BinaryNode * clone (BinaryNode *t) const;
};

