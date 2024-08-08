#include<iostream>
#include<iomanip>
using namespace std;

class City
{
    public:
    string name;
    int fuel;
    City *next=NULL;
};

City *c[10];
int n;
void create()
{
    cout<<"Enter number of cities : ";
    cin>>n;
    cout<<"Enter city names : ";
    for(int i=0;i<n;i++)
    {
        c[i]=new City;
        cin>>c[i]->name;
        c[i]->fuel=0;
        c[i]->next=NULL;
    }
}

void connect()
{
    int e;
    cout<<"Enter number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        string s_city,d_city;
        cout<<"Enter source city name : ";
        cin>>s_city;
        for(int j=0;j<n;j++)
        {
            if(s_city==c[j]->name)
            {
                City *new_conn=new City;
                new_conn->next=NULL;
                cout<<"Enter destination city : ";
                cin>>new_conn->name;
                cout<<"Enter fuel : ";
                cin>>new_conn->fuel;
                new_conn->next=c[j]->next;
                c[j]->next=new_conn;
                break;
            }
        }
    }
}

void display()
{
    // cout<<setw(10);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<c[i]->name<<setw(5);    
    // }
    // cout<<endl;

    for(int i=0;i<n;i++)
    {
        City *temp=c[i];
        cout<<temp->name;
        temp=temp->next;
        while(temp!=NULL)
        {
            cout<<setw(5)<<temp->fuel;
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    create();
    connect();
    display();
    return 0;
}