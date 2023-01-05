#include<iostream>
using namespace std;

template<typename T> 
struct Queuenode
{
    T data;
    struct Queuenode* next;
};

template<class T> 
class Queue    
{
private:
    struct Queuenode<T>* first;
    int size;
    
public:
	Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count(); 

};

    template<class T> 
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


    template<class T> 
    void Queue<T>::Enqueue(T no)  
	{
		struct Queuenode<T>* newn = new Queuenode<T>;  
		
		newn->data = no;
		newn->next = NULL;

		if(first == NULL)
		{	
			first = newn;
		}
		else
		{
			struct Queuenode<T>* temp = first;
		
			while(temp->next != NULL)
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
    
	template<class T> 
    	int Queue<T>::Dequeue()  
	{
		struct Queuenode<T>* temp = first;
	
		if(first != NULL)
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

    	template<class T> 
	void Queue<T>::Display()
	{
		struct Queuenode<T>* temp = first;
				
		if(temp == NULL)
		{
			return;
		}
		else
		{
			while(temp != NULL)
			{
				cout<<"|"<<temp->data<<"|-->";
				temp = temp->next;
			}
		}
		cout<<"NULL \n";
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

    template<class T> 
    int Queue<T>::Count()
    {
        return size;
    }

//////////////////////////////////////////////////////////////////////////////

int main()
{
cout<<"\n\n--------------------Queue Start---------------------------"<<"\n\n";
/////////////////////////////////////////////////////////////////////////////
    Queue<int>qiobj;
    
    qiobj.Enqueue(11);
    qiobj.Enqueue(21);
    qiobj.Enqueue(51);
    qiobj.Enqueue(101);

    cout<<"\nElements of Queue :"<<"\n";

    qiobj.Display();
    int iret = qiobj.Count();  
    cout<<"\nSize of queue is : "<<iret<<"\n";  

    qiobj.Dequeue();
       
    cout<<"\nElements of Queue :"<<"\n";

    qiobj.Display(); 
    iret = qiobj.Count();  
    cout<<"\nSize of queue is : "<<iret<<"\n"; 
    

//////////////////////////////////////////////////////////////////////////////

    Queue<char>qcobj;
    
    qcobj.Enqueue('A');
    qcobj.Enqueue('B');
    qcobj.Enqueue('C');
    qcobj.Enqueue('D');

    cout<<"\nElements of Queue :"<<"\n";

    qcobj.Display();
    iret = qcobj.Count();  
    cout<<"\nSize of queue is : "<<iret<<"\n";  

    qcobj.Dequeue();
       
    cout<<"\nElements of Queue :"<<"\n";

    qcobj.Display(); 
    iret = qcobj.Count();  
    cout<<"\nSize of queue is : "<<iret<<"\n";   
 
//////////////////////////////////////////////////////////////////////////
cout<<"\n\n--------------------Queue End-----------------------------"<<"\n\n";
   
    return 0;
}
