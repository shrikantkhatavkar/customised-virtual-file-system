#include<iostream>
using namespace std;

template<typename T>
struct Stacknode
{
    T data;
    struct Stacknode* next;
};


template<class T>
class Stack     
{
private:
    struct Stacknode<T>* first;
    int size;
    
public:
	Stack();
	void push(T);
	int pop();
	void Display();
	int Count();

};

    template<class T>
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


    template<class T>
    void Stack<T>::push(T no)   // InsertFirst()
    {
        struct Stacknode<T>* newn = new Stacknode<T>;

	newn->data = no;
	newn->next = NULL;

	if(first == NULL)
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

    template<class T>
    int Stack<T>::pop()   // DeleteFirst()
    {
	int no = 0;
	struct Stacknode<T>* temp = first;
	if(size == 0)     // (first == NULL)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	
	if(size == 1)     //(first->next == NULL)
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

    template<class T>
    void Stack<T>::Display()
    {
	struct Stacknode<T>* temp = first;
		
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|"<<"\n";
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

    template<class T>
    int Stack<T>::Count()
    {
        return size;
    }


////////////////////////////////////////////////////////////////////////

int main()
{
cout<<"\n\n--------------------Stack Start---------------------------"<<"\n\n";
////////////////////////////////////////////////////////////////////////

    Stack<int>siobj;
    
    siobj.push(11);
    siobj.push(21);
    siobj.push(51);
    siobj.push(101);
 
    cout<<"\nElements of stack :"<<"\n";   
    siobj.Display();

    int iret = siobj.pop();      
    cout<<"\nPoped element is :"<<iret<<"\n";     
    
    cout<<"\nElements of stack :\n";
    siobj.Display();         
    iret = siobj.Count();

    cout<<"\nSize of stack is : "<<iret<<"\n";  

////////////////////////////////////////////////////////////////////////

    Stack<char>scobj;
    
    scobj.push('A');
    scobj.push('B');
    scobj.push('C');
    scobj.push('D');
 

    cout<<"\nElements of stack :"<<"\n";   
    scobj.Display();

    char cret = scobj.pop();      
    cout<<"\nPoped element is :"<<cret<<"\n";     
    
    cout<<"\nElements of stack :\n";
    scobj.Display();         
    iret = scobj.Count();

    cout<<"\nSize of stack is : "<<iret<<"\n";     

/////////////////////////////////////////////////////////////////////////
cout<<"\n\ns--------------------Stack End------------------------------"<<"\n\n";
 
    return 0;
}