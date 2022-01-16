

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
  
ll count(ll n) 
{ 
    return ll((-1 + sqrt(1 + 8 * n)) / 2); 
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
    cout << count(n); 
  
    return 0; 
} 