//Program: To implement stack using the dynamic array.
#include<iostream>
using namespace std;
/*

  Objective  : To implement stack using dynamic array.
  Input Parameters  :values to pushed in the stack.
  Return Value      : popped values and/or the elements in array.
  Approach          : using the dynamic array(template).
*/
template<class T> //template class T
class stack
{
	T *Stack;
	T top;
	public:
    stack()
	{
	    //Initialising the class stack
        Stack= new T[20];
		top=-1;	
	}	
	~stack()
	{
	    //destory the constructor
		delete Stack;
	}
	
		void push(T x)
		{
		    //To push the element in the Stack
			if(top==19)
			{
				cout<<"stack is full!!";
			}
			else
			
			top=top+1;
			Stack[top]=x;
			cout<<"element pushed into the stack is:"<<x<<endl;
			
		}
		T pop()
		{  
		    //To pop the top element of the stack
			if(top==-1)
			{
				cout<<"stack is empty!!";
				return -1;
			}
			else
			{
			
			T val=Stack[top];
			top=top-1;
			cout<<"element deleted is:"<<val<<endl;
		    return val;
		    }
		}
		T top_ele()
		{
		    //To display the top element of the stack
			return Stack[top];
		}
		T display()
		{
		    //To display the stack elements
			if(top==-1)
			{
				cout<<"your stack is empty!!\n";
			}
			else
			{
			cout<<"your stack contains:";
			for(int i=top;i>=0;i--)
			{
				cout<<Stack[i]<<endl;
			}
		    }
		}
};
int main()
{
	stack<int> s1;
	int choice;
	int ele;
	char ch;
	
	do
	{
	    //Menu-
		cout<<"MENU-\n 1.push\n 2.pop\n 3.display\n 4.Top element  \n";
	    cout<<"enter your choice:\n";
	    cin>>choice;
		switch(choice)
		{
		
		case 1:
			{
			cout<<"Enter element to be pushed:\n";
			cin>>ele;
			s1.push(ele);
			break;
		    }
		case 2:
			{
				s1.pop();
				break;
			}
		case 3:
			{
					s1.display();
					break;
			}
        case 4:{
            
                    cout<<"\n";
                    cout<<"top element is:"<<s1.top_ele();
                    break;
            
            }
		default:
			{
						cout<<"wrong choice!!";
						break;
			}
		}
				cout<<"\n Do you want to continue?..(y/n):";
				cin>>ch;
		
	}while(ch=='y'||ch=='Y');
	return 0;
}