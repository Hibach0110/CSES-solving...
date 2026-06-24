#include <algorithm>
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
   vector<int> a(N+5);
   for (int i = 1; i <= N; i++) {
      cin >> a[i];
   }

   vector<int> dp;
   for (int i = 1; i <= N; i++) {
      if (dp.empty() || dp.back() < a[i]) {
         dp.push_back(a[i]); 
      } else {
         int id = lower_bound(all(dp), a[i]) - dp.begin();
         dp[id] = a[i];
      }
      // for (int x : dp) cout << x << " ";
      // cout << "\n";
   }

   cout << dp.size();
   return 0;
}
