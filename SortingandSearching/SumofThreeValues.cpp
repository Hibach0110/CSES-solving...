#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, X; cin >> N >> X;
     vector<pair<int, int>> a(N+5);
     for (int i = 1; i <= N; i++) {cin >> a[i].first; a[i].second = i;}

     sort(a.begin() + 1, a.begin() + N+1);

     for (int i = 1; i <= N; i++) {
          int need = X - a[i].first;
          int l = i+1, r = N;
          while (l < r) {
               int64_t sum = a[l].first + a[r].first;
               if (sum == need) {
                    cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n"; return 0;
               } else if (sum < need) l++;
               else r--;
          }
     }

     cout << "IMPOSSIBLE\n";
     
     return 0;
}
