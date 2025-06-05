#include <bits/stdc++.h>
using namespace std;

#define int long long



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

    int src =1;
    queue<vector<int>> que;
    vector<int> dis(n+1,INT_MAX);
    vector<int> parent(n+1,-1);

    dis[src]=0;
    que.push({src,dis[src],parent[src]});

    while(!que.empty()){

        auto fr = que.front();
        que.pop();

        int node = fr[0];
        int curr_dis = fr[1];

        for(auto v: adj[node]){
            if(curr_dis+1 < dis[v]){
                dis[v] = curr_dis+1;
                parent[v]=node;
                que.push({v,dis[v],node});
            }
        }
    }

    if(dis[n]==INT_MAX) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    int temp = n;    
    vector<int> path;
    while(temp!=-1){
        path.push_back(temp);
        temp = parent[temp];
    }

    reverse(begin(path),end(path));
    cout<<path.size()<<endl;
    for (int i = 0; i < path.size(); ++i)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;

    return 0;
}