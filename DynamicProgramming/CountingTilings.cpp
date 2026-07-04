#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void generate(int cur_mask, int nxt_mask, int row, int N, vector<int>& trans) {
     if (row == N) {trans.push_back(nxt_mask); return;}
     if ((cur_mask >> row) & 1) generate(cur_mask, nxt_mask, row+1, N, trans);
     else {
          generate(cur_mask, nxt_mask | (1<<row), row+1, N, trans);
          if (row + 1 < N && !((cur_mask >> (row + 1)) & 1)) generate(cur_mask, nxt_mask, row+2, N, trans);
     }
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, M; cin >> N >> M;
     
     int total_mask = 1 << N;
     vector<int> dp(total_mask, 0); dp[0] = 1;

     vector<vector<int>> trans(total_mask);
     for (int mask = 0; mask < total_mask; mask++) {
          generate(mask, 0, 0, N, trans[mask]);
     }
     for (int i = 0; i < M; i++) {
          vector<int> nxt_dp(total_mask, 0);
          for (int mask = 0; mask < total_mask; mask++) {
               if (dp[mask] == 0) continue;
               for (int nxt_mask : trans[mask]) {
                    nxt_dp[nxt_mask] = (nxt_dp[nxt_mask] + dp[mask]) % MOD;
               }
          }
          dp = move(nxt_dp);
     }

     cout << dp[0];
          
     return 0;
}
