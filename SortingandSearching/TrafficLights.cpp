#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int X, N; cin >> X >> N;
     
     set<int> lights; 
     lights.insert(0); lights.insert(X);
     multiset<int> gaps; 
     gaps.insert(X);

     for (int i = 0; i < N; i++) {
          int p; cin >> p;
          auto it = lights.upper_bound(p);
          int nxt = *it;
          int prv = *prev(it);
          gaps.erase(gaps.find(nxt - prv));
          gaps.insert(nxt - p); 
          gaps.insert(p - prv);
          lights.insert(p);
          cout << *gaps.rbegin() << " ";
     }

     return 0;
}
