// list all prime number upto n in o(n) time
#include<bits/stdc++.h>
using namespace std;


class Prime
{
    public:
    bool is_prime(int n)
    {
        if(n == 1)
            return false;
        for(int i = 2; i*i <= n; i++)
            if(n%i == 0)
                return false;

        return true;
    }

    vector<int> all_primes(int n)
    {
        vector<int> is_prime(n+1,0);
        vector<int> primelist;
        for(int i = 2; i <= n; i++)
        {
            if(is_prime[i] == 0)
            {
                is_prime[i] = i;
                primelist.push_back(i);
            }
            for(int j = 0; j < primelist.size()&&i*primelist[j]<=n&&primelist[j]<=is_prime[i]; j++)
            {
                is_prime[i*primelist[j]] = primelist[j];
            }
        }
        return primelist;
    }

    vector<int> primeFactors(int n)
    {
        vector<int> factorization;
        for (int d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            factorization.push_back(n);
        return factorization;
    }
};

int main()
{
    class Prime ps;
}