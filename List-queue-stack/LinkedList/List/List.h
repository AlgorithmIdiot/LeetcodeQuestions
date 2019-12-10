template <typename Object>
class List
{
    private:
        struct Node
        {
            //Figure 3.13
            Object data;
            Node *prev;
            Node *next;

            Node (const Object & d = Object{}, Node* p = nullptr,
                                               Node* n = nullptr)
                : data{d}, prev{p},next{n}{}
            
            Node (Object && d, Node * p = nullptr, Node *n =nullptr )
                : data{std::move(d)}, prev{p},next{n} {}
        };
    public:
        class const_iterator
        {
            // fig 3.14
            public: 
                const_iterator():current{nullptr}{} // what
                const Object & operator*() const{return retrieve();}
                const iterator & operator++ ()
                {
                    current = current->next;
                    return * this;
                }
                // use int to mark the postfix ++
                const_iterator operator++ (int)
                {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }

                bool operator == (const const_iterator & rhs) const
                    {return current == rhs.current;}
                bool operator != (const const_iterator & rhs) const
                    {return !(*this == rhs);}
            protected:
                Node* current;
                Object & retrieve()const{return current->data;}
                const_iterator (Node *p):current{p} {}
                friend class List<Object>;
        };
        class iterator: public const_iterator
        {
            //fig 3.15
            iterator()
            {}
            Object & operator*()
            {return const_iterator::retrieve();}
            const Object & operator*()const
            {return const_iterator::operator*();}

            iterator & operator++ ()
            {
                this->current = this->current->next;
                return *this;
            }
            iterator operator++ (int)
            {
                iterator old =*this;
                ++(*this);
                return old;
            }
            protected:
                iterator (Node *p ): const_iterator{p}{}
                friend class List<Object>;
        };
    public:
        List()
        {
            //fig 3.16
            init();
        }
        List (const List & rhs)
        {
            //fig 3.16
            init();
            for(auto &x:rhs)
                push_back(x);
        }
        ~List()
        {
            //fig 3.16
            clear();
            delete head;
            delete tail;
        }
        List & operator= (const List & rhs)
        {
            //fig 3.16
            List copy = rhs;
            std::swap(*this,copy);
            return *this;
        }
        List (List && rhs):theSize{rhs.theSize},head{rhs.head},tail{rhs.tail}
        {
            // fig 3.16
            rhs.theSize = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }
        List & operator= (List && rhs)
        {
            //fig 3.16
            std::swap(theSize, rhs.theSize);
            std::swap(head,rhs.head);
            std::swap(tail,rhs.tail);

            return *this;
        }

        iterator begin()
        {
            return {head->next};
        }
        const_iterator begin() const
        {
            return {head->next};
        }
        iterator end()
        {
            return {tail};
        }
        const_iterator end() const
        {
            return {tail};
        }

        int size()const 
        {
            return theSize;
        }
        bool empty() const
        {
            return size()==0;
        }

        void clear()
        {
            while (!empty())
                pop_front();
        }

        Object & front()
        {return *begin();}
        const Object & front() const
        {return *begin();}
        Object & back ()
        {return *--end();}
        const Object & back() const
        {return *--end();}

        void push_front(const Object & x )
        {insert (begin(),x);}
        void push_front(Object && x)
        {insert (begin(),std::move(x));} // the usage of std::move?

        void push_back(const Object & x)
        {insert(end(),x);}
        void push_back(Object && x)
        {insert(begin(),std::move(x));}

        void pop_front()
        {erase(begin());}
        void pop_back()
        {erase(--end());}

        iterator insert(iterator itr,const Object & x)
        {//fig 3.18; insert x before itr
            Node *p = itr.current;
            theSize++;
            return{p->prev= p->prev->next = new Node{x,p->prev,p}};
        }
        iterator insert(iterator itr, Object && x)
        {//fig 3.18 insert x before itr
            Node * p = itr.current;
            theSize++;
            return {p->prev = p->prev->next 
                                        = new Node{std::move(x),p->prev,p}};
        }

        iterator erase(iterator itr)
        {//fig 3.20
            Node*p = itr.current;
            iterator retVal{p->next};// why use the {} rather than ()
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            theSize--;

            return retVal;

        }
        iterator erase (iterator from, iterator to)
        {
            //fig 3.20
            for (iterator itr = from , iterator to )
                itr = erase(itr);
            return to;
        }

        private:
            int theSize;
            Node *head;
            Node *tail;

            void init()
            {
                //fig 3.16
                theSize = 0;
                head= new Node;
                tail = new Node;
                head->next = tail;
                tail->prev = head;
            }

};