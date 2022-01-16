#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e3 + 5;
string s;

deque<char>f,b;

int dp[N][N];


int solve(int i,int j){
    if(i >= j)
        return 0;
    

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    if(s[i] == s[j])
        return ret = solve(i + 1,j - 1);

    int ch1 = 1 + solve(i + 1,j);
    int ch2 = 1 + solve(i,j - 1);

    return ret = min(ch1,ch2);

}



void build(int i,int j){
    if(i > j)
        return;
    if(i == j){
        f.push_back(s[i]);
        return;
    }
    if(s[i] == s[j]){
        f.push_back(s[i]);
        b.push_front(s[j]);
        build(i + 1,j - 1);
        return;
    }

    int ch1 = 1 + solve(i +1 ,j);
    int ch2 = 1 + solve(i,j -1);
    if(solve(i,j) == ch1){
        f.push_back(s[i]);
        b.push_front(s[i]);
        build(i + 1,j);
    }
    else{
        f.push_back(s[j]);
        b.push_front(s[j]);
        build(i,j - 1);
    }

    
}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    while(cin >> s){
        memset(dp,-1,sizeof dp);
        f.clear();
        b.clear();
        cout << solve(0,s.size() - 1) << " ";
        build(0,s.size() - 1);
        for(auto it : f)
            cout << it;
        for(auto it : b)
            cout << it;
        cout << endl;

    }




}