#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];
bool vis[1005][1005];

int dX[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dY[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     queue<pair<int, int>> q; q.push({1, 1}); vis[1][1] = true;
     while (!q.empty()) {
          auto p = q.front(); q.pop();
          int i = p.first, j = p.second;
          for (int k = 0; k < 8; k++) {
               int ni = i + dX[k], nj = j + dY[k];
               if (ni < 1 || nj < 1 || ni > N || nj > N || vis[ni][nj]) continue;
               d[ni][nj] = d[i][j] + 1;
               vis[ni][nj] = true; q.push({ni, nj});
          }
     }

     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
               cout << d[i][j] << " \n"[j == N];
          }
     }

     return 0;
}
