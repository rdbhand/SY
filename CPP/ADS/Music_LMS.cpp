// 3. A Music Library System is a software application used to manage the storage and retrieval of music 
// tracks and albums. System need to maintain information such as track title, artist, album, genre, duration, 
// release year, and any other relevant attributes. System should able to add new music track, remove the 
// track, update the information of the track, search the specific track also it should display the information 
// of all the track which are present in the database. Use the Concept of Circular Linked list to implement the 
// above system.

#include<iostream>
using namespace std;

class Music
{
    public:
    int music_id;
    string music_name;
    string singer_name;
    Music *next;
}*start=NULL,*last=NULL;

void add_music()
{
    int c;
    do
    {
        Music *new_music=new Music;
        cout<<"Enter music ID , music name , singer name ";
        cin>>new_music->music_id>>new_music->music_name>>new_music->singer_name;
        new_music->next=NULL;
        if(start==NULL)
        {
            start=last=new_music;
        }
        else
        {
            last->next=new_music;
            new_music->next=start;
            last=last->next;
        }
        cout<<"Do you want to add another music (1/0) : ";
        cin>>c;
    } 
    while(c==1);
    
}

void display()
{
    Music *temp=start;
    if(temp==NULL)
    {
        cout<<"List is Empty !!"<<endl;
    }
    else
    {
        cout<<"Music Id "<<"Music Name "<<"Singer name "<<endl;
        do
        {
            cout<<temp->music_id<<"\t"<<temp->music_name<<"\t"<<temp->singer_name<<endl;
            temp=temp->next;
        }
        while(temp->next!=start);
    }
}

void search()
{
    Music *temp=start;
    if(temp==NULL)
    {
        cout<<"List is Empty !!"<<endl;
    }
    else
    {
        int i,fl=0;
        cout<<"Enter music Id you want to search : ";
        cin>>i;
        do
        {
            if(temp->music_id==i)
            {
                cout<<"Music Id "<<"Music Name "<<"Singer name "<<endl;
                cout<<temp->music_id<<"\t"<<temp->music_name<<"\t"<<temp->singer_name<<endl;
                fl=1;
                break;
            }
            temp=temp->next;
        }
        while(temp->next!=start);
        if(fl==0)
        {
            cout<<"Music not found with Music ID "<<i<<endl;
        }
    }
}

void delete_any_music()
{
    if (start == NULL)
    {
        cout << "Database is Empty !!" << endl;
    }
    else
    {
        int id;
        cout << "Enter Donor Id to delete : ";
        cin >> id;
        Music *temp =start;
        Music *p=NULL;
        int fl = 0;
        while (temp != NULL)
        {
            if (id == temp->music_id)
            {
                if (temp == start)
                {
                    start = temp->next;
                    temp->next = NULL;
                }
                else if (temp == last)
                {
                    
                }
                else
                {
                    
                }
                delete temp;
                fl = 1;
                break;
            }
            p=temp;
            temp = temp->next;
        }
        if (fl == 0)
        {
            cout << "Donor Not Found with ID : " << id << endl;
        }
        else
        {
            cout << "Donor with ID " << id << " Deleted Successfully !!" << endl;
        }
    }
}

int main()
{
    add_music();
    display();
    return 0;
}