#include<bits/stdc++.h>
using namespace std;
int bucket =7;
int hashfunction(int x)
{
    return(x%bucket);
}
void hashDelete(list<int> table[],int x)
{
    int k=hashfunction(x);
    list<int> :: iterator i;
    for(i=table[k].begin();i!=table[k].end();i++)
    {
        if(*i==x)break;
    }
    if(i!=table[k].end())table[k].erase(i);

}
void hashInsert(list <int> table[],int x)
{
    int k=hashfunction(x);
    table[k].push_back(x);
}
void hashdisplay(list <int> table[])
{
    for(int i=0;i<bucket;i++)
    {
        cout<<i;
        for (auto j : table[i])
        {
            cout<< " --> "<<j;
        }
        cout<<endl;
    }
}
int main()
{
    int arr[]={1,2, 3, 4 ,5 ,6 ,7 ,8 ,9 , 10 , 21,25 ,100};
    int n=sizeof(arr)/sizeof(arr[0]);
    list<int>table[bucket];
    for(int i=0;i<n;i++)
    {
        hashInsert(table ,arr[i]);
    }
    hashDelete(table,100);
    hashdisplay(table);
}
