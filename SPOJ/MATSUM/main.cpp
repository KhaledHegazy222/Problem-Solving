#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1 << 11;

struct BIT{
    ll tree[N][N];

    void init(){
        memset(tree,0,sizeof tree);
    }

    void add(int x,int y,int v){
        x++,y++;
        int tmp = y;
        while(x < N){
            y = tmp;
            while(y < N){
                tree[x][y] += v;
                y += y & -y;
            }
            x += x & -x;
        }
    }

    ll get(int x,int y){
        x++,y++;
        ll ret = 0;
        int tmp = y;
        while(x){
            y = tmp;
            while(y){
                ret += tree[x][y];
                y -= y & -y;
            }
            x -= x & -x;
        }
        return ret;
    }
    
    ll getRange(int x1,int y1,int x2,int y2){
        return get(x2,y2) - get(x1-1,y2) - get(x2,y1-1) + get(x1-1,y1-1);
    }

    void set(int x,int y,int v){
        return add(x,y,v - getRange(x,y,x,y));
    }

}bit;





int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int t;
    cin >> t;
    while(t--){
        bit.init();
        int n;
        cin >> n;
        string s;
        while(cin >> s){
            if(s == "END")
                break;
            else if(s == "SET"){
                int x,y,v;
                cin >> x >> y >> v;
                bit.set(x,y,v);
            }
            else{
                int x1,y1,x2,y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << bit.getRange(x1,y1,x2,y2) << '\n';
            }
        }

    }


}