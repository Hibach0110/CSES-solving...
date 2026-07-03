#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, X; cin >> N >> X; map<int64_t, int> mp; int64_t sum = 0, ans = 0;
     mp[0] = 1;
     for (int i = 0; i < N; i++) {
          int x; cin >> x; sum += x;
          ans += mp[sum - X];
          mp[sum]++;
     }
     cout << ans;
          
     return 0;
}
