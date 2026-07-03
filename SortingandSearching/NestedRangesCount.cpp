#include <bits/stdc++.h>
using namespace std;

struct Range {
     int x, y, id, x_comp;
};

bool cmp(const Range& a, const Range& b) {
     if (a.y == b.y) return a.x > b.x;
     return a.y < b.y;
}

struct FenwickTree {
     int size;
     vector<int> tree;
     
     void init(int n) {
          size = n;
          tree.assign(n+1, 0);
     }

     void update(int idx, int delta) {
          for (; idx <= size; idx += idx & -idx) {
               tree[idx] += delta;
          }
     }

     int query(int idx) {
          int sum = 0;
          for (; idx > 0; idx -= idx & -idx) {
               sum += tree[idx];
          }
          return sum;
     }
};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<Range> a(N); for (int i = 0; i < N; i++) {cin >> a[i].x >> a[i].y; a[i].id = i;}
     vector<int> all_x; for (int i = 0; i < N; i++) all_x.push_back(a[i].x);
     
     sort(all_x.begin(), all_x.end());
     all_x.erase(unique(all_x.begin(), all_x.end()), all_x.end());
     for (int i = 0; i < N; i++) {
          a[i].x_comp = lower_bound(all_x.begin(), all_x.end(), a[i].x) - all_x.begin() + 1;
     }

     sort(a.begin(), a.end(), cmp);

     vector<int> contained(N, 0), contains(N, 0);
     FenwickTree bit;
     int mx_x_comp = all_x.size();

     bit.init(mx_x_comp);
     for (int i = 0; i < N; i++) {
          int idx = lower_bound(all_x.begin(), all_x.end(), a[i].x) - all_x.begin() + 1;
          contains[a[i].id] = bit.query(mx_x_comp) - bit.query(idx-1);
          bit.update(a[i].x_comp, 1);
     }

     bit.init(mx_x_comp);
     for (int i = N-1; i >= 0; i--) {
          int idx = lower_bound(all_x.begin(), all_x.end(), a[i].x) - all_x.begin() + 1;
          contained[a[i].id] = bit.query(idx);
          bit.update(a[i].x_comp, 1);
     }

     for (int &x : contains) {cout << x << " ";} cout << "\n";
     for (int &x : contained) cout << x << " ";

     return 0;
}
