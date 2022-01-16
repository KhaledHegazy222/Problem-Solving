
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;


int n;

char grid[12][12];


int valid(int i,int j, char c){
    if(i > 0 && grid[i-1][j] == c){
        return 0;
    }
    else if(i<n-1 && grid[i+1][j] == c){
        return 0;
    }
    else if(j<n-1 && grid[i][j+1] == c){
        return 0;
    }
    else if(j > 0 && grid[i][j-1] == c){
        return 0;
    }
    return 1;
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
    int cs = 1;
    while(t--){

        cin >> n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin >> grid[i][j];
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '.'){
                    if(valid(i,j,'A')){
                        grid[i][j] = 'A';
                    }
                    else if(valid(i,j,'B')){
                        grid[i][j] = 'B';
                    }
                    else if(valid(i,j,'C')){
                        grid[i][j] = 'C';
                    }
                    else if(valid(i,j,'D')){
                        grid[i][j] = 'D';
                    }
                    else{
                        grid[i][j] = 'E';
                    }
                }
            }
        }

        cout << "Case " << cs++ << ":\n";

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout << grid[i][j];
            }
            cout << endl;
        }


    }


}