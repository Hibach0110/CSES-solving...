#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(NULL);
     using ll = long long;

     int n, k; cin >> n >> k;
     vector<ll> a(n);
     int x, A, B, C; cin >> x >> A >> B >> C;
     a[0] = x;
     for (int i = 1; i < n; i++) {
          a[i] = ((ll)A * a[i-1] % C + B) % C;
     }

     deque<int> dq;
     for (int i = 0; i < k; i++) {
          while (!dq.empty() && a[dq.back()] >= a[i]) {
               dq.pop_back();
          }
          dq.push_back(i);
     }
     int ans = a[dq.front()];
     for (int i = k; i < n; i++) {
          while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
          while (!dq.empty() && a[dq.back()] >= a[i]) {
               dq.pop_back();
          }
          dq.push_back(i);
          ans ^= a[dq.front()];
     }
     cout << ans;

     return 0;
}