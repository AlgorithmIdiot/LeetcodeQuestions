#pragma once
#include <vector>
template <class T> class Set;
template <class T> class Node_Iterator;

// binary node 
template<class T>
struct Node_Set 
{
	Node_Set(const T& data)
	{
		_value = data;
		_left = NULL;
		_right = NULL;
		_friend = NULL;
	}

	~Node_Set()
	{
		delete _left;
		delete _right;
	}

	T _value;
	Node_Set *_left;
	Node_Set *_right;
	Node_Set *_friend; // in-order traversal
};

template<class T>
class Set
{
public:
	Set() :_size{ 0 }, _root{nullptr}
	{}

	~Set()
	{
		clear();
	}

	//typedef typename Node_Iterator<T> iterator;
	using iterator = Node_Iterator<T>;
	Set(const Set &s)
	{
		_size = 0;
		_root = NULL;
		for (iterator it = s.begin(); it != s.end(); it++)
		{
			insert(*it);
		}
	}

	Set& operator =(const Set &s)
	{
		if (&s == this) return *this;

		clear();
		for (iterator it = s.begin(); it != s.end(); it++)
		{
			insert(*it);
		}
		return *this;
	}


	void clear()
	{
		if (_root)
		{
			delete _root;
			_root = NULL;
			_size = 0;
		}
	}

	size_t size() const
	{
		return _size;
	}

	bool empty() const
	{
		return _size == 0;
	}

	size_t _size;
	Node_Set<T> *_root; // define the _root of the Set<T>
	// mutable keyword is to mark things that can change but are not visible to the outside interface
	mutable Node_Set<T> *startIterator;

	T& insert(const T& t)
	{
		return insert_imp(t, _root, _size);
	}

	bool find(const T& t, T*& result)
	{
		return (find_imp(t, result, _root) != NULL);
	}

	bool remove(const T& t)
	{
		T *result;
		Node_Set<T> **nodeRemove = find_imp(t, result, _root);

		if (nodeRemove == NULL) {
			return false;
		}

		_size--;
		remove_imp(*nodeRemove);
		return true;
	}

	iterator begin() const
	{
		build_iterators(_root);
		return iterator(startIterator);
	}

	iterator end() const {
		return iterator(0);
	}

	void print()
	{
		print_helper();
	}

private:
	void print_helper() // private member can only be called inside the class 
	{
		for (iterator it = this->begin(); it != this->end(); it++)
			std::cout << *it << ' ';
		std::cout<< std::endl;
	}

	void build_iterators(const Node_Set<T> *root) const
	{
		size_t i;
		std::vector<Node_Set<T>*> iterators;
		build_iterators_imp(iterators, root);

		if (empty())
		{
			startIterator = NULL;
			return;
		}

		startIterator = iterators[0];
		for (i = 0; i < iterators.size() - 1; i++)
		{
			iterators[i]->_friend = iterators[i + 1];
		}
		iterators[i]->_friend = NULL;
	}

	static void build_iterators_imp(std::vector<Node_Set<T>*> &iterators, const Node_Set<T> *root)
	{
		if (root == NULL) {
			return;
		}

		build_iterators_imp(iterators, root->_left);

		iterators.push_back((Node_Set<T>*)root);

		build_iterators_imp(iterators, root->_right);
	}

	static T& insert_imp(const T& t, Node_Set<T> *&root, size_t &_size)
	{
		if (!root)
		{
			_size++;
			root = new Node_Set<T>(t);
			return root->_value;
		}

		if (t == root->_value)
		{
			return root->_value;
		}
		else if (t < root->_value)
		{
			return insert_imp(t, root->_left, _size);
		}
		else
		{
			return insert_imp(t, root->_right, _size);
		}
	}

	static Node_Set<T>** find_imp(const T& t, T*& result, Node_Set<T> *&root)
	{
		if (!root)
		{
			result = NULL;
			return NULL;
		}

		if (t == root->_value)
		{
			result = &root->_value;
			return &root;
		}
		else if (t < root->_value)
		{
			return find_imp(t, result, root->_left);
		}
		else
		{
			return find_imp(t, result, root->_right);
		}
	}

	static void travel_rightmost(Node_Set<T> *&_this, Node_Set<T> **&nodeResult)
	{
		if (!_this) return;
		if (_this->_right) {
			nodeResult = &_this;
			return travel_rightmost(_this->_right, nodeResult);
		}
	}

	static void travel_leftmost(Node_Set<T> *&_this, Node_Set<T> **&nodeResult)
	{
		if (!_this) return;
		if (_this->_left) {
			nodeResult = &_this;
			return travel_leftmost(_this->_left, nodeResult);
		}
	}

	static void remove_imp(Node_Set<T> *&root)
	{
		if (root == NULL) {
			return;
		}

		if (root->_left == NULL && root->_right == NULL)
		{
			delete root;
			root = NULL;
			return;
		}

		if (root->_left != NULL && root->_right == NULL)
		{
			Node_Set<T> *leftNode = root->_left;
			root->_left = NULL;
			delete root;
			root = leftNode;
			return;
		}

		if (root->_left == NULL && root->_right != NULL)
		{
			Node_Set<T> *rightNode = root->_right;
			root->_right = NULL;
			delete root;
			root = rightNode;
			return;
		}

		if (root->_left != NULL && root->_right != NULL)
		{
			Node_Set<T> **nodeLeftMost = NULL;
			Node_Set<T> **nodeRightMost = NULL;
			Node_Set<T> *leftChild = root->_left;
			Node_Set<T> *rightChild = root->_right;

			travel_leftmost(root->_right, nodeRightMost);

			if (nodeRightMost != NULL && (*nodeRightMost)->_left == NULL && (*nodeRightMost)->_right == NULL)
			{
				root->_value = (*nodeRightMost)->_value;
				delete *nodeRightMost;
				*nodeRightMost = NULL;

				return;
			}

			travel_rightmost(root->_left, nodeLeftMost);

			if (nodeLeftMost != NULL && (*nodeLeftMost)->_left == NULL && (*nodeLeftMost)->_right == NULL)
			{
				root->_value = (*nodeLeftMost)->_value;
				delete *nodeLeftMost;
				*nodeLeftMost = NULL;

				return;
			}
			else if (leftChild->_right == NULL)
			{
				root->_left = NULL;
				root->_right = NULL;
				delete root;
				root = leftChild;
				root->_right = rightChild;
			}
			else if (rightChild->_left == NULL)
			{
				root->_left = NULL;
				root->_right = NULL;
				delete root;
				root = rightChild;
				root->_left = leftChild;
			}
		}
	}


};

template <class T>
class Node_Iterator
{
	Node_Set<T> * n;
public:
	Node_Iterator() : n(0) {}
	Node_Iterator(Node_Set<T> * newNode) : n(newNode) { }

	bool operator == (Node_Iterator it) const { return n == it.n; }
	bool operator != (Node_Iterator it) const { return n != it.n; }

	// In-order traversal
	Node_Iterator & operator++();
	Node_Iterator operator++(int);

	T & operator*() { return n->_value; }
	T * operator->() { return &n->_value; }
	Node_Iterator & operator=(Node_Iterator<T> it) { n = it.n; return *this; }

	friend class Set<T>;
};

template <class T>
Node_Iterator<T>& Node_Iterator<T>::operator ++()
{
	n = n->_friend;
	return *this;
}

template <class T>
Node_Iterator<T> Node_Iterator<T>::operator ++(int)
{
	Node_Iterator<T> it(*this); ++(*this);

	return it;
}