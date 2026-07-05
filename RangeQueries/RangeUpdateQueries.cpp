#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegmentTree {
private:
     int n; vector<ll> tree;
     const int INF = INT_MAX;
     void build(const vector<ll>& arr, int node, int start, int end) {
          if (start == end) {tree[node] = arr[start]; return;}
          int mid = start + (end - start) / 2;
          build(arr, 2*node, start, mid); build(arr, 2*node+1, mid+1, end);
          tree[node] = 0;
     }
     void update(int node, int start, int end, int l, int r, ll val) {
          if (r < start || end < l) return;
          if (l <= start && end <= r) {tree[node] += val; return;}
          int mid = start + (end - start) / 2;
          update(node*2, start, mid, l, r, val);
          update(node*2+1, mid+1, end, l, r, val);
     }
     ll query(int node, int start, int end, int idx) {
          if (start == end) return tree[node];
          int mid = start + (end - start) / 2;
          if (idx <= mid) return tree[node] + query(node*2, start, mid, idx);
          else return tree[node] + query(node*2+1, mid+1, end, idx);
     }
public:
     SegmentTree(const vector<ll>& arr) {
          n = arr.size(); tree.assign(4*n, 0); 
          build(arr, 1, 0, n-1);
     }
     void update(int l, int r, ll val) {
          update(1, 0, n-1, l, r, val);
     }
     ll query(int idx) {
          return query(1, 0, n-1, idx);
     }
};



int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, Q; cin >> N >> Q;
     vector<ll> a(N); for (ll &x : a) cin >> x;

     SegmentTree st(a);
     
     while (Q--) {
          int type; cin >> type;
          if (type == 1) {
               int l, r; 
               ll u; 
               cin >> l >> r >> u; l--; r--;
               st.update(l, r, u);
          } else {
               int k; cin >> k; k--;
               cout << st.query(k) << "\n";
          }
     }
     
     return 0;
}
