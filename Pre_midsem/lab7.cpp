#include<bits/stdc++.h>
using  namespace std;

int compare_ab(string a,string b)
{
    string ab = a+b;
    string ba = b+a;
    if((ab.compare(ba))>0) return 1;
    else return 0;
}

void swap(string* a, string* b)  
{  
    string t = *a;  
    *a = *b;  
    *b = t;  
}  
  

int partition (string arr[], int low, int high)  
{  
    string pivot = arr[high]; 
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
         
        if (compare_ab(pivot,arr[j])==0)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  

void quickSort(string arr[], int low, int high)  
{  
    if (low < high)  
    {  
        
        int pi = partition(arr, low, high);  
  
        
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  

void printArray(string arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i];  
    cout << endl;  
}  

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
              cin>>arr[i];
        }
        
       quickSort(arr,0,n-1);
        printArray(arr,n);
        
    }
    return 0;
}
