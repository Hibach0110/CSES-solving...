#include <bits/stdc++.h>
using namespace std;

int N, M;
bool vis[1005][1005];
vector<string> grid;
pair<int, int> par_cell[1005][1005];
char par_dir[1005][1005];


int dX[] = {1, -1, 0, 0};
int dY[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     cin >> N >> M;
     grid.resize(N);
     for (string &s : grid) cin >> s;

     int startX = -1, startY = -1, endX = -1, endY = -1;
     for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
               if (grid[i][j] == 'A') { startX = i; startY = j; }
               if (grid[i][j] == 'B') { endX = i; endY = j; }
          }
     }

     queue<pair<int, int>> q; q.push({startX, startY}); vis[startX][startY] = true;
     bool found = false;
     while (!q.empty()) {
          auto [x, y] = q.front(); q.pop();
          if (grid[x][y] == 'B') {
               found = true; break;
          }
          for (int i = 0; i < 4; i++) {
               int nx = x + dX[i], ny = y + dY[i];
               if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
               if (vis[nx][ny] || grid[nx][ny] == '#') continue;
               vis[nx][ny] = true;
               par_cell[nx][ny] = {x, y};
               par_dir[nx][ny] = dir[i];
               q.push({nx, ny});
          }
     }

     if (found) {
          cout << "YES\n";
          string path = "";
          int curX = endX, curY = endY;
          while (curX != startX || curY != startY) {
               path += par_dir[curX][curY];
               auto [pX, pY] = par_cell[curX][curY];
               curX = pX; 
               curY = pY;
          }
          reverse(path.begin(), path.end());
          cout << path.size() << "\n" << path;
     } else {
          cout << "NO\n";
     }

     return 0;
}
