#include <bits/stdc++.h>
using namespace std;
int mirror(int a,int b,int qu,pair<int,int>tree[]){
    if(a==-1 || b==-1)return -1;
    if(a==qu)return b;
    if(b==qu)return a;
    return max(mirror(tree[a].first,tree[b].second,qu,tree),mirror(tree[a].second,tree[b].first,qu,tree));
}
int main()
{
    int n,q;
    cin>>n>>q;
    int f,s;
    char c;
    pair<int,int>tree[n+1];
    for(int i=0;i<n;i++)
        tree[i].first=tree[i].second=-1;
    for(int i=0;i<n-1;i++){
        cin>>f>>s>>c;
        if(c=='R')
            tree[f].second=s;
            else
            tree[f].first=s;
    }
    int qu;
    while(q--){
            cin>>qu;
            if(qu==1) cout<<1<<"\n";
            else{ 
                int ans=mirror(tree[1].first,tree[1].second,qu,tree);
                if(ans>0) cout<<ans<<"\n";
                else cout<<-1<<"\n";
            }
    }
}
/*
Mirror Image (Sample I/P)
10 8
1 2 R
1 3 L
2 4 R
2 5 L
3 6 R
3 7 L
5 8 R
5 9 L
7 10 R
2
5
3
6
1
10
9
4
*/
