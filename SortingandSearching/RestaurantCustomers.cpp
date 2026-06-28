#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<pair<int, int>> events;
     for (int i = 0; i < N; i++) {
          int l, r; cin >> l >> r;
          events.push_back({l, 1});
          events.push_back({r, -1});
     }

     sort(events.begin(), events.end());
     int cur = 0, mx = 0;
     for (auto& e : events) {
          cur += e.second;
          mx = max(mx, cur);
     }

     cout << mx;

     return 0;
}
