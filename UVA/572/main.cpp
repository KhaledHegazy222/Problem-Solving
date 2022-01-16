

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


char mapa[101][101];
int n,m;


void dfs(int i,int j){
    if(i < 0 || i >= n || j < 0 || j >= m || mapa[i][j] == '*'){
        return;
    }
    mapa[i][j] = '*';

    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i+1,j+1);
    dfs(i+1,j-1);
    dfs(i-1,j+1);
    dfs(i-1,j-1);


}

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    

    while(1){
        cin >> n >> m;
        if(!n && !m){
            return 0;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin >> mapa[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mapa[i][j] == '@'){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << endl;
        
    }

}

