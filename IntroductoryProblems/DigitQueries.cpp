#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int Q; cin >> Q;
     while (Q--) {
          int64_t K; cin >> K;
          int64_t cur = 0, nums = 9, dg = 1, s = 0;
          while (cur + nums * dg <= K) {
               cur += nums * dg;
               s += nums;
               nums = nums * 10; dg++;
          }
          // 9999999 <- s;
          K -= cur;
          s += K / dg + (K % dg == 0 ? 0 : 1);
          K %= dg;
          if (K == 0) {
               cout << (s % 10) << "\n";
          } else {
               int64_t b10 = 1;
               for (int i = 1; i <= dg - K; i++) b10 *= 10;
               cout << (s / b10) % 10 << "\n";
          }
     }

     return 0;
}
