#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define NL "\n"
#define all(x) x.begin(), x.end()

const int SS = 100000;
const int VV = 1000;
int d, i, s, v, f;
map<int, string> int_str;
map<string, int> str_int;
map<int,int> street_time;
vector<pair<int, int>> intersection[SS];
vector<int> v_paths[VV];
vector<bool>valid_car(VV,true);
vector<int> sum(SS,0);

vector<pair<int,int>> intersection_with_traffic_shedule[SS];

void remove()
{
    int min_time;
    for(int i=0; i<v; i++)
    {
        min_time=0;
        for(int j=0; j<v_paths[i].size(); j++)
        {
            min_time+=street_time[v_paths[i][j]];
        }
        if(min_time>d) valid_car[i]=false;
    }
}

inline void SOLVE()
{
    // Convert your toughts into code here.

    cin >> d >> i >> s >> v >> f;
    for (int rep = 0; rep < s; rep++)
    {
        int b, e;
        cin >> b >> e;
        string road;
        cin >> road;
        int l;
        cin >> l;
        int_str[str_int.size()] = road;
        str_int[road] = str_int.size();
        street_time[str_int[road]]=l;
        // intersection.emplace_back(b,e);
        intersection[e].push_back(make_pair(b, str_int[road]));
    }

    for (int rep = 0; rep < v; rep++) {
        int path_cnt;
        cin >> path_cnt;
        for (int path = 0; path < path_cnt; path++) {
            string road;
            cin >> road;
            v_paths[rep].push_back(str_int[road]);
            // intersection[e].push_back(make_pair(b, str_int[road]));
        }
    }

    remove();

    map<int,int> valid_street;
    for(int car_number = 0; car_number < v; car_number++)
    {
        if(valid_car[car_number])
        {
            for(int paths = 0; paths < (int)v_paths[car_number].size(); paths++)
            {
                valid_street[v_paths[car_number][paths]]++;
            }
        }
    }

    vector<vector<int>> intersection_stree(i);

    for(int iter = 0; iter < i; iter++)
    {
        for(int it = 0; it < (int)intersection[iter].size(); it++)
        {
            intersection_stree[iter].push_back(intersection[iter][it].second);
        }
    }

    for(int it = 0; it < v; it++)
    {
        for(int paths = 0; paths < (int)v_paths[it].size()-1; paths++)
        {
            // sum[v_paths[it][paths]]+=((int)v_paths[it].size()-1-paths-1);
            for(int for_paths = paths+1; for_paths < (int)v_paths[it].size()-1; for_paths++)
            {
                sum[v_paths[it][paths]]+=street_time[v_paths[it][for_paths]];
            }
        }
    }

    // for(int it = 0; it < i; it++)
    // {
    //     if(valid_street[it] > 0)
    //         sum[it]/=valid_street[it];
    // }

    for(int it = 0; it < i; it++)
    {
        vector<pair<int,int>> temp;
        for(int street_n = 0; street_n < (int)intersection_stree[it].size(); street_n++)
        {
            if(valid_street[intersection_stree[it][street_n]] != 0)
            {
                // intersection_with_traffic_shedule[it].emplace_back(intersection_stree[it][street_n],valid_street[intersection_stree[it][street_n]]);
                temp.emplace_back(sum[intersection_stree[it][street_n]],intersection_stree[it][street_n]);
            }
        }
        sort(all(temp));
        int c=1;
        int jump = ((int)temp.size()+3)/4;
        for(int it1 = 0; it1 < (int)temp.size(); it1+=jump)
        {
            c++;
            for(int local_it = it1; local_it < min(it1+jump,(int)temp.size()); local_it++)
                intersection_with_traffic_shedule[it].emplace_back(temp[local_it].second,(valid_street[temp[local_it].second]+c-1)/c);
        }
    }


    // Output

    int cnt = 0;
    for(int iter = 0; iter<i; iter++)
    {
        if(intersection_with_traffic_shedule[iter].size()){
            cnt++;
        }
    }

    cout<<cnt<<NL;


    for(int iter = 0; iter<i; iter++)
    {
        if(intersection_with_traffic_shedule[iter].size()){
            cout<<iter<<NL;
            cout<<(int)intersection_with_traffic_shedule[iter].size()<<NL;
            for(int path=0; path<(int)intersection_with_traffic_shedule[iter].size(); path++){
                cout<<int_str[intersection_with_traffic_shedule[iter][path].first]<<" "<<intersection_with_traffic_shedule[iter][path].second<<NL;
            }
        }
    }
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    SOLVE();
    return 0;
}
