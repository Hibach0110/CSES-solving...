#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define v vector<ll> 
#define vv vector<vector<ll>>
#define vp vector<pair<ll,ll>> 

const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

void solve() {

}

ll dp[505][505];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int A, B; cin >> A >> B;
   for (int i = 1; i <= A; i++) {
      for (int j = 1; j <= B; j++) {
         if (i == j) dp[i][j] = 0;
         else dp[i][j] = INF;
      }
   }
   for (int i = 1; i <= A; i++) {
      for (int j = 1; j <= B; j++) {
         if (i == j) continue;
         for (int k = 1; k < j; k++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
         }
         for (int k = 1; k < i; k++) {
            dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
         }
         // cout << dp[i][j] << " \n"[j == B];
      }
   }
   cout << dp[A][B];
   return 0;
}
