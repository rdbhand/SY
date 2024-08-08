// #include <iostream>
// using namespace std;

// int n=0;

// class Chain
// {
// public:
//     int data;
//     Chain *next = NULL;
// };

// Chain *hashtab[10];

// void insert(Chain *k, Chain *p)
// {
//     Chain * temp=p;
//     if (temp->data == 0)
//     {
//         temp->data=
//     }
//     else
//     {
//         insert(k, p->next);
//     }
// }
// void accept()
// {
//     int ch;
//     do
//     {
//         int key;
//         cout << "Enter key to be inserted : ";
//         cin >> key;
//         n++;
//         int pos = key % 10;
//         Chain *new_key=new Chain;
//         new_key->data=key;
//         insert(new_key, hashtab[pos]);
//         cout<<"Do you want to insert more keys : ";
//         cin>>ch;
//     }
//     while(ch);
// }

// void display()
// {
//     cout<<"Location Keys"<<endl;
//     for(int i=0;i<10;i++)
//     {
//         Chain * temp=hashtab[i];
//         cout<<i<<"\t";
//         while(temp!=NULL)
//         {
//             cout<<temp->data<<"\t";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     accept();
//     display();
//     return 0;
// }