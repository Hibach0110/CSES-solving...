#include <bits/stdc++.h>
using namespace std;

struct customer {
     int l, r, id;
};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<customer> a(N);
     for (int i = 0; i < N; i++) {
          int l, r; cin >> l >> r;
          a[i] = {l, r, i};
     }

     auto cmp = [](const auto& a, const auto& b) {
          return a.l < b.l;
     };
     sort(a.begin(), a.end(), cmp);

     auto pq_cmp = [](const auto& a, const auto& b) {
        return a.first > b.first; 
     };
     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pq_cmp)> pq(pq_cmp);

     int Nrooms = 0;
     vector<int> rooms(N);
     for (int i = 0; i < N; i++) {
          if (pq.empty() || pq.top().first >= a[i].l) {
               Nrooms++;
               rooms[a[i].id] = Nrooms;
               pq.push({a[i].r, Nrooms});
          } else {
               auto cl = pq.top(); pq.pop();
               rooms[a[i].id] = cl.second; 
               cl.first = a[i].r;
               pq.push(cl);
          }
     }

     cout << Nrooms << "\n";
     for (int &x : rooms) {
          cout << x << " ";
     }

     return 0;
}
