

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    ll a,b,z;
    cin >> a >> b >> z;
    ll x = max(a,b);
    a = min(a,b);
    b = x;  
    ll c2 = (b/z) * z;
    ll c1 = ((a+z-1)/z) * z;
    if(c2 < c1){
        cout << 0 << endl;
    }
    else {
        ll n = (c2-c1)/z + 1;
        ll sum = n*(c2 + c1)/2;
        cout << sum << endl;
    }
}
