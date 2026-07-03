#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, K; cin >> N >> K;
     vector<pair<int, int>> a(N); for (int i = 0; i < N; i++) {cin >> a[i].second >> a[i].first;}
     
     sort(a.begin(), a.end()); 
     multiset<int> ms; for (int i = 0; i < K; i++) ms.insert(0);
     
     int ans = 0;
     for (int i = 0; i < N; i++) {
          int start = a[i].second, end = a[i].first;
          auto it = ms.upper_bound(start);
          if (it == ms.begin()) {
               continue;
          }
          --it; 
          ans++;
          ms.erase(it); ms.insert(end);
     }
     cout << ans;

     return 0;
}
