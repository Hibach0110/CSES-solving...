#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define v vector<ll> 
#define vv vector<vector<ll>>
#define vp vector<pair<ll,ll>> 

const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;

void solve() {

}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   string S, T; cin >> S >> T;
   int N = S.size(), M = T.size();

   vv f(N+1, v(M+1, INT_MAX));
   for (int i = 0; i <= N; i++) f[i][0] = i;
   for (int j = 0; j <= M; j++) f[0][j] = j;
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
         if (S[i-1] == T[j-1]) {
            f[i][j] = min(f[i][j], f[i-1][j-1]);
         } else {
            f[i][j] = min({f[i][j], f[i-1][j-1] + 1, f[i-1][j] + 1, f[i][j-1] + 1});
         } 
      }
   }

   cout << f[N][M];
   return 0;
}
