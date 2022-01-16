

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
    int t;
    cin >> t;
    while(t--){ 
        int n,k;
        cin >> n >> k;
        if(n % 2 != k %2 ){
            cout << "NO\n";
        }
        else{
            ll c1 = 1;
            ll c2 = (k-1)*2+1;
            ll x = (c2-c1)/2 + 1;
            if(x * (c1 + c2)/2 <= n){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}