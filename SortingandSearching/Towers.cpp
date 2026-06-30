#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<int> a;
     for (int i = 0; i < N; i++) {
          int x; cin >> x;
          if (a.empty() || a.back() <= x) {
               a.push_back(x);
          } else {
               int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
               a[idx] = x;
          }
     }
     cout << a.size();

     return 0;
}
