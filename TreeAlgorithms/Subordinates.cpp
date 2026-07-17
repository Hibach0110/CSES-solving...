#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int sz[N];

void dfs(int u) {
     sz[u] = 1;
     for (int v : adj[u]) {
          dfs(v);
          sz[u] += sz[v];
     }
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n; cin >> n;
     for (int i = 2; i <= n; i++) {
          int p; cin >> p;
          adj[p].push_back(i);
     }

     dfs(1);

     for (int i = 1; i <= n; i++) cout << sz[i]-1 << " ";

     return 0;
}