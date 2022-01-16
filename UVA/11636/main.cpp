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

    int cs = 1;
    int n;
    while(cin >> n,n > 0){
        cout << "Case " << cs++ << ": ";
        if(!(n & (n - 1)) ){
            cout << (int) log2(n) << endl;
        }
        else{
            cout << (int) log2(n) + 1 << endl;
        }
    }

}