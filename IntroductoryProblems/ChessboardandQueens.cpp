#include <bits/stdc++.h>
using namespace std;

char c[8][8];
bool col[8], diag1[15], diag2[15]; //diag1: anti-diagonal ... diag2: main_diagonal
int ans = 0;

void placeQueens(int r) {
     if (r == 8) {
          ans++; return;
     }
     for (int j = 0; j < 8; j++) {
          if (c[r][j] == '*') continue;
          if (!col[j] && !diag1[r+j] && !diag2[r-j+7]) {
               col[j] = 1; diag1[r+j] = 1; diag2[r-j+7] = 1;
               //place...
               placeQueens(r + 1);
               
               col[j] = 0; diag1[r+j] = 0; diag2[r-j+7] = 0;
          }
     }
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     for (int i = 0; i < 8; i++) {
          for (int j = 0; j < 8; j++) {
               cin >> c[i][j];
          }
     }

     placeQueens(0);
     cout << ans;

     return 0;
}
