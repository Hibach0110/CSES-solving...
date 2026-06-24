#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

char C[MAXN][MAXN];
bool vis[MAXN][MAXN];
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
     vis[x][y] = true;
     for (int k = 0; k < 4; k++) {
          int i = x + dx[k], j = y + dy[k];
          if (vis[i][j] || i < 1 || i > N || j < 1 || j > M || C[i][j] == '#') continue;
          dfs(i, j);
     }
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     cin >> N >> M;
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
               cin >> C[i][j];
          }
     }
     
     int rooms = 0;
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
               if (C[i][j] == '.' && !vis[i][j]) {
                    rooms++; dfs(i, j);
               }
          }
     }

     cout << rooms;
     return 0;
}
