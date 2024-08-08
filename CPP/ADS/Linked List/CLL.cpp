#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *start = NULL, *last = NULL;

void insert()
{
    int ch;
    do
    {
        Node *new_node = new Node;
        new_node->next = NULL;
        cout << "Enter data to insert : ";
        cin >> new_node->data;
        if (start == NULL)
        {
            start = new_node;
            last = new_node;
        }
        else
        {
            new_node->next = start;
            start = new_node;
            last->next = start;
        }
        cout << "do you want to add more node : (1/0) : ";
        cin >> ch;
    } while (ch == 1);
}

void display()
{
    if (start != NULL)
    {
        Node *temp = start;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        } while (temp!=start);
    }
    else
    {
        cout<<"list is Empty !!"<<endl;
    }
}

void _delete()
{
    int dd;
    cout<<"Enter data t be deleted : ";
    cin>>dd;
    Node *temp=start,*pos=NULL,*prv=last;
    do
    {
        if(temp->data==dd)
        {
            pos=temp;
            break;
        }
        prv=temp;
        temp=temp->next;
    }
    while(temp!=start);

    if(pos!=NULL)
    {
        if(pos==start)
        {
            start=pos->next;
        }
        if(pos==last)
        {
            last=prv;
        }
        prv->next=pos->next;
        delete pos;
        cout<<dd<<" deleted Successfully !!"<<endl;
    }
    else
    {
        cout<<dd<<" Not Found to delete !!";
    }
}

void update()
{
    int ud;
    cout<<"Enter data t be updated : ";
    cin>>ud;
    Node *temp=start,*pos=NULL;
    do
    {
        if(temp->data==ud)
        {
            pos=temp;
            break;
        }
        temp=temp->next;
    }
    while(temp!=start);

    if(pos!=NULL)
    {
        cout<<"Enter new data : ";
        cin>>pos->data;
        cout<<ud<<" updated Successfully !!"<<endl;
    }
    else
    {
        cout<<ud<<" Not Found to update !!";
    }
}

int main()
{
    int cc;
    do
    {
        cout << "\nMenu :  \n1.Insert   2.Display   3.Delete   4.Update   5.Exit \nEnter your choice : ";
        cin >> cc;
        switch (cc)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            _delete();
            break;
        case 4:
            update();
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "Wrong choice !!";
        }
    } while (1);
    return 0;
}