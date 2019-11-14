#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void dfs2(vector<ll>* adjlist, ll n, int* visited, ll start)
{
    visited[start] = 1;
    cout<<start<<" ";
    for(ll i=0;i<adjlist[start].size();i++)
    {
        ll cv = adjlist[start][i];
        if(!visited[cv])
        {
            dfs2(adjlist,n,visited,cv);
        }
    }
}

void dfs(vector<ll>* adjlist, ll n)
{
    int visited[n] = {0};
    // start from vertex 0
    
    // loop for connected components
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
            {dfs2(adjlist,n,visited,i);}
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll v,e;
    cin>>v>>e;
    vector<ll> adjlist[v];
    for(ll i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    dfs(adjlist,v);
    
    return 0;
}