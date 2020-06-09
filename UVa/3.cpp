/* 8 Queens Chess Problem */
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int row[9], TC, a, b, lineCounter; // it is ok to use global variables in competitive programming

bitset<30> rw, ld, rd;
int n,ans;
char board[15][15];
void backtrack(int c) {
    if (c == n) {
        for(int i = 0; i < n; i++)
            cout<<row[i]<<" ";
        cout<<endl;
        ans++; 
        return; 
    }
    // a solution for (int r = 0; r < n; r++) // try all possible row
    for (int r = 0; r < n; r++)
        if (board[r][c] != '*' && !rw[r] && !ld[r - c + n - 1] && !rd[r + c]) 
        { 
            row[c] = r;
            rw[r] = ld[r - c + n - 1] = rd[r + c] = true; // flag off backtrack(c + 1);
            backtrack(c + 1);
            rw[r] = ld[r - c + n - 1] = rd[r + c] = false; // restore
        }
}

int main() {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
      for(int j = 0; j < n; j++)
      {
          cin>>board[i][j];
      }
  }
  backtrack(0);
  cout<<ans<<endl;
  return 0;
}