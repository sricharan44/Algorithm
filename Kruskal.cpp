#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define LL long long int 
LL id[MAX], nodes, edges;
pair <LL, pair<LL, LL> > graph[MAX];
LL disjoint_set(LL x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(LL x, LL y){
    LL p = disjoint_set(x);
    LL q = disjoint_set(y);
    id[p] = id[q];
}
LL kruskal(pair<LL, pair<LL, LL> > graph[]){
    LL x,y,cost, minimumCost = 0;
    for(LL i = 0;i < edges;++i){
        x = graph[i].second.first;
        y = graph[i].second.second;
        cost = graph[i].first;
        // Check if the selected edge is creating a cycle or not
        if(disjoint_set(x) != disjoint_set(y)){
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}
int main(){
    LL x,y,weight,cost,minimumCost;
    for(LL i=0;i<MAX;i++)
    	id[i]=i;
    cin >> nodes >> edges;
    for(LL i = 0;i < edges;++i){
        cin >> x >> y >> weight;
        graph[i] = make_pair(weight, make_pair(x, y));
    }
    sort(graph, graph + edges);
    minimumCost = kruskal(graph);
    cout << minimumCost << endl;
    return 0;
}
/*
4 5 
0 1 10
0 3 5
0 2 6
2 3 4
1 3 15
*/
