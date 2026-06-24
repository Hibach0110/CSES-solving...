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

const int MAXN = 5e3 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

ll f[MAXN][MAXN][2];

void solve() {

}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N; cin >> N;
   vector<int> a(N);
   for (int &x : a) {
      cin >> x;
   }
   
   vector<ll> pf(N); pf[0] = a[0];
   for (int i = 1; i < N; i++) {
      pf[i] = pf[i - 1] + a[i];
   }
   auto get_sum = [pf](int l, int r) -> ll{
      return pf[r] - (l ? pf[l-1] : 0);
   };

   for (int i = 0; i < N; i++) {
      f[i][i][0] = f[i][i][1] = a[i]; // 0: first player ... 1: second player
   }
   for (int len = 2; len <= N; len++) {
      for (int i = 0; i + len - 1 < N; i++) {
         int j = i + len - 1;
         f[i][j][0] = max(a[i] + get_sum(i+1,j) - f[i+1][j][1], get_sum(i,j-1) - f[i][j-1][1] + a[j]);
         f[i][j][1] = max(a[i] + get_sum(i+1,j) - f[i+1][j][0], get_sum(i,j-1) - f[i][j-1][0] + a[j]);
         // bug(i,j,f[i][j][0]);
      }
   }

   cout << f[0][N-1][0];
   return 0;
}
