#include<iostream>
using namespace std;

class Family
{
    public:
    string name,gender;
    int age;
    Family *l_child,*r_child;
    void accept();
    void insert(Family *rt,Family *n_member);
    void display();
}*root=NULL;

void Family::insert(Family *rt,Family *n_member)
{
    cout<<"Where you want to insert left(L) or right(R) of "<<rt->name<<" : ";
    cin>>ch;
    
}

void Family::accept()
{
    int ch;
    root=new Family;
    cout<<"Enter name ,gender ,age : ";
    cin>>root->name>>root->gender>>root->age;
    root->l_child=root->r_child=NULL;
    do
    {
        cout<<"Do you want to add another member : ";
        cin>>ch;
        if(ch==1)
        {
            Family *new_member=NULL;
            cout<<"Enter name ,gender ,age : ";
            cin>>new_member->name>>new_member->gender>>new_member->age;
            insert(root,new_member);
        }
    } while (ch==1);
    
}
int main()
{

    return 0;
}