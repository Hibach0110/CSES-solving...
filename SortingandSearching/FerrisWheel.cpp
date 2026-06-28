#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, X; cin >> N >> X;
     vector<int> a(N);
     for (int &child : a) cin >> child;

     sort(a.begin(), a.end());
     int ans = 0;
     int i = 0, j = N-1;
     while (i <= j) {
          if (i == j) {
               ans++; break;
          }
          if (a[i] + a[j] <= X) {
               ans++; i++; j--;
          } else if (a[j] + a[i] > X) {
               ans++; j--;
          }
     }
     cout << ans;

     return 0;
}
