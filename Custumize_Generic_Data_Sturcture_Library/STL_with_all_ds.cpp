#include <iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node *next;
	struct node *prev;	 //-->only for Doubly linked lists  //not for singly linked lists
	struct node *Lchild; //-->only for BST
	struct node *Rchild; //-->only for BST
};
/////////////////////////////////SinglyLL/////////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// Class name    : SinglyLL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
class SinglyLL
{
private:
	node<T> *first;
	int size;

public:
	SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};

/*
////////////////////////////////////////////////////////////////////////////
//
// function name : SinglyLL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
SinglyLL<T>::SinglyLL()
{
	first = NULL;
	size = 0;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Input         : int 
// Output        : 
// Description   : Insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Input         : int 
// Output        : 
// Description   : Insert element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		node<T> *temp = first;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Input         : int
// Output        : void
// Description   : Insert element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int ipos)
{
	if ((ipos < 1) || (ipos > (size + 1)))
	{
		return;
	}
	if (ipos == 1)
	{
		InsertFirst(no);
	}
	else if (ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		node<T> *newn = new node<T>;
		newn->data = no;
		newn->next = NULL;

		node<T> *temp = first;
		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

		size++;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Input         : 
// Output        : 
// Description   : Delete element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::DeleteFirst()
{
	node<T> *temp = first;

	if (first != NULL)
	{
		first = first->next;
		delete temp;

		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Input         : 
// Output        : 
// Description   : delete element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::DeleteLast()
{
	node<T> *temp = first;

	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		delete first;
		first = NULL;
		size--;
	}
	else
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = NULL;
		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Input         : int
// Output        : 
// Description   : delete element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
	if ((ipos < 1) || (ipos > (size)))
	{
		return;
	}
	if (ipos == 1)
	{
		DeleteFirst();
	}
	else if (ipos == size)
	{
		DeleteLast();
	}
	else
	{
		node<T> *temp = first;

		for (int i = 1; i <= ipos - 1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next;
		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Display
// Input         : 
// Output        : 
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::Display()
{
	node<T> *temp = first;

	while (temp != NULL)
	{
		cout << "|" << temp->data << "|-->";
		temp = temp->next;
	}
	cout << "\n";
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int SinglyLL<T>::Count()
{
	return size;
}

/////////////////////////////////SinglyCL///////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// Class name    : SinglyCL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
class SinglyCL
{
private:
	node<T> *first;
	node<T> *last;
	int size;

public:
	SinglyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : SinglyCL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
SinglyCL<T>::SinglyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Display
// Input         : 
// Output        : 
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::Display()
{
	node<T> *temp = first;

	if ((first == NULL) && (last == NULL))
	{
		return;
	}

	do
	{
		cout << "|" << temp->data << "|-->";
		temp = temp->next;
	} while (temp != last->next);
	cout << "\n";
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int SinglyCL<T>::Count()
{
	return size;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Input         : int 
// Output        : 
// Description   : Insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if ((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	last->next = first;
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Input         : 
// Output        : 
// Description   : Insert element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if ((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next = newn;
		last = newn;
	}
	last->next = first;
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Input         : int ,int 
// Output        : 
// Description   : Insert element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
	if ((ipos < 1) || (ipos > (size + 1)))
	{
		return;
	}
	if (ipos == 1)
	{
		InsertFirst(no);
	}
	else if (ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		node<T> *newn = new node<T>;
		newn->data = no;
		newn->next = NULL;

		node<T> *temp = first;
		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

		size++;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Input         : 
// Output        : 
// Description   : delete element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::DeleteFirst()
{
	if ((first == NULL) && (last == NULL))
	{
		return;
	}
	else if (first == last)
	{
		delete first;
		delete last;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		last->next = first;
	}
	size--;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Input         : 
// Output        : 
// Description   : delete element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::DeleteLast()
{
	if ((first == NULL) && (last == NULL))
	{
		return;
	}
	else if (first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		node<T> *temp = first;
		while (temp->next != last)
		{
			temp = temp->next;
		}
		delete last;
		last = temp;

		last->next = first;
	}
	size--;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Input         : 
// Output        : 
// Description   : delete element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
	if ((ipos < 1) || (ipos > (size + 1)))
	{
		return;
	}
	if (ipos == 1)
	{
		DeleteFirst();
	}
	else if (ipos == size + 1)
	{
		DeleteLast();
	}
	else
	{
		node<T> *temp = first;
		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}

		node<T> *targated = temp->next;

		temp->next = targated->next; // temp->next = temp->next->next;
		delete targated;
		size--;
	}
}

/////////////////////////////////DoublyCL/////////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// Class name    : DoublyCL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
class DoublyCL
{
private:
	node<T> *first;
	node<T> *last;
	int size;

public:
	DoublyCL()
	{
		first = NULL;
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

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Input         : 
// Output        : 
// Description   : Insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::InsertFirst(int no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if ((first == NULL) && (last == NULL))
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

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Input         : 
// Output        : 
// Description   : Insert element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::InsertLast(int no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if ((first == NULL) && (last == NULL))
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

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Display
// Input         : 
// Output        : 
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::Display()
{
	node<T> *temp = first;

	for (int i = 1; i <= size; i++)
	{
		cout << "|" << temp->data << "|-->";
		temp = temp->next;
	}
	cout << "\n";
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
int DoublyCL<T>::Count()
{
	return size;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Input         : 
// Output        : 
// Description   : delete element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::DeleteFirst()
{
	if ((first == NULL) && (last == NULL))
	{
		return;
	}
	else if (first == last)
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

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Input         : 
// Output        : 
// Description   : delete element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::DeleteLast()
{
	if ((first == NULL) && (last == NULL))
	{
		return;
	}
	else if (first == last)
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

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Input         : int, int 
// Output        : 
// Description   : Insert element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::InsertAtPos(int no, int ipos)
{
	if ((ipos < 1) || (ipos > size + 1))
	{
		return;
	}
	if (ipos == 1)
	{
		InsertFirst(no);
	}
	else if (ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		node<T> *newn = new node<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		node<T> *temp = first;

		for (int i = 1; i < ipos - 1; i++)
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

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Input         : 
// Output        : 
// Description   : delete element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
	if ((ipos < 1) || (ipos > size))
	{
		return;
	}
	if (ipos == 1)
	{
		DeleteFirst();
	}
	else if (ipos == size)
	{
		DeleteLast();
	}
	else
	{
		node<T> *temp = first;

		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;

		size--;
	}
}

/////////////////////////////////////////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// Class name    : DoublyLL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
class DoublyLL
{
private:
	node<T> *first;
	node<T> *last;
	int size;

public:
	DoublyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DoublyLL
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
DoublyLL<T>::DoublyLL()
{
	first = NULL;
	//last = NULL;
	size = 0;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Insertfirst
// Input         : 
// Output        : 
// Description   : insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Input         : 
// Output        : 
// Description   : Insert element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
	node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		node<T> *temp = first;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Input         : 
// Output        : 
// Description   : Insert element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int ipos)
{
	if ((ipos < 1) || (ipos > (size + 1)))
	{
		return;
	}
	if (ipos == 1)
	{
		InsertFirst(no);
	}
	else if (ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		node<T> *newn = new node<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		node<T> *temp = first;
		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		newn->prev = temp;
		temp->next = newn;
		size++;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Input         : 
// Output        : 
// Description   : Delete element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::DeleteFirst()
{
	node<T> *temp = first;

	if (first != NULL)
	{
		first = first->next;
		delete temp;
		if (first != NULL)
		{
			first->prev = NULL;
		}
		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Input         : 
// Output        : 
// Description   : Delete element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::DeleteLast()
{
	node<T> *temp = first;

	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		delete first;
		first = NULL;
		size--;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->prev->next = NULL;
		delete temp;
		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Input         : 
// Output        : 
// Description   : delete element in linked list at given position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
	if ((ipos < 1) || (ipos > (size)))
	{
		return;
	}
	if (ipos == 1)
	{
		DeleteFirst();
	}
	else if (ipos == size)
	{
		DeleteLast();
	}
	else
	{
		node<T> *temp = first;

		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete (temp->next->prev);
		temp->next->prev = temp;
		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Display
// Input         : 
// Output        : 
// Description   : Count element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::Display()
{
	node<T> *temp = first;

	while (temp != NULL)
	{
		cout << "|" << temp->data << "|-->";
		temp = temp->next;
	}
	cout << "NULL";
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int DoublyLL<T>::Count()
{
	return size;
}

////////////////////////////////////////////////////////////////////////////

//////////////////////////////Stack/////////////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// Class name    : Stack
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
class Stack
{
private:
	struct node<T> *first;
	int size;

public:
	Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
};

/*
////////////////////////////////////////////////////////////////////////////
//
// function name : Stack
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
Stack<T>::Stack()
{
	first = NULL;
	size = 0;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Push
// Input         : Int 
// Output        : 
// Description   : Insert element in stack at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Stack<T>::push(T no) // InsertFirst()
{
	struct node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Pop
// Input         :  
// Output        : 
// Description   : Delete element stack at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int Stack<T>::pop() // DeleteFirst()
{
	int no = 0;
	struct node<T> *temp = first;
	if (size == 0) // (first == NULL)
	{
		cout << "Stack is empty\n";
		return -1;
	}

	if (size == 1) //(first->next == NULL)
	{
		no = first->data;
		delete first;
		first = NULL;
	}
	else
	{
		no = first->data;
		first = first->next;
		delete temp;
	}
	size--;
	return no;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Display
// Input         : 
// Output        : 
// Description   : Display element in stack
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Stack<T>::Display()
{
	struct node<T> *temp = first;

	while (temp != NULL)
	{
		cout << "|" << temp->data << "|"
			 << "\n";
		temp = temp->next;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : count element in Stack
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////
*/

