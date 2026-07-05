#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, K; cin >> N >> K;
     vector<string> grid(N); for (string &s : grid) cin >> s;

     vector<vector<int>> dp(N, vector<int>(N, 1));
     vector<int64_t> ans(26, 0);

     for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
               char C = grid[i][j];
               if (i > 0 && j > 0 && grid[i][j-1] == C && grid[i-1][j-1] == C && grid[i-1][j] == C)
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
               else
                    dp[i][j] = 1;
               ans[C - 'A'] += dp[i][j];
          }
     }

     for (int i = 0; i < K; i++) cout << ans[i] << "\n";
     
     return 0;
}
