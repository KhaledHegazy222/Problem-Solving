

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

double meel(double x1,double y1,double x2,double y2){
    double makam = x2-x1;
    if(abs(makam) <= 1e-6 ){
        return 1e9;
    }
    return (y2-y1)/makam;
}

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double m1 = meel(x1,y1,x2,y2);
    cin >> x1 >> y1 >> x2 >> y2;
    double m2 = meel(x1,y1,x2,y2);

    if(abs(m1-m2) <= 1e-6){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    
}