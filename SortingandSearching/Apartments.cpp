#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, M, K; cin >> N >> M >> K;
     vector<int> a(N), b(M);
     for (int &x : a) {
          cin >> x;
     }
     sort(a.begin(), a.end());

     for (int &x : b) {
          cin >> x;
     }
     sort(b.begin(), b.end());

     int i = 0, j = 0, ans = 0;
     while (i < N && j < M) {
          if (abs(a[i] - b[j]) <= K) {
               ans++; i++; j++;
          } else if (a[i] < b[j]) {
               i++;
          } else {
               j++;
          }
     }
     cout << ans;

     return 0;
}
