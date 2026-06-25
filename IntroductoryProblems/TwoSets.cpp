#include <bits/stdc++.h>
using namespace std;

bool used[1000005];

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     using ll = long long;

     int N; cin >> N;
     ll sum = 1ll * N * (N + 1) / 2;
     
     if (sum & 1) {
          cout << "NO"; return 0;
     }
     
     sum /= 2;
     int cnt = 0;
     for (int i = N; i >= 1; i--) {
          if (sum > i) {
               used[i] = true; cnt++;
               sum -= i;
          } else {
               used[sum] = true; cnt++;
               break;
          }
     }

     cout << "YES\n";
     cout << cnt << "\n";
     for (int i = 1; i <= N; i++) {
          if (used[i]) cout << i << " \n"[i == N];
     }
     cout << N - cnt << "\n";
     for (int i = 1; i <= N; i++) {
          if (!used[i]) cout << i << " ";
     }

     return 0;
}
