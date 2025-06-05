#include <bits/stdc++.h>
using namespace std;

#define int long long

bool BFS(int node,vector<vector<int>> &adj,vector<int>& color){
    color[node]=0;
    queue<int> que;
    que.push(node);
    while(!que.empty()){
        int u= que.front();
        que.pop();
       
        for(auto v: adj[u]){
            if(color[v]==-1){
                color[v]=1-color[u];
                que.push(v);
            }else{
                if(color[v]==color[u])
                    return false;
            }
        }
    }
    return true;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1,vector<int>());

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n+1,-1);

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!BFS(i,adj,color))
            {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
        cout<<color[i]+1<<" ";
    cout<<endl;

    return 0;
}