#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



vector<ll> factorize(ll n){
    vector<ll>ret = {1};
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            ret.push_back(i);
            if(n / i != i)
                ret.push_back(n / i);
        }
    }
    return ret;
}


int isPrime(int n){
    if(n < 2) return 0;
    if(n % 2 == 0 && n != 2) return 0;
    for(int i = 2;i*i<=n;i++)
        if(n % i == 0)
            return 0;
    return 1;
}



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n;
    while(cin >> n,n){
        if(isPrime(n)){
            ll perfect = ((1ll << n) - 1);
            vector<ll>x = factorize(perfect);
            ll res = accumulate(all(x),0ll);
            for(int i = 1;i< n;i++){
                res += (perfect * (1ll << (i-1))) + (1 << (n - i));
            }
            if(res == perfect * (1ll << (n-1))){
                cout << "Perfect: " << perfect * (1ll << (n-1)) << "!\n";
            }
            else{
                cout << "Given number is prime. But, NO perfect number is available.\n";
            }
        }
        else{
            cout << "Given number is NOT prime! NO perfect number is available.\n";
        }
    }

}