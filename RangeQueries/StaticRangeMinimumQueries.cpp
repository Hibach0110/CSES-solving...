#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 18;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, Q; cin >> N >> Q;
     vector<int> a(N); for (int &x : a) cin >> x;

     vector<vector<int>> st(N, vector<int>(MAX_K + 1));
     for (int i = 0; i < N; i++) st[i][0] = a[i];
     for (int j = 1; j <= MAX_K; j++) {
          for (int i = 0; i + (1 << j) <= N; i++) {
               st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
          }
     }

     vector<int> lg(N+1, 0);
     for (int i = 2; i <= N; i++) lg[i] = lg[i/2] + 1;

     while (Q--) {
          int A, B; cin >> A >> B; A--; B--;
          int k = lg[B - A + 1];
          int ans = min(st[A][k], st[B - (1<<k) + 1][k]);
          cout << ans << "\n";
     }

     return 0;
}
