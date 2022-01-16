

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;
using namespace std;



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int n,m,b;
    while(cin >> n >> m >> b && n){
        ll pairs = 0;
        if(b){
            pairs += ((1ll * max(0,n-7) * max(0,m-7))+1)/2;
        }   
        else{
            pairs +=  ((1ll * max(0,n-8) * max(0,m-7))+1)/2;
            pairs += (max(0,m-8)+1) / 2;
        }
        cout << pairs << '\n';
    }

    

}   