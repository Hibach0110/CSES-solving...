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
        f[0] = 1;
        for (int i=0; i<N; i++) {
                for (int j=1; j<=X; j++) if(j>=c[i]) f[j] = (f[j] + f[j - c[i]]) % mod;
        }
        cout << f[X];
        return 0;
}
