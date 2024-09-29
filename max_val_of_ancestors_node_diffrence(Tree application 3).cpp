#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int ans[100100];
int val[100100];

void dfs(int node,int parent,int max_val,int min_val){
    ans[node] = max(abs(max_val-val[node]),abs(min_val-val[node]));
    for(auto v : g[node]){
        if(v!=parent){
            dfs(v,node,max(max_val,val[node]),min(min_val,val[node]));
        }
    }
}

void solve(){
    dfs(root,0,-1e9,1e9);//or dfs(root,0,val[root],val[root])
    ans[root]=......  //do as per the question
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--){
        solve();
    }
    return 0;
}








