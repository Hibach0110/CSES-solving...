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

int inv(int a, int m) { // finish less than 50 iterations
     return a <= 1 ? a : m - (ll)(m/a) * inv(m % a, m) % m;
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);  
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif
     // cout << fixed << setprecision(12);

     int nPr; cin >> nPr;
     ll num = 1, sum = 1, prd = 1;
     vector<pair<int, int>> store;
     while (nPr--) {
          int p, k; cin >> p >> k;
          store.push_back({p, k});
          num *= k + 1; 
          num %+ mod;
          ll numerator = (binpower(p, k+1, mod) - 1 + mod) % mod;
          sum *= numerator * inv(p-1, mod) % mod;
          sum %= mod;
     }
     for (int i = 0; i < sz(store); i++) {
          int p = store[i].first, v = store[i].second;
          ll value = num * inv(v+1, mod) % mod;
          v %= mod;
          ll sum_pow = (ll)v * (v+1) % mod * inv(2, mod) % mod;
          prd *= binpower(p, sum_pow * value % mod, mod);
          prd %= mod;
     }
     cout << num << " " << sum << " " << prd;

     return 0;
}
