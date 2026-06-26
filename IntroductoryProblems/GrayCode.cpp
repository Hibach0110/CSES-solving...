#include <bits/stdc++.h>
using namespace std;

bool vis[1<<16];

void dfs(int x, int N) {
     vis[x] = 1;
     string S = "";
     for (int i = 0; i < N; i++) {
          if (x & (1 << i)) S += "1";
          else S += "0";
     }
     cout << S << "\n";
     for (int i = 0; i < N; i++) {
          int y = x ^ (1 << i);
          if (!vis[y]) dfs(y, N);
     }
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     dfs(0, N);

     return 0;
}
