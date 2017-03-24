#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    void print(node *last)
    {
        node *temp=this;
        while(temp!=last)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<temp->data;
    }
};
int count=0;
node *head,*last;
void insertion()
{
    int n;
    node *temp=new node();
    cout<<endl<<"Enter the position you want to enter new node: ";
    cin>>n;
    if(n-1>count)
    {
        cout<<"Invalid position!!!!!!";
        return;
    }
    cout<<"enter data: ";
    cin>>temp->data;
    temp->next=NULL;
    if(n==1)
    {
        temp->next=head;
        head=temp;
    }
    if(n==2)
    {
        node *temp2=head->next;
        head->next=temp;
        temp->next=temp2;
    }
    else if(count==n-1)
    {
        if(last->next!=NULL)
        {
            temp->next=head;
        }
        last->next=temp;
        last=temp;
    }
    else
    {
        node *temp2=head;
        for(int i=0;i<n-2;i++)
            temp2=temp2->next;
        node *temp3=temp2->next;
        temp2->next=temp;
        temp->next=temp3;
    }
}

void deletion()
{
    cout<<endl<<"enter the position you want to delete the node from: ";
    int n;
    cin>>n;
    node *temp;
    if(n>count)
    {
        cout<<"void deletion"<<endl;
        return;
    }
    if(n==1)
    {
        head=head->next;
        if(last->next!=NULL)
            last->next=head;
    }
    else if(n==2)
    {
        temp=head;
        temp->next=temp->next->next;
    }
    else
    {
        temp=head;
        for(int i=0;i<n-2;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    if(count==n)
    {
        last=temp;
    }
}

int main()
{
    int n;
    cout<<"1) linear linked list "<<endl<<"2) circular linked list"<<endl;
    cin>>n;
    head=new node();
    count=1;
    last=head;
    cout<<"enter data: ";
    cin>>head->data;
    head->next=NULL;
    char ch='y';
    cout<<"want to enter another node(y/n): ";
    cin>>ch;
    switch(n)
    {
    case 1:
        while(ch!='n')
        {
            node *temp=new node();
            count++;
            temp->next=NULL;
            cout<<"enter data";
            cin>>temp->data;
            last->next=temp;
            last=temp;
            cout<<"want to enter another node(y/n)";
            cin>>ch;
        }
        break;
    case 2:
        while(ch!='n')
        {
            node *temp=new node();
            count++;
            temp->next=head;
            cout<<"enter data: ";
            cin>>temp->data;
            last->next=temp;
            last=temp;
            cout<<"want to enter another node(y/n): ";
            cin>>ch;
        }
        break;
    }
    cout<<endl<<"select the operation"<<endl<<"1) insertion"<<endl<<"2) deletion"<<endl<<"3) print list"<<endl<<"4) exit"<<endl;
    cin>>n;
    while(n!=4)
    {
        switch(n)
        {
        case 1:
            insertion();
            head->print(last);
            break;
        case 2:
            deletion();
            head->print(last);
            break;
        case 3:
            head->print(last);
        }
        cout<<endl<<"select the operation"<<endl<<"1) insertion"<<endl<<"2) deletion"<<endl<<"3) print list"<<endl<<"4) exit"<<endl;
        cin>>n;
    }
    return 0;
}
