
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
        int n;
        cin >> n;
        int sum = 0;
        int ones = 0;
        while(n--){
            int x;
            cin >> x;
            if(x %2){
                ones = 1;
            }
            sum += x;
        }
        if(sum %2 == 0 &&(  (sum / 2) % 2 == 0 || (ones) )){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    #ifdef offline_vs_code
        //goto loop;
    #endif 
 
}
