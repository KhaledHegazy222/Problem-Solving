#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 100 + 2;
int arr[N][N],vis[N][N];
int n;
int valid(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y];
}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int t;
    cin >> t;
    while(t--){

        memset(vis,0,sizeof vis);

        cin >> n;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                cin >> arr[i][j];
        int r = 0,c = 0;
        int cnt = 1;
        cout << arr[0][0] << " ";
        while(r != n - 1 || c != n - 1){
            if(valid(r,c + 1)){
                cout << arr[r][++c] << " ";
                vis[r][c] = 1;
                if((++cnt) % n == 0)
                    cout << endl;
            }
            while(valid(r + 1,c - 1)){
                cout << arr[++r][--c] << " ";
                vis[r][c] = 1;
                if((++cnt) % n == 0)
                    cout << endl;
            }
            if(valid(r +1,c)){
                cout << arr[++r][c] << " ";
                vis[r][c] = 1;
                if((++cnt) % n == 0)
                    cout << endl;
            }
            while(valid(r - 1,c + 1)){
                cout << arr[--r][++c] << " ";
                vis[r][c] = 1;
                if((++cnt) % n == 0)
                    cout << endl;
            }
        }
    }

}