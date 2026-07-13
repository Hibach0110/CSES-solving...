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

     int n; cin >> n;
     vector<int> cnt(1e6+1, 0);
     for (int i = 0; i < n; i++) {
          int x; cin >> x;
          cnt[x]++;
     }
     
     int ans = 1;
     for (int i = 2; i <= 1e6; i++) {
          int cnt_nums = 0;
          for (int j = i; j <= 1e6; j += i) {
               cnt_nums += cnt[j];
               if (cnt_nums >= 2) {
                    ans = i;
                    break;
               }
          }
     }

     cout << ans;
     return 0;
}
