#include<bits/stdc++.h>
using namespace std;

// this programme gives kth plaindrome number greater than k
void kthPlaindrome(long int n, long int k, long int sum, long int i,int s[]){
    s[0] = 1;
    long int j;
    for(j = 1; j <= i-2; j++){
        s[j] = 0;
    }

    s[i-1] = 1;

    k-=sum;

    for(j = 0; j <= (i-1)/2; j++){
        if(j == 0){            s[0] = ceil(double(k)/pow(10,(i-1)/2));
            k-=(s[0]-1)*pow(10,(i-1)/2);
        }else{            s[j] = ceil(double(k)/pow(10,(i-1)/2-j))-1;
            k-=(s[j]*pow(10,(i-1)/2-j));
        }
    }

    for(j = 0; j < i/2; j++){
        s[i-j-1] = s[j];
    }
}

long long int decodePlainDrome(long long int n){
    string s = to_string(n);
    int length = s.length();

    long long int sum = 1;
    int i;
    for(i = 1; i < length; i++){
        sum+=9*pow(10,(i-1)/2);
    }

    int power = ceil(double(length)/2)-1;

    for(i = 0; i <= ceil(double(length)/2)-1; i++){
        int num = s[i]-48;
        if(i == 0){
            sum+=(num-1)*pow(10,power);
        }else{
            sum+=num*pow(10,power);
        }
        power--;
    }

    return sum;
}

bool isPlain(long int n){
    string s = to_string(n);

    int size = s.length();
    for(int i = 0; i < size/2; i++){
        if(s[i]!=s[size-i-1]){
            return false;
        }
    }

    return true;
}

long long int giveNearstPlain(long long int x){
    string s = to_string(x);
    string t = "";
    int size = s.length();

    int i;

    for(i = 0; i <= (size-1)/2; i++){
        t+=s[i];
    }

    for(i = size/2-1; i >= 0; i--){
        t+=s[i];
    }

    long long int num = stoll(t);

    if(num>x){
        return decodePlainDrome(x)-1;
    }else{
        return decodePlainDrome(x);
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        long int x,k;
        cin>>x>>k;

        if(isPlain(x))
            k--;

        long long int index = giveNearstPlain(x);
        k+=index;
        long int sum = 0;
        long int i = 1;
        while(1){
            long int res = 9*pow(10,(i-1)/2);
            if(sum+res < k)
                sum+=res;
            else
                break;
            i++;
        }

        int s[i];

        kthPlaindrome(1,k,sum,i,s);

        int j;

        for(j = 0; j < i; j++){
            cout<<s[j];
        }
        cout<<endl;
    }}
}