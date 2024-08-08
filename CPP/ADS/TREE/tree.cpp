#include<iostream>
using namespace std;

class Tree_node
{
    public:
    int data;
    Tree_node *l_child,*r_child;
}*root=NULL;

void insert(Tree_node *rt,Tree_node *nn)
{
    if(rt==NULL)
    {
        rt=nn;
        cout<<"OK"<<endl;
        return;
    }
    else
    {
        char c;
        cout<<"Where you want to insert ? left(l) or right(r) of : "<<rt->data<<" : ";
        cin>>c;
        if(c=='l' || c=='L')
        {
            insert(rt->l_child,nn);
        }
        else
        {
            insert(rt->r_child,nn);
        }
    }
}

void create()
{
    int ch;
    do
    {
        Tree_node *new_node=new Tree_node;
        cout<<"Enter data to insert : ";
        cin>>new_node->data;
        new_node->l_child=NULL;
        new_node->r_child=NULL;
        if(root==NULL)
        {
            root=new_node;
        }
        else
        {
            insert(root,new_node);
        }
        cout<<"do you want to add another node (1/0) : ";
        cin>>ch;
    } while (ch==1);
    
}

int main()
{
    create();
    return 0;
}