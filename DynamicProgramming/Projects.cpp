#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

#define ll long long

struct Project{
   int l, r, p;
};
Project a[MAXN];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   
   int N; cin >> N;
   for (int i = 1; i <= N; i++) {
      cin >> a[i].l >> a[i].r >> a[i].p;
   }
   
   auto cmp = [](const Project& A, const Project& B) {
      return A.r < B.r;
   };
   sort(a+1, a+N+1, cmp);

   vector<ll> dp(N+5, 0);
   for (int i = 1; i <= N; i++) {
      int l = 0, r = i - 1;
      while (l < r) {
         int mid = l + (r - l + 1) / 2;
         if (a[mid].r < a[i].l) l = mid;
         else r = mid - 1;
      }
      dp[i] = max(dp[i-1], dp[l] + a[i].p);
   }

   cout << dp[N]; 
   return 0;
}
