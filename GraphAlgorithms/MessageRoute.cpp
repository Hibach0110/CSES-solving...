#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

vector<int> adj[100005];
int dist[100005];
int par[100005];

void bfs(int start) {
     queue<int> q; q.push(start); dist[start] = 0;
     while (!q.empty()) {
          int u = q.front(); 
          q.pop();
          for (int v : adj[u]) {
               if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1; par[v] = u;
                    q.push(v);
               }
          }
     }
}

void solve() {
     int N, M; cin >> N >> M;
     for (int i = 1; i <= N; i++) dist[i] = INT_MAX;
     for (int i = 1; i <= M; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     bfs(1);
     if (dist[N] == INT_MAX) {
          cout << "IMPOSSIBLE\n";
     } else {
          cout << dist[N]+1 << "\n";
          vector<int> path;
          while (1) {
               path.push_back(N);
               if (N == 1) break;
               N = par[N];
          }
          reverse(all(path));
          for (int x : path)
               cout << x << " ";
     }
}

int32_t main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);
     
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif

     // cout << fixed << setprecision(12);

     int tc = 1; // cin >> tc;
     while (tc--) {
          solve();
     }

     return 0;
}
