#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int tc; cin >> tc;
     while (tc--) {
          int N, A, B; cin >> N >> A >> B;
          
          if ((A > 0 && B == 0) || (B > 0 && A == 0)) {
               cout << "NO\n"; continue;
          }
          if (A + B > N) {
               cout << "NO\n"; continue;
          }
 
          int draw = N - A - B;
          vector<int> a(N), b(N);
          for (int i = 1; i <= draw; i++) { //draw
               a[i-1] = b[i-1] = i;
          }
          
          for (int i = 0; i < A + B; i++) {
               int val = draw + i + 1;
               a[i + draw] = val;
               int shifted_id = (i + B) % (A + B);
               b[shifted_id + draw] = val;
          }

          cout << "YES\n";
          for (int &x : a) cout << x << " ";
          cout << "\n";
          for (int &x : b) cout << x << " ";
          cout << "\n";
     }

     return 0;
}
