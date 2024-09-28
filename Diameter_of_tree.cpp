#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[100100];
int dep[100100];
int par[100100];

void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    for(auto v :g[node]){
        if(v!=parent){
            numChild[node]++;
            dfs(v,node,depth+1);
        }
    }

}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    int maxch = 1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch = j;
        }
    }
    dfs(maxch,0,0);
    maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch = j;
        }
    }
    cout<<dep[maxch]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}