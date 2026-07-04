#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][11][2][2];
string num;

ll solve(int idx, int prv_digit, bool is_tight, bool is_leading_zero) {
     if (idx == num.length()) return 1;
     if (dp[idx][prv_digit][is_tight][is_leading_zero] != -1) 
          return dp[idx][prv_digit][is_tight][is_leading_zero];
     
     ll ans = 0; int lim = is_tight ? (num[idx] - '0') : 9;
     for (int digit = 0; digit <= lim; digit++) {
          bool nxt_tight = is_tight && (digit == lim);
          bool nxt_leading_zero = is_leading_zero && (digit == 0);
          if (!nxt_leading_zero && digit == prv_digit) continue;
          int nxt_prv = nxt_leading_zero ? 10 : digit;
          ans += solve(idx+1, nxt_prv, nxt_tight, nxt_leading_zero);
     }

     return dp[idx][prv_digit][is_tight][is_leading_zero] = ans;
}

ll cnt(ll x) {
     if (x < 0) return 0; if (x == 0) return 1;
     num = to_string(x);
     memset(dp, -1, sizeof(dp));
     return solve(0, 10, true, true);
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     ll A, B; cin >> A >> B;
     cout << cnt(B) - cnt(A-1) << "\n";

     return 0;
}
