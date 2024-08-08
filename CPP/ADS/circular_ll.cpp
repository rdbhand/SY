#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *start = NULL,*last=NULL;

void create()
{
    int ch;
    do
    {
        Node *new_node=new Node;
        new_node->next=NULL;
        cout<<"Enter data to insert : ";
        cin>>new_node->data;
        if(start==NULL)
        {
            start=new_node;
            last=new_node;
            last->next=start;
        }
        else
        {
            last->next=new_node;
            last=new_node;
            last->next=start;
        }
        cout<<"Do you want to insert more node (1/0) : ";
        cin>>ch;
    } 
    while(ch==1);
    
}

void display()
{
    Node* temp=start;
    if(temp==NULL)
    {
        cout<<"Circular list is Empty !!"<<endl;
    }
    else
    {
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        while(temp!=start);
    }
}

void delete_any_node()
{
    if(start==NULL)
    {
        cout<<"Circular linked list is Empty !!"<<endl;
    }
    else
    {
        int d,fl=0;
        cout<<"Enter data to be deleted : ";
        cin>>d;
        Node *p=last;
        Node *temp=start;
        do
        {
            if(temp->data==d)
            {
                if(temp==start)
                {
                    if(start==last)
                    {
                        start=last=temp=NULL;
                    }
                    else
                    {
                        p->next=temp->next;
                        start=temp->next;
                        temp->next=NULL;
                    }
                    
                }
                else if(temp==last)
                {
                    p->next=temp->next;
                    last=p;
                    temp->next=NULL;
                }
                else
                {
                    p->next=temp->next;
                    temp->next=NULL;
                }
                delete temp;
                fl=1;
                break;
            }
            p=temp;
            temp=temp->next;
        }
        while(temp!=start);
        if(fl==0)
        {
            cout<<"Node not found with data : "<<d<<endl;
        }
        else
        {
            cout<<"Node with data "<<d<<" deleted Successfully !!"<<endl;
        }
    }
}

int main()
{
    cout << "\n----: MENU :----\n1.Create circular LL \n2.display \n3.delete any node \n4.Exit \n";
    int ch;
    do
    {
        cout<<"Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            create();
            break;
        
        case 2:
            display();
            break;
        case 3:
            delete_any_node();
            break;
        case 4:
            exit(1);
            break;
        default:
            cout<<"Wrong choice !!"<<endl;
        }
    } while (1);
    return 0;
}
