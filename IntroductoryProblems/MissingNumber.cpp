#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n; cin >> n;
        int xr = 0;
        for (int i = 1; i <= n; i++) xr ^= i;
        for (int i = 1; i < n; i++) {
                int x; cin >> x; xr ^= x;
        }
        cout << xr;
        return 0;
}
