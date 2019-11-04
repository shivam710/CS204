#include <bits/stdc++.h>
using namespace std;

bool DFS(vector <vector<int>> graph,int src ,int * color){
	bool temp =1;

	for(int i=0;i<graph[src].size();i++){
		if(color[graph[src][i]]==0){
			color[graph[src][i]]=3-color[src];
			temp=temp&DFS(graph,i ,color);
		}
		else if((color[graph[src][i]]==1&&color[src]==1)||(color[graph[src][i]]==2&&color[src]==2)){
			return 0;
		}
	}

		return temp;
}

int main(){

	long long int n,v;cin>>v>>n;
	vector <vector<int>> graph(v+n);
	for(int i=0;i<n;i++){
		int x,y,w;cin>>x>>y>>w;
		if(w%2==0){
			v++;
			graph[v-1].push_back(x-1);
			graph[v-1].push_back(y-1);
			graph[x-1].push_back(v-1);
			graph[y-1].push_back(v-1);

		}
		else{
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	    }
	}

	int color[v]={0};
	bool ans=1;
	for(int i=0;i<v;i++){
		if(color[i]==0){
			color[i]=1;
		    ans=DFS(graph,i,color);

		}
		if(ans==0)break;
	}
	if(ans)cout<<"NO";
	else cout<<"YES";

}
