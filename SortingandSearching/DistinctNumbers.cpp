#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     int N; cin >> N;
     set<int> s;
     for (int i = 1; i <= N; i++) {
          int x; cin >> x; s.insert(x);
     }
     cout << s.size();
     return 0;
}
