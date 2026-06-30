#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N; cin >> N;
     vector<int> pos(N+5);
     for (int i = 0; i < N; i++) {
          int x; cin >> x; 
          pos[x] = i;
     }
     int ans = 0;
     for (int i = 2; i <= N; i++) {
          if (pos[i] < pos[i-1]) ans++;
     }
     cout << ans+1;

     return 0;
}
