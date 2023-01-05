#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
	struct node* Lchild;
	struct node* Rchild;
};

template<class T>
class  BST
{
	private:
		struct node<T>* first;
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

template<class T>
void BST<T>::Insert(T no)
{
	struct node<T>* newn = new node<T>;

	newn->data = no;
	newn->Lchild = NULL;
	newn->Rchild = NULL;
	
	if(first == NULL)
	{
		first = newn;	
	}
	else
	{
		struct node<T>* temp = first;	
	
		while(1)         //Unconditinal loop  for(;;)
		{
			if(temp->data == no)
			{
				cout<<"Duplicate node\n";

				delete newn;
				break;
			}	
			else if(temp->data > no)     // lahan data
			{
				if(temp->Lchild == NULL)
				{
					temp->Lchild = newn;
					break;
				}
				temp = temp->Lchild;
	
			}
			else if(temp->data < no)    // motha data
			{
				if(temp->Rchild == NULL)
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

template<class T>
bool BST<T>::Search(T no)
{
	if(first == NULL)    // if tree is empty
	{
		return false;
	}
	else  //tree contains atleast one node
	{
		while(first != NULL)
		{
			if(first->data == no)  // node sapadla
			{
				break;
			}
			else if(no > (first->data))
			{	
				first = first->Rchild;
				
			}
			else if(no < (first->data))
			{	
				first = first->Lchild;	
			}
		}
		if(first == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

template<class T>
int BST<T>::Count()
{

	return size;
}

/////////////////////////////////////////////////////////////////////////////


int main()
{
	int no = 0, iret = 0; char ch = '\0';
	bool bret = false;
	
	/*////////////////////////////////////////////////////////////////////

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

	////////////////////////////////////////////////////////////////////*/

	BST<char>bcobj;

	bcobj.Insert('A');
	bcobj.Insert('B');
	bcobj.Insert('C');

	bcobj.Insert('D');
	bcobj.Insert('E');
	bcobj.Insert('F');

	cout<<"Enter element to be searched\n";
	cin>>ch;

	bret = bcobj.Search(ch);
	if(bret == true)

	{
		cout<<"Data found\n";	
	}
	else
	{
		cout<<"Data not found\n";
	}
	
	iret = bcobj.Count();
	cout<<"Number of elements are :"<<iret<<"\n";

	/////////////////////////////////////////////////////////////////////
	return 0;
}









