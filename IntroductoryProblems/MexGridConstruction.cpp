#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<vector<int>> a(N+5, vector<int>(N+5, 0));
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
               vector<int> b;
               for (int k = i-1; k >= 1; k--) b.push_back(a[k][j]);
               for (int k = j-1; k >= 1; k--) b.push_back(a[i][k]);
               sort(b.begin(), b.end());
               int cur = 0;
               for (int &x : b) {
                    if (x == cur) cur++;
               }
               a[i][j] = cur;
               cout << a[i][j] << " \n"[j == N];
          }
     }

     return 0;
}
