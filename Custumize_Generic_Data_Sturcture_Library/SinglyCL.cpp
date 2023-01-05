#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
	struct node *next;
};

template <class T>
class SinglyCL
{
	private:
		node<T>* first;
		node<T>* last;
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
			last  = NULL;
			size = 0;
		}
	
		
		template <class T>	
		void SinglyCL<T>::Display()
		{
			node<T>* temp = first;
			
			if((first == NULL) && (last == NULL))
			{
				return;
			}
			
			do
			{
				cout<<"|"<<temp->data<<"|-->";
				temp = temp->next;
			}while(temp != last->next);
			cout<<"\n";
		}
		
		
		template <class T>
		int SinglyCL<T>::Count()
		{
			return size;
		}
	
	
		template <class T>
		void SinglyCL<T>::InsertFirst(T no)
		{
			node<T>* newn = new node<T>;
			
			newn->data = no;
			newn->next = NULL;
	
			if((first == NULL) && (last == NULL))
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

		
		template <class T>
		void SinglyCL<T>::InsertLast(T no)
		{
			node<T>* newn = new node<T>;
			
			newn->data = no;
			newn->next = NULL;
	
			if((first == NULL) && (last == NULL))
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

		
		template <class T>
		void SinglyCL<T>::InsertAtPos(T no, int ipos)
		{
			if((ipos<1) || (ipos >(size+1)))		
			{
				return;
			}
			if(ipos == 1)
			{
				InsertFirst(no);
			}
			else if(ipos == size+1)
			{
				InsertLast(no);
			}
			else
			{
				node<T>* newn = new node<T>;
				newn->data = no;
				newn->next = NULL;
		
				node<T>* temp = first;
				for(int i = 1;i<ipos-1;i++)
				{
					temp = temp->next;	
				}
				newn->next = temp->next;
				temp->next = newn;

				size++;		
			}
		}


		template <class T>
		void SinglyCL<T>::DeleteFirst()
		{
			if((first == NULL) && (last == NULL))
			{	
				return;
			}
			else if(first == last)
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

		
		template <class T>
		void SinglyCL<T>::DeleteLast()
		{
			if((first == NULL) && (last == NULL))
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
				node<T>* temp = first;
				while(temp->next != last)
				{
					temp = temp->next;	
				}
				delete last;
				last = temp;

				last->next = first;
			}
			size--;
		}

		template <class T>
		void SinglyCL<T>::DeleteAtPos(int ipos)
		{
			if((ipos<1) || (ipos >(size+1)))		
			{
				return;
			}
			if(ipos == 1)
			{
				DeleteFirst();
			}
			else if(ipos == size+1)
			{
				DeleteLast();
			}
			else
			{
				node<T>* temp = first;
				for(int i = 1;i<ipos-1;i++)
				{
					temp = temp->next;	
				}
				
				node<T>* targated = temp->next;

				temp->next = targated->next; // temp->next = temp->next->next;
				delete targated;
				size--;	
			}
		}


///////////////////////////////////////////////////////////////////////////

int main()
{
	SinglyCL<char>cobj;
	int iRet = 0;

	cobj.InsertFirst('C');
	cobj.InsertFirst('B');
	cobj.InsertFirst('A');

	cobj.InsertLast('D');

	cobj.InsertAtPos('E', 4);

	cobj.Display();
	iRet = cobj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";

	cobj.DeleteAtPos(4);

	cobj.DeleteFirst();
	cobj.DeleteLast();

	cobj.Display();
	iRet = cobj.Count();
	cout<<"NUmber of elements are :"<<iRet<<"\n";

///////////////////////////////////////////////////////////////////////////

	SinglyCL<int>iobj;

	iobj.InsertFirst(51);
	iobj.InsertFirst(21);
	iobj.InsertFirst(11);

	iobj.InsertLast(101);

	iobj.InsertAtPos(55, 4);

	iobj.Display();
	iRet = iobj.Count();
	cout<<"NUmber of elements are :"<<iRet<<"\n";

	iobj.DeleteAtPos(4);

	iobj.DeleteFirst();
	iobj.DeleteLast();

	iobj.Display();
	iRet = iobj.Count();
	cout<<"NUmber of elements are :"<<iRet<<"\n";

	return 0;
}