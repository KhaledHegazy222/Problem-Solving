

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

double dp[2000][2000];
int vis[2000][2000];

class Volleyball{
    public:
        double win(int s_scr, int r_scr,double p,int level = 0){
            if(vis[s_scr][r_scr]) return dp[s_scr][r_scr];
            vis[s_scr][r_scr] = 1;
            if(level == 1900) return 0.5;
            double& ret = dp[s_scr][r_scr];
            if(abs(s_scr-r_scr) >= 2 && ( s_scr >= 15 || r_scr >= 15))  return  ret = s_scr > r_scr;


            return ret = p * win(s_scr+1,r_scr,p,level+1) + (1-p)*( 1 - win(r_scr+1,s_scr,p,level+1));

        }
};
