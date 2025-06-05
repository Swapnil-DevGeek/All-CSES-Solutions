#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;

    int src_x, src_y, dest_x, dest_y;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<char>> direction(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                src_x = i; src_y = j;
            }
            if (graph[i][j] == 'B') {
                dest_x = i; dest_y = j;
            }
        }
    }

    queue<pair<int, int>> que;
    que.push({src_x, src_y});

    // mark source as visited
    graph[src_x][src_y] = '#';

    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<char> path_ch = {'U', 'L', 'D', 'R'};

    while (!que.empty()) {
        auto fr = que.front(); que.pop();
        int r = fr.first;
        int c = fr.second;

        if (r == dest_x && c == dest_y) {
            vector<char> path;
			int a = dest_x, b = dest_y;

			while (make_pair(a, b) != make_pair(src_x, src_y)) {
			    char d = direction[a][b];
			    path.push_back(d);

			    if (d == 'U') a++;
			    else if (d == 'D') a--;
			    else if (d == 'L') b++;
			    else if (d == 'R') b--;
			}

			cout << "YES\n";
			cout << path.size() << "\n";
			reverse(path.begin(), path.end());
			for (char ch : path) cout << ch;
			cout << "\n";
		
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && graph[nr][nc] != '#') {
                graph[nr][nc] = '#';  
                que.push({nr, nc});
                direction[nr][nc]=path_ch[i];
            }
        }
    }

    cout << "NO\n";
    return 0;
}
