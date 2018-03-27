//To implement stack data structure using singly linked list.
#include<iostream>
#include<conio.h>

using namespace std;
/*
	Objective: To implement stack using the singly linked list.
	Input parameters: To push in the elements in the linked list.(int type)
	Return value: To return the popped or/and all elements of the stack.
	approach: Using singly linked list.
*/

struct Node  // creating a node 
{
    int info;
    Node *next;
}*head,*tail,*temp;

class sll{   //class of singly linked list
    public:
        Node* create_node(int);
        void insert_beg(Node *np);
        void insert_end(Node *np);
        void search(int n);
        int del_beg();
        int del_end();
        void display();
};
Node *sll :: create_node(int n)
{
	//to create a new  node 
	struct Node *newptr;
 newptr= new Node;
 newptr->info=n;
 newptr->next=NULL;
 return newptr;
}

void sll:: insert_beg(Node *np)
{
	//to insert a node at the beginning of the linked list
    if(head==NULL)
        head=np;
    else
    {
        np->next=head;
        head=np;
    }
}

void sll:: insert_end(Node *np)
{	
	//to insert a node at the end the linked list
    temp=head;
    if(head==NULL)
        head=np;
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=np;
        tail=np;
    }
}

void sll:: search(int n)
{
	//to search an element in the linked list
    temp=head;
  if(head==NULL)
    cout<<"list is empty \n";
  else{
    while(temp->next!=NULL && temp->info!=n)
        temp=temp->next;
    if(temp->info==n)
        cout<<"element is present in the list \n";
    else if(temp->next==NULL)
        cout<<"not found \n";
  }
}


int sll:: del_beg()
{
	// to delete a node at the beginning of the linked list
    int ret;
    temp=head;
    if(head==NULL)
        cout<<"empty list \n";
    else if(head->next==NULL)
        head=tail=NULL;
    else{
        ret=head->info;
        head=head->next;
        return ret;
    }

}

int sll:: del_end()
{
    //to delete the last node of the linked list
	int ret;
    temp=head;
    if(head==NULL)
        cout<<"empty list \n";
    else if(head->next==NULL)
        head=tail=NULL;
    else{
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ret=temp->next->info;
        temp->next=NULL;
        return ret;
    }
}

void sll:: display()
{
	//to display the data of the linked list
  temp=head;
  while(temp->next!=NULL)
  {   cout<<"-------"<<"\n";
      cout<<"|  "<<temp->info<<"  |"<<"\n";
      cout<<"-------"<<"\n";
      temp=temp->next;
  }
	cout<<"-------"<<"\n";
    cout<<"|  "<<temp->info<<"  |"<<"\n";
    cout<<"-------"<<"\n";
}
int main()
{
    int inf,ch1,inf2;
    sll obj;
    Node *np;
    char ch2;
    do{
        cout<<"1-Insert at beginning\n2-Insert at the end\n3-Search\n4-Modify\n5-Delete from beg\n6-Delete from end\n7-Display\n";
        cout<<"Enter yr choice \n";
        cin>>ch1;
        switch(ch1)
        {
        case 1:cout<<"enter the data u want to enter "<<"\n";	
               cin>>inf;
               np=obj.create_node(inf);
               obj.insert_beg(np);
            break;
        case 2:cout<<"enter the data u want to enter "<<"\n"; //to enter the values in the linked list
               cin>>inf;
               np=obj.create_node(inf);
               obj.insert_end(np);
            break;
        case 3:cout<<"enter the data u want to search"<<"\n";	 // to search an element in the linked list
               cin>>inf;
               obj.search(inf);
            break;
        case 4:
            inf=obj.del_beg();
            cout<<"deleted element is "<<inf<<"\n";	// to delete the first node of the linked list
            break;
        case 5:
            inf=obj.del_end();		// to delete the node at the end of the linked list
            cout<<"deleted element is "<<inf<<"\n";;
            break;
        case 6:cout<<"Displaying data "<<"\n";	// to display the linked list contents
            obj.display();
            break;
        default:cout<<"wrong choice\n"; // alert message for wrong choice 
        }
        std::cout<<"Do u want to continue\n";  //to continue to display the menu if the choice is "y" or "Y"
        std::cin>>ch2;
    }while(ch2=='Y'||ch2=='y'); 
    return 0;
}