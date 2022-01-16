

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



const int N = 2e5 + 1;

int x,y;

double eval(double a){
    double h = (x - a)/2;
    double b = (y  - 2 * h);

    return a * h * b;
}


double ts(){
    double l = 0;
    double sz = 200;
    for(;sz > 1e-20;sz *= 2.0/3){
        double a = l + sz/3;
        double b = a + sz/3;
        if(eval(a) < eval(b))
            l = a;

    }
    return eval(l);

}


int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    

    int t;
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << fixed << setprecision(11) <<  ts() << "\n";
    }

}
