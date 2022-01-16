#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 52000 + 5;
vector<bool>isPrime(N,1);
vector<int>primes;

void sieve(){
    isPrime[0] = isPrime[1] = 0;

    for(int i = 2;i*i < N ;i++)
        if(isPrime[i])
            for(int j = 2 * i;j < N;j += i)
                isPrime[j] = 0;

    for(int i = 0;i<N;i++)
        if(isPrime[i])
            primes.push_back(i);
}







int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    sieve();
    int l,r;
    while(cin >> l >> r){
        if(!l && !r)
            return 0;
        if(l > r)
            swap(l,r);
        for(int i = 0;i<primes.size();i++){
            if(primes[i] >= l){
                l = i;
                break;
            }
        }
        for(int i = primes.size() - 1;i >= 0;i--){
            if(primes[i] <= r){
                r = i;
                break;
            }
        }
        for(int i = l + 2;i<=r;){
            if(primes[i] - primes[i - 1] == primes[i - 1] - primes[i - 2]){
                int dist = primes[i] - primes[i - 1];
                if(i == 2 || primes[i-2] - primes[i-3] != dist){
                    vector<int>x = {primes[i - 2],primes[i-1]};
                    while(i <= r && primes[i] - primes[i-1] == dist){
                        x.push_back(primes[i++]);
                    } 
                    if( primes[i] - primes[i-1] == primes[i-1] - primes[i - 2]){
                        i++;
                    }
                    else{
                        for(int i = 0;i<x.size();i++)
                            cout << x[i] << " \n"[i + 1 == x.size()];                                        
                    }
                }
                else
                    i++;
            }
            else{
                i++;
            }
        }
        
    }


}