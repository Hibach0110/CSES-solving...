#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     map<int, int> prv;

     int ans = 1, cur_r = 0;
     for (int i = 1; i <= N; i++) {
          int x; cin >> x;
          cur_r = max(cur_r, prv[x]);
          ans = max(ans, i - cur_r);
          prv[x] = i;
     }
     cout << max(ans, N - cur_r);

     return 0;
}
