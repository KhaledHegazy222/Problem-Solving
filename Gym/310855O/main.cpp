

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

    double a,b,c,d;
    cin >> a >> b >>c >>d;
    cout << fixed << setprecision(9) << sqrt((a-c)*(a-c) + (b-d)*(b-d)) << endl;

    
}