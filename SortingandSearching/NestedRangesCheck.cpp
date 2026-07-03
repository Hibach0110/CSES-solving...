#include <bits/stdc++.h>
using namespace std;

struct Range {
     int x, y, id;
};

bool cmp(const Range& a, const Range& b) {
     if (a.y == b.y) return a.x > b.x;
     return a.y < b.y;
}


int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int N; cin >> N;
     vector<Range> a(N); for (int i = 0; i < N; i++) {cin >> a[i].x >> a[i].y; a[i].id = i;}

     sort(a.begin(), a.end(), cmp);

     vector<int> contained(N, 0), contains(N, 0);
     int mx_x = 0;
     for (int i = 0; i < N; i++) {
          contains[a[i].id] = (mx_x >= a[i].x ? 1 : 0);
          mx_x = max(mx_x, a[i].x);
     }
     
     int mn_x = 1e9+1;
     for (int i = N-1; i >= 0; i--) {
          contained[a[i].id] = (mn_x <= a[i].x ? 1 : 0);
          mn_x = min(mn_x, a[i].x);
     }

     for (int &x : contains) {cout << x << " ";} cout << "\n";
     for (int &x : contained) cout << x << " ";

     return 0;
}
