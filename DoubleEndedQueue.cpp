#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *rear;
    Node *first;
};
void InsertatFront(Node *head,int x)
{
    Node *t=new Node();
    if(t==NULL)
    cout<<"Queue is Full "<<endl;
    else
    {
        t->data=x;
        t->next=NULL;
        if(head->first==NULL)
        head->first=head->rear=t;
        else
        {
            t->next=head->first;
            head->first=t;
        }
    }
}
void InsertatEnd(Node *head,int x)
{
    Node *t=new Node();
    if(t==NULL)
    cout<<"Queue is Full "<<endl;
    else
    {
        t->data=x;
        t->next=NULL;
        if(head->first==NULL)
        head->first=head->rear=t;
        else
        {
            head->rear->next=t;
            head->rear=t;
        }
    }
}
int DeleteatFront(Node *head)
{
    int x=-1;
    Node *p;
    if(head->first==NULL)
    cout<<"Queue is Empty "<<endl;
    else
    {
        p=head->first;
        head->first=head->first->next;
        x=p->data;
        delete p;
    }
    return x;
}
int DeleteatEnd(Node *head)
{
    int x=-1;
    Node *p;
    if(head->first==NULL)
    cout<<"Queue is Empty "<<endl;
    else
    {
        p=head->first;
        while(p->next!=head->rear)
        p=p->next;
        x=head->rear->data;
        delete head->rear;
        head->rear=p;
        head->rear->next=NULL;
    }
    return x;
}
void Display(Node *head)
{
    Node *p=head->first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    Node *head=new Node;
    head->first=NULL;
    head->rear=NULL;
    InsertatFront(head,10);
    Display(head);
    InsertatFront(head,20);
    Display(head);
    InsertatFront(head,30);
    InsertatEnd(head,40);
    Display(head);
    InsertatEnd(head,50);
    Display(head);
    InsertatEnd(head,60);
    Display(head);
    DeleteatFront(head);
    Display(head);
    DeleteatEnd(head);
    Display(head);
    return 0;
}