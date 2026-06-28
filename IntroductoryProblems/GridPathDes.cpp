#include <bits/stdc++.h>
using namespace std;

string S;
bool vis[9][9];
int dX[] = {1, -1, 0, 0}; // down up right left..
int dY[] = {0, 0, 1, -1};

int dfs(int x, int y, int i) {
     if (x == 7 && y == 1) return i==48;
     if (i == 48) return 0;

     if (vis[x][y+1] && vis[x][y-1] && !vis[x-1][y] && !vis[x+1][y]) return 0;
     if (!vis[x][y+1] && !vis[x][y-1] && vis[x-1][y] && vis[x+1][y]) return 0;
     
     int res = 0; 
     vis[x][y] = true;
     if (S[i] != '?') {
          int k = -1;
          if (S[i] == 'D') k = 0;
          else if (S[i] == 'U') k = 1;
          else if (S[i] == 'R') k = 2;
          else k = 3;
          
          int nx = x + dX[k], ny = y + dY[k];
          if (!vis[nx][ny]) {
               res = dfs(nx, ny, i+1); 
          }
     } else {
          for (int k = 0; k < 4; k++) {
               int nx = x + dX[k], ny = y + dY[k];
               if (vis[nx][ny]) continue;
               res += dfs(nx, ny, i+1); 
          }
     }
     
     vis[x][y] = 0;
     return res;
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     cin >> S;
     
     for (int i = 0; i <= 8; i++) {
          vis[i][0] = vis[i][8] = vis[0][i] = vis[8][i] = true; // wall.. 
     }
     
     cout << dfs(1, 1, 0);

     return 0;
}
