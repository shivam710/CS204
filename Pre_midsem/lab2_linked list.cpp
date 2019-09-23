#include <iostream>
#include<cstdlib>
using namespace std;


struct Node
{
    int y;
    int x;
    Node *next;
};
struct Node* head = NULL;

void AddFirst(int x , int y)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->x  = x;
    new_node->y  = y;

    new_node->next = (head);

    (head)    = new_node;
}

void DelFirst()
{
    if (head == NULL)
        {cout<<"-1\n";return ;}

    Node* temp = head;
    head = head->next;

    delete(temp);

}

void Del( int x,int y)
{

   if (head == NULL)
      {cout<<"-1\n";return ;}


   struct Node* temp = head;
  struct Node* prev = NULL;

    if ((head->x)==x&&(head->y)==y)
    {
        head = temp->next;
        free(temp);
        return ;
    }


    for (int i=0; temp!=NULL; i++)
         {
             if(temp->x==x&&temp->y==y)
             {
                 break;
             }
             prev = temp;
             temp = temp->next;
         }

    if (temp == NULL )
      {cout<<"-1\n";return ;}

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next;

    // Unlink the node from linked list
    free(temp);  // Free memory

    prev->next = next;  // Unlink the deleted node from list
}

int Search(int d)
{
    struct Node* temp = head;
    int counter=0;
    while (temp!= NULL)
    {
        if((temp->x)*(temp->x)+(temp->y)*(temp->y)<=d*d)
        {
            //cout<<"("<<(temp->x)<<","<<(temp->y)<<") ";
            counter++;
        }
        temp=temp->next;
    }
    if(counter>0) return counter;
    else return -1;
}

void Search(int x,int y)
{
    struct Node* temp = head;
    int counter=0;
    while (temp!= NULL) {
        if((temp->x)==x&&(temp->y)==y)
        {
            counter+=1;
        }
        temp=temp->next;
    }
    if(counter==0) cout<<"False";
    else cout<<"True";
}

int Length()
{
    struct Node* temp = head;
    int l=0;
    while (temp!= NULL) {
        l++;
        temp=temp->next;
    }
    return l;
}
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x,y;
            cin>>x>>y;
           AddFirst(x,y);
        }
        else if(a==2){DelFirst();}
        else if(a==3)
        {
            int x,y;
            cin>>x>>y;
           Del(x,y);
        }
        else if(a==4)
        {
            int d;
            cin>>d;
           cout<< Search(d);
            cout<<endl;

        }
        else if(a==5)
        {
            int x,y;
            cin>>x>>y;
            Search(x,y);
            cout<<endl;
        }
        else if(a==6)
        {
            cout<<Length()<<endl;
        }
    }
}

