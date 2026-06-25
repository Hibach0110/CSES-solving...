#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
          
     using ll = long long;
     int N; cin >> N;

     for (int i = 1; i <= N; i++) {
          ll invalid = i < 3 ? 0 : 4ll * (i - 2) * (i-1);
          ll all = 1ll * (i*i) * (i*i-1) / 2;
          ll ans = all - invalid;
          cout << ans << "\n";
     }

     return 0;
}
