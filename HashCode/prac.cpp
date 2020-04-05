#include<bits/stdc++.h>
using namespace std;

int main(){
    int books,libraries,days;
    cin>>books>>libraries>>days;
    vector<int> prices(books);

    int i;
    for(i = 0; i < books; i++){
        cin>>prices[i];
    }

    vector<vector<pair<int,int>>> books_in_a_lib(libraries);
    vector<pair<int,long long int>> sums(libraries);
    vector<bool> visited(books,false);



    for(i = 0; i < libraries; i++){
        int bookc,signup_time,ship_per_day;
        cin>>bookc>>signup_time>>ship_per_day;
        int j;

        for(j = 0; j < bookc; j++){
            int value;
            cin>>value;
            books_in_a_lib[i].push_back({value,prices[value]});
        }

        sort(books_in_a_lib[i].begin(),books_in_a_lib[i].end(),[](pair<int,int> a, pair<int,int> b)->bool{
            return a.second>b.second;
        });

        long long int sum = 0;

        int day = days-signup_time;

        int k = 0;

        int booksc = bookc;

        while(day > 0 && books > 0){
            int size = ship_per_day;

            while(size>0&&k<bookc){
                sum+=prices[books_in_a_lib[i][k].first];
                k++;
                size--;
                bookc--;
            }
            day--;
        }

        sums[i] = {i,sum/days};
    }

    sort(sums.begin(),sums.end(),[](pair<int,long long int>a,pair<int,long long int>b)->bool{
        return a.second>b.second;
    });

    cout<<libraries<<endl;

    for(i = 0; i < libraries; i++){
        int size = books_in_a_lib[sums[i].first].size();
        cout<<sums[i].first<<" "<< size<<endl;

        long long int sumc = sums[i].second;

        vector<bool> printed(size,false);

        int j;
        for(j = 0; j < size; j++){
            if(!visited[books_in_a_lib[sums[i].first][j].first]){
                cout<<books_in_a_lib[sums[i].first][j].first<<" ";
                printed[j] = true;
                sumc -= prices[books_in_a_lib[sums[i].first][j].first];
                if(sumc>=0){
                    visited[books_in_a_lib[sums[i].first][j].first] = true;
                }
            }
        }

        for(j = 0; j < size; j++){
            if(!printed[j])
                cout<<books_in_a_lib[sums[i].first][j].first<<" ";
        }
        cout<<endl;
    }
}