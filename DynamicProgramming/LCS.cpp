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

int f[1005][1005];
void check(int i1, int j1, int i2, int j2, vector<vp> &tr) {
   if (f[i1][j1] <= f[i2][j2]) {
      f[i1][j1] = f[i2][j2]; tr[i1][j1] = {i2, j2};
   }
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N, M; cin >> N >> M;
   v a(N), b(M);
   for (int i = 0; i < N; i++) cin >> a[i];
   for (int i = 0; i < M; i++) cin >> b[i];

   vector<vp> tr(N+1, vp(M+1, {-1, -1}));
   for (int i = 0; i <= N; i++) f[i][0] = 0;
   for (int j = 0; j <= M; j++) f[0][j] = 0;
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
         check(i,j,i-1,j,tr); check(i,j,i,j-1,tr); 
         if (a[i-1] == b[j-1]) {
            if (f[i-1][j-1] + 1 > f[i][j]) {
               f[i][j] = f[i-1][j-1] + 1; tr[i][j] = {i-1, j-1};
            }
         }
         // cout << f[i][j] << " \n"[j == M];
      }
   }

   cout << f[N][M] << "\n";
   
   v trace;
   int i = N, j = M;
   while (1) {
      int i2 = tr[i][j].first, j2 = tr[i][j].second;
      if (i2 == -1 || j2 == -1) break;
      if (f[i][j] != f[i2][j2]) trace.push_back(a[i-1]);
      i = i2; j = j2;
   }
   for (i = trace.size() - 1; i >= 0; i--) cout << trace[i] << " ";

   return 0;
}
