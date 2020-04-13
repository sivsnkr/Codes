#include<bits/stdc++.h>
using namespace std;

long long int p1,p2;
long long int arr[200001],arr1[200001];
int ac,bc;

int is()
{
    int size = min(ac,bc);
    for(int i = 0; i < size; i++)
    {
        if(arr[i]>arr1[i])
            return 0;
        else if(arr[i]<arr1[i])
            return 1;
    }

    if(ac==bc)
        return 2;
    else if(size == ac)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    bool lm;
    for(int i = 0; i < n; i++)
    {
        int p;cin>>p;
        lm = 0;
        if(p < 0)
        {
            p2+=(-p);
            arr1[bc++] = -p;
            lm = 1;
        }
        else
        {
            p1+=p;
            arr[ac++] = p;
        }
    }

    if(p1 > p2)
        cout<<"first";
    else if(p2 > p1)
        cout<<"second";
    else
    {
        if(is() == 0)
            cout<<"first";
        else if(is() == 1)
            cout<<"second";
        else
        {
            if(lm)
                cout<<"second";
            else
            {
                cout<<"first";
            }
        }
    }

    cout<<"\n";
    return 0;
}