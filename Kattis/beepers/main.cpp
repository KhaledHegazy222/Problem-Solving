

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MAX 100000

using namespace std;


int Mat[20][20];
pair<int,int> B[10];
int n;
int vis[10],vid;        
int si,sj;



int dfs(int i,int j,int steps){
    int ret = INT_MAX;
    bool enter = 0;
    for(int x = 0;x<n;x++){
        if(vis[x] == vid) continue;
        vis[x] = vid;
        enter = 1;
        ret = min(ret,dfs(B[x].first,B[x].second,steps + abs(B[x].first - i) + abs(B[x].second - j) )  );
        vis[x] = 0;
    }
    if(enter == 0){    
        return steps + abs(si - i) + abs(sj - j);
    }
    return ret;
}
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    
    int t;
    cin >> t;
    while(t--){
        vid++;
        int r,c;
        cin >> r >> c;
        cin >> si >> sj;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> B[i].first >> B[i].second;
        }

        cout << dfs(si,sj,0) << endl;
    }
    



}

