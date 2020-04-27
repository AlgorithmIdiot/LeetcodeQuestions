#include<iostream>
#include"BinarySearchTree.h"
//template <typename Comparable1>
//class BinarySearchTree;

template <typename Comparable>
class Set : public BinarySearchTree <Comparable>
{
    class iterator;
    public: 
        Set(){};
        ~Set(){};
        // the public insert 
        iterator insert(const Comparable &x ){
            Size++;
            return insert (x, this->root, this->root);
        }

        //the public begin
        iterator begin(){
            BinaryNode<Comparable> *t = BinarySearchTree::root;
            while (t->left)
                t= t->left;
            return iterator(t);
        }
    private:

        class const_iterator 
        {
            public:
                const_iterator(): current(NULL)
                {}
                const Comparable & operator* () const
                { return retrieve();}
                const_iterator & operator++()
                {
                    BinaryNode<Comparable> *t;
                    if ( current->right)
                    {
                        t = current->right;
                        while(t->left!=NULL)
                            t = t->left;
                        current = t;
                    }
                    else 
                    {
                        t = current->parent;
                        std::cout << "first parent is " << t->element<< std::endl;
                        while ( t&& t->element < current->element)
                            t = t->parent;
                        current = t;
                    }
                    return * this;
                }
                const_iterator operator++ (int)
                {
                    const_iterator old = * this;
                    ++(*this);
                    return old;
                }

                bool operator == (const const_iterator * rhs) const
                {return current == rhs.current;}

                bool operator != (const const_iterator & rhs) const
                {return !(*this == rhs);}
            protected:
                BinaryNode<Comparable> * current;
                Comparable & retrieve () const
                {return current->element;}
                const_iterator (BinaryNode<Comparable> * p ) : current(p)
                {}
        };

        class iterator : public const_iterator 
        {
            public: 
                iterator()
                {}
                Comparable * operator * ()
                {return const_iterator :: retrieve();}
                const Comparable & operator * () const
                {return const_iterator::operator*();}

                iterator & operator++()
                {
                    BinaryNode<Comparable> *t; 
                    if (BinarySearchTree::current->right)
                    {
                        t = BinarySearchTree::current->right;
                        while(t->left !=NULL)
                            t = t->left;
						BinarySearchTree::current = t ;
                    }
                    else 
                    {
                        t = BinarySearchTree::current->parent;
                        std::cout<< "first parent is "<< t->element<< std::endl;
                        while (t && t->element < BinarySearchTree::current->element)
                            t = t->parent;
						BinarySearchTree::current = t;
                    }
                    return *this;
                }
                iterator operator++(int)
                {
                    const_iterator old=*this;
                    ++(*this);
                    return old;
                }
                iterator (BinaryNode<Comparable>* p) :const_iterator (p)
                {  
                }
                friend class Set;
        };

        // this is the private insert
        iterator insert(const Comparable & x ,
                        BinaryNode<Comparable> * &t,
                        BinaryNode<Comparable> * p ) // parent node
        {
            if(t == NULL)
            {
                t = new BinaryNode<Comparable> (x, NULL,NULL,p);
                return iterator(t);
            }
            else if (x<t->element)
                return (insert(x,t->left,t));
            else if(t->element <x )
                return (insert(x,t->right,t));
            return iterator (t);
        }
        int Size; 
};

