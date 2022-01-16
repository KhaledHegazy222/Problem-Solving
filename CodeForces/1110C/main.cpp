// #include <bits/stdc++.h>
// #define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
// #define all(a) a.begin(),a.end()

// typedef long long ll;
// typedef unsigned long long ull;

// using namespace std;



// ll factorize(ll n){
//     for(ll i = 2;i * i <= n;i++){
//         if(n % i == 0)
//             return n / i;
//     }
//     return -1;
// }


// signed main(void){

//     #ifdef Khaled
//         freopen("in.txt","r",stdin);
//         //freopen("out.txt","w",stdout);
//     #endif
//     #ifndef Khaled
//         #define endl '\n'
//         fast;
//     #endif
    
//     ll q;
//     cin >> q;
//     while(q--){
//         ll a;
//         cin >> a;
//         ll b = factorize(a);
//         if(!~b){
//             b = 1;
//         }
//         cout << __gcd(a^b,a & b) << endl;
//     }


    




// }


#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll factorize(ll n){
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0)
            return n / i;
    }
    return -1;
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
    
    ll q;
    cin >> q;
    while(q--){
        ll a;
        cin >> a;
        ll x = a;
        ll b = 0;
        ll fact = 1;
        while(x){
            if(!(x & 1)){  
                b += fact;
            }
            fact <<= 1;
            x >>= 1;
        }
        if(b){
            cout << __gcd(a^b,a & b) << endl;
        }
        else{
            b = factorize(a);
            if(~b){
                cout << __gcd(a^b,a & b) << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
    }


    




}







