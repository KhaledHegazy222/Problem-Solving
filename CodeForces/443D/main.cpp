
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;






int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    int n;
    cin >> n;
    vector<double>p(n);    
    

    double not_come = 1,one_come = 0;
    double x = 1, y = 0;
    for(int i = 0;i<n;i++){
        cin >> p[i];
        not_come *= (1-p[i]);
    }
    for(int i = 0;i<n;i++){
        one_come += not_come * p[i] / (1-p[i]) ;
    }
    

    sort(all(p));

    for(int i = 0;i<n;i++){
        double risk = (one_come - (not_come / (1-p[i]) *p[i])) / (1-p[i]);
        if(risk > one_come)
            (one_come = risk),not_come /= (1-p[i]);
    }
    if(one_come == one_come){
        
    }
    else{
        one_come = 1;
    }
    cout << fixed << setprecision(9) << one_come << endl;

}   