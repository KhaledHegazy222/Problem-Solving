


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MOD ((ll)1e9+7)

using namespace std;


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    int x;
    cin >> x;
    if(x < 2){
        cout << 1 << endl;
    }
    else{

        double d = 0;
        for(int i = 2;i<=x;i++){
            d += log10(i);
        }
        ll x = floor(d);
        if(abs(d - round(d)) <= 1e-3){
            x = round(d);
        }
        cout << 1 + x << endl;
        
    }
}


