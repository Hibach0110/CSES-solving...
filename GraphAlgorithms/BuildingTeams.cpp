#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

vector<int> adj[100005];
int team[100005];

bool bfs(int start) {
     queue<int> q; q.push(start); team[start] = 1;
     while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int v : adj[u]) {
               if (team[v] == team[u]) return false;
               if (!team[v]) {
                    q.push(v); team[v] = 3 - team[u];
               }
          }
     }
     return true;
}

void solve() {
     int N, M; cin >> N >> M;
     for (int i = 1; i <= M; i++) {
          int u, v; cin >> u >> v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     bool can_assign = true;
     for (int i = 1; i <= N; i++) {
          if (team[i] == 0) {
               can_assign &= bfs(i);
          }
     }
     if (can_assign) {
          for (int i = 1; i <= N; i++)
               cout << team[i] << " ";
     } else {
          cout << "IMPOSSIBLE";
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
