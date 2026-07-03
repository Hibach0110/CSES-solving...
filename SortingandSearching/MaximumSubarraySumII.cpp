#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N, A, B; cin >> N >> A >> B;
     vector<int> x(N); for (int &X : x) cin >> X;
     vector<int64_t> p(N+1, 0); for (int i = 1; i <= N; i++) p[i] = p[i-1] + x[i-1];

     int64_t mx_sum = -1e18;
     multiset<int64_t> ms;
     for (int i = A; i <= N; i++) {
          ms.insert(p[i - A]);
          if (i > B) {
               ms.erase(ms.find(p[i-B-1]));
          }
          int64_t cur_sum = p[i] - *ms.begin();
          mx_sum = max(mx_sum, cur_sum);
     }
     cout << mx_sum;

     return 0;
}
