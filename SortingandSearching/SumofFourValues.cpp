#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int64_t N, X; cin >> N >> X;
     vector<int64_t> a(N); for (auto &x : a) cin >> x;

     map<int64_t, pair<int, int>> mp;
     for (int i = 0; i < N; i++) {
          for (int j = i+1; j < N; j++) {
               mp[a[i] + a[j]] = {i, j};
          }
     }

     for (int i = 0; i < N; i++) {
          for (int j = i+1; j < N; j++) {
               int64_t need = X - a[i] - a[j];
               if (mp.count(need)) {
                    auto [i1, i2] = mp[need];
                    if (i != i1 && i != i2 && j != i1 && j != i2) {
                         cout << ++i << " " << ++i2 << " " << ++j << " " << ++i1 << "\n"; return 0;
                    }
               }
          }
     }

     cout << "IMPOSSIBLE";

     return 0;
}
