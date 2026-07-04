#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
     int n; vector<int> tree;
     void init(int size) {
          n = size; tree.assign(4*n, 0);
     }
     void update(int node, int start, int end, int idx, int val) {
          if (start == end) {
               tree[node] = val; return;
          }
          int mid = (start + end) / 2;
          if (idx <= mid) update(node * 2, start, mid, idx, val);
          else update(node * 2 + 1, mid+1, end, idx, val);
          tree[node] = max(tree[node*2], tree[node*2+1]);
     }
     int query(int node, int start, int end, int l, int r) {
          if (r < start || end < l) return 0;
          if (l <= start && end <= r) return tree[node];
          int mid = (start + end) / 2;
          return max(query(node*2, start, mid, l, r),
                     query(node*2+1, mid+1, end, l, r));
     }
     void update(int idx, int val) {update(1, 0, n-1, idx, val);}
     int query(int l, int r) {if (l > r) return 0; return query(1, 0, n-1, l, r);}
};

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<int> h(N); vector<pair<int, int>> sorted(N); 
     for (int i = 0; i < N; i++) {cin >> h[i]; sorted[i] = {h[i], i};}

     sort(sorted.begin(), sorted.end());

     vector<int> L(N, -1); stack<int> st;
     for (int i = 0; i < N; i++) {
          while (!st.empty() && h[st.top()] < h[i]) st.pop();
          if (!st.empty()) L[i] = st.top();
          st.push(i);
     }
     while (!st.empty()) st.pop();
     vector<int> R(N, N);
     for (int i = N-1; i >= 0; i--) {
          while (!st.empty() && h[st.top()] < h[i]) st.pop();
          if (!st.empty()) R[i] = st.top();
          st.push(i);
     }
     
     SegmentTree segTree; segTree.init(N);
     int ans = 0;
     for (int i = 0; i < N; i++) {
          int idx = sorted[i].second;
          int mxL = segTree.query(L[idx] + 1, idx-1);
          int mxR = segTree.query(idx+1, R[idx] - 1);
          int dp_val = 1 + max(mxL, mxR); ans = max(ans, dp_val);
          segTree.update(idx, dp_val);
     }
     cout << ans;

     return 0;
}
