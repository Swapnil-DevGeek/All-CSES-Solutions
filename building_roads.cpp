#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> rk,parent;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);

}

void un(int u,int v){
    int pu=find(u),pv=find(v);
    if(pu==pv) return;
    if(rk[pu]>rk[pv]){
        parent[pv] = pu;
    }else if(rk[pv]>rk[pu]){
        parent[pu]=pv;
    }else{
        parent[pv]=pu;
        rk[pu]++;
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    rk.resize(n+1,1);
    parent.resize(n+1);

    for(int i=1;i<=n;i++) parent[i]=i;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        un(u,v);
    }

    vector<int> leaders;
    for(int i=1;i<=n;i++){
        if(i==find(i)) leaders.push_back(i);
    }

    cout<<leaders.size()-1<<endl;

    for(int i=1;i<leaders.size();i++){
        cout<<leaders[i-1]<<" "<<leaders[i]<<endl;
    }
   
    return 0;
}
