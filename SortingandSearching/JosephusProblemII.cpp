#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> bit;

void update(int idx, int val) {
     for (; idx <= N; idx += idx & -idx) {
          bit[idx] += val;
     }
}

int find_kth(int k) {
     int idx = 0;
     for (int i = 1<<__lg(N); i > 0; i >>= 1) {
          if (idx + i <= N && bit[idx + i] < k) {
               idx += i;
               k -= bit[idx];
          }
     }
     return idx+1;
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int K; cin >> N >> K;
     bit.assign(N+1, 0); for (int i = 1; i <= N; i++) update(i, 1);
     
     int cur_pos = 0;
     for (int remain = N; remain > 0; remain--) {
          cur_pos = (cur_pos + K) % remain;
          int idx = find_kth(cur_pos + 1);
          cout << idx << " ";
          update(idx, -1);
     }

     return 0;
}
