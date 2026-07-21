#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
ll fac[N], inv[N];

ll binpow(ll a, int b, int m) {
     ll res = 1;
     while (b) {
          if (b & 1) res = res * a % m;
          b >>= 1; 
          a = a * a % m;
     }
     return res;
}

ll Comb(int n, int k) {
     return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);
     fac[0] = 1;
     for (int i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
     inv[N-1] = binpow(fac[N-1], mod-2, mod);
     for (int i = N-1; i >= 1; i--) inv[i-1] = inv[i] * i % mod;
     int q; cin >> q;
     while (q--) {
          int a, b; cin >> a >> b;
          cout << Comb(a, b) << "\n";
     }
     return 0;
}