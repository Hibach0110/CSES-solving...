#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, T; cin >> N >> T;
     vector<int> a(N);
     for (int &x : a) cin >> x;

     using ll = long long;
     ll lo = 0, hi = 1e18;
     while (lo < hi) {
          ll mid = lo + (hi - lo) / 2;
          ll products = 0;
          for (int &x : a) {
               products += mid / x;
               if (products >= T) break;
          }
          if (products >= T) hi = mid;
          else lo = mid + 1;
     }
     cout << lo;

     return 0;
}
