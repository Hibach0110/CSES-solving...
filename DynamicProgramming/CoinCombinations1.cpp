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
        int N,X; cin >> N >> X;
        vector<int> c(N);
        for (int i=0; i<N; i++) cin >> c[i];

        vector<ll> f(X+5, 0);
        f[0]=1;
        for (int i=1; i<=X; i++) {
                for (int j=0; j<N; j++) {
                        if (i >= c[j]) f[i] = (f[i] + f[i - c[j]]) % mod;
                }
        }
        cout << f[X];
        return 0;
}
