#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using v = vector<ll>;
using vv = vector<v>;
using vp = vector<pll>;

#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define bug(x,y,z) cout << #x << "=" << x << ", " << #y << "=" <<  y << ", " << #z << "=" << z << "\n"  

const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

ll bin_pow(ll a, ll b) {
   ll res = 1;
   while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod; b >>= 1;
   }
   return res;
}

void solve() {

}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N; cin >> N;
   ll sum = (N + 1) * N / 2;
   if (sum & 1) {
      cout << 0; return 0;
   }

   sum /= 2;
   vector<ll> f(sum+5, 0);
   f[0] = 1;
   for (int i = 1; i <= N; i++) {
      for (int j = sum; j >= 1; j--) {
         if (j >= i) f[j] = (f[j] + f[j-i]) % mod;
      }
   }
   
   ll ans = f[sum] * bin_pow(2, mod-2) % mod;
   cout << ans;

   return 0;
}
