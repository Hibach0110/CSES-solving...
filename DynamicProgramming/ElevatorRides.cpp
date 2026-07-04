#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, X; cin >> N >> X;
     vector<int> a(N); for (int &x : a) cin >> x;

     int total_states = 1 << N;
     vector<pair<int, long long>> dp(total_states); dp[0] = {1, 0};
     for (int mask = 1; mask < total_states; mask++) {
          dp[mask] = {N+1, 0};
          for (int i = 0; i < N; i++) {
               if ((mask >> i) & 1) {
                    int prv = mask ^ (1<<i);
                    int cur_rides; long long cur_weight;
                    if (dp[prv].second + a[i] <= X) {
                         cur_rides = dp[prv].first;
                         cur_weight = dp[prv].second + a[i];
                    } else {
                         cur_rides = dp[prv].first + 1;
                         cur_weight = a[i];
                    }
                    dp[mask] = min(dp[mask], {cur_rides, cur_weight});
               }
          }
     }

     cout << dp[total_states-1].first;
          
     return 0;
}
