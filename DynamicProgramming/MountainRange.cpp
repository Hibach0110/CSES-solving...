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

int mx[MAXN][21];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N; cin >> N;
   vector<int> a(N+5);
   for (int i = 1; i <= N; i++) {
      cin >> a[i]; mx[i][0] = a[i];
   }
   
   for (int l = 1; l <= 20; l++) {
      for (int i = 1; i + (1 << l) - 1 <= N; i++) {
         mx[i][l] = max(mx[i][l-1], mx[i+(1<<(l-1))][l-1]);
      }
   }   

   auto get_max = [](int l, int r) -> int {
      int k = __lg(r - l + 1);
      return max(mx[l][k], mx[r-(1<<k)+1][k]);
   };

   int ans = 0;
   for (int i = 1; i <= N; i++) {
      int l = 1, r = i, cdd = 0;
      while (l < r) {
         int mid = l + (r - l) / 2;
         if (get_max(mid, i-1) < a[i]) r = mid;
         else l = mid + 1;
      }
      cdd += i - l + 1;
      l = i; r = N;
      while (l < r) {
         int mid = l + (r - l + 1) / 2;
         if (get_max(i+1, mid) < a[i]) l = mid;
         else r = mid - 1;
      }
      cdd += l - i;
      bug(i,cdd,0);
      ans = max(ans, cdd);
   }

   cout << ans;
   return 0;
}
