
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

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
        int n;
        cin >> n;
        int res;
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            if(!i)
                res = x;
            else
                res = __gcd(res,x);
        }
        if(res == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

}