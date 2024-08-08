#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next,*prev;
} *head = NULL, *tail = NULL;

void insertAtHead(Node *&head)
{
    Node *new_node = new Node;
    cout << "Enter number to insert : ";
    cin >> new_node->data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev=new_node;
        head = new_node;
    }
}

void insertAtTail(Node *&tail)
{
    Node *new_node = new Node;
    cout << "Enter number to insert : ";
    cin >> new_node->data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev=tail;
        tail = new_node;
    }
}

void insertAtany(Node *&head)
{
    int pos;
    cout << "Enter position to insert new node : ";
    cin >> pos;
    Node *temp = head;
    Node *new_node = new Node;
    cout << "Enter number to insert : ";
    cin >> new_node->data;
    new_node->next = NULL;
    new_node->prev = NULL;
    for (int i = 1; i < pos; i++)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    new_node->next = temp->next;
    new_node->prev=temp;
    temp->next = new_node;
}

void display(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Sorry List is Empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    cout << "\n----: MENU :----\n1.Insert at head\n2.Insert at tail\n3.Insert at any\n4.display\n5.delete at pos \nEnter your choice : ";
    int ch;
    do
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            insertAtHead(head);
            break;
        case 2:
            insertAtTail(tail);
            break;
        case 3:
            insertAtany(head);
            break;
        case 4:
            display(head);
            break;
        }
    } while (1);
    return 0;
}
