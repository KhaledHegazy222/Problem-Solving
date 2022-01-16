#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1000000 + 5;

int com[N];

int fact(int n){
    int cnt = 0;
    for(int i = 2;i * i <= n;i++)
        while(n % i == 0){
            cnt++;
            n /= i;
        }

    if(n - 1)
        cnt++;

    return cnt;
}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif


    // sieve();
    for(int i = 1;i<N;i++)
        com[i] = com[i - 1] + fact(i);
    ll n;
    while(cin >> n){
        // ll ret = 0;
        // for(ll i = 0;i < primes.size() && primes[i] <= n;i++)
        //     ret += solve(n,primes[i]);
        // cout << ret << endl;
        cout << com[n] << endl;
    }
    
    


}


