#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        string S; cin >> S;
        int ans = 1, len = 1;
        for (int i=1; i<S.size(); i++) {
                if (S[i] == S[i-1]) ans = max(ans, ++len);
                else len = 1;
        }
        cout << ans;
        return 0;
}
