#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
	struct node*next;
	struct node*prev;
};

template <typename T>
class DoublyCL
{
	private:
		node<T>* first;
		node<T>* last;
		int size;
	
	public:
		DoublyCL()
		{
			first =NULL;
			last = NULL;
			size = 0;
		}

		void Display();
		int Count();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPos(int, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
};

template <typename T>
void DoublyCL<T>::InsertFirst(int no)
{
	node<T>* newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if( (first == NULL) && (last == NULL) )
	{
		first = newn;
		last = newn;	
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	last->next = first;
	first->prev = last;
	size++;
}

template <typename T>
void DoublyCL<T>::InsertLast(int no)
{
	node<T>* newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if( (first == NULL) && (last == NULL) )
	{
		first = newn;
		last = newn;	
	}
	else
	{
		last->next = newn;
		newn->prev = last;
		last = newn;
	}

	last->next = first;
	first->prev = last;
	size++;
}

template <typename T>
void DoublyCL<T>::Display()
{
	node<T>* temp = first;
	
	for(int i = 1;i<=size; i++)
	{
		cout<<"|"<<temp->data<<"|-->";
		temp = temp->next;
	}
	cout<<"\n";
}


template <typename T>
int DoublyCL<T>::Count()
{
	return size;
}


template <typename T>
void DoublyCL<T>::DeleteFirst()
{
	if( (first == NULL) && (last == NULL) )
	{
		return;	
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		first->prev = last;
		last->next = first;
	}
	size--;
}

template <typename T>
void DoublyCL<T>::DeleteLast()
{
	if( (first == NULL) && (last == NULL) )
	{
		return;	
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		last = last->prev;
		delete last->next;
		first->prev = last;
		last->next = first;
	}
	size--;
}	

template <typename T>
void DoublyCL<T>::InsertAtPos(int no, int ipos)
{
	if( (ipos<1) || (ipos> size+1) )
	{	return;		 }
	if(ipos == 1)
	{	InsertFirst(no);	}
	else if(ipos == size+1)
	{	InsertLast(no);		}
	else
	{
		node<T>* newn = new node<T>;
		
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		node<T>* temp = first;
	
		for(int i = 1; i< ipos-1; i++)
		{
			temp = temp->next;
		} 
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		size++;		
	}
}


template <typename T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
	if( (ipos<1) || (ipos> size) )
	{	return;		}
	if(ipos == 1)
	{	DeleteFirst();	}
	else if(ipos == size)
	{	DeleteLast();		}
	else
	{
		node<T>* temp = first;
		
		for(int i = 1; i<ipos -1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;

		size--;		
	}
}

//////////////////////////////////////////////////////////////////////////


int main()
{
	DoublyCL<char>cobj;
	int iRet = 0;
	
	cobj.InsertFirst('A');
	cobj.InsertFirst('B');
	cobj.InsertFirst('C');

	cobj.InsertLast('D');

	cobj.InsertAtPos('E',4);

	cobj.Display();
	iRet = cobj.Count();
	cout<<"\nNumber of elements are :"<<iRet<<"\n";

	cobj.DeleteAtPos(4);

	cobj.DeleteFirst();
	cobj.DeleteLast();

	cobj.Display();
	iRet = cobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";

/////////////////////////////////////////////////////////////////////



	DoublyCL<int>iobj;
	
	iobj.InsertFirst(51);
	iobj.InsertFirst(21);
	iobj.InsertFirst(11);

	iobj.InsertLast(101);

	iobj.InsertAtPos(55,4);

	iobj.Display();
	iRet = iobj.Count();
	cout<<"\nNumber of elements are :"<<iRet<<"\n";

	iobj.DeleteAtPos(4);

	iobj.DeleteFirst();
	iobj.DeleteLast();

	iobj.Display();
	iRet = iobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";


	return 0;
}