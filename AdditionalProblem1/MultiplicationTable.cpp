#include <bits/stdc++.h>

using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<long long> a;
     for (int i = 1; i <= N; i++) {
          a.push_back(1LL * i * (N-i+1));
     }
     sort(a.begin(), a.end());
     
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
               cout << i * j << " \n"[j == N];
          }
     }

     for (int x : a) cout << x << " ";
     cout << "\n";

     cout << a[a.size() / 2];

     return 0;
}
