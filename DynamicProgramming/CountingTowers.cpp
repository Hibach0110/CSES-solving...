#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define v vector<ll> 
#define vv vector<vector<ll>>
#define vp vector<pair<ll,ll>> 

const int MAXN = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {

}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   
   v f(MAXN, 0), g(MAXN, 0); //f: end with ver    g: no ver
   f[1] = g[1] = 1;
   f[2] = 5; g[2] = 3;
   for (int i = 3; i <= 1e6; i++) {
      f[i] = (4 * f[i-1] + g[i-1]) % mod;
      g[i] = (2 * g[i-1] + f[i-1]) % mod;
   }

   int tc; cin >> tc;
   while (tc--) {
      int N; cin >> N;
      ll ans = (f[N] + g[N]) % mod;
      // cout << g[N] << " ";
      cout << ans << "\n";
   }
   return 0;
}
