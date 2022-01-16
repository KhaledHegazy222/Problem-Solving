
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
    ll a,b,c;
    cin >> a >> b >> c;
    ll dif = b - a;
    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        if(x < a){
            cout << "NO\n";
            continue;
        }
        x-= a;
        if(x % dif == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}