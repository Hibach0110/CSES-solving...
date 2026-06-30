#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<int> a(N);
     for (int &x : a) {
          cin >> x; 
     }
     
     sort(a.begin(), a.end());
     int64_t med = a[N / 2];
     int64_t ans = 0;
     for (int &x : a) {
          ans += abs(x - med);
     }

     cout << ans;

     return 0;
}
