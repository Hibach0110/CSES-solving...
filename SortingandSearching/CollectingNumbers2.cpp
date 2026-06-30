#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, Q; cin >> N >> Q;
     vector<int> pos(N+5), a(N);
     for (int i = 0; i < N; i++) {
          int x; cin >> x;
          pos[x] = i; a[i] = x;
     }
     pos[N+1] = N; pos[0] = -1;
     
     int cur_ans = 1;
     for (int i = 2; i <= N; i++) cur_ans += (pos[i] < pos[i-1]);

     while (Q--) {
          int A, B; cin >> A >> B; A--; B--;
          if (A > B) swap(A, B); 
          int x = a[A], y = a[B];

          int l = min(x, y), r = max(x, y);
          if (A < pos[l-1] && pos[l-1] < B) cur_ans += (x == l ? -1 : 1);
          if (A < pos[r+1] && pos[r+1] < B) cur_ans += (x == r ? 1 : -1);
          if (abs(x - y) == 1) {
               cur_ans += (x > y ? -1 : 1);
          } else {
               if (A < pos[l+1] && pos[l+1] < B) cur_ans += (x == l ? 1 : -1);
               if (A < pos[r-1] && pos[r-1] < B) cur_ans += (x == r ? -1 : 1);
          }

          a[A] = y; a[B] = x;
          pos[x] = B; pos[y] = A; 
          // cout << B << " " << x << "\n";
          // for (int i = 1; i <= N; i++) cout << pos[i] << " \n"[i == N];

          cout << cur_ans << "\n";
     }

     return 0;
}
