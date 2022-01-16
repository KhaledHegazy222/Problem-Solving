
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


double p(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int main(void){
    int n;
    cin >> n;
    ll max_x = INT_MIN;
    ll max_y = INT_MIN;
    ll min_y = INT_MAX;
    ll min_x = INT_MAX;

    while(n--){
        ll x,y;
        cin >> x >> y;
        max_x = max(max_x,x);
        max_y = max(max_y,y);
        min_x = min(min_x,x);
        min_y = min(min_y,y);

    }       
     double dist = max(max_x - min_x,max_y - min_y);
        dist = max(dist,p(max_x,0,0,max_y));
        dist = max(dist,p(max_x,0,0,min_y));
        dist = max(dist,p(min_x,0,0,max_y));
        dist = max(dist,p(min_x,0,0,min_y));

        cout << fixed << setprecision(6) << dist << endl;
}