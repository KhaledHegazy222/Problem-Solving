
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


string str = "ICPCASIASG";
char Mat[100][100];
int n;


int mem[100][100][12];


int valid(int x1,int y1,int x2,int y2){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == 5;
}


int dp(int x,int y,int idx){
    if(idx == str.size()) return 1;
    int &ret = mem[x][y][idx];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = max(x-5,0);i <= min(x + 5,n-1) && !ret;i++){
        for(int j = max(y - 5,0);j <= min(y + 5,n-1) && !ret;j++){
            if(valid(x,y,i,j) && Mat[i][j] == str[idx]){
                ret |= dp(i,j,idx+1);
            }
        }
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
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> Mat[i][j];
        }
    }
    int res = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(Mat[i][j] == 'I'){
                memset(mem,-1,sizeof mem);
                res |= dp(i,j,1);
            }
        }
    }

    if(res) {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}