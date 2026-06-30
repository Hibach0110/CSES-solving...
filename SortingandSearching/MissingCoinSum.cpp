#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<int> a(N);
     for (int &x : a) cin >> x;

     sort(a.begin(), a.end());
     int64_t cur = 0;
     for (int &x : a) {
          if (cur < x) {
               if (cur+1 != x) {cout << cur+1; return 0;}
               cur += x;
          } else { 
               cur += x;
          } 
     }
     cout << cur+1;

     return 0;
}
