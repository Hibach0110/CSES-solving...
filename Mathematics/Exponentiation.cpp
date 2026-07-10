#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

using ll = long long;

ll exp(int a, int b, int m) {
     ll res = 1;
     while (b) {
          if (b & 1) res = res * a % m;
          a = (ll)a * a % m;
          b >>= 1;
     }
     return res;
}

void solve() {
     int a, b; cin >> a >> b;
     cout << exp(a, b, 1000000007) << "\n";
}

int32_t main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif
     // cout << fixed << setprecision(12);

     int tc = 1; cin >> tc;
     while (tc--) {
          solve();
     }

     return 0;
}
