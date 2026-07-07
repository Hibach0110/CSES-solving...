#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegmentTree {
     int n;
     vector<ll> tree;

     SegmentTree(int size) : n(size), tree(4 * size, 0) {}

     void build(const vector<int>& arr, int node, int start, int end) {
          if (start == end) {
               tree[node] = arr[start];
          } else {
               int mid = (start + end) / 2;
               build(arr, 2 * node + 1, start, mid);
               build(arr, 2 * node + 2, mid + 1, end);
               tree[node] = 0;
          }
     }

     void update(int node, int start, int end, int l, int r, int val) {
          if (r < start || end < l) return;
          if (l <= start && end <= r) {tree[node] += val; return;}
          int mid = start + (end - start) / 2;
          update(2 * node + 1, start, mid, l, r, val);
          update(2 * node + 2, mid + 1, end, l, r, val);
     }

     ll query(int node, int start, int end, int idx) {
          if (start == end) return tree[node];
          int mid = start + (end - start) / 2;
          if (idx <= mid) {
               return tree[node] + query(2 * node + 1, start, mid, idx);
          } else {
               return tree[node] + query(2 * node + 2, mid + 1, end, idx);
          }
     }
};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, Q; cin >> N >> Q;
     vector<int> a(N); for (int &x : a) cin >> x;

     SegmentTree st(N); st.build(a, 1, 0, N - 1);

     while (Q--) {
          int type; cin >> type;
          if (type == 1) {
               int l, r, u; cin >> l >> r >> u; l--; r--;
               st.update(1, 0, N - 1, l, r, u);
          } else {
               int idx; cin >> idx; idx--;
               cout << st.query(1, 0, N - 1, idx) << "\n";
          }
     }

     return 0;
}
