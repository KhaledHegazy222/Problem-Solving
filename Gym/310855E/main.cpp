
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;



int main(void){
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    int t;
    scanf("%lld",&t);
    while (t--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",n*(n+1)*(2*n+1)/6);
    }
    
}