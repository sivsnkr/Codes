#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

bool valid(tuple<int,int,int> temp)
{
    int a = get<0>(temp),b = get<1>(temp),c = get<2>(temp);
    if(a==b||a==c||b==c)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    scanf("%d",&t);
    while(t > 0)
    {
        int n,k;
        scanf("%d%d",&n,&k);

        vector<tuple<int,int,int>> ma(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&get<0>(ma[i]));
            get<1>(ma[i]) = i;
        }
        vector<int> sma(n);
        transform(ma.begin(),ma.end(),sma.begin(),[](tuple<int,int,int> a)->int{
            return get<0>(a);
        });
        sort(sma.begin(),sma.end());
        unordered_map<int,int> in,ns;
        for(int i = 0; i < n; i++)
        {
            in[sma[i]] = i;
            ns[get<0>(ma[i])] = i;
        }
        vector<tuple<int,int,int>> prt;
        set<int> na;
        for(int i = 0; i < n; i++)
        {
            get<2>(ma[i]) = in[get<0>(ma[i])];
            if(get<2>(ma[i]) != get<1>(ma[i]))
            {
                na.insert(get<1>(ma[i]));
            }
        }
        int i;
        
        for(i = 0; i < n && k >= 0; i++)
        {
            if(get<1>(ma[i]) != get<2>(ma[i]))
            {
                tuple<int,int,int> temp;
                get<0>(temp) = i;
                get<1>(temp) = in[get<0>(ma[i])];
                get<2>(temp) = ns[sma[i]];
                // printf("%d %d %d\n",get<0>(temp),get<1>(temp),get<2>(temp));

                if(!valid(temp))
                {
                    // printf("i at : %d\n",i);
                    puts("-1");
                    return 0;
                }
                int a = get<0>(temp),b = get<1>(temp),c = get<2>(temp);
                ma[c] = ma[b];
                get<1>(ma[c]) = c;
                ma[b] = ma[a];
                get<1>(ma[b]) = b;
                get<0>(temp)++,get<1>(temp)++,get<2>(temp)++;
                prt.push_back(temp);
                k--;
            }
        }
        if(i != n)
        {
            // printf("i at bo : %d\n",i);
            puts("-1");
        }
        else
        {
            int size = prt.size();
            printf("%d\n",size);
            for(int i = 0; i < size; i++)
            {
                printf("%d %d %d\n",get<0>(prt[i]),get<1>(prt[i]),get<2>(prt[i]));
            }
        }
        t--;
    }
    return 0;
}