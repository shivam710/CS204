#include<bits/stdc++.h>
using namespace std;
//template<typename K, typename V>
int capacity=20;
int Size=0;
struct Node
{
    int key;
    int value;
};
int hashvalue(int key)
{
    return (key%capacity);
}
void Insert(struct Node arr[] ,int key,int value)
{
    struct Node node;
    node.key=key;
    node.value=value;
    int index=hashvalue(key);
    while(arr[index].key!=-2)
    {
        if(arr[index].key==-1||arr[index].key==key)
        {
            break;
        }
        index++;
        index%=capacity;
    }
    if(arr[index].key==-2||arr[index].key==-1){arr[index]=node;Size++;}


}
struct Node* Search(struct Node arr[],int key)
{
    int counter=0;
    int index =hashvalue(key);
    while(arr[index].key!=-2||counter!=capacity)
    {
        if(arr[index].key==key)
        {
            return &arr[index];
        }
        index++;
        index%=capacity;
        counter++;
    }
    struct Node temp;
    temp.key=-2;
    temp.value=-2;
    return &temp;
};
int Delete(struct Node arr[],int key)
{
    int index=hashvalue(key);
    struct Node temp=*(Search(arr,key));

    if(temp.key!=-2)
    {
        //int temp=*(Search(arr,key)).value;
        struct Node temp1;
        temp1.key=-1;
        temp1.value=-1;
        *(Search(arr,key))=temp1;
        return temp.value;


    }
    else cout<<"Element Not Found"<<endl;
}
void display(struct Node arr[])
{
    for(int i=0;i<capacity;i++)
    {
        if(arr[i].key!=-2&&arr[i].key!=-1)
        {
            cout<<"key is "<<arr[i].key<<"  value is "<<arr[i].value<<endl;
        }
    }
}
int main()
{
    struct Node arr[capacity];
    for(int i=0;i<capacity;i++)
    {
        arr[i].key=-2;
        arr[i].value=-2;
    }
    Insert(arr ,1,1);
     Insert(arr ,2,745);
      Insert(arr ,2,3);
      Insert(arr ,3,8);
      Insert(arr ,4,9);
      Insert(arr ,5,10);
      Insert(arr ,11,4);
      Insert(arr ,7,6);
      cout<<Delete(arr,11)<<endl;
      cout<<(*(Search(arr,2))).value<<endl;
      display(arr);


}



