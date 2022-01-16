
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
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n = 10000000;
    double fact[n+10];
    fact[0] = fact[1] = 0.0;
    for(int i = 2;i<=n;i++){
        fact[i] = fact[i-1] + log10(i);
    }

    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        double inc = log10(a); 
        int l = 1,r = n;
        while(l!=r){
            int mid = (l+r)/2;
            double x = mid;
            double srch = x*inc;
            double f = fact[mid];
            double p = srch;
            if(abs(f-p) > 1e-6 && f > p){
                r = mid;
            } 
            else{
                l = mid+1;
            }
        }
        cout << l << endl;
    }

    



}