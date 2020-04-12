#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[50][50];
bool visited[50][50];

bool findc(int i, int j, char src)
{
    if(i >= n||j>=m||i < 0||j <0 || arr[i][j] != src)
        return false;
    if(visited[i][j])
        return true;
    visited[i][j] = true;
    return findc(i+1,j,src)||findc(i,j+1,src);
}

int main()
{
    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    memset(visited,0,sizeof(visited));

    bool hc = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                if(findc(i,j,arr[i][j]))
                {
                    hc = true;
                    break;
                }
            }
        }
    }
    if(hc)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<"\n";
}