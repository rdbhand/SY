#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    void insert();
    void display();
    void _delete();
    void update();
} *head = NULL, *tail = NULL;

void Node::insert()
{
    int ch;
    do
    {
        Node *new_node = new Node;
        cout << "Enter data to insert : ";
        cin >> new_node->data;
        new_node->next = NULL;
        new_node->prev=NULL;
        char p;
        cout << "Where you want to insert new node ? start(s) | end(e) | after given Node (a) : ";
        cin >> p;
        switch (p)
        {
        case 's':
            if (head == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                head->prev=new_node;
                new_node->next = head;
                head = new_node;
            }
            break;
        case 'e':
            if (tail == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                new_node->prev=tail;
                tail->next = new_node;
                tail = new_node;
            }
            break;

        case 'a':
            int a;
            cout << "Enter data after which you want to insert : ";
            cin >> a;
            Node *temp = head;
            Node *pos = NULL;
            while (temp != NULL)
            {
                if (temp->data == a)
                {
                    pos = temp;
                }
                temp = temp->next;
            }
            if (pos != NULL)
            {
                if (pos == tail)
                {
                    tail = new_node;
                }
                new_node->next = pos->next;
                new_node->prev=pos;
                pos->next = new_node;
            }
            else
            {
                cout << "Invalid data !!" << endl;
            }
            break;
        }
        cout << "Do you want to add another Node (1/0) : ";
        cin >> ch;
    } while (ch == 1);
}

void Node ::display()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "List is Empty !!" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << setw(5);
            temp = temp->next;
        }
    }
}

void Node::_delete()
{
    if (head == NULL)
    {
        cout << "List is Empty !!" << endl;
    }
    else
    {
        int dd;
        Node *pos = NULL;
        cout << "Enter data to be deleted : ";
        cin >> dd;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == dd)
            {
                pos = temp;
                break;
            }
            temp=temp->next;
        }
        if (pos != NULL)
        {
            if (pos->prev != NULL)
            {
                (pos->prev)->next = pos->next;
                pos->next->prev=pos->prev;
                if (temp == tail)
                {
                    tail = temp->prev;
                }
            }
            else
            {
                head = head->next;
            }
            delete temp;
            cout << dd << " deleted successfully !!" << endl;
        }
        else
        {
            cout << dd << " Not found to delete !!" << endl;
        }
    }
}

void Node::update()
{
    if (head == NULL)
    {
        cout << "List is Empty !!" << endl;
    }
    else
    {
        int ud;
        Node *pos = NULL;
        cout << "Enter data to be updated : ";
        cin >> ud;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == ud)
            {
                pos = temp;
                break;
            }
            temp = temp->next;
        }
        if (pos != NULL)
        {
            cout<<"Enter new data : ";
            cin>>pos->data;
            cout << ud << " updated successfully !!" << endl;
        }
        else
        {
            cout << ud << " Not found to update !!" << endl;
        }
    }
}
int main()
{
    Node n;
    int cc;
    do
    {
        cout << "\nMenu :  \n1.Insert   2.Display   3.Delete   4.Update   5.Exit \nEnter your choice : ";
        cin >> cc;
        switch (cc)
        {
        case 1:
            n.insert();
            break;
        case 2:
            n.display();
            break;
        case 3:
            n._delete();
            break;
        case 4:
            n.update();
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
