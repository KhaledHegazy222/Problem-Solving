#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()


#define clear_bit(var,bit)  ((var) &= ~(1 << (bit)))
#define set_bit(var,bit)    ((var) |= (1 << (bit)))
#define get_bit(var,bit)    (((var) >> (bit)) & 1)
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;

int dp[1 << 13];


int solve(int mask){

    int &res = dp[mask];
    if(~res)
        return res;
    
    res =  __builtin_popcount(mask);
    for(int i = 0;i < s.size();i++){
        int msk;
        if(i - 2 >= 0 && i - 1 >= 0 && get_bit(mask,i) && get_bit(mask,i - 1) && !get_bit(mask,i - 2)){
            msk = mask;
            clear_bit(msk,i);
            clear_bit(msk,i - 1);
            set_bit(msk,i - 2);
            res = min(res,solve(msk));
        }
        if(i + 1 < s.size() && i + 2 < s.size() && get_bit(mask,i) && get_bit(mask,i + 1) && !get_bit(mask,i + 2) ){
            msk = mask;
            clear_bit(msk,i);
            clear_bit(msk,i + 1);
            set_bit(msk,i + 2);
            res = min(res,solve(msk));
        }

    }
    return res;

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
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> s;
        int res = 0;
        int fact = 1;
        reverse(all(s));
        for(int i = 0;i < s.size();i++){
            res += fact * (s[i] == 'o');
            fact <<= 1;
        }
        cout << solve(res) << endl;

    }

}


