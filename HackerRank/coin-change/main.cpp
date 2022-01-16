

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



int coins[50];
int n,m;


ll mem[251][50];


ll dp(int rem,int idx){
    if(rem == 0) return 1;
    if(idx == m) return 0;
    
    ll& ret = mem[rem][idx];
    

    if(ret != -1) return ret;

    ll choice1 = dp(rem,idx+1);
    ll choice2 = 0;
    if(rem >= coins[idx]){
        choice2 = dp(rem-coins[idx],idx);
    }
    return ret = choice1 + choice2;

}





int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    cin >> n >> m;
    for(int i = 0;i<m;i++){
        cin >> coins[i];
    }

    memset(mem,-1,sizeof mem);
    

    cout << dp(n,0) << endl;


}

