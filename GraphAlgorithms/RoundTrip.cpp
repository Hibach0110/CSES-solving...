#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

vector<int> adj[100005];
vector<int> par, vis;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int p) {
     vis[u] = 1;
     for (int v : adj[u]) {
          if (v == p) continue;
          if (vis[v] == 1) {
               cycle_start = v; 
               cycle_end = u;
               return true;
          }
          if (vis[v] == 0) {
               par[v] = u;
               if (dfs(v, u)) return true;
          }
     }
     vis[u] = 2;
     return false;
}

void solve() {
     int N, M; cin >> N >> M;
     par.resize(N+5, -1);
     vis.resize(N+5, 0);
     for (int i = 1; i <= M; i++) {
          int u, v; cin >> u >> v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     
     for (int i = 1; i <= N; i++) {
          if (vis[i] == 0) {
               if (dfs(i, -1)) break;
          }
     }

     if (cycle_start == -1) {
          cout << "IMPOSSIBLE\n";
     } else {
          vector<int> cycle;
          cycle.pb(cycle_start);
          for (int cur = cycle_end; cur != cycle_start; cur = par[cur]) 
               cycle.pb(cur);
          cycle.pb(cycle_start);

          cout << cycle.size() << "\n";
          for (int i = 0; i < sz(cycle); i++)
               cout << cycle[i] << " ";
     }
}

int32_t main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);
     
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif

     // cout << fixed << setprecision(12);

     int tc = 1; //cin >> tc;
     while (tc--) {
          solve();
     }

     return 0;
}
