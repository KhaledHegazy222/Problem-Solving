#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()
#define PI (acos(-1))
typedef long long ll;
typedef unsigned long long ull;

using namespace std;


double b,c;

double fun(double x){
    return (x * x + b * x + c) / sin(x);
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif

    int t;
    cin >> t;
    while(t--){
        cin >> b >> c;

        double l = 1e-6, r = PI / 2 - 1e-6;
        for(int i = 0;i<100;i++){
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            if(fun(mid1) > fun(mid2))
                l = mid1;
            else
                r = mid2;
        }
        cout << fixed << setprecision(9);
        // cout << l <<  " ";
        cout << fun(l) << endl;
    }




}


