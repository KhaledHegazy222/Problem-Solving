

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int N = 2e5;
int n,H[N],C[N];
double eval(double h){
    double cost = 0;
    for(int i = 0;i<n;i++){
        cost += fabs((H[i] - h) * C[i] );
    }
    return cost;
}

ll ts(void){
    double l = 0;
    double sz = 1e4;
    for(;sz > 1e-3;sz *= 2.0/3){
        double a = l + sz/3;
        double b = a + sz/3;
        if(eval(a) > eval(b))
            l = a;
    }
    int x = l;
    int y = ceil(l);
    return min(round(eval((double)x)),round(eval((double)y)) );
} 

int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    int t;
    cin >> t;
    while(t--){
        cin >> n;   
        for(int i =0;i<n;i++){
            cin >> H[i];
        }
        for(int i =0;i<n;i++){
            cin >> C[i];
        }

        cout << ts() << endl;


    }


}


