#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     using ll = long long;

     int N; cin >> N;
     ll nums = 1;
     for (int i = 1; i <= N; i++) {
          nums = nums * 2 % mod;
     }

     cout << nums;

     return 0;
}
