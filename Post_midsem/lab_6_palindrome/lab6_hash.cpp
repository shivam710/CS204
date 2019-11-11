#include<bits/stdc++.h>
using namespace std;
#define lli long long
lli n;


lli hashf(string s)
{
    lli r=0;
    for(int i=0;i<s.length();i++)
    {
        r=(r+s[i]*(i+1))%n;
    }
    return r;
}

class hasht{
    public:
    void insert(string x)
    {
        this->a[hashf(x)].push_front(x);
    }
    int search(string x)
    {
        int index = hashf(x);
        list <string> :: iterator i;
        for (i = a[index].begin(); i != a[index].end(); i++) {
        if (*i == x)
        {
            return 1;
        }
        }
        return 0;
    }
    void deletehash(string x)
    {
        int index = hashf(x);
        list <string> :: iterator i;
        for (i = a[index].begin(); i != a[index].end(); i++) {
        if (*i == x)
        {
            a[index].erase(i);
            cout<<"Deleted "<<x<<endl;
            return;
        }
        }
        cout<<x<<" not found"<<endl;
    }
    hasht(lli m)
    {

        a = new list<string>[m];
    }

    private:
    list<string> *a;
};

int main()
{
    string s,str;
    cin>>n;
    short f=0;
    hasht H(n);
    for(lli i=0;i<n;i++)
    {
        cin>>s;
        str=s;
        reverse(str.begin(), str.end());
        if(H.search(str)&&s!=str)
        f=1;
        H.insert(s);
    }
    if(f)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
