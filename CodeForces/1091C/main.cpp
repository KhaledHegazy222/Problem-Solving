#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<ll> devisors(ll n){
    vector<ll>ret;

    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ret.push_back(i);
            if(n / i != i)
                ret.push_back(n / i);
        }
    }
    sort(all(ret),greater<ll>());
    return ret;

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
    
    ll n;
    cin >> n;
    auto d = devisors(n);


    for(auto elem : d){
        cout << (2 + (n / elem - 1) * elem)*(n / elem) / 2 << " ";
    }
    cout << endl;




}


