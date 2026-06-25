#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int tc; cin >> tc;
     while (tc--) {
          long long R, C; cin >> R >> C;
          long long B = max(R, C);
          //even: ver ... odd: hor
          long long x;
          if (B & 1) {
               if (C == B) {
                    x = B * B - R + 1;
               } else {
                    x = (B * B - B + 1) - B+1 + C-1;
               }
          } else {
               if (R == B) {
                    x = B * B - C + 1;
               } else {
                    x = (B * B - B + 1) - B+1 + R-1;
               }
          }
          cout << x << "\n";
     }

     return 0;
}
