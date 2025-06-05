#include<bits/stdc++.h>
using namespace std;

#define long long int

void DFS(int i,int j,vector<vector<char>>& graph){
	if(i<0 or i>=graph.size() or j<0 or j>=graph[0].size() or graph[i][j]=='#')
		return;

	graph[i][j]='#';

	DFS(i-1,j,graph);
	DFS(i+1,j,graph);
	DFS(i,j-1,graph);
	DFS(i,j+1,graph);

}

int main(){


	int n,m;
	cin >>n>>m;

	vector<vector<char>> graph(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>graph[i][j];
	}

	int cnt =0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(graph[i][j]=='.'){
				DFS(i,j,graph);
				cnt++;
			}
	}

	cout<<cnt;

	return 0;
}