#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e3 + 4;
map<pair<int,int>,double>dp;
int n;
int X[N],Y[N],T[N],I[N];
double P[N];

double dist(int x1,int y1,int x2,int y2){
    // return abs(x1 - x2) + abs(y1 - y2);
    return hypot(abs(x1-x2),abs(y1-y2));
}

int equal(double a,double b){
    return abs(a - b) < 1e-3;
}

double solve(int idx,int last){
    if(idx == n)
        return 0;
    if(dp.find({idx,last}) != dp.end())    
        return dp[{idx,last}];
    int i = I[idx];
    double ch1 = 0,ch2 = 0;
    int x,y;

    if(~last)
        x = X[I[last]],y = Y[I[last]];

    if(!~last || equal(dist(x,y,X[i],Y[i]),T[i] - T[I[last]]) || dist(x,y,X[i],Y[i]) < T[i] - T[I[last]])
        ch1 = P[i] + solve(idx + 1,idx);
    ch2 = solve(idx + 1,last);
    dp.insert({{idx,last},max(ch1,ch2)});
    return max(ch1,ch2);

    
}

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> X[i] >> Y[i] >> T[i] >> P[i];
    }
    iota(I,I+n,0);
    sort(I,I+n,[](int a,int b){
        return T[a] < T[b];
    });
    double res = 0;
    for(int i = 0;i<n;i++)
        res = max(res,solve(i,-1));
    cout << fixed << setprecision(6) << res << endl;


}