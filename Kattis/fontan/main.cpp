
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
int n,m;


void dfs(char arr[50][50],int i ,int j){
    if (i < 0 || i >= n || j < 0 || j >= m){
        return;
    }
    if(arr[i][j] != '#' && arr[i][j] != 'v'){
        arr[i][j] = 'v';    
    }
    else{
        return ;
    }
    if(i < n-1){
        if(arr[i+1][j] == '.'){
            dfs(arr,i+1,j);
        }
        else if(arr[i+1][j] == '#'){
            dfs(arr,i,j+1);
            dfs(arr,i,j-1);
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
    


    cin >> n >> m;
    char arr[50][50];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] == 'V'){
                dfs(arr,i,j);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << (char)toupper(arr[i][j]);
        }
        cout << endl;
    }


}

