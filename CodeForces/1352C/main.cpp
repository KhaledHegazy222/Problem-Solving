
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
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll l = 1;
        ll r = 1e10;
        while(1){
            ll middle = (l+r)/2;
            if(middle % n == 0){
                middle++;
            }
            ll pos = middle - (middle/n); 
            if(pos == k){
                cout << middle << endl;
                break;
            }
            else if(pos > k){
                r = middle - 1;
            }
            else{
                l = middle + 1;
            }
        }
    }



}




