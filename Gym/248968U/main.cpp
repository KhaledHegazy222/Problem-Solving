
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
ll zeros(ll n) { 
    ll count = 0; 
  
    for (ll i = 5; n / i >= 1; i *= 5) 
        count += n / i; 
  
    return count; 
} 
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

    cout << zeros(n) << endl;
    
}