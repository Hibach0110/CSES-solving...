#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     using ll = long long;
     ll sum = 0;

     int N; cin >> N;
     vector<int> a(N);
     for (int &x : a) {
          cin >> x; sum += x;
     }
     
     ll ans = 1e18;
     for (int m = 0; m < (1<<N); m++) {
          ll s1 = 0;
          for (int i = 0; i < N; i++) {
               if (m & (1 << i)) {
                    s1 += a[i];
               }
          }
          ans = min(ans, abs(sum - s1 * 2));
     }
     
     cout << ans;

     return 0;
}
