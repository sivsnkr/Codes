#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int h,w;cin>>h>>w;
    vector<vector<char>> grid(h,vector<char>(w));

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            scanf("%c", &grid[i][j]);
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    return 0;
}