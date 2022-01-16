

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

    ll fib[100];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2;i<=50;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    ll a,b;
    cin >> a >> b;
    cout << fib[a] << " ";
    for(int i = 0;i<=50;i++){
        if(fib[i] == b){
            cout << i << endl;
            return 0;
        }
    }
}