


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
    ll n;
    cin >> n;
    ll l = 1;
    ll a = 0;
    ll b = 1;
    ll c;
    for(ll i = 0;i<=n * n;i++){
        c = a + b;
        c %= n;
        a = b;
        b = c;
        if (a == 0 && b == 1){
            break;
        }
        l++;
    }
    if (n == 1){
        l = 1;
    }
    cout << l << endl;
    
}   