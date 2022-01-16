
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;



int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
   
    int r1,c1;
    cin >> r1 >> c1;
    int m1[r1][c1];
    for(int i = 0;i<r1;i++){
        for(int j = 0;j<c1;j++){
            cin >> m1[i][j];
        }
    }
    int r2,c2;
    cin >> r2 >> c2;
    int m2[r2][c2];
    for(int i = 0;i<r2;i++){
        for(int j = 0;j<c2;j++){
            cin >> m2[i][j];
        }
    }

    int res[r1][c2];
    memset(res,0,sizeof res);
    for(int i = 0;i<r1;i++){
        for(int j = 0;j<c1;j++){
            for(int k = 0;k<c2;k++){
                res[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    for(int i = 0;i<r1;i++){
        for(int j = 0;j<c2;j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}