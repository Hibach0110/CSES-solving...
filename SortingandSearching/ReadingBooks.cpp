#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<int> a(N);
     for (int &x : a) cin >> x;

     sort(a.begin(), a.end());
     int64_t sum = 0;
     for (int i = 0; i < N-1; i++) sum += a[i];

     if (sum <= a[N-1]) {
          cout << 2ll * a[N-1];
     } else {
          sum += a[N-1];
          cout << sum;
     }

     return 0;
}
