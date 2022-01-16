

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

    int psc[31][31];
    memset(psc,0,sizeof psc);
    psc[0][1] = 1;
    for(int i = 1;i<31;i++){
        for(int j = 1;j<31;j++){
            psc[i][j] = psc[i-1][j-1] + psc[i-1][j];
        }
    }
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=i+1;j++){
            cout << psc[i][j] << " ";
        }
        cout << endl;
    }
}