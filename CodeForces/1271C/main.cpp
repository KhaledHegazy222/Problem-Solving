


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
    

    int n,sx,sy;
    cin >> n >> sx >> sy;
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;


    while(n--){
        int x,y;
        cin >> x >> y;
        if(x > sx){
            right++;
        }
        if(y > sy){
            up++;
        }
        if(x < sx){
            left++;
        }
        if(y < sy){
            down++;
        }
    }
    int mx = max(up,max(down,max(right,left)));
    if(mx == up){
        cout << up << endl<< sx << " " << sy+1 << endl;
    }
    else if(mx == right){
        cout << right << endl << sx+1  << " " << sy << endl;
    }
    else if(mx == left){
        cout << left  << endl<< sx-1  << " " << sy << endl;
    }
    else if(mx == down){
        cout << down << endl << sx  << " " << sy-1 << endl;
    
    }
}

