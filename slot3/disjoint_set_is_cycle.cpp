#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int src,dest;

};

struct Graph
{
    int V;
    int E;
    Edge* edge;
};

Graph* createGraph(int V,int E)
{
    Graph* graph =new Graph();
    graph->V=V;
    graph->E=E;
    Edge edge[E];
    graph->edge=(Edge*)malloc(E*sizeof(Edge));

}

int find(int parent[],int x)
{
    if(parent[x]==-1)return x;
    else return(find(parent,parent[x]));
}

void Union(int parent[],int x,int y)
{
    int set1=find(parent,x);
    int set2=find(parent,y);
    if(set1!=set2)
    {
        parent[set1]=set2;
    }
}


int isCycle(Graph* graph)
{
    int parent[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        parent[i]=-1;
    }

    for(int i=0;i<graph->E;i++)
    {
        int x=find(parent,graph->edge[i].src);
        int y=find(parent,graph->edge[i].dest);
        if(x==y) return 1;
        Union(parent,x,y);

    }
    return 0;

}

int main()
{
    int V = 4, E = 3;
    Graph* graph = createGraph(V, E);
    graph->edge[0]={0,1};
    graph->edge[1]={1,2};
    graph->edge[2]={2,3};

    if (isCycle(graph))
        cout<<"Contains cycle";
    else
        cout<<"Doesn't contain cycle";

    return 0;

}
