

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;

int mem[30][2][2][2];


int dp(int i,int a,int b,int c){
    if(i == n){
        if(a || b || c) return 0;
        return 1;
    }


    int& ret = mem[i][a][b][c];
    if(ret != -1) return ret;


    int cnt = dp(i+1,!a,!b,!c);
    if(!a && !b){
        cnt += dp(i+1,0,0,!c);
    }
    if(!b && !c){
        cnt += dp(i+1,!a,0,0);
    }
    return ret = cnt;
}




int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    


    while(1){
        cin >> n;
        if(n == -1){
            return 0;
        }
        memset(mem,-1,sizeof mem);
        cout << dp(0,0,0,0) << endl;
    }

    
}