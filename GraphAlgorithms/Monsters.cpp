#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

char dir[] = {'D', 'U', 'L', 'R'};
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, -1, 1};

void solve() {
     int N, M; cin >> N >> M;
     vector<string> grid(N); vector<vector<int>> monster_dist(N, vector<int>(M, 1e9));
     pair<int, int> start;
     queue<pair<int, int>> q;

     for (int i = 0; i < N; i++) {
          cin >> grid[i];
          for (int j = 0; j < M; j++) {
               if (grid[i][j] == 'M') {
                    monster_dist[i][j] = 0;
                    q.push({i, j});
               } else if (grid[i][j] == 'A') {
                    start = {i, j};
               }
          }
     }

     while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          for (int i = 0; i < 4; i++) {
               int nx = x + dirX[i];
               int ny = y + dirY[i];
               if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != '#') {
                    if (monster_dist[nx][ny] > monster_dist[x][y] + 1) {
                         monster_dist[nx][ny] = monster_dist[x][y] + 1;
                         q.push({nx, ny});
                    }
               }
          }
     }

     vector<vector<int>> player_dist(N, vector<int> (M, 1e9));
     vector<vector<int>> par(N, vector<int> (M, -1));
     player_dist[start.first][start.second] = 0;
     q.push(start);
     pair<int, int> escape_cell = {-1, -1};
     while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();
          if (x == 0 || x == N-1 || y == 0 || y == M-1) {
               escape_cell = {x, y}; break;
          }
          for (int i = 0; i < 4; i++) {
               int nx = x + dirX[i];
               int ny = y + dirY[i];
               if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != '#') {
                    int nxt_dist = player_dist[x][y] + 1;
                    if (nxt_dist < monster_dist[nx][ny] && player_dist[nx][ny] > nxt_dist) {
                         player_dist[nx][ny] = nxt_dist;
                         par[nx][ny] = i;
                         q.push({nx, ny});
                    }
               }
          }
     }

     if (escape_cell.first == -1) {
          cout << "NO\n";
     } else {
          cout << "YES\n";
          string path = "";
          auto [cx, cy] = escape_cell;
          while (make_pair(cx, cy) != start) {
               int d = par[cx][cy];
               path += dir[d];
               cx -= dirX[d];
               cy -= dirY[d];
          }
          reverse(all(path));
          cout << sz(path) << "\n" << path << "\n";
     }
}

int32_t main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);
     
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif

     // cout << fixed << setprecision(12);

     int tc = 1; //cin >> tc;
     while (tc--) {
          solve();
     }

     return 0;
}
