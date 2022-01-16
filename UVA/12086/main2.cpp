#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 2e5 + 5;

struct BIT{
    int arr[N];
    void init(){
        memset(arr,0,sizeof arr);
    }
    void add(int idx,int v){
        while(idx < N){
            arr[idx] += v;
            idx += (idx & -idx);
        }
    }

    int get(int idx){
        int ret = 0;
        while(idx){
            ret += arr[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
    void s(int idx,int v){
        int x = get(idx) - get(idx - 1);
        add(idx,v - x);
    }
    int m(int l,int r){
        return get(r) - get(l - 1);
    } 

}bit;





int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int cs = 1;
    int n;
    while(cin >> n , n){

        if(cs - 1) 
            cout << endl;
        cout << "Case " << cs++ << ":\n";
        bit.init();
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            bit.add(i+1,x);
        }
        string line;
        cin.ignore();
        while(getline(cin,line)){
            if(line[0] == 'E')
                break;
                
            stringstream ss(line);
            char op;
            int a,b;
            ss >> op >> a >> b;
            if(op == 'M'){
                cout << bit.m(a,b) << endl;
            }
            else{
                bit.s(a,b);//


            }
        }
    }




}