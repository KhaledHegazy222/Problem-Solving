

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

double p,q,r,s,t,u;

double eval(double x){
    return (p*exp(-1*x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x *x  +u );
}



double bs(void){
    double l = 0;
    double r=  1;
    for(int i = 0;i<100;i++){
        double mid = (l + r) / 2;
        double res = eval(mid);
        if(res > 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    while(cin >> p >> q >> r >> s >> t >>u){
        double x = bs();
        if(abs(eval(x)) >= 1e-6){
            cout << "No solution\n";
        }
        else{
            cout << fixed << setprecision(4) << x << endl;
        }
    }


}
