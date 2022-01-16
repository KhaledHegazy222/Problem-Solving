#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
const int N = 32;
ll c[N][N];
void NCR(){
    for(int i = 0;i<N;i++)
        c[i][0] = 1;
    for(int i = 1;i<N;i++){
        for(int j = 1;j<=i;j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
}
 
 
 
int main(void){
 
    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    NCR();
    int n,m,t;
    cin >> n >> m >> t;
    ll res = 0;
    for(int i = 4;i<t;i++){
        if(i <= n && t - i <= m)
            res += c[n][i] * c[m][t - i];
    }
    cout << res << endl;
 
 
}//