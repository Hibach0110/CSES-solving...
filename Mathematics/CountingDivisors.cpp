#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

using ll = long long;

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);  
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif
     // cout << fixed << setprecision(12);

     int tc; cin >> tc;
     while (tc--) {
          int n; cin >> n;
          int cnt_divi = 0;
          for (int i = 1; i * i <= n; i++) {
               if (n % i == 0) {
                    cnt_divi++;
                    if (i * i != n) cnt_divi++;
               }
          }
          cout << cnt_divi << "\n";
     }

     return 0;
}
