#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 5;

struct BIT{
    ll arr[N];
    void init(){
        memset(arr,0,sizeof arr);
    }
    void add(int idx,int v){
        while(idx < N){
            arr[idx] += v;
            idx += (idx & -idx);
        }
    }

    ll get(int idx){
        ll ret = 0;
        while(idx){
            ret += arr[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
    void set(int idx,int v){
        ll x = get(idx) - get(idx - 1);
        add(idx,v - x);
    }
    ll getRange(int l,int r){
        return get(r) - get(l - 1);
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
    int cs = 1;
    while(t--){
        cout << "Case " << cs++ << ":\n";
        bit.init();
        int n,q;
        cin >> n >> q;
        for(int i = 1;i<=n;i++){
            int x;
            cin >> x;
            bit.add(i,x);
        }
        while(q--){
            int type;
            cin >> type;
            int a,b;
            cin >> a;
            if(type == 1){
                cout << bit.getRange(a + 1,a + 1) << endl;
                bit.set(a + 1,0);
            }
            else if(type == 2){
                cin >> b;
                bit.add(a + 1,b);
            }
            else{
                cin >> b;
                cout << bit.getRange(a+1,b+1) << endl;
            }
        }
    }


}