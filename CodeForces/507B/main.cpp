


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
using namespace std;
double dist(ll a,ll b,ll c,ll d){
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}


int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    ll r,a,b,c,d;
    cin >> r >> a >> b >> c >> d;

    double ds = dist(a,b,c,d);
    int x = round(ds);
    if(abs(x-ds) > 1e-6 && ds > x ){
        x++;
    }

    cout <<  (x + 2*r - 1)/ (2*r) << endl;
    

}