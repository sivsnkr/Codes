#include<bits/stdc++.h>
using namespace std;

void shift(char a[], int i, int size)
{
    int j = i;
    while(j+1 < size)
    {
        a[j-1] = a[j+1];
        j++;
    }
}

int main()
{
    char a[200],b[200];
    cin>>a>>b;

    int l1 = -1,l2 = -1;
    for(int i = 0; i < strlen(a); i++)
    {
        if(a[i] != '#')
        {
            a[++l1] = a[i];
        }
        else
        {
            if(l1-1 >= -1)
                l1--;
        }
    }

    for(int i = 0; i < strlen(b); i++)
    {
        if(b[i] != '#')
        {
            b[++l2] = b[i];
        }
        else
        {
            if(l2-1 >= -1)
                l2--;
        }
    }

    cout<<l1<<" "<<l2<<"\n";
    bool isvalid = true;
    if(l1 != l2)
        isvalid = false;
    else
    {
        for(int i = 0; i <= l1; i++)
        {
            if(a[i] != b[i])
            {
                isvalid = false;
                break;
            }
        }
    }

    isvalid?cout<<"true":cout<<"false";
    cout<<"\n";
}