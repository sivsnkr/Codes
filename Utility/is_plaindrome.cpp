#include<iostream>

bool isplain(std::string s)
{
    int st = 0,e = s.length()-1;
    while(st < e)
    {
        if(s[st] != s[e])
            return false;
        st++,e--;
    }
    return true;
}

int main()
{
    std::string st;std::cin>>st;
    bool isp = isplain(st);
    std::cout<<isp<<std::endl;
}