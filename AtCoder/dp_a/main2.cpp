#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e5 + 5;
int n,A[N];


int memo[N];



int solve(int idx){
    if(idx >= n)
        return 1e9 + 5;
    if(idx == n - 1)
        return 0;
    
    int &ret = memo[idx];
    if(~ret)
        return ret;

    return ret = min(solve(idx + 1) + abs(A[idx] - A[idx + 1]),solve(idx + 2) + abs(A[idx] - A[idx + 2]));
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

    memset(memo,-1,sizeof memo);

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> A[i];
    cout << solve(0) << endl;





}


