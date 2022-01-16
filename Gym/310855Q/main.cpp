

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


double dist(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    ll x,y;
    double r;
    cin >> x >> y >> r;
    ll n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        double d= dist(x,y,a,b);
        if(abs(d - r) <= 1e-6 || d < r ){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    } 
    
}