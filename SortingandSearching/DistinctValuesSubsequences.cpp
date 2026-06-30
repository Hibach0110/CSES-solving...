#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int64_t bin_pow(int64_t a, int b) {
     int64_t res = 1;
     while (b) {
          if (b & 1) res = res * a % mod;
          a = a * a % mod;
          b >>= 1; 
     }
     return res;
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     int64_t ans = 0, prod = 1;
     map<int, int> mp;
     for (int i = 1; i <= N; i++) {
          int x; cin >> x;
          prod = prod * bin_pow(mp[x] + 1, mod - 2) % mod;
          ans = (ans + prod) % mod;
          mp[x]++;
          prod = prod * (mp[x] + 1) % mod;
     }
     cout << ans;

     return 0;
}
