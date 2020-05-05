#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

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
                na.erase(ns[sma[i]]);
                tuple<int,int,int> temp;
                while(!na.empty()&&get<1>(ma[*na.begin()])==get<2>(ma[*na.begin()]))
                {
                    na.erase(na.begin());
                }
                if(na.empty())
                {
                    // printf("i %d\n",i);
                    // puts("1st check");
                    puts("-1");
                    return 0;
                }
                get<0>(temp) = *na.begin();
                na.erase(na.begin());
                while(!na.empty()&&get<1>(ma[*na.begin()])==get<2>(ma[*na.begin()]))
                {
                    na.erase(na.begin());
                }
                if(na.empty())
                {
                    // printf("i %d\n",i);
                    // puts("2nd check");
                    puts("-1");
                    return 0;
                }
                get<1>(temp) = *na.begin();
                na.erase(na.begin());
                get<2>(temp) = ns[sma[i]];
                // printf("formed tuple = (%d %d %d)",get<0>(temp),get<1>(temp),get<2>(temp));
                // rotate
                ma[get<2>(temp)] = ma[get<1>(temp)];
                get<1>(ma[get<2>(temp)]) = get<2>(temp);
                ma[get<1>(temp)] = ma[get<0>(temp)];
                get<1>(ma[get<1>(temp)]) = get<1>(temp);

                if(get<1>(ma[get<2>(temp)]) != get<2>(ma[get<2>(temp)]))
                {
                    // printf("inserting %d\n",get<1>(ma[get<2>(temp)]));
                    na.insert(get<1>(ma[get<2>(temp)]));
                }
                if(get<1>(ma[get<1>(temp)]) != get<2>(ma[get<1>(temp)]))
                {
                    // printf("inserting %d\n",get<1>(ma[get<1>(temp)]));
                    na.insert(get<1>(ma[get<1>(temp)]));
                }
                get<0>(temp)++;
                get<1>(temp)++;
                get<2>(temp)++;
                prt.push_back(temp);
                k--;
                // printf("unsorted indexm\n");
                // for(int a : na)
                // {
                //     printf("%d ",a);
                // }
                // printf("\n");
            }
            ns.erase(i);
        }
        if(i != n)
        {
            // printf("i %d\n",i);
            // puts("3rd check");
            puts("-1");
        }
        else
        {
            printf("%d\n",int(prt.size()));
            int size = prt.size();
            for(int i = 0; i < size; i++)
            {
                printf("%d %d %d\n",get<0>(prt[i]),get<1>(prt[i]),get<2>(prt[i]));
            }
        }
        t--;
    }
    return 0;
}