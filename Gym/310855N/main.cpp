

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
    cin >> a >> b >> c >> d;
    double r1 = b*log10(a);
    double r2 = d*log10(c);
    if(abs(r1-r2) > 1e-6 && r1 > r2){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

}
