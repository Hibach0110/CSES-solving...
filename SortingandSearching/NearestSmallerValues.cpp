#include <bits/stdc++.h>
using namespace std;

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N; vector<int> a(N+5); stack<int> st;
     for (int i = 1; i <= N; i++) {
          cin >> a[i];
          while (!st.empty() && a[st.top()] >= a[i]) st.pop();
          cout << (st.empty() ? 0 : st.top()) << " ";
          st.push(i);
     }

     return 0;
}
