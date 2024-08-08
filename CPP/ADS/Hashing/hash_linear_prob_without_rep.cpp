#include<iostream>
using namespace std;
int key[20], c[10], n,i;
class student
{
    public:
    int prn, roll, phno;
    string name, add;
    float per;
    void declare();
    void Htable();
    void accept();
    void search();
}h[20];
void student :: declare ()
{
    cout<<"Enter the total number of Keys : ";
    cin>>n;
    cout<<" \n Enter the Keys : ";
    for(int i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0; i<10; i++)
    {
        h[i].prn=0;
        c[i]=-1;
    }
}
void student :: Htable ()
{
    cout<<"\n INDEX \tPRN \t RNO \t Name \t Address \t chain \n";
    for(i=0;i<10;i++)
    {
        cout<<i<<"\t"<<h[i].prn<<"\t"<<h[i].roll<<"\t"<<h[i].name<<"\t  "<<h[i].add<<" \t\t "<<c[i]<<"\n";
    }
}
void student :: accept ()
{
    int no, pos;
    for (int i=0; i<n ; i++)
    {
        no=key[i]%10;
        pos=no;
        do
        {
            if(h[no].prn==0)
            {
                h[no].prn=key[i];
                if(no!=pos)
                {
                    c[pos]=no;
                }
                cout<<"Enter student  roll no, name, address : ";
                cin>>h[no].roll>>h[no].name>>h[no].add;
                break;
            }
            else
            {
                no++;
                if(no>=10)
                {
                    no=0;
                }
            }
        } while (no<10);
        
    }
}


int main()
{
    student s;
    s.declare();
    //s.Htable();
    s.accept();
    s.Htable();
    return 0;
}
