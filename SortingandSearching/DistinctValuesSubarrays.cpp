#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     map<int, int> lst;
     int64_t ans = 0;
     int mx_r = 0;
     for (int i = 1; i <= N; i++) {
          int x; cin >> x;
          mx_r = max(mx_r, lst[x]);
          ans += i - mx_r;
          lst[x] = i;
     }
     cout << ans;

     return 0;
}
