#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int x;
    Node *next;
};
struct Node* head = NULL;

void Addfirst(int key)
{

        struct Node* node =(struct Node*)malloc(sizeof(struct Node));
        node->x=key;

        node->next=head;
        head=node;
}

void DelFirst()
{
    if(head!=NULL)
    {
        Node* temp = head;
        head=head->next;
        free(temp);
    }

}

void Del(int x)
{
    if(head==NULL)return;
    if(head->x==x)
    {
        DelFirst();
    }
    Node* temp1=head;
    Node* prev=NULL;
    while(temp1!=NULL)
    {
        if(temp1->x==x)
        {
            Node* temp= temp1;
            prev->next=temp1->next;
            free(temp);
            break;

        }
        prev=temp1;
        temp1=temp1->next;

    }
}

void Search(int x)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->x==x)cout<<"Found";
        temp=temp->next;
    }
    cout<<"Not Found";

}
int Length()
{
    int counter=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        counter++;
        temp=temp->next;
    }
    cout<<counter;
}
void display()
{
    struct Node* temp=head;
    cout<<endl;
    while(temp!=NULL)
    {
        cout<<temp->x<<" ";
        temp=temp->next;
    }
    cout<<endl;

}
int main()
{
    Addfirst(1);
    Addfirst(2);
    Addfirst(3);
    Addfirst(4);
    Addfirst(5);
    Addfirst(6);
    display();
    DelFirst();
    display();
    Del(4);
    display();
}








