#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long;

struct fenwickTree {
     int n;
     vector<ll> t;

     fenwickTree(int n) : n(n), t(n+1, 0) {};

     int f(int x) {
          return x & (-x);
     }
     void upd(int i, int add) {
          for (; i > 0 && i <= n; i += f(i)) {
               t[i] += add;
          }
     }
     ll get(int i) {
          ll sum = 0;
          for (; i > 0; i -= f(i)) {
               sum += t[i];
          }
          return sum;
     }
};

int timer = 1;
vector<int> adj[N];
int a[N], tin[N], tout[N];
ll sum[N];

void dfs(int u, int p) {
     sum[u] += a[u];
     tin[u] = timer++;
     for (int v : adj[u]) {
          if (v != p) {
               sum[v] += sum[u];
               dfs(v, u);
          }
     }
     tout[u] = timer-1;
}

int main() { 
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n, q; cin >> n >> q;
     for (int i = 1; i <= n; i++) {
          cin >> a[i];
     }
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     
     dfs(1, 1);
     fenwickTree t(n);

     while (q--) {
          int cmd; cin >> cmd;
          if (cmd == 1) {
               int s, x; cin >> s >> x;
               t.upd(tin[s], x - a[s]);
               t.upd(tout[s]+1, a[s] - x);
               a[s] = x;
          } else {
               int s; cin >> s;
               ll ans = sum[s] + t.get(tin[s]);
               cout << ans << "\n";
          }
     }

     return 0;
}