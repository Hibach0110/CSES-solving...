#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     int tc; cin >> tc;
     while (tc--) {
          int a, b; cin >> a >> b;
          int diff = abs(a - b);
          if (diff > min(a, b)) {
               cout << "NO\n"; continue;
          }
          int total = a + b;
          cout << (total % 3 == 0 ? "YES" : "NO") << "\n";
     }
     return 0;
}
