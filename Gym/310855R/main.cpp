

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


double dist(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    double x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double arr[3] = {
        dist(x1,y1,x2,y2),
        dist(x1,y1,x3,y3),
        dist(x2,y2,x3,y3)
    };
    sort(arr,arr+3);
    if(abs( arr[0]+ arr[1] -arr[2]  )  <= 1e-6 ){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    
    
}