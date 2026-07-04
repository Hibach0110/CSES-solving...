#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

struct FenwickTree {
     int size;
     vector<ll> tree;
     
     void init(int n) {
          size = n;
          tree.assign(n+1, 0);
     }
 
     void update(int idx, ll delta) {
          for (; idx <= size; idx += idx & -idx) {
               tree[idx] += delta;
          }
     }
 
     ll query(int idx) {
          ll sum = 0;
          for (; idx > 0; idx -= idx & -idx) {
               sum += tree[idx];
          }
          return sum;
     }
};


int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N; cin >> N;
     vector<int> a(N), all_x; for (int &x : a) {cin >> x; all_x.push_back(x);}

     sort(all_x.begin(), all_x.end());
     all_x.erase(unique(all_x.begin(), all_x.end()), all_x.end());
     for (int i = 0; i < N; i++) {
          a[i] = lower_bound(all_x.begin(), all_x.end(), a[i]) - all_x.begin() + 1;
     }
     
     FenwickTree bit; bit.init(all_x.size()); 

     ll ans = 0;
     for (int i = 0; i < N; i++) {
          ll dp_i = (bit.query(a[i] - 1) + 1) % MOD;
          ans = (ans + dp_i) % MOD;
          bit.update(a[i], dp_i);
     }
     cout << ans;

     return 0;
}
