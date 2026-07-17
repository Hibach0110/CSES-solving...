#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];

void bfs(int start, vector<int> &dist) {
     dist.assign(n+1, 0);
     queue<int> q;
     vector<bool> vis(n+1, false);
     q.push(start);
     vis[start] = true;
     dist[start] = 0;
     while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int v : adj[u]) {
               if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    dist[v] = dist[u] + 1;
               }
          }
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     cin >> n;
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     vector<int> dist;
     bfs(1, dist);
     int far_node = 0, max_dist = 0;
     for (int i = 1; i <= n; i++) {
          if (dist[i] > max_dist) {
               max_dist = dist[i];
               far_node = i;
          }
     }
     bfs(far_node, dist);
     cout << *max_element(dist.begin(), dist.end());

     return 0;
}