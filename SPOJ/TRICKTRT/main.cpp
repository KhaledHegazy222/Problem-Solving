

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int N = 2e5;
int n;
vector<pair<double,double>>pos(N);

double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double eval(double x){
    double mx = 0;
    for(int i = 0;i<n;i++){
        mx = max(mx,dist(pos[i].first,pos[i].second,x,0));
    }
    return mx;
}


void ts(void){
    double l = -1e9;
    double sz = 2e9;
    for(;sz >= 1e-20;sz *= 2.0/3){
        double a = l + sz/3;
        double b = a + sz/3;
        if(eval(a) > eval(b))
            l = a;
    }
    cout << fixed << setprecision(9) << l << " ";
    cout << fixed << setprecision(9) << eval(l) << "\n";
}



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    while(1){
        cin >> n;
        if(!n) return 0;
        for(int i = 0;i<n;i++)
            cin >> pos[i].first >> pos[i].second;
        ts();
    }




}

