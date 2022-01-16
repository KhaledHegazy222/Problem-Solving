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
    long long a,b;
    while(cin >> a >> b && (a || b)){
        if(a > b)
            swap(a,b);
        int p = 0;
        while(a && b && 2 * a > b){
            p = !p;
            b -= a;
            swap(a,b);
        }
        if(a && b)
            p = !p;
        cout << (p ? "Stan wins" : "Ollie wins") << endl;
    }


}