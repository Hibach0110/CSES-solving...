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

void solve() {

}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N; cin >> N;
   vector<int> a(N);
   int sum = 0;
   for (int &x : a) {
      cin >> x; sum += x;
   }
   
   vector<int> f(sum+5, 0);
   f[0] = 1;
   for (int i = 0; i < N; i++) {
      for (int j = sum; j >= 0; j--) {
         if (j >= a[i]) f[j] |= f[j - a[i]];
      }
   }

   int ans = 0;
   for (int i = 1; i <= sum; i++) ans += (f[i] ? 1 : 0);
   cout << ans << "\n";
   for (int i = 1; i <= sum; i++) {
      if (f[i]) cout << i << " ";
   }
   return 0;
}
