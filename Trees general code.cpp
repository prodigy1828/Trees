#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSz[100100];
int numChild[100100];

void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    subtreeSz[node]=1;//intially subtree has only one node
    
    numChild[node] =0;
    for(auto v :g[node]){
        if(v!=parent){
            numChild[node]++;
            dfs(v,node,depth+1);
            subtreeSz[node]+=subtreeSz[v];//add subtree sizes of all the neighbour nodes
        }
    }
    if(numChild[node]==0) isLeaf[node]=true;
}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);//preferebly keep parent as 0 (helpful in advanced techniques)
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}