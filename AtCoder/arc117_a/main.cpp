#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    ll a,b;
    cin >> a >> b;
    vector<ll>A(a);
    vector<ll>B(b);
    iota(all(A),1);
    iota(all(B),1);
    cin >> a >> b;
    if(a > b){
        B.back() = accumulate(all(A),0ll) - accumulate(all(B),0ll) + B.back();
    } 
    else{
        A.back() = accumulate(all(B),0ll) - accumulate(all(A),0ll) + A.back();
    }
    for(auto elem : A)
        cout << elem << " ";
    for(auto elem : B)
        cout << -elem << " ";
    cout << endl;
    // cout << accumulate(all(A),0ll) - accumulate(all(B),0ll) << endl;
}


