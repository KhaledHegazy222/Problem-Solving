#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define oo ((ll) 1e9)
#define _oo ((ll) -1e9)
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define mod ((ll)1e7)
 
 
using namespace std;
 
 
 
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
        // loop:
    #endif
 
 
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int sh1 = 1,sh2 = 1;
        while(a % 2 == 0){
            sh1*=2;
            a /= 2;
        }
        while(b % 2 == 0){
            sh2*=2;
            b /= 2;
        }
        if(sh1 * sh2 >= c){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    #ifdef offline_vs_code
        //goto loop;
    #endif 
 
 
 
 
 
 
 
 
 
}