#include <bits/stdc++.h>
using namespace std;

vector<string> Ss;
int cnt[26];

void doit(int cur, int N, string s) {
     if (cur == N) {
          Ss.push_back(s); return;
     }
     for (int i = 0; i < 26; i++) {
          if (cnt[i]) {
               char C = 'a' + i;
               cnt[i]--;
               doit(cur + 1, N, s + C);
               cnt[i]++;
          }
     }
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     string S; cin >> S;
     for (int i = 0; i < S.size(); i++) {
          cnt[S[i] - 'a']++;
     }
     
     doit(0, S.size(), "");
     sort(Ss.begin(), Ss.end());
     
     cout << Ss.size() << "\n";
     for (string &s : Ss) {
          cout << s << "\n";
     }
     
     return 0;
}
