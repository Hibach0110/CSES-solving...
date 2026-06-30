#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     const int64_t INF = 1e18;

     int N; cin >> N;
     int64_t ans = -INF;
     int64_t sum = 0, mn = 0;
     for (int i = 1; i <= N; i++) {
          int x; cin >> x; 
          sum += x;
          ans = max(ans, sum - mn);
          mn = min(mn, sum);
     }
     cout << ans;

     return 0;
}
