#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
     int n; vector<int> tree;
     const int INF = INT_MAX;
     void build(const vector<int>& arr, int node, int start, int end) {
          if (start == end) {tree[node] = arr[start]; return;}
          int mid = start + (end - start) / 2;
          build(arr, 2*node, start, mid); build(arr, 2*node+1, mid+1, end);
          tree[node] = min(tree[2*node], tree[2*node+1]);
     }
     void update(int node, int start, int end, int idx, int val) {
          if (start == end) {tree[node] = val; return;}
          int mid = start + (end - start) / 2;
          if (idx <= mid) update(node*2, start, mid, idx, val);
          else update(node*2+1, mid+1, end, idx, val);
          tree[node] = min(tree[2*node], tree[2*node+1]);
     }
     int query(int node, int start, int end, int l, int r) {
          if (r < start || end < l) return INF;
          if (l <= start && end <= r) return tree[node];
          int mid = start + (end - start) / 2;
          return min(    query(node*2, start, mid, l, r),
                         query(node*2+1, mid+1, end, l, r));
     }
public:
     SegmentTree(const vector<int>& arr) {
          n = arr.size(); tree.assign(4*n, INF); 
          build(arr, 1, 0, n-1);
     }
     void update(int idx, int val) {
          if (idx < 0 || idx >= n) return;
          update(1, 0, n-1, idx, val);
     }
     int query(int l, int r) {
          return query(1, 0, n-1, l, r);
     }
};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, Q; cin >> N >> Q;
     vector<int> a(N); for (int &x : a) cin >> x;

     SegmentTree st(a);

     while (Q--) {
          int type; cin >> type;
          if (type == 1) {
               int k, u; cin >> k >> u;
               st.update(k-1, u);
          } else {
               int l, r; cin >> l >> r; l--; r--;
               cout << st.query(l, r) << "\n";
          }
     }

     return 0;
}
