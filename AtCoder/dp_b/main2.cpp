#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e5 + 500;
int n,k,A[N];


int memo[N];



int solve(int idx){
    if(idx >= n)
        return 1e9 + 5;
    if(idx == n - 1)
        return 0;
    
    int &ret = memo[idx];
    if(~ret)
        return ret;
    ret = 1e9 + 5;

    for(int i = 1;i <= k;i++)
        ret = min(ret,abs(A[idx] - A[idx + i]) + solve(idx + i));

    return ret;


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

    cin >> n >> k;
    for(int i = 0;i < n;i++)
        cin >> A[i];
    cout << solve(0) << endl;





}


