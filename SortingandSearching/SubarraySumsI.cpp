#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, X; cin >> N >> X; vector<int> a(N); for (int &x : a) cin >> x;
     
     int64_t sum = 0; int ans = 0, left = 0;
     for (int i = 0; i < N; i++) {
          sum += a[i];
          while (sum > X && left <= i) {
               sum -= a[left]; left++;
          }
          if (sum == X) ans++;
     }
     cout << ans;
          
     return 0;
}
