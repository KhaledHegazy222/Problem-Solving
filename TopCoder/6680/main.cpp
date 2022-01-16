
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 20 + 2;

int R[N],G[N],B[N];
int n;

int dp[N][4];

int solve(int idx,int lst){
    if(idx == n)
        return 0;

    int &ret = dp[idx][lst];
    if(~ret) return ret;

    int ch1 = 1e9,ch2 = 1e9,ch3 = 1e9;
    if(lst != 1){
        ch1 = R[idx] + solve(idx + 1,1);
    } 
    if(lst != 2){
        ch2 = G[idx] + solve(idx + 1,2);
    } 
    if(lst != 3){
        ch3 = B[idx] + solve(idx + 1,3);
    } 

    return ret = min({ch1,ch2,ch3});
}


class RGBStreet{
    public :
    int estimateCost(vector<string>houses){
        memset(dp,-1,sizeof dp);
        n = houses.size();
        for(int i = 0;i<n;i++){
            stringstream ss(houses[i]);
            ss >> R[i] >> G[i] >> B[i];
        }
        
        return solve(0,0);
    }
};
