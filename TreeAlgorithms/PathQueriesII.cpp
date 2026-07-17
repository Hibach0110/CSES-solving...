#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
using ll = long long;

vector<int> adj[N];
     


int main() { 
     ios_base::sync_with_stdio(false); cin.tie(NULL);

     int n, q; cin >> n >> q;
     for (int i = 1; i < n; i++) {
          int u, v; cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     


     return 0;
}