#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int k1, k2;
int sz_subtree[N], par[N], cnt[N];
vector<int> adj[N], touched;
ll ans = 0;
bool removed[N];

struct fenwick {
     int n;
     vector<ll> t;

     fenwick(int n) : n(n), t(n + 1, 0) {};

     void upd(int i, ll add) {
          for (; i <= n; i += i&(-i)) t[i] += add;
     }
     ll get(int i) {
          ll sum = 0;
          for (; i > 0; i -= i&(-i)) sum += t[i];
          return sum;
     }
     ll query(int a, int b) {
          return get(b) - get(a-1);
     }
};
fenwick t(N);

int get_sz_subtree(int u, int p = -1) {
     sz_subtree[u] = 1;
     for (int v : adj[u]) {
          if (v != p && !removed[v]) {
               sz_subtree[u] += get_sz_subtree(v, u);
          }
     }
     return sz_subtree[u];
}

int get_centroid(int u, int sztree, int p = -1) {
     for (int v : adj[u]) {
          if (v != p && !removed[v]) {
               if (sz_subtree[v] * 2 > sztree) {
                    return get_centroid(v, sztree, u);
               }
          }
     }
     return u;
}

void get_dist(int u, int p, int h, vector<int> &cur_dist) {
     if (h > k2) return;
     cur_dist.push_back(h);
     for (int v : adj[u]) {
          if (v != p && !removed[v]) {
               get_dist(v, u, h+1, cur_dist);
          }
     }
}

void doit(int centroid) {
     t.upd(1, 1);
     touched.clear();
     for (int v : adj[centroid]) {
          if (!removed[v]) {
               vector<int> cur_dist;
               get_dist(v, centroid, 1, cur_dist);
               for (int d : cur_dist) {
                    ans += t.query(max(k1 - d, 0) + 1, k2 - d + 1);
               }
               for (int d : cur_dist) {
                    if (cnt[d] == 0) touched.push_back(d);
                    cnt[d]++;
                    t.upd(d+1, 1);
               }
          }
     }
     for (int d : touched) {
          t.upd(d+1, -cnt[d]);
          cnt[d] = 0;
     }
     t.upd(1, -1);
}

void decompose(int u) {
     int tree_size = get_sz_subtree(u);
     int centroid = get_centroid(u, tree_size);
     doit(centroid);
     removed[centroid] = true;
     for (int v : adj[centroid]) {
          if (!removed[v]) decompose(v);
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n; cin >> n >> k1 >> k2;
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     decompose(1);

     cout << ans;

     return 0;
}