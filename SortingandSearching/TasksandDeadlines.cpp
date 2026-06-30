#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<int> a(N);
     int64_t ans = 0;
     for (int i = 0; i < N; i++) {
          int D; cin >> a[i] >> D;
          ans += D;
     }
     sort(a.begin(), a.end());
     int cnt = N;
     for (int i = 0; i < N; i++) {
          ans -= 1ll * cnt * a[i]; cnt--;
     }
     cout << ans;

     return 0;
}
