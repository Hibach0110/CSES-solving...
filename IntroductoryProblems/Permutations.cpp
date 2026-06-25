#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     // 3 1 4 2
     // 3 1 4 2 5
     
     int N; cin >> N;
     if (N == 1) {
          cout << 1; return 0;
     }
     if (N < 4) {
          cout << "NO SOLUTION"; return 0;
     }

     int i = 1, j = N / 2 + 1;
     while (i < N / 2 + 1 || j <= N) {
          if (j <= N) cout << j++ << " ";
          if (i < N / 2 + 1) cout << i++ << " ";
     }

     return 0;
}
