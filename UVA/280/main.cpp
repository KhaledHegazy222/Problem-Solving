

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
bool enter;
int dfs(vector<vector<int>>&v,int u,int visited[]){
    if(visited[u]){
        return 0;
    }
    int cnt = 0;
    if(enter){
        cnt = 1;
        visited[u] = 1;
    }
    enter = true;
    for(int i = 0;i<v[u].size();i++){
        int x = v[u][i];
        cnt += dfs(v,x,visited);
    } 
    return cnt;
}



int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n;
    while(1){
        cin >> n;
        if(!n){
            return 0;
        }

        vector<vector<int>>v(n);
        int x;
        while(1){
            cin >> x;
            if(x == 0){
                break;
            }
            while(1){
                int a;
                cin >> a;
                if(a){
                    v[x-1].push_back(a-1);
                }
                else{
                    break;
                }
            }
        }
        int len;
        cin >> len;
        for(int i = 0;i<len;i++){
            int a;
            cin >> a;
            int visited[n] = {0};
            enter = false;
            int p = n - dfs(v,a-1,visited);
            cout << p;
            if(p){
                cout << " ";
            }
            int print = 1;
            for(int i = 0;i<n;i++){
                if(!visited[i]){
                    if(print){
                        cout << i + 1;
                        print = 0;
                    }
                    else{
                        cout << " " << i+1;
                    }
                }
            }
            cout << endl;
        }
    }
}

