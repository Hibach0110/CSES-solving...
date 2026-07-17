#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long;

int n;
vector<int> adj[N];
int par[N], depth[N], heavy[N], head[N], pos[N];     

int dfs(int u) {
     int size = 1, max_v_size = 0;
     for (int v : adj[u]) {
          if (v != par[u]) {
               par[v] = u;
               depth[v] = depth[u] + 1;
               int v_size = dfs(v);
               size += v_size;
               if (v_size > max_v_size) {
                    max_v_size = v_size;
                    heavy[u] = v;
               }
          }
     }
     return size;
}

int cur_pos = 1;
void decompose(int u, int h) {
     head[u] = h;
     pos[u] = cur_pos++;
     if (heavy[u] != 0) decompose(heavy[u], h);
     for (int v : adj[u]) {
          if (v != par[u] && v != heavy[u]) {
               decompose(v, v);
          }
     }
}

int st[N*2];
void update(int p, int value) {
     for (st[p+=n] = value; p > 1; p >>= 1) {
          st[p>>1] = max(st[p], st[p ^ 1]);
     }
}
int query_tree(int l, int r) {
     int res = 0;
     for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
          if (l & 1) res = max(res, st[l++]);
          if (r & 1) res = max(res, st[--r]);
     }
     return res;
}

int query(int a, int b) {
     int res = 0;
     for (; head[a] != head[b]; b = par[head[b]]) {
          if (depth[head[a]] > depth[head[b]]) swap(a, b);
          int cur_max = query_tree(pos[head[b]]-1, pos[b]-1);
          res = max(res, cur_max);
     }
     if (depth[a] > depth[b]) swap(a, b);
     res = max(res, query_tree(pos[a]-1, pos[b]-1));
     return res;
}

int main() { 
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int q; cin >> n >> q;
     vector<int> a(n);
     for (int i = 0; i < n; i++) {
          cin >> a[i];
     }
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     
     dfs(1);
     decompose(1, 1);
     for (int i = 1; i <= n; i++) st[pos[i] + n - 1] = a[i-1];
     for (int i = n-1; i > 0; i--) st[i] = max(st[i<<1], st[i<<1|1]);

     while (q--) {
          int cmd; cin >> cmd;
          if (cmd == 1) {
               int s, x; cin >> s >> x;
               update(pos[s]-1, x);
          } else {
               int a, b; cin >> a >> b;
               cout << query(a, b) << " ";
          }
     }

     return 0;
}