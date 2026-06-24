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
        vector<ll> f(N+5, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= N; i++) {
                int cl = i;
                while (cl) {
                        f[i] = min(f[i], f[i - cl % 10] + 1);
                        cl /= 10;
                }
        }
        cout << f[N];
        return 0;
}
