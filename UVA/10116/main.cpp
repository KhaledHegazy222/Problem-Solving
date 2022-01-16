


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

int n,m,s;



int dfs(char arr[10][10],int i,int j,int mode,int steps){
    if(mode == 0){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return steps;
        }
        if(arr[i][j] > 'Z'){
            return dfs(arr,i,j,mode+1,0);
        }
        else{
            if(arr[i][j] == 'W'){
                arr[i][j] = 'w';
                return dfs(arr,i,j-1,mode,steps+1);
            }
            if(arr[i][j] == 'E'){
                arr[i][j] = 'e';
                return dfs(arr,i,j+1,mode,steps+1);
            }
            if(arr[i][j] == 'N'){
                arr[i][j] = 'n';
                return dfs(arr,i-1,j,mode,steps+1);
            }
            if(arr[i][j] == 'S'){
                arr[i][j] = 's';
                return dfs(arr,i+1,j,mode,steps+1);
            }
        }
    }
    else if(mode == 1){
        if(arr[i][j] == '*'){
            return steps;
        }
        char current = arr[i][j];
        arr[i][j] = '*';
        if(current == 'w'){
            return dfs(arr,i,j-1,mode,steps-1);
        }
        if(current == 'e'){
            return dfs(arr,i,j+1,mode,steps-1);
        }
        if(current == 'n'){
            return dfs(arr,i-1,j,mode,steps-1);
        }
        if(current == 's'){
            return dfs(arr,i+1,j,mode,steps-1);
        }
    }
    else if(mode == 2){
        if(arr[i][j] == '*'){
            return steps;
        }
        char current = arr[i][j];
        if(current == 'w'){
            return dfs(arr,i,j-1,mode,steps+1);
        }
        if(current == 'e'){
            return dfs(arr,i,j+1,mode,steps+1);
        }
        if(current == 'n'){
            return dfs(arr,i-1,j,mode,steps+1);
        }
        if(current == 's'){
            return dfs(arr,i+1,j,mode,steps+1);
        }
    }
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
        cin >> n >> m >> s;
        if(!n && !m && !s){
            return 0;
        }

        char arr[10][10];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin >> arr[i][j];
            }
        }

        int res = dfs(arr,0,s-1,0,0);
        if(res > 0){
            cout << res << " step(s) to exit\n";
        }
        else{
            int t = dfs(arr,0,s-1,2,0);
            cout << t << " step(s) before a loop of " << -1 * res << " step(s)\n";
        }
    }
    

}

