#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

double calc(double x,double y){
    return x + y - min(y,2 * x);
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
    int n;
    cin >> n;
    vector<double>v(n);
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        v[i] = (x / 2.0);
    }   

    sort(all(v));
    cout << fixed << setprecision(9);
    double x;
    if(n % 2){
        x =  v[n / 2];
    }
    else{
        int y = n / 2;
        x = (v[y] + v[y - 1]) / 2.0 ;
    }
    double sum = 0;
    for(int i = 0;i<n;i++)
        sum += calc(x,v[i] * 2);

    cout << sum / n << endl;
}


