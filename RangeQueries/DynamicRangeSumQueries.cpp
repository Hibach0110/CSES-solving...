#include <bits/stdc++.h>
using namespace std;

template <typename T>
class FenwickTree {
private:
     int n;
     vector<T> tree;

     inline int lowbit(int x) {
          return x & (-x);
     }

public:
     FenwickTree(int size) : n(size), tree(size + 1, 0) {}

     void build(const vector<int>& arr) {
          n = arr.size();
          tree.assign(n + 1, 0);
          for (int i = 1; i <= n; i++) {
               tree[i] += arr[i - 1];
               int parent = i + lowbit(i);
               if (parent <= n)
                    tree[parent] += tree[i];
          }
     }

     void add(int idx, T delta) {
          for (; idx <= n; idx += lowbit(idx)) {
               tree[idx] += delta;
          }
     }

     T query(int idx) {
          T sum = 0;
          for (; idx > 0; idx -= lowbit(idx)) {
               sum += tree[idx];
          }
          return sum;
     }

     T rangeQuery(int left, int right) {
          if (left > right) return 0;
          return query(right) - query(left - 1);
     }
};


int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, Q; cin >> N >> Q;
     vector<int> a(N); for (int &x : a) cin >> x;

     FenwickTree<int64_t> bit(N); bit.build(a);

     while (Q--) {
          int type; cin >> type;
          if (type == 1) {
               int k, u; cin >> k >> u; 
               int64_t diff = u - a[k-1];
               a[k-1] = u;
               bit.add(k, diff);
          } else {
               int a, b; cin >> a >> b;
               cout << bit.rangeQuery(a, b) << "\n";
          }
     }

     return 0;
}
