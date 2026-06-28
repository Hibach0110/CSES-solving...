#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, M; cin >> N >> M;

     multiset<int> ms;
     for (int i = 0; i < N; i++) {
          int price; cin >> price;
          ms.insert(price);
     }

     for (int i = 0; i < M; i++) {
          int t; cin >> t;
          auto it = ms.upper_bound(t);
          if (it == ms.begin()) {
               cout << -1 << "\n";
          } else {
               --it;
               cout << *it << "\n";
               ms.erase(it);
          }
     }

     return 0;
}
