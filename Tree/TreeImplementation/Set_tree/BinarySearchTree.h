#include<iostream>
template <typename Comparable>
class Set
{
    public:
        Set()
        {};
        Set(const Set & rhs):root{nullptr}
        {
            root = clone(rhs.root);
        }
        Set(Set && rhs);
        // destructor of the tree 
        ~Set(){
            makeEmpty();
        }

        const Comparable & findMin() const;
        const Comparable & findMax() const;
        bool contains(const Comparable & x) const{
            return contains(x,root);
        }
        bool isEmpty() const{
            if(root==nullptr)
                return true;
            else 
                return false;
        }
        void printTree(std::ostream & out = std::cout) const{
            if(isEmpty())
                out << "Empty tree" << std::endl;
            else 
                printTree(root,out);
        }
        
        void makeEmpty(){
            makeEmpty(root);
        }
        void insert(const Comparable & x){
            insert(x,root);
        }

        void insert ( Comparable && x )
        { 
            insert(x,root);
        }
        void remove (const Comparable & x){
            remove (x,root);
        }

        Set & operator = (const Set & rhs );
        Set & operator = (Set && rhs);
    private:
        struct BinaryNode
        {
            Comparable element;
            BinaryNode * left;
            BinaryNode * right;
            BinaryNode (const Comparable & theElement, BinaryNode* lt, BinaryNode * rt)
            : element{theElement},left{lt},right{rt} {}
        };
        BinaryNode * root = nullptr; 
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
        void remove (const Comparable &x , BinaryNode * &t){
            if(t == nullptr)
                return; //items not found; do nothing
            if (x < t->element)
                remove(x, t->left);
            else if(x > t->element)
                remove(x, t->right);
            else if (t->left!=nullptr && t->right !=nullptr ) // two children
            {
                t->element = findMin(t->right)->element;
                remove(t->element,t->right);
            }
            else
            {
                BinaryNode *oldNode = t;
                t = (t->left != nullptr) ? t->left:t->right;
                delete oldNode;
            }
            
        }
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
        void makeEmpty(BinaryNode* &t){
            if(t!=nullptr)
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = nullptr;
        }
        void printTree(BinaryNode *t , std::ostream &out) const {
            if(t!= nullptr)
            {
                printTree(t->left,out);
                out << t->element << std::endl;
                printTree(t->right,out);
            }
        }
        BinaryNode * clone (BinaryNode *t) const{
            if(t == nullptr)
                return nullptr;
            else 
                return new BinaryNode{t->element, clone(t->left), clone(t->right)};
        }
};
