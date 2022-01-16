#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 5e4 + 5;
struct point{
    double x,y;
    double dist(point b){
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
}A[N];
int n;
double fun(point home){
    double ret = 0;
    for(int i = 0;i<n;i++){
        ret = max(ret,home.dist(A[i]));
    }
    return ret;

}

double TS(){
    double l = -N,r = N;
    for(int i = 0;i<100;i++){
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if(fun((point){mid1,0}) > fun((point){mid2,0}))
            l = mid1;
        else
            r = mid2;
    }
    return l;
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
    cout << fixed << setprecision(6);
    while(cin >> n,n){
        for(int i = 0;i<n;i++)
            cin >> A[i].x >> A[i].y;
        double res = TS();
        
        cout << res << " " << fun((point){res,0}) << endl;    
    }

}


