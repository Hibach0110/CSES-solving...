#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     int ans = 0;
     while (N) {
          ans += N / 5;
          N /= 5;
     }
     cout << ans;

     return 0;
}
