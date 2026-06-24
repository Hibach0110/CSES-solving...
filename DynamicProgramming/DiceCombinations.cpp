#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define v vector<ll> 
#define vp vector<pair<ll,ll>> 

const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;

void solve() {

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int N; cin >> N;
        ll f[N+5] = {0};
        f[0] = 1;
        for (int i=1; i<=N; i++) {
                for (int j=1; j<=6; j++) {
                        if (i-j>=0)
                                f[i] = (f[i] + f[i-j]) % mod;
                }
        }
        cout << f[N];
        return 0;
}
