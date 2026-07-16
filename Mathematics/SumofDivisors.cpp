#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

using ll = long long;
const int mod = 1e9 + 7;

ll binpower(ll a, int b, int m) {
     ll res = 1;
     while (b) {
          if (b & 1) res = res * a % m;
          a = a * a % m;
          b >>= 1;
     }
     return res;
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);  
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif
     // cout << fixed << setprecision(12);

     ll inv = binpower(2, mod-2, mod);

     ll n; cin >> n;
     ll total = 0, sq = 0;
     for (ll i = 1; i * i <= n; i++) {
          total += i * (n / i) % mod;
          total %= mod;
          sq = i;
     }
     for (ll i = 1; i * i <= n; i++) { // contribute i times
          // find [l, r] that n/x = i;
          ll value = n / i;
          if (value <= sq) break;
          ll boundL = max(n / (i+1), sq);

          ll v_mod = value % mod;
          ll b_mod = boundL % mod;
          ll s1 = v_mod * inv % mod * ((v_mod + 1) % mod) % mod;
          ll s2 = b_mod * inv % mod * ((b_mod + 1) % mod) % mod;
          total += (s1 - s2 + mod) % mod * i % mod;
          total %= mod;
     }
     
     cout << total;

     return 0;
}
