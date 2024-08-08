#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *l_child = NULL, *r_child = NULL;
} *root = NULL, *st[20], *st2[20];

void insert(Node *rt, Node *nn)
{
    if (root == NULL)
    {
        root = nn;
    }
    else
    {
        if (rt->data > nn->data)
        {
            if (rt->l_child == NULL)
            {
                rt->l_child = nn;
            }
            else
            {
                insert(rt->l_child, nn);
            }
        }
        if (rt->data <= nn->data)
        {
            if (rt->r_child == NULL)
            {
                rt->r_child = nn;
            }
            else
            {
                insert(rt->r_child, nn);
            }
        }
    }
}
void create()
{
    int a;
    do
    {
        Node *new_node = new Node;
        new_node->l_child = new_node->r_child = NULL;
        cout << "Enter data : ";
        cin >> new_node->data;
        insert(root, new_node);
        cout << "Do you want to insert another Node : ";
        cin >> a;
    } while (a == 1);
}

int top = -1;
void display()
{
    Node *temp = root;
    if (temp != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->l_child;
            }
            if (top != -1)
            {
                temp = st[top];
                cout << temp->data << " ";
                temp = temp->r_child;
                top--;
            }
        } while (top != -1 || temp != NULL);
    }
    else
    {
        cout << "Tree is Empty !! " << endl;
    }
}

void delete_node()
{
    int f = 0;
    Node *temp = root;
    Node *prev = NULL;
    if (temp != NULL)
    {
        int d;
        top = -1;
        cout << "Enter data to be deleted : ";
        cin >> d;
        do
        {
            while (temp != NULL)
            {
                top++;
                st2[top] = temp;
                prev = temp;
                temp = temp->l_child;
            }
            if (top != -1)
            {
                temp = st2[top];
                if (temp->data == d)
                {
                    if (temp->l_child == NULL && temp->r_child == NULL)
                    {
                        if (prev == NULL)
                            root = NULL;
                        else if (prev->l_child == temp)
                            prev->l_child = NULL;
                        else
                            prev->r_child = NULL;
                    }
                    else if (temp->l_child == NULL || temp->r_child == NULL)
                    {
                        if (temp->l_child == NULL)
                        {
                            if (prev == NULL)
                            {
                                root = temp->r_child;
                            }
                            else
                            {
                                prev = temp->r_child;
                            }
                        }
                        if (temp->r_child == NULL)
                        {
                            if (prev == NULL)
                            {
                                root = temp->l_child;
                            }
                            else
                            {
                                prev = temp->l_child;
                            }
                        }
                    }
                    else
                    {
                        if (prev != NULL)
                        {
                            int fl = 0;
                            Node *p = temp;
                            Node *x = temp->l_child;
                            while (x->r_child != NULL)
                            {
                                p = x;
                                x = x->r_child;
                                fl = 1;
                            }
                            root = x;
                            if (fl == 1)
                            {
                                p->r_child = NULL;
                            }
                            else
                            {
                                p->l_child = NULL;
                            }
                        }
                        else
                        {
                            int fl = 0;
                            Node *p = temp;
                            Node *x = temp->l_child;
                            while (x->r_child != NULL)
                            {
                                p = x;
                                x = x->r_child;
                                fl = 1;
                            }
                            if (x->data < prev->data)
                            {
                                prev->l_child = x;
                            }
                            else
                            {
                                prev->r_child = x;
                            }

                            if (fl == 1)
                            {
                                p->r_child = NULL;
                            }
                            else
                            {
                                p->l_child = NULL;
                            }
                        }
                    }
                    delete temp;
                    cout << "Delition Successful !!" << endl;
                    f = 1;
                    return;
                }
                prev = temp;
                temp = temp->r_child;
                top--;
            }
        } while (top != -1 || temp != NULL);
    }
    else
    {
        cout << "Tree is Empty !! " << endl;
    }
    if (f == 0)
    {
        cout << "Data Not Found !!" << endl;
    }
}

int treeHeight(Node* rt) {
    if (rt == nullptr) {
        return 0; 
    }
    int leftHeight = treeHeight(rt->l_child);
    int rightHeight = treeHeight(rt->r_child);
    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    create();
    display();
    // delete_node();
    // display();
    int h=treeHeight(root);
    cout<<"Height : "<<h<<endl;
    return 0;
}

// char ch;
        // cout<<"Where you want to insert left(L) or Right(R) of "<<rt->data<<" : ";
        // cin>>ch;
        // if(ch=='L' || ch=='l')
        // {
        //     if(rt->l_child==NULL)
        //     {
        //         rt->l_child=nn;
        //     }
        //     else
        //     {
        //         insert(rt->l_child,nn);
        //     }

        // }
        // if(ch=='R' || ch=='r')
        // {
        //     if(rt->r_child==NULL)
        //     {
        //         rt->r_child=nn;
        //     }
        //     else
        //     {
        //         insert(rt->r_child,nn);
        //     }

        // }