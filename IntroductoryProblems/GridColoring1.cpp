#include <bits/stdc++.h>
using namespace std;

int cnt[4][2];

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, M; cin >> N >> M;
     vector<vector<char>> c(N+5, vector<char>(M+5));
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
               cin >> c[i][j];
          }
     }

     for (int sum = 2; sum <= N+M; sum++) {
          for (int i = 1; i <= N; i++) {
               int j = sum - i;
               if (j < 1 || j > M) continue; 
               if (sum % 2 == 0) {
                    c[i][j] = (c[i][j] == 'A' ? 'B' : 'A');
               } else {
                    c[i][j] = (c[i][j] == 'C' ? 'D' : 'C');
                }
          } 
     }

     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
               cout << c[i][j];
          }
          cout << "\n";
     }
          

     return 0;
}
