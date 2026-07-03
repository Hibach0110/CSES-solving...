#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N, K; cin >> N >> K; 
     vector<int> a(N); for (int &x : a) cin >> x;

     map<int, int> freq;
     int64_t ans = 0; int left = 0;
     for (int i = 0; i < N; i++) {
          freq[a[i]]++;
          while (freq.size() > K) {
               freq[a[left]]--;
               if (freq[a[left]] == 0) {
                    freq.erase(a[left]);
               }
               left++;
          }
          ans += i - left + 1;
     }
     cout << ans;

     return 0;
}
