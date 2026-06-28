#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
          
     string S; cin >> S;
     int N = S.size();
     vector<char> c(N*3, '?');
     
     for (int i = 0; i < N; i++) {
          cnt[S[i] - 'A']++;
     }
     
     int len = N; // how many char left...
     int last_char = -1;
     while (len) {
          int mx_cnt = 0, cur_char = -1;
          for (int i = 0; i < 26; i++) {
               if (mx_cnt < cnt[i]) {
                    mx_cnt = cnt[i]; cur_char = i;
               }
          }
          if (mx_cnt > (len + 1) / 2) { // too many...
               cout << -1 << "\n"; return 0;
          }
          if (mx_cnt * 2 - 1 == len) { // force to place
               c[N-len] = 'A' + cur_char;
               last_char = cur_char; cnt[cur_char]--;
               len--; continue;
          } else { // greedy
               for (int i = 0; i < 26; i++) {
                    if (i != last_char && cnt[i]) {
                         c[N-len] = 'A' + i;
                         last_char = i; cnt[i]--; len--;
                         break;
                    }
               }
          }
     }

     // for (int i = 0; i < N; i++) {
     //      if (c[i] == '?' || (i > 1 && c[i] == c[i-1])) {
     //           cout << -1; return 0;
     //      }
     // }
     for (int i = 0; i < N; i++) cout << c[i];

     return 0;
}
