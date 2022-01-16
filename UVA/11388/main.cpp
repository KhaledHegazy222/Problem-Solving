
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int c = max(a,b);
        b = min(a,b);
        a = c; 

        if(a % b){
            cout << -1 << endl;
        }
        else{
            cout << b << " " << a << endl;
        }
    }
    



}   


