#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1000];
bool visited[1000]={0};
int nodes;
void dfs(int x){
	nodes++;
	visited[x]=1;
	cout<<x<<":";
	for(int i=0;i<graph[x].size();i++){
		//cout<<graph[x][i]<<":";
		if(!visited[graph[x][i]])
			dfs(graph[x][i]);
	}
}
int main(){
    int N,M,a,b;
    cin>>N>>M;
    for(int i=0;i<M;i++){
    	cin>>a>>b;
    	graph[a].push_back(b);
    	graph[b].push_back(a);
	}
	/*for(int i=1;i<=N;i++){
		nodes=0;
		if(!visited[i]){
			dfs(i);
			nodes++;
		}
		cout<<nodes<<"\n";
	}*/
	dfs(3);
}
/*
5 4
1 2 
2 3
3 1
4 5
*/
/*
4 6
1 2
1 3
2 3
3 1
3 4
4 4
*/
