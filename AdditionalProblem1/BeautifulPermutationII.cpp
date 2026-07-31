#include <bits/stdc++.h>
using namespace std;

vector<int> res, ele;

void backtrack() {
     if (ele.empty()) {
          for (int x : res) cout << x << " ";
          exit(0);     
     }
     for (int i = ele.size()-1; i >= 0; i--) {
          int x = ele[i];
          if (res.empty() || abs(res.back() - x) != 1) {
               ele.erase(ele.begin() + i);
               res.push_back(x);
               backtrack();
               res.pop_back();
               ele.insert(ele.begin() + i, x);
          }
     }
}

void solve() {
     int n; cin >> n;
     if (n == 2 || n == 3) {
          cout << "NO SOLUTION"; return;
     }
     for(int i = n; i >= 1; i--) ele.push_back(i);
     backtrack();
}

int main() {
     cin.tie(0)->sync_with_stdio(0);
     solve();
     return 0;
}
