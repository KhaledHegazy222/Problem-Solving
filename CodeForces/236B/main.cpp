

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MOD 1073741824


using namespace std;




int div_num(int n){
    int cnt = 0;
    if(n == 1){
        return 1;
    }
    for(ll i = 2;i*i<=n;i++){
        if(n % i == 0){
            if(n / i == i){
                cnt--;
            }
            cnt += 2;
        }
    }
    return cnt+2;
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    
    

    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int sum = 0;
    unordered_map<int,int>st;
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            for(int k = 1;k<=c;k++){
                int x;
                auto it = st.find(i*j*k);
                if(it == st.end()){
                    x =div_num(i*j*k);
                    st.insert({i*j*k,x});
                }
                else{
                    x = st[i*j*k];
                }
                sum += x;
                sum %= MOD;
            }
        }
    }
    printf("%d\n",sum);


}