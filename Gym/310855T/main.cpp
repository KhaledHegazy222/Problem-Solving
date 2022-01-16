

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2));
}
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    double cx1,cy1,cx2,cy2;
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double r1 = dist(x1,y1,x2,y2)/2; 
    cx1 = (x1+x2)/2;
    cy1 = (y1+y2)/2; 

    cin >> x1 >> y1 >> x2 >> y2;
    double r2 = dist(x1,y1,x2,y2)/2;
    cx2 = (x1+x2)/2;
    cy2 = (y1+y2)/2;

    double d = dist(cx1,cy1,cx2,cy2);
    if(abs(d-r1-r2)<= 1e-6 || d < r1+r2){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}