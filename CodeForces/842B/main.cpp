


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
using namespace std;



double dist(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int r,d;
    cin >> r >> d;
    int n;
    cin >> n;
    int total = 0;
    while(n--){
        int x,y,_r;
        cin >> x >> y >> _r;
        double d_org = dist(x,y,0,0);
        if( ( abs(d_org-_r-(r-d)) <= 1e-6 || d_org - _r > r-d ) && (abs(d_org+_r - r) <= 1e-6 || d_org+_r < r) ){
            total++;
        }
    }
    cout << total << endl;

}