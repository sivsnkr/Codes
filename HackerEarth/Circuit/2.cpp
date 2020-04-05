#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<pair<int,int>> test;
    test.insert({1,2});
    test.insert({2,3});

    if(test.find({1,2}) != test.end())
    {
        test.erase({1,2});
        cout<<"Erased"<<endl;
    }

    cout<<test.size()<<endl;
}