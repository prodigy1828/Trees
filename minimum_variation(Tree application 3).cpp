#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int ans[100100];
int val[100100];
multiset<int>mts;
void insert(int x){
    mts.inset(x);
}
void remove(int x){
    mts.erase(mts.find(x));
}
void query(int x){
    int ans = 1e9;
    auto it = mts.lower_bound(x);// this will give the iterator pointing to the val greater than or equal to x
    if(it!=mts.end()){
        ans = min(ans,abs(*it-x));
    }
    if(it!=mts.begin()){
        it--;// this will point to the iterator value just less than x
        ans = min(ans,abs(*it-x));
    }
}

void dfs(int node,int parent,int max_val,int min_val){
    ans[node] = query(val[node]);
    insert(val[node]);
    for(auto v : g[node]){
        if(v!=parent){
            dfs(v,node);
        }
    }
    remove(val[node]);
}

void solve(){
    dfs(root,0,-1e9,1e9);//or dfs(root,0,val[root],val[ root])
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








