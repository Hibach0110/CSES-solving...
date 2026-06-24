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
        int N; cin >> N;
        string S[N];
        for (int i = 0; i < N; i++) cin >> S[i];
        
        vv f(N, v(N, 0));
        f[0][0] = (S[0][0] == '*' ? 0 : 1);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (i == 0 && j == 0) continue;
                        if (S[i][j] == '*') continue;
                        if (i == 0) f[i][j] = f[i][j - 1];
                        else if (j == 0) f[i][j] = f[i - 1][j];
                        else f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
                }
        }
        // for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cout << f[i][j] << " \n"[j == N-1];
        cout << f[N-1][N-1];
        return 0;
}
