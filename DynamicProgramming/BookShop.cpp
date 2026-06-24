#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define v vector<ll> 
#define vv vector<vector<ll>>
#define vp vector<pair<ll,ll>> 

const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;

void solve() {

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int N, X; cin >> N >> X;
        v h(N), s(N);
        for (int i = 0; i < N; i++) cin >> h[i];
        for (int i = 0; i < N; i++) cin >> s[i];
        v f(X+5, 0);
        for (int i = 0; i < N; i++) {
                for (int j = X; j >= 1; j--) {
                        if (j >= h[i]) f[j] = max(f[j], f[j - h[i]] + s[i]);
                }
                for (int j = 1; j <= X; j++) f[j] = max(f[j], f[j - 1]);
                // for (int j = 1; j <= X; j++) cout << f[j] << " \n"[j == X];
        }
        cout << f[X];
        return 0;
}
