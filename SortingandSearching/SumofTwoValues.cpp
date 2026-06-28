#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, X; cin >> N >> X;
     int ans = 0;
     map<int, int> mp;
     for (int i = 1; i <= N; i++) {
          int x; cin >> x;
          if (mp.count(X - x)) {
               cout << i << " " << mp[X - x] << "\n";
               return 0;
          }
          mp[x] = i;
     }

     cout << "IMPOSSIBLE";
     
     return 0;
}
