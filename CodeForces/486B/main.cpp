
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


int b[101][101];
int n,m;



bool check_row(int r){
    for(int i = 0;i<m;i++){
        if(b[r][i] == 0){
            return false;
        }
    }
    return true;
}


bool check_col(int c){
    for(int i = 0;i<n;i++){
        if(b[i][c] == 0){
            return false;
        }
    }
    return true;
}




int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> b[i][j];
        }
    }


    int rows[n] = {0};
    int cols[m] = {0};

    bool pos = true;
    int a[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(b[i][j] == 1){
                bool ro = check_row(i);
                bool co = check_col(j);
                if(ro){
                    rows[i] = 1;
                }
                if(co){
                    cols[j] = 1; 
                }
                if(ro && co){
                    a[i][j] = 1;
                }    
                else if(ro || co){
                    a[i][j] = 0;
                }
                else {
                    pos = false;
                    break;
                }
            }
            else {
                a[i][j] = 0;
            }
        }
    }



    bool l = false;
    bool r = false;
    for(int i = 0;i<n;i++){
        if(rows[i]){
            l = true;
            break;
        }
    }

    for(int i = 0;i<m;i++){
        if(cols[i]){
            r = true;
            break;
        }
    }

    if(pos && !(l ^ r)){
        cout << "YES\n";
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO\n";
    }


}

