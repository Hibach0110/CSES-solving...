#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

vector<int> adj[N];
bool removed[N];
int subtree_size[N];
int k;
ll ans = 0;
vector<int> cnt, touched;

int get_subtree_size(int u, int p = -1) {
     subtree_size[u] = 1;
     for (int v : adj[u]) {
          if (v != p && !removed[v]) {
               subtree_size[u] += get_subtree_size(v, u);
          }
     }
     return subtree_size[u];
}

int get_centroid(int u, int tree_size, int p = -1) {
     for (int v : adj[u]) {
          if (v != p && !removed[v]) {
               if (subtree_size[v] * 2 > tree_size)
               return get_centroid(v, tree_size, u);
          }
     }
     return u;
}

void go_in(int u, int p, int depth, vector<int> &dist) {
     if (depth > k) return;
     dist.push_back(depth);
     for (int v : adj[u]) {
          if (!removed[v] && v != p) {
               go_in(v, u, depth + 1, dist);
          }
     }
}

void doit(int centroid) {
     touched.clear();
     cnt[0] = 1;
     for (int v : adj[centroid]) {
          if (!removed[v]) {
               vector<int> cur_dist;
               go_in(v, centroid, 1, cur_dist);
               for (int d : cur_dist) ans += cnt[k - d];
               for (int d : cur_dist) {
                    if (cnt[d] == 0) touched.push_back(d);
                    cnt[d]++;
               }
          }
     }
     for (int idx : touched) cnt[idx] = 0;
}

void decompose(int u) {
     int tree_size = get_subtree_size(u);
     int centroid = get_centroid(u, tree_size);
     doit(centroid);
     removed[centroid] = true;
     for (int v : adj[centroid]) {
          if (!removed[v]) decompose(v);
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n; cin >> n >> k;
     cnt.assign(k + 1, 0);
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     decompose(1);
     
     cout << ans;

     return 0;
}