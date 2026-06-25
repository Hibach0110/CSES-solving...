#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     int N; cin >> N;
     vector<int> a(N);
     for (int &x : a) {
          cin >> x;
     }

     long long ans = 0;
     for (int i = 1; i < N; i++) {
          if (a[i] < a[i - 1]) {
               ans += a[i - 1] - a[i];
               a[i] = a[i - 1];
          }
     }

     cout << ans;
     return 0;
}
