


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
typedef unsigned long long ull;
typedef long long ll;

using namespace std;
int n;
double p;
double prob(int level){
    if(level == 0) return 1.0;
    double ret; 
    double pp = prob(level/2);
    ret = pp*pp + (1-pp)*(1-pp);
    if(level&1) ret = (1-p)*ret + (1-ret)*p;

    return ret;


}



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    cin >> n >> p;
    cout << fixed << setprecision(9);
    cout << prob(n) << '\n';





}   


