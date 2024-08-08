#include <iostream>
#include <iomanip>
using namespace std;

class Music
{
public:
    int key;
    string name;
    string singer;
    int chain;
};
string mus_list[10];
Music ht[10];
void declare()
{
    for (int i = 0; i < 10; i++)
    {
        ht[i].key = -1;
        ht[i].chain = -1;
    }
}

void create()
{
    int ch;
    string s;
    do
    {
        cout << "Enter Music name : ";
        cin >> s;
        int x = s[0] % 10;
        for (int k = x; k < 10; k++)
        {
            if (ht[k].key == -1)
            {
                ht[k].name = s;
                cout << "Enter singer name : ";
                cin >> ht[k].singer;
                ht[k].key = x;
                break;
            }
            if (k == 9)
            {
                k = -1;
            }
        }
        cout << "Do you want to add another music (1/0) : ";
        cin >> ch;
    } while (ch == 1);
}

void display()
{
    cout << "index" << setw(7) << "key" << setw(7) << "name" << setw(7) << "singer" << setw(7) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << setw(7) << ht[i].key << setw(7) << ht[i].name << setw(7) << ht[i].singer << setw(7) << endl;
    }
}

void search()
{
    int pos,fl=0;
    string m_name;
    cout << "Enter music name : ";
    cin >> m_name;
    pos = m_name[0] % 10;
    for (int k = pos; k < 10; k++)
    {
        if (ht[k].key == pos)
        {
            fl=1;
            cout<<"Music Found !!"<<endl;
            break;
        }
        if (k == 9)
        {
            k = -1;
        }
    }
    if(fl==0)
    {
        cout<<"Music Not Found !!"<<endl;
    }

}

int main()
{
    display();
    declare();
    create();
    display();
    search();
    return 0;
}