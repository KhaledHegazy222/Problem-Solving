

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;


int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
   
    ll i, j, n, m, k;
    ll temp = 0, flag = 1, b = 0;
    cin >> n >> m;
 
    if (m > (2 * n + 2))
    {
        cout << -1;
        return 0;
    }
    if (n > (m + 1))
    {
        cout << -1;
        return 0;
    }
    if (n == m + 1)
    {
        cout << 0;
        n--;
    }
 
    while (m + n > 0)
    {
        if (n == m)
        {
            cout << 10;
            n--;
            m--;
        }
        else if (m == 2 && n == 0)
        {
            cout << 11;
            m -= 2;
        }
        else if (m == 1 && n == 0)
        {
            cout << 1;
            m--;
        }
        else 
        {
            cout << 110;
            m -= 2;
            n--;
        }
    }

}