#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e4 + 5;
vector<bool>isPrime(N,1);
vector<int>primes;
void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i * i < N;i++)
        if(isPrime[i])
            for(int j = 2 * i;j<N;j += i)
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int res = -1;
        int resP = -1;
        for(int i = 0;i<primes.size();i++){
            int x = primes[i];
            int p = n / x;
            if(p && p * x <= n && (p + 1) * x > n){
                if(res < n - p * x){
                    res = n - p * x;
                    resP = x;
                }
            }
        }
        cout << resP << endl;
    }


}