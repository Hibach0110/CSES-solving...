#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, K; cin >> N >> K;
     vector<int> a(N); for (int &x : a) cin >> x;

     using ll = long long;

     auto check = [N, &a, K](ll lim) {
          int split = 0; ll sum = 0;
          for (int i = 0; i < N; i++) {
               if (sum + a[i] > lim) {
                    split++; sum = 0;
               }
               sum += a[i];
          }
          return split <= K-1;
     };

     ll lo = *max_element(a.begin(), a.end());
     ll hi = 0; for (int x : a) hi += x;
     while (lo < hi) {
          ll mid = lo + (hi - lo) / 2;
          if (check(mid)) hi = mid;
          else lo = mid + 1;
     }
     cout << lo;

     return 0;
}