template <class T>
int Stack<T>::Count()
{
	return size;
}

////////////////////////////////////////////////////////////////////////////

////////////////////////////Queue///////////////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// class nam     : Queue
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
class Queue
{
private:
	struct node<T> *first;
	int size;

public:
	Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
};

/*
////////////////////////////////////////////////////////////////////////////
//
// function name : Queue
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
Queue<T>::Queue()
{
	first = NULL;
	size = 0;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Enqueue
// Input         : Int 
// Output        : 
// Description   : Insert element in Queue at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Queue<T>::Enqueue(T no)
{
	struct node<T> *newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		struct node<T> *temp = first;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Dequeue
// Input         : Int 
// Output        : 
// Description   : Delete element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int Queue<T>::Dequeue()
{
	struct node<T> *temp = first;

	if (first != NULL)
	{
		first = first->next;
		delete temp;

		size--;
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Display
// Input         : 
// Output        : 
// Description   : Display element in Queue
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Queue<T>::Display()
{
	struct node<T> *temp = first;

	if (temp == NULL)
	{
		return;
	}
	else
	{
		while (temp != NULL)
		{
			cout << "|" << temp->data << "|-->";
			temp = temp->next;
		}
	}
	cout << "NULL \n";
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in queue
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int Queue<T>::Count()
{
	return size;
}

///////////////////////////////////////////////////////////////////////////

////////////////////////////////////BST/////////////////////////////////////

/*
////////////////////////////////////////////////////////////////////////////
//
// Class name    : BST
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
class BST
{
private:
	struct node<T> *first;
	int size;

public:
	BST()
	{
		first = NULL;
		size = 0;
	}
	void Insert(T no);
	bool Search(T no);
	int Count();
};

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Insert
// Input         : int
// Output        : 
// Description   : Insert element in BST
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void BST<T>::Insert(T no)
{
	struct node<T> *newn = new node<T>;

	newn->data = no;
	newn->Lchild = NULL;
	newn->Rchild = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		struct node<T> *temp = first;

		while (1) //Unconditinal loop  for(;;)
		{
			if (temp->data == no)
			{
				cout << "Duplicate node\n";

				delete newn;
				break;
			}
			else if (temp->data > no) // lahan data
			{
				if (temp->Lchild == NULL)
				{
					temp->Lchild = newn;
					break;
				}
				temp = temp->Lchild;
			}
			else if (temp->data < no) // motha data
			{
				if (temp->Rchild == NULL)
				{
					temp->Rchild = newn;
					break;
				}
				temp = temp->Rchild;
			}
		}
	}
	size++;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Search
// Input         : int
// Output        : bool
// Description   : Search element in BST
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
bool BST<T>::Search(T no)
{
	if (first == NULL) // if tree is empty
	{
		return false;
	}
	else //tree contains atleast one node
	{
		while (first != NULL)
		{
			if (first->data == no) // node sapadla
			{
				break;
			}
			else if (no > (first->data))
			{
				first = first->Rchild;
			}
			else if (no < (first->data))
			{
				first = first->Lchild;
			}
		}
		if (first == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in BST
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int BST<T>::Count()
{

	return size;
}

/////////////////////////////main function/////////////////////////////////////

int main()
{
	int iRet = 0, no = 0;
	char ch = '\0';
	bool bret = false;
	
	//////////////////////////////////////////////////////////////
	cout << "\n\n-----------SinglyLL Start--------------------\n\n";
	SinglyLL<char> sllcobj;

	sllcobj.InsertFirst('A');
	sllcobj.InsertFirst('B');
	sllcobj.InsertFirst('C');

	sllcobj.InsertLast('D');

	sllcobj.InsertAtPos('E', 4);

	sllcobj.Display();
	iRet = sllcobj.Count();
	cout << "\nNumber of elemensts are : " << iRet << "\n";

	sllcobj.DeleteAtPos(4);

	sllcobj.DeleteFirst();
	sllcobj.DeleteLast();

	sllcobj.Display();
	iRet = sllcobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	////////////////////////////////////////////////////////

	SinglyLL<int> slliobj;

	slliobj.InsertFirst(51);
	slliobj.InsertFirst(21);
	slliobj.InsertFirst(11);

	slliobj.InsertLast(101);

	slliobj.InsertAtPos(55, 4);

	slliobj.Display();
	iRet = slliobj.Count();
	cout << "\nNumber of elemensts are : " << iRet << "\n";

	slliobj.DeleteAtPos(4);

	slliobj.DeleteFirst();
	slliobj.DeleteLast();

	slliobj.Display();
	iRet = slliobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	cout << "\n\n-----------SinglyLL End----------------------\n\n";
	//////////////////////////////////////////////////////////////

	cout << "\n\n-----------SinglycL Start--------------------\n\n";
	SinglyCL<char> sclcobj;

	sclcobj.InsertFirst('C');
	sclcobj.InsertFirst('B');
	sclcobj.InsertFirst('A');

	sclcobj.InsertLast('D');

	sclcobj.InsertAtPos('E', 4);

	sclcobj.Display();
	iRet = sclcobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	sclcobj.DeleteAtPos(4);

	sclcobj.DeleteFirst();
	sclcobj.DeleteLast();

	sclcobj.Display();
	iRet = sclcobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	///////////////////////////////////////////////////////////////////////////

	SinglyCL<int> scliobj;

	scliobj.InsertFirst(51);
	scliobj.InsertFirst(21);
	scliobj.InsertFirst(11);

	scliobj.InsertLast(101);

	scliobj.InsertAtPos(55, 4);

	scliobj.Display();
	iRet = scliobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	scliobj.DeleteAtPos(4);

	scliobj.DeleteFirst();
	scliobj.DeleteLast();

	scliobj.Display();
	iRet = scliobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	cout << "\n\n-----------SinglyCL End----------------------\n\n";
	/////////////////////////////////////////////////////////////////

	cout << "\n\n----------DoublyCL Start-----------------------------\n\n";
	////////////////////////////////////////////////////////////////////

	DoublyCL<char> dclcobj;

	dclcobj.InsertFirst('A');
	dclcobj.InsertFirst('B');
	dclcobj.InsertFirst('C');

	dclcobj.InsertLast('D');

	dclcobj.InsertAtPos('E', 4);

	dclcobj.Display();
	iRet = dclcobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	dclcobj.DeleteAtPos(4);

	dclcobj.DeleteFirst();
	dclcobj.DeleteLast();

	dclcobj.Display();
	iRet = dclcobj.Count();
	cout << "Number of elements are :" << iRet << "\n";

	/////////////////////////////////////////////////////////////////////

	DoublyCL<int> dcliobj;

	dcliobj.InsertFirst(51);
	dcliobj.InsertFirst(21);
	dcliobj.InsertFirst(11);

	dcliobj.InsertLast(101);

	dcliobj.InsertAtPos(55, 4);

	dcliobj.Display();
	iRet = dcliobj.Count();
	cout << "\nNumber of elements are :" << iRet << "\n";

	dcliobj.DeleteAtPos(4);

	dcliobj.DeleteFirst();
	dcliobj.DeleteLast();

	dcliobj.Display();
	iRet = dcliobj.Count();
	cout << "Number of elements are :" << iRet << "\n";

	/////////////////////////////////////////////////////////////////////
	cout << "\n\n--------------DoublyCL End----------------------------\n\n";

	cout << "\n\n--------------DoublyLL Start---------------------------\n\n";
	//////////////////////////////////////////////////////////////////////

	DoublyLL<char> dllcobj;

	dllcobj.InsertFirst('A');
	dllcobj.InsertFirst('B');
	dllcobj.InsertFirst('C');

	dllcobj.InsertLast('D');

	dllcobj.InsertAtPos('E', 4);

	dllcobj.Display();
	iRet = dllcobj.Count();
	cout << "\nNumber of elemensts are : " << iRet << "\n";

	dllcobj.DeleteAtPos(4);

	dllcobj.DeleteFirst();
	dllcobj.DeleteLast();

	dllcobj.Display();
	iRet = dllcobj.Count();
	cout << "\nNUmber of elements are :" << iRet << "\n";

	////////////////////////////////////////////////////////////////////////

	DoublyLL<int> dlliobj;

	dlliobj.InsertFirst(51);
	dlliobj.InsertFirst(21);
	dlliobj.InsertFirst(11);

	dlliobj.InsertLast(101);

	dlliobj.InsertAtPos(55, 4);

	dlliobj.Display();
	iRet = dlliobj.Count();
	cout << "\nNumber of elemensts are : " << iRet << "\n";

	dlliobj.DeleteAtPos(4);

	dlliobj.DeleteFirst();
	dlliobj.DeleteLast();

	dlliobj.Display();
	iRet = dlliobj.Count();
	cout << "\nNUmber of elements are :" << iRet << "\n";

	//////////////////////////////////////////////////////////////////////
	cout << "\n\n--------------DoublyLL End-----------------------------\n\n";

	cout << "\n\n--------------------Stack Start--------------------"
		 << "\n\n";
	////////////////////////////////////////////////////////////////////////

	Stack<int> siobj;

	siobj.push(11);
	siobj.push(21);
	siobj.push(51);
	siobj.push(101);

	cout << "\nElements of stack :"
		 << "\n";
	siobj.Display();

	int iret = siobj.pop();
	cout << "\nPoped element is :" << iret << "\n";

	cout << "\nElements of stack :\n";
	siobj.Display();
	iret = siobj.Count();

	cout << "\nSize of stack is : " << iret << "\n";

	////////////////////////////////////////////////////////////////////////

	Stack<char> scobj;

	scobj.push('A');
	scobj.push('B');
	scobj.push('C');
	scobj.push('D');

	cout << "\nElements of stack :"
		 << "\n";
	scobj.Display();

	char cret = scobj.pop();
	cout << "\nPoped element is :" << cret << "\n";

	cout << "\nElements of stack :\n";
	scobj.Display();
	iret = scobj.Count();

	cout << "\nSize of stack is : " << iret << "\n";

	/////////////////////////////////////////////////////////////////////////
	cout << "\n\ns--------------------Stack End-----------------------"
		 << "\n\n";

	//////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------Queue Start---------------------------"
		 << "\n\n";
	/////////////////////////////////////////////////////////////////////////////
	Queue<int> qiobj;

	qiobj.Enqueue(11);
	qiobj.Enqueue(21);
	qiobj.Enqueue(51);
	qiobj.Enqueue(101);

	cout << "\nElements of Queue :"
		 << "\n";

	qiobj.Display();
	iret = qiobj.Count();
	cout << "\nSize of queue is : " << iret << "\n";

	qiobj.Dequeue();

	cout << "\nElements of Queue :"
		 << "\n";

	qiobj.Display();
	iret = qiobj.Count();
	cout << "\nSize of queue is : " << iret << "\n";

	//////////////////////////////////////////////////////////////////////////////

	Queue<char> qcobj;

	qcobj.Enqueue('A');
	qcobj.Enqueue('B');
	qcobj.Enqueue('C');
	qcobj.Enqueue('D');

	cout << "\nElements of Queue :"
		 << "\n";

	qcobj.Display();
	iret = qcobj.Count();
	cout << "\nSize of queue is : " << iret << "\n";

	qcobj.Dequeue();

	cout << "\nElements of Queue :"
		 << "\n";

	qcobj.Display();
	iret = qcobj.Count();
	cout << "\nSize of queue is : " << iret << "\n";

	//////////////////////////////////////////////////////////////////////////
	cout << "\n\n--------------------Queue End-----------------------------"
		 << "\n\n";

	//////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------BST Start---------------------------"
		 << "\n\n";
	/////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////

	BST<int>biobj;

	biobj.Insert(51);
	biobj.Insert(21);
	biobj.Insert(101);

	biobj.Insert(52);
	biobj.Insert(22);
	biobj.Insert(102);

	cout<<"Enter number to be searched\n";
	cin>>no;

	bret = biobj.Search(no);
	if(bret == true)

	{
		cout<<"Data found\n";	
	}
	else
	{
		cout<<"Data not found\n";
	}
	
	iret = biobj.Count();
	cout<<"Number of elements are :"<<iret<<"\n";

	////////////////////////////////////////////////////////////////////

	BST<char> bcobj;

	bcobj.Insert('A');
	bcobj.Insert('B');
	bcobj.Insert('C');

	bcobj.Insert('D');
	bcobj.Insert('E');
	bcobj.Insert('F');

	cout << "Enter element to be searched\n";
	cin >> ch;

	bret = bcobj.Search(ch);
	if (bret == true)

	{
		cout << "Data found\n";
	}
	else
	{
		cout << "Data not found\n";
	}

	iret = bcobj.Count();
	cout << "Number of elements are :" << iret << "\n";

	cout << "\n\n--------------------BST End-------------------------"<< "\n\n";
	/////////////////////////////////////////////////////////////////////////////

	return 0;
}