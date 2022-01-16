



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
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int n;
    cin >> n;
    int max_x = max(x1,max(x2,max(x3,x4)));
    int max_y = max(y1,max(y2,max(y3,y4)));
    int min_x = min(x1,min(x2,min(x3,x4)));
    int min_y = min(y1,min(y2,min(y3,y4)));
    while(n--){
        int x,y;
        cin >> x >> y;
        
        if(x >= min_x && x <= max_x && y <= max_y && y >= min_y){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}