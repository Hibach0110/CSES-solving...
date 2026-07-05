#include <bits/stdc++.h>
using namespace std;

struct element {
     int height, width;
};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, K; cin >> N >> K;
     vector<string> grid(N); for (string &s : grid) cin >> s;

     vector<int64_t> ans(K, 0);
     vector<int> h(N, 0);
     
     vector<element> stk; stk.reserve(N);
     for (int r = 0; r < N; r++) {
          stk.clear();
          int64_t nRecs = 0;
          for (int c = 0; c < N; c++) { 
               char cur_char = grid[r][c]; int cur_idx = cur_char - 'A';
               
               if (r > 0 && grid[r-1][c] == cur_char) h[c]++;
               else h[c] = 1;
               
               if (c > 0 && grid[r][c-1] != cur_char) {
                    stk.clear();
                    nRecs = 0;
               }

               int cur_width = 1;
               while (!stk.empty() && stk.back().height >= h[c]) {
                    element top = stk.back(); stk.pop_back();
                    nRecs -= (int64_t)top.height * top.width;
                    cur_width += top.width;
               }

               nRecs += (int64_t)h[c] * cur_width;
               stk.push_back({h[c], cur_width});

               ans[cur_idx] += nRecs;
          }
     }
          
     for (int i = 0; i < K; i++) cout << ans[i] << "\n";

     return 0;
}
