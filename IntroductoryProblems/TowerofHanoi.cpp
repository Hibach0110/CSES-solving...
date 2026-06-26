#include <bits/stdc++.h>
using namespace std;

void doit(int N, int a, int b, int c) {
     if (N == 0) return;
     doit(N-1, a, c, b);
     cout << a << " " << c << "\n";
     doit(N-1, b, a, c);
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     int N; cin >> N;
     cout << (1<<N) - 1 << "\n";

     doit(N, 1, 2, 3);

     return 0;
}
