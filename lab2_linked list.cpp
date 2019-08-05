#include <iostream> 
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

int DelFirst() 
{ 
    if (head == NULL) 
        {cout<<"empty linked list";return -1 ;} 

    Node* temp = head; 
    head = head->next; 
  
    delete(temp); 

} 

void Del( int x,int y) 
{ 
   
   if (head == NULL) 
      {cout<<"empty linked list";return ;} 
  
    
   struct Node* temp = head; 
  struct Node* prev = NULL;
     
    if ((head->x)==x&&(head->y)==y) 
    { 
        head = temp->next;    
        free(temp);              
        return; 
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
      {cout<<"not found";return ;} 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct Node *next = temp->next; 
  
    // Unlink the node from linked list 
    free(temp);  // Free memory 
  
    prev->next = next;  // Unlink the deleted node from list 
} 

void Search(int d) 
{ 
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)*(temp->x)+(temp->y)*(temp->y)<=d*d)
        {
            cout<<"("<<(temp->x)<<","<<(temp->y)<<") ";
        }
        temp=temp->next;
    } 
} 

int Search(int x,int y) 
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
    return counter;
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

    while(1)
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
            Search(d);
            cout<<endl;
            
        }
        else if(a==5)
        {
            int x,y;
            cin>>x>>y;
            cout<<Search(x,y)<<endl;
        }
        else if(a==6)
        {
            cout<<Length()<<endl;
        }
    }
}
