#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1000 + 1;

vector<bool>isPrime(N,1);
vector<int>primes;

ll dp[N][N];

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i * i <= N;i++){
        if(isPrime[i]){
            for(int j = 2 * i;j < N;j+= i)
                isPrime[j] = 0;
        }
    }
    for(int i = 0;i<N;i++)
        if(isPrime[i])
            primes.push_back(i);
}

ll power(ll b,ll p){
    ll ret = 1;
    while(p){
        if(p & 1)
            ret *= b;
        b *= b;
        p >>= 1;
    }
    return ret;
}


ll solve(int idx,int rem){
    if(rem == 1)
        return 1;

    ll &res = dp[idx][rem];
    if(~res)
        return res;   
    res = 1e19;
    for(int i = 1;i<rem;i++){
        if(rem % (i + 1) == 0){
            if(pow(primes[idx],i) * solve(idx + 1,rem / (i + 1) ) > 2e18)
                continue;
            
            res = min(res,power(primes[idx],i) * solve(idx + 1,rem / (i + 1)));
        }
    }
    return res;
    
    
    
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;   
    memset(dp,-1,sizeof dp);
    sieve();
    int n;
    cin >> n;
    cout << solve(0,n) << endl;



}