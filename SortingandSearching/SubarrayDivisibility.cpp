#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N; cin >> N; int64_t ans = 0, sum = 0;
     vector<int> cnt(N); cnt[0] = 1;
     for (int i = 0; i < N; i++) {
          int x; cin >> x; sum = ((sum + x) % N + N) % N;
          ans += cnt[sum];
          cnt[sum % N]++;
     }
     cout << ans;

     return 0;
}
