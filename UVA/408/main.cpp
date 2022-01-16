#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int step,mod;


    while(cin >> step >> mod){
        
        string res = __gcd(step,mod) == 1 ? "Good Choice" : "Bad Choice";
        cout << right << setw(10) << step;
        cout << right << setw(10) << mod;
        cout << string(4,' ');
        cout << res << endl;
        cout << endl;
    }

}
