
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

ull ncr(int n,int r){
    r = min(r,n - r);
        ull p = 1,k = 1;
        while(r)
        {
            p *= n;
            k *= r;
            ull g = __gcd(p,k);
            p/=g;
            k/=g;
            n--;r--;
        }
        return p / k;




}



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 



    int n,r;
    while(1){
        scanf("%d%d",&n,&r);
        if(!n && !r) return 0;
        printf("%lld\n",ncr(n,r));
    }
    
}

