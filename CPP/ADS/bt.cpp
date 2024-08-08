#include<iostream>
using namespace std;

int cnt=0;

class Family
{
    public:
    string name;
    Family *left,*right;
}*root=NULL;

void insert(Family *&root,Family *&n)
{
    char chr;
    cout<<"Do you want to insert left(L) or Right(R) of "<<root->name<<" : "<<endl;
    cin>>chr;
    if(chr=='L' || chr=='l')
    {
        if(root->left==NULL)
        {
            root->left=n;
        }
        else
        {
            insert(root->left,n);
        }
    }

    if(chr=='R' || chr=='r')
    {
        if(root->right==NULL)
        {
            root->right=n;
        }
        else
        {
            insert(root->right,n);
        }
    }

}

void buildTree()
{
    int ch;
    Family *rt=new Family;
    cout<<"Enter name of family member : ";
    cin>>rt->name;
    rt->left=NULL;
    rt->right=NULL;
    root=rt;
    do
    {
        cout<<"Do you want to add more menbers(1/0) : ";
        cin>>ch;
        if(ch==1)
        {   
            Family *n=new Family;
            cout<<"Enter the member name : ";
            cin>>n->name;
            n->left=n->right=NULL;
            insert(root,n);
        }
    } while (ch==1);
    
}

void inorder(Family *&rt)
{
    if(rt==NULL)
    {
        return;
    }
    else
    {
        inorder(rt->left);
        cout<<rt->name<<"  ";
        inorder(rt->right);
    }
}

void preorder(Family *&rt)
{
    if(rt==NULL)
    {
        return;
    }
    else
    {
        cout<<rt->name<<"  ";
        preorder(rt->left);
        preorder(rt->right);
    }
}

void postorder(Family *&rt)
{
    if(rt==NULL)
    {
        return;
    }
    else
    {
        postorder(rt->left);
        postorder(rt->right);
        cout<<rt->name<<"  ";
    }
}

int main()
{
    int c;
    do
    {
        cout<<"\nMENU :--->>"<<endl;
        cout<<"1.Create Tree \n2.Inorder \n3.Preorder \n4.Postorder \n5.exit \nEnter your choice : ";
        cin>>c;
        switch(c)
        {
            case 1:
            buildTree();
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            exit(1);
            break;
            default:
            cout<<"Wrong choice !!";
            break;
        }
    } while (1);
    
    return 0;
}