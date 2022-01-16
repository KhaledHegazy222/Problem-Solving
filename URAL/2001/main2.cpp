

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
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
   
    int a1,b1;
    cin >> a1 >> b1;
    int a2,b2;
    cin >> a2 >> b2;
    int a3,b3;
    cin >> a3 >> b3;

    cout << a1-a3 << " " << b1 - b2 << endl;
}
