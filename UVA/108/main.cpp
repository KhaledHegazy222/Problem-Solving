#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n;
    cin >> n;
    int grid[n][n];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin >> grid[i][j];
        

    int mxSum = 0;

    for(int l = 0;l<n;l++){
        int tmp[n] = {0};
        for(int r = l;r <n ;r++){
            int sum = 0;
            for(int i = 0;i<n;i++){
                tmp[i] += grid[i][r];
                sum += tmp[i];
                if(sum < 0)
                    sum = 0;
                mxSum = max(mxSum,sum);
            }
        }
    }
    cout << mxSum << endl;

}