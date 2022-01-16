


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2));
}
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    ll r,l;
    cin >> r >> l;
    double h_dia = l * sqrt(2)/2.0;
    if(l >= 2* r){
        cout << "Square\n";
    }
    else if(abs(h_dia-r) <= 1e-6 ||  r > h_dia){
        cout << "Circle\n";
    }
    else {
        cout << "Complex\n";
    }
}