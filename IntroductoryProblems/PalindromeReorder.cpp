#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     string S; cin >> S;
     for (int i = 0; i < S.size(); i++) {
          cnt[S[i] - 'A']++;
     }
     
     char odd = '?';
     for (int i = 0; i < 26; i++) {
          if (cnt[i] & 1) {
               if (odd == '?') odd = 'A' + i;
               else {
                    cout << "NO SOLUTION"; return 0;
               }
          }
     }

     string ls = "";
     for (int i = 0; i < 26; i++) {
          char C = 'A' + i;
          for (int j = 1; j <= cnt[i] / 2; j++) ls += C;
     }
     
     string rs = ls; reverse(rs.begin(), rs.end());
     
     cout << ls;
     if (odd != '?') {
          cout << odd;
     }
     cout << rs;
   
     return 0;
}
