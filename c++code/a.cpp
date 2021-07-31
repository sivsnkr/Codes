#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro

class Employee{
    string Name;
    string Company;
    int Age;
    public:
        Employee(){
            Name = "John Doe";
            Company = "Default Company";
            Age = 25;
        }

        Employee(string name, string company, int age){
            Name = name, Company = company, Age = age;
        }

        void intro(){
            cout<<"Name: "<<Name<<NL;
            cout<<"Company: "<<Company<<NL;
            cout<<"Age: "<<Age<<NL;
        }
};

class Developer : public Employee{
    string FavProgrammingLanguage;
    public:
        Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name, company, age){
            FavProgrammingLanguage = favProgrammingLanguage;
        }

        void setFavProgrammingLanguage(string language){
            FavProgrammingLanguage = language;
        }

        string getFavProgrammingLanguage(){
            return FavProgrammingLanguage;
        }
};

inline void solve()
{
    class Developer st("Shiv Shankar", "KLA", 25, "C++");
    st.intro();

    Developer *e1 = &st;
    e1->intro();

    st.setFavProgrammingLanguage("python");
    cout<<"my fav programming language: "<<st.getFavProgrammingLanguage()<<NL;
}

int32_t main()
{
    clock_t startTime;
    startTime = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    int t = 1;
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
