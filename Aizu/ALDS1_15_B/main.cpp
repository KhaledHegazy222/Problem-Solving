

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)




using namespace std;



bool cmp(pair<double,int>& a,pair<double,int>& b){
    return a.first > b.first;
}

int main(void){
    

    ll n,w;
    cin >> n >> w;
    vector<pair<double,int>>v(n);
    for(int i = 0;i<n;i++){
        double a,b;
        cin >> a >> b;
        double m = a / b;
        v[i].first = m;
        v[i].second = round(b);
    }

    sort(all(v),cmp);

    double total = 0;
    for(int i = 0;i<n && w;i++){
        if(w - v[i].second >= 0){
            total += v[i].second * v[i].first;
            w -= v[i].second;
        }
        else{
            total += v[i].first * w;
            w = 0;
        }
    }


    cout << fixed << setprecision(6) << total << endl;



}