#include<bits/stdc++.h>
using namespace std;
#define mod 10e9+7
struct Edge
{
    int src,dest;
    long long int weight;
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

int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight < b1->weight;  
}  

void kruskal(struct Graph* graph)
{
	int V= graph->V;
	int E= graph->E;
	struct Edge ans[V];
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 
	int x=0;
	int y=0;

	struct subset subsets[V+1];
	for(int i=0;i<V;i++)
	{
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	while(x<V-1 && y<E)
	{
		struct Edge temp=graph->edge[y++];

		int set1=find(subsets,temp.src);
		int set2=find(subsets,temp.dest);
		if(set1!=set2)
		{
			Union(subsets,set1,set2);
			ans[x++]=temp;
		}

	}
	long long int total=0;
	for(int i=0;i<x;i++)
	{
		total=total+ans[i].weight;
		//cout<<"src -> "<<ans[i].src<<" | dest -> "<<ans[i].dest<<" | weight -> "<<ans[i].weight<<endl;
	}
	cout<<total<<endl;
	

}







int main()
{
	int V,E;
	cin>>V>>E;
	struct Graph* graph =createGraph(V,E);
	for(int i=0;i<E;i++)
	{
		int a,b;
		long long int w;
		cin>>a>>b>>w;
		graph->edge[i].src=a;
		graph->edge[i].dest=b;
		graph->edge[i].weight=w;

	}
	kruskal(graph);


}
