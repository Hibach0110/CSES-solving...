#include <bits/stdc++.h>
using namespace std;

// reflection

void printout(int m, int N) {
     string S = "";
     for (int i = 0; i < N; i++) {
          if (m & (1 << i)) S += "1";
          else S += "0";
     }
     cout << S << "\n";
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     for (int m = 0; m < (1<<N); m++) {
          int i = m ^ (m >> 1);
          printout(i, N);
     }
     
     return 0;
}
