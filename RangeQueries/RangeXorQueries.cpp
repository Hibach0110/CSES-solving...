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

     void build(const vector<T>& arr) {
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
               tree[idx] ^= delta;
          }
     }

     T query(int idx) {
          T sum = 0;
          for (; idx > 0; idx -= lowbit(idx)) {
               sum ^= tree[idx];
          }
          return sum;
     }

     T rangeQuery(int left, int right) {
          if (left > right) return 0;
          return query(right) ^ query(left - 1);
     }
};


int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, Q; cin >> N >> Q;
     vector<int> a(N); for (int &x : a) cin >> x;

     FenwickTree<int> bit(N); for (int i = 0; i < N; i++) bit.add(i+1, a[i]);

     while (Q--) {
          int l, r; cin >> l >> r;
          cout << bit.rangeQuery(l, r) << "\n";
     }

     return 0;
}
