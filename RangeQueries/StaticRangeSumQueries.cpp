#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     using ll = long long;

     int N, Q; cin >> N >> Q;
     vector<int> a(N+5);
     vector<ll> pf(N+5);
     for (int i = 1; i <= N; i++) {
          cin >> a[i]; pf[i] = pf[i - 1] + a[i];
     }
     while (Q--) {
          int a, b; cin >> a >> b;
          ll sum = pf[b] - pf[a - 1];
          cout << sum << "\n";
     }
     return 0; 
}
