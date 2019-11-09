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
    struct Edge *edge;

};

struct subset
{
    int parent;
    int rank;
};

struct Graph* createGraph(int V,int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge*)malloc(sizeof(struct Edge));
    return graph;

}

int find(struct subset subsets[],int x)
{
    if(subsets[x].parent==x)return x;
    subsets[x].parent=find(subsets,subsets[x].parent);
    return subsets[x].parent;
}

void Union(struct subset subsets[],int x,int y)
{
    int set1=find(subsets,x);
    int set2=find(subsets,y);
    if(subsets[set1].rank>subsets[set2].rank)
    {
        subsets[set2].parent=set1;
    }

    else if(subsets[set1].rank<subsets[set2].rank)
    {
        subsets[set1].parent=set2;
    }
    else
    {
        subsets[set1].parent=set2;
        subsets[set2].rank++;
    }

}

int isCycle(struct Graph* graph)
{
    struct subset subsets[graph->V];
    for(int i=0;i<graph->V;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    for(int i =0;i<graph->E;i++)
    {
        int x=find(subsets,graph->edge[i].src);
        int y=find(subsets,graph->edge[i].dest);
        if(x==y)return 1;
        Union(subsets,x,y);
    }
    return 0;
}

int main()
{
    int v=5,e=4;
    struct Graph* graph=createGraph(5,4);
    graph->edge[0]={0,1};
    graph->edge[1]={1,2};
    graph->edge[2]={2,3};
    graph->edge[3]={3,1};
    if(isCycle(graph))cout<<"YES";
    else cout<<"NO";
}

