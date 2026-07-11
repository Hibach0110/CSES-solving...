#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

using ll = long long;
const int mod = 1e9 + 7;

ll exp(ll a, ll b, int m) {
     ll res = 1;
     while (b) {
          if (b & 1) res = res * a % m;
          a = a * a % m;
          b >>= 1;
     }
     return res;
} 

void solve() {
     int a, b, c; cin >> a >> b >> c;
     ll ans = exp(a, exp(b, c, mod-1), mod);
     cout << ans << "\n";
}

int main() {
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
