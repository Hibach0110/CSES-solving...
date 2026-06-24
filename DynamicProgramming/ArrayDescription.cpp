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
        int N, M; cin >> N >> M;
        v a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        vv dp(N, v(M+5, 0));
        
        if (a[0] != 0) dp[0][a[0]] = 1;
        else for (int j = 1; j <= M; j++) dp[0][j] = 1;

        for (int i = 1; i < N; i++) {
                if (a[i] != 0) {
                        int j = a[i];
                        for (int prev = j-1; prev <= j+1; prev++) {
                                if (prev >= 1 && prev <= M) {
                                        dp[i][j] = (dp[i][j] + dp[i-1][prev]) % mod;
                                }
                        }
                } else {
                        for (int j = 1; j <= M; j++) {
                                for (int prev = j-1; prev <= j+1; prev++) {
                                        if (prev >= 1 && prev <= M) {
                                                dp[i][j] = (dp[i][j] + dp[i-1][prev]) % mod;
                                        }
                                }
                        }
                }
        }

        ll ans = 0;
        if (a[N-1] != 0) ans = dp[N-1][a[N-1]];
        else for (int j = 1; j <= M; j++) ans = (ans + dp[N-1][j]) % mod;

        cout << ans;
        return 0;
}
