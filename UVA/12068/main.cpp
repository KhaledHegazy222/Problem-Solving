



#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

ll lcm(ll a,ll b){
    return a / __gcd(a,b) * b;
}


int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int t;
    cin >> t;

    int cs = 1;
    while(t--){
        int n;
        cin >> n;
        ll arr[n];
        ll lcm_ = 0;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
            if(!i)
                lcm_ = arr[i];
            else
                lcm_ = lcm(lcm_,arr[i]);
        }
        ll d = 0;
        for(int i = 0;i<n;i++){
            d += (lcm_/arr[i]);
        }
        ll m = lcm_ * n;
        ll g = __gcd(m,d); 
        m /= g;
        d /= g;
        cout << "Case " << cs++ << ": " << m << "/" << d << endl;
    }




}
