///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////START DoublyCL///////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct DoublyCLnode
{
	T data;
	struct DoublyCLnode *next;
	struct DoublyCLnode *prev;
};

template <typename T>
class DoublyCL
{
private:
	DoublyCLnode<T> *first;
	DoublyCLnode<T> *last;
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
// Input         : Int 
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
	DoublyCLnode<T> *newn = new DoublyCLnode<T>;

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
// Input         : Int 
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
	DoublyCLnode<T> *newn = new DoublyCLnode<T>;

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
// Description   : Display elements in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <typename T>
void DoublyCL<T>::Display()
{
	DoublyCLnode<T> *temp = first;

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
// Output        : int
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
// Description   : Delete element in linked list at First position
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
// Description   : Delete element in linked list at Last position
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
		DoublyCLnode<T> *newn = new DoublyCLnode<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		DoublyCLnode<T> *temp = first;

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
// Input         : int 
// Output        : 
// Description   : Delete element in linked list at given position
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
		DoublyCLnode<T> *temp = first;

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

///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////END DoublyCL/////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////START DoublyLL///////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct DoublyLLnode
{
	T data;
	struct DoublyLLnode *next;
	struct DoublyLLnode *prev;
};

template <class T>
class DoublyLL
{
private:
	DoublyLLnode<T> *first;
	DoublyLLnode<T> *last;
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

template <class T>
DoublyLL<T>::DoublyLL()
{
	first = NULL;
	size = 0;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Input         : Int 
// Output        : 
// Description   : Insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
	DoublyLLnode<T> *newn = new DoublyLLnode<T>;

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
// Input         : Int 
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
	DoublyLLnode<T> *newn = new DoublyLLnode<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		DoublyLLnode<T> *temp = first;
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
// Input         : int, int
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
		DoublyLLnode<T> *newn = new DoublyLLnode<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		DoublyLLnode<T> *temp = first;
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
	DoublyLLnode<T> *temp = first;

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
// Description   : Delete element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::DeleteLast()
{
	DoublyLLnode<T> *temp = first;

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
// Input         : int
// Output        : 
// Description   : Delete element in linked list at given position
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
		DoublyLLnode<T> *temp = first;

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
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void DoublyLL<T>::Display()
{
	DoublyLLnode<T> *temp = first;

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

///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////END DoublyLL/////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////STRAT SinglyCL///////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct SinglyCLnode
{
	T data;
	struct SinglyCLnode *next;
};

template <class T>
class SinglyCL
{
private:
	SinglyCLnode<T> *first;
	SinglyCLnode<T> *last;
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
	SinglyCLnode<T> *temp = first;

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

template <class T>
int SinglyCL<T>::Count()
{
	return size;
}

/*
////////////////////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Input         : Int 
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
	SinglyCLnode<T> *newn = new SinglyCLnode<T>;

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
// Input         : Int 
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
	SinglyCLnode<T> *newn = new SinglyCLnode<T>;

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
// Input         : int, int
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
		SinglyCLnode<T> *newn = new SinglyCLnode<T>;
		newn->data = no;
		newn->next = NULL;

		SinglyCLnode<T> *temp = first;
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
// Description   : Delete element in linked at first position
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
// Description   : Delete element in linked list at last position
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
		SinglyCLnode<T> *temp = first;
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
// Input         : int 
// Output        : 
// Description   : Delete element in linked list at given position
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
		SinglyCLnode<T> *temp = first;
		for (int i = 1; i < ipos - 1; i++)
		{
			temp = temp->next;
		}

		SinglyCLnode<T> *targated = temp->next;

		temp->next = targated->next; // temp->next = temp->next->next;
		delete targated;
		size--;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////END SinglyCL///////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////START SinglyLL/////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct SinglyLLnode
{
	T data;
	struct SinglyLLnode *next;
};

template <class T>
class SinglyLL
{
private:
	SinglyLLnode<T> *first;
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
	SinglyLLnode<T> *newn = new SinglyLLnode<T>;

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
// Input         : Int 
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
	SinglyLLnode<T> *newn = new SinglyLLnode<T>;

	newn->data = no;
	newn->next = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		SinglyLLnode<T> *temp = first;

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
// Input         : int, int
// Output        : 
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
		SinglyLLnode<T> *newn = new SinglyLLnode<T>;
		newn->data = no;
		newn->next = NULL;

		SinglyLLnode<T> *temp = first;
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
	SinglyLLnode<T> *temp = first;

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
// Description   : Delete element in linked list at last position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void SinglyLL<T>::DeleteLast()
{
	SinglyLLnode<T> *temp = first;

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
// Input         : int, int 
// Output        : 
// Description   : Delete element in linked list at given position
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
		SinglyLLnode<T> *temp = first;

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
	SinglyLLnode<T> *temp = first;

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

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////END SinglyLL///////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////START Stack////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct Stacknode
{
	T data;
	struct Stacknode *next;
};

template <class T>
class Stack
{
private:
	struct Stacknode<T> *first;
	int size;

public:
	Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
};

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
// Description   : Insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Stack<T>::push(T no) // InsertFirst()
{
	struct Stacknode<T> *newn = new Stacknode<T>;

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
// Description   : Delete element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int Stack<T>::pop() // DeleteFirst()
{
	int no = 0;
	struct Stacknode<T> *temp = first;
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
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Stack<T>::Display()
{
	struct Stacknode<T> *temp = first;

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
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int Stack<T>::Count()
{
	return size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////End Stack/////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////Start Queue/////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct Queuenode
{
	T data;
	struct Queuenode *next;
};

template <class T>
class Queue
{
private:
	struct Queuenode<T> *first;
	int size;

public:
	Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
};

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
// Description   : Insert element in linked list at first position
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Queue<T>::Enqueue(T no)
{
	struct Queuenode<T> *newn = new Queuenode<T>;

	newn->data = no;
	newn->next = NULL;

	if (first == NULL)
	{
		first = newn;
	}
	else
	{
		struct Queuenode<T> *temp = first;

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
	struct Queuenode<T> *temp = first;

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
// Description   : Display element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
/////////////////////////////////////////////////////////////////////////////
*/

template <class T>
void Queue<T>::Display()
{
	struct Queuenode<T> *temp = first;

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
/////////////////////////////////////////////////////////////////////////////////////////
//
// Function name : Count
// Input         : 
// Output        : 
// Description   : Count element in linked list
// Auther        : Shrikant
// Date          : 18/11/2021
//
//////////////////////////////////////////////////////////////////////////////////////////
*/

template <class T>
int Queue<T>::Count()
{
	return size;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{

	/////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n----------------------------DoublyCL Start---------------------------"<< "\n\n";
	//////////////////////////////////////DoublyCL Start //////////////////////////////////

	DoublyCL<char> dclcobj;
	int iRet = 0;

	dclcobj.InsertFirst('A');
	dclcobj.InsertFirst('B');
	dclcobj.InsertFirst('C');

	dclcobj.InsertLast('D');

	dclcobj.InsertAtPos('E', 4);

	dclcobj.Display();
	iRet = dclcobj.Count();
	cout << "\nNumber of elements in Doubly Circular Linked List are :" << iRet << "\n";

	dclcobj.DeleteAtPos(4);

	dclcobj.DeleteFirst();
	dclcobj.DeleteLast();

	dclcobj.Display();
	iRet = dclcobj.Count();
	cout << "\nNumber of elements in Doubly Circular Linked List are :" << iRet << "\n";

	/////////////////////////////////////////////////////////////////////////////////////

	DoublyCL<int> dcliobj;

	dcliobj.InsertFirst(51);
	dcliobj.InsertFirst(21);
	dcliobj.InsertFirst(11);

	dcliobj.InsertLast(101);

	dcliobj.InsertAtPos(55, 4);

	dcliobj.Display();
	iRet = dcliobj.Count();
	cout << "\nNumber of elements in Doubly Circular Linked List are :" << iRet << "\n";

	dcliobj.DeleteAtPos(4);

	dcliobj.DeleteFirst();
	dcliobj.DeleteLast();

	dcliobj.Display();
	iRet = dcliobj.Count();
	cout << "\nNumber of elements in Doubly Circular Linked List are :" << iRet << "\n";

	/////////////////////////////////////DoublyCL End///////////////////////////////////
	cout << "\n\n----------------------------DoublyCL End-------------------------"<< "\n\n";

	////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n----------------------------DoublyLL Start----------------------"<< "\n\n";
	//////////////////////////////////////DoublyLL Start////////////////////////////////

	DoublyLL<char> dllcobj;

	//int iRet = 0;

	dllcobj.InsertFirst('A');
	dllcobj.InsertFirst('B');
	dllcobj.InsertFirst('C');

	dllcobj.InsertLast('D');

	dllcobj.InsertAtPos('E', 4);

	dllcobj.Display();
	iRet = dllcobj.Count();
	cout << "\nNumber of elements in Doubly Linear Linked List are :" << iRet << "\n";

	dllcobj.DeleteAtPos(4);

	dllcobj.DeleteFirst();
	dllcobj.DeleteLast();

	dllcobj.Display();
	iRet = dllcobj.Count();
	cout << "\nNumber of elements in Doubly Linear Linked List are :" << iRet << "\n";

	/////////////////////////////////////////////////////////////////////////////////////

	DoublyLL<int> dlliobj;

	dlliobj.InsertFirst(51);
	dlliobj.InsertFirst(21);
	dlliobj.InsertFirst(11);

	dlliobj.InsertLast(101);

	dlliobj.InsertAtPos(55, 4);

	dlliobj.Display();
	iRet = dlliobj.Count();
	cout << "\nNumber of elements in Doubly Linear Linked List are :" << iRet << "\n";

	dlliobj.DeleteAtPos(4);

	dlliobj.DeleteFirst();
	dlliobj.DeleteLast();

	dlliobj.Display();
	iRet = dlliobj.Count();
	cout << "\nNumber of elements in Doubly Linear Linked List are :" << iRet << "\n";

	//////////////////////////////////////DoublyLL End////////////////////////////////////
	cout << "\n\n-------------------------DoublyLL End--------------------------"<< "\n\n";

	//////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n-------------------------SinglyCL Start-------------------------"<< "\n\n";
	////////////////////////////////////////////SinglyCL Start///////////////////////////

	SinglyCL<char> sclcobj;
	//int iRet = 0;

	sclcobj.InsertFirst('C');
	sclcobj.InsertFirst('B');
	sclcobj.InsertFirst('A');

	sclcobj.InsertLast('D');

	sclcobj.InsertAtPos('E', 4);

	sclcobj.Display();
	iRet = sclcobj.Count();
	cout << "\nNumber of elements in Singly Circular Linked List are :" << iRet << "\n";

	sclcobj.DeleteAtPos(4);

	sclcobj.DeleteFirst();
	sclcobj.DeleteLast();

	sclcobj.Display();
	iRet = sclcobj.Count();
	cout << "\nNumber of elements in Singly Circular Linked List are :" << iRet << "\n";

	/////////////////////////////////////////////////////////////////////////////////////

	SinglyCL<int> scliobj;

	scliobj.InsertFirst(51);
	scliobj.InsertFirst(21);
	scliobj.InsertFirst(11);

	scliobj.InsertLast(101);

	scliobj.InsertAtPos(55, 4);

	scliobj.Display();
	iRet = scliobj.Count();
	cout << "\nNumber of elements in Singly Circular Linked List are :" << iRet << "\n";

	scliobj.DeleteAtPos(4);

	scliobj.DeleteFirst();
	scliobj.DeleteLast();

	scliobj.Display();
	iRet = scliobj.Count();
	cout << "\nNumber of elements in Singly Circular Linked List are :" << iRet << "\n";

	///////////////////////////////SinglyCL End/////////////////////////////////////
	cout << "\n\n---------------------SinglyCL End---------------------------"<< "\n\n";

	////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n----------------------SinglyLL Start----------------------" << "\n\n";
	/////////////////////////////////SinglyLL Start////////////////////////////////

	SinglyLL<char> sllcobj;

	// int iRet = 0;

	sllcobj.InsertFirst('A');
	sllcobj.InsertFirst('B');
	sllcobj.InsertFirst('C');

	sllcobj.InsertLast('D');

	sllcobj.InsertAtPos('E', 4);

	sllcobj.Display();
	iRet = sllcobj.Count();
	cout << "\nNumber of elements in Singly Linear Linked List are :" << iRet << "\n";

	sllcobj.DeleteAtPos(4);

	sllcobj.DeleteFirst();
	sllcobj.DeleteLast();

	sllcobj.Display();
	iRet = sllcobj.Count();
	cout << "\nNumber of elements in Singly Linear Linked List are :" << iRet << "\n";

	///////////////////////////////////////////////////////////////////////////////

	SinglyLL<int> slliobj;

	slliobj.InsertFirst(51);
	slliobj.InsertFirst(21);
	slliobj.InsertFirst(11);

	slliobj.InsertLast(101);

	slliobj.InsertAtPos(55, 4);

	slliobj.Display();
	iRet = slliobj.Count();
	cout << "\nNumber of elements in Singly Linear Linked List are :" << iRet << "\n";

	slliobj.DeleteAtPos(4);

	slliobj.DeleteFirst();
	slliobj.DeleteLast();

	slliobj.Display();
	iRet = slliobj.Count();
	cout << "\nNumber of elements in Singly Linear Linked List are :" << iRet << "\n";

	//////////////////////////////SinglyLL End//////////////////////////////////
	cout << "\n\n---------------------SinglyLL End-----------------------"<< "\n\n";

	/////////////////////////////////Stack Start////////////////////////////////

	cout << "\n\n-----------------Stack Start---------------------"<< "\n\n";
	////////////////////////////////////////////////////////////////////////

	Stack<int> siobj;

	siobj.push(11);
	siobj.push(21);
	siobj.push(51);
	siobj.push(101);

	cout << "\nElements of stack :"
		 << "\n";
	siobj.Display();

	int siret = siobj.pop();
	cout << "\nPoped element is :" << siret << "\n";

	cout << "\nElements of stack :\n";
	siobj.Display();
	siret = siobj.Count();

	cout << "\nSize of stack is : " << siret << "\n";

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
	siret = scobj.Count();

	cout << "\nSize of stack is : " << siret << "\n";

	/////////////////////////////////////////////////////////////////////////
	cout << "\n\ns--------------------Stack End--------------------"<< "\n\n";

	///////////////////////////////Stack End///////////////////////////////////



	//////////////////////////////Queue Start//////////////////////////////////

	cout << "\n\n-----------------Queue Start---------------------"<< "\n\n";
	////////////////////////////////////////////////////////////////////////
	Queue<int> qiobj;

	qiobj.Enqueue(11);
	qiobj.Enqueue(21);
	qiobj.Enqueue(51);
	qiobj.Enqueue(101);

	cout << "\nElements of Queue :"
		 << "\n";

	qiobj.Display();
	int iret = qiobj.Count();
	cout << "\nSize of queue is : " << iret << "\n";

	qiobj.Dequeue();

	cout << "\nElements of Queue :"
		 << "\n";

	qiobj.Display();
	iret = qiobj.Count();
	cout << "\nSize of queue is : " << iret << "\n";

	////////////////////////////////////////////////////////////////////////

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
	cout << "\n\n-------------------Queue End---------------------" << "\n\n";

	//////////////////////////////Queue End///////////////////////////////////

	//////////////////////////////////////////////////////////////////////////

	return 0;
}