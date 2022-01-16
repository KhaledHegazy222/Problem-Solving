#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 1e4 + 5;

ll sumDigits(ll n){
    ll sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
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
    vector<ll>res;
    for(ll i = 19;res.size() < N;i++){
        if(sumDigits(i) == 10)
            res.push_back(i);
    }
    ll n;
    cin >> n;
    n--;
    cout << res[n] << endl;
}


