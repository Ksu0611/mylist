#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>    //Node * n = (Node*)calloc (sizeof(Node))
using namespace std;

template <typename T1>
int vecsize(vector <T1> v)
{
	int t = 0;
	for (auto i: v)
		t++;
	return t;
}


template <typename T>
class List
{
public:
	struct Node
	{
		Node * next;
		Node * prev;
		T data;
	};
	Node * head;
	Node * ass;
	int size = 0;


	class iter
	{
	private:
		T begin;
		T end;
	public:
		iter (List<T> a)
		{
			T begin = * a.head->data;
			T end = * a.ass->next->data;	
		}
		T first(List<T> a)
		{
			return begin;
		}
		T last(List<T> a)
		{
			return end;
		}
	};


	List(vector<T> v)
	{	

		head = NULL;
		ass = NULL;

		Node * b = new Node();
		
		b->next = NULL;
		b->prev = ass;
		b->data = v[0];
		ass = b;
		head = b;
		size++;

		
		for(int i = 1; i < vecsize(v); i++)
		{
			Node * n = new Node();
			n->next = NULL;
			n->prev = ass;
			n->data = v[i];


			ass->next = n;
			
			ass = n;
			size++;

		}
	}

	List()
	{
		head = NULL;
		ass = NULL;

		Node * b = new Node();
		
		b->next = NULL;
		b->prev = ass;
		b->data = 0;
		ass = b;
		head = b;
		size++;
	}

	void pushback(T elem)
	{
		Node * x = new Node();
		x->next = NULL;
		x->prev = ass;
		x->data = elem;

		ass->next = x;
		ass = x;
		size++;

	}
	void pushfront(T elem)
	{
		Node * y = new Node();
		y->next = head;
		y->prev = NULL;
		y->data = elem;

		head->prev = y;
		head = y;
		size++;
	}

	void print()
	{
		Node * z = new Node();
		z = head->next;
		cout << head->data << " ";
		while (z != NULL)
		{
			cout << z->data << " ";
			z = z->next;
		}
		cout << endl;
	}
	bool operator==(List b)
	{
		Node * x1 = new Node();
		Node * x2 = new Node();
		x1 = head;
		x2 = b.head;
		if (size != b.size)
		{
			return false;
		}
		while (x1 != NULL)
		{
			if (x1->data != x2->data)
			{
				return false;
			}
			x1 = x1->next;
			x2 = x2->next;
		}
		return true;
	}
	bool operator!=(List b)
	{
		Node * x1 = new Node();
		Node * x2 = new Node();
		x1 = head;
		x2 = b.head;
		if (size != b.size)
		{
			return true;
		}
		while (x1 != NULL)
		{
			if (x1->data != x2->data)
			{
				return true;
			}
			x1 = x1->next;
			x2 = x2->next;
		}
		return false;
	}
	List operator=(List b)
	{
		Node * x1 = new Node();
		Node * x2 = new Node();
		x1 = head;
		x2 = b.head;
		if(size == b.size)
		{
			while (x1 != NULL)
			{
				x1->data = x2->data;
				x1 = x1->next;
				x2 = x2->next;
			}
			
		}
		if(size > b.size)
		{
			while (x2 != NULL)
			{
				x1->data = x2->data;
				x1 = x1->next;
				x2 = x2->next;
			}
			while (x1 != NULL)
			{
				x1->data = 0;
				x1 = x1->next;
			}

		}
		if (size < b.size)
		{
			while (x1 != NULL)
			{
				x1->data = x2->data;
				x1 = x1->next;
				x2 = x2->next;
			}
			while(x2 != NULL)
			{
				Node * n = new Node();
				n->next = NULL;
				n->prev = ass;
				n->data = x2->data;
				ass->next = n;
				ass = n;

				x2 = x2->next; 
			}
		}
		return *this;
	}
};
template <typename T>
int listsize(List <T> a)
{
	return a.size;
}



int main()
{
	vector <int> v = {1, 2, 3, 4, 5};
	List<int> mylist(v);
	
	vector <int> r = {1, 2, 31, 5, 8, 9};
	List<int> mylist2(r);

	iter n = iter(mylist);

	mylist = mylist2;
	mylist.print();

	// if (mylist == mylist2)
	// {
	// 	cout << "true" << endl;
	// }
	// else
	// 	cout << "false" << endl;

	mylist.pushback(6);
	mylist.print();

	mylist.pushfront(7);
	mylist.print();
	cout << listsize(mylist);
	return 0;
}