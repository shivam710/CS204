#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,flag=0;
    cin>>n;
    set <string> s;
    for(int i=0;i<n;i++)
    {
        string q;
        cin>>q;
        string p=q;
        reverse(q.begin(),q.end());
        if(p!=q)
        {
            if(s.find(q)!=s.end())flag=1;
            else s.insert(p);
        }

    }
    if(flag==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
