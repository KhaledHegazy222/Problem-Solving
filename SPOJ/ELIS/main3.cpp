#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e1 + 5;

int A[N],n;

int solve(int idx,int last){
    if(idx == n)
        return 0;

    int ch1 = 0,ch2 = 0;
    ch1 = solve(idx + 1,last);

    if((!~last) || A[idx] > A[last])
        ch2 = 1 + solve(idx + 1,idx);

    return max(ch1,ch2);

}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> A[i];
    cout << solve(0,-1) << endl;


}