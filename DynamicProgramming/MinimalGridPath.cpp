#include <bits/stdc++.h>
#include <queue>
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

bool vs[3005][3005];
pll cur[2] = {{0,1}, {1,0}};
char S[3005][3005];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int N; cin >> N;
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
         cin >> S[i][j];
      }
   }   

   string ans = "";
   vector<pll> lay, lay2; lay.pb({1,1});
   vs[1][1] = 1;
   while (!lay.empty()) {
      char C = '?';
      for (int i = 0; i < lay.size(); i++) {
         int I = lay[i].fi, J = lay[i].se;
         if (C == '?' || C > S[I][J]) C = S[I][J];
      }
      ans += C;
      for (int i = 0; i < lay.size(); i++) {
         int I = lay[i].fi, J = lay[i].se;
         if (S[I][J] != C) continue;
         for (int k = 0; k < 2; k++) {
            int ni = I + cur[k].fi, nj = J + cur[k].se;
            if (vs[ni][nj] || ni < 1 || ni > N || nj < 1 || nj > N) continue;
            vs[ni][nj] = true;
            lay2.pb({ni, nj});
         }
      }
      swap(lay, lay2); 
      lay2.clear();
   }

   cout << ans;
   return 0;
}
