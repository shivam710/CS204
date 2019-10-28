 #include <bits/stdc++.h> 
using namespace std;
int n,m;
bool Isbipartite_vertex(vector<int> v[],int src,int colour[])
{
    colour[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
       /* if(G[u][u]==1)
        {
            return false;//self loop
        }*/
        for(int i=0;i<v[u].size();i++)
        {
            if(colour[v[u][i]]==-1)
            {
                colour[v[u][i]]=1-colour[u];
                q.push(v[u][i]);

            }
            else if(colour[v[u][i]]==colour[u])
            {
                return false;
            }
        }
        
    }
    return true;



}

bool Isbipartite(vector<int> v[])
{
    int colour[n+1];
    for(int i=1;i<n+1;i++)
    {
        colour[i]=-1;
    }
    for(int i=1;i<n+1;i++)
    {
        if(colour[i]==-1)
        {
            if(Isbipartite_vertex(v,i,colour)==false)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    
    
    cin>>n>>m;
    vector<int>v[n+1];
   // int G[n][n]={0};
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        // G[a][b]==1;

    }
    if(Isbipartite(v))
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"NO"<<endl;
}
