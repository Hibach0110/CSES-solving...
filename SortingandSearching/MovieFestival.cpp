#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     vector<pair<int, int>> movies(N);
     for (int i = 0; i < N; i++) {
          int a, b; cin >> a >> b;
          movies[i] = {b, a};
     }

     sort(movies.begin(), movies.end());
     int cnt = 0, cur_end = 0;
     for (int i = 0; i < N; i++) {
          if (movies[i].second >= cur_end) {
               cnt++;
               cur_end = movies[i].first;
          }
     }

     cout << cnt;

     return 0;
}
