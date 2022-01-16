


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
const int N = 2e6 + 5;
vector<int>isPrime(N+1,1);

void sieve(void){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 0;i*i <= N;i++){
        if(isPrime[i])
            for(int j = 2*i;j<=N;j+=i){
                isPrime[j] = 0;
            }
    }
}
int rev(int num){
    string s = to_string(num);
    reverse(all(s));
    num = stoi(s);
    return num;
}

int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    sieve();
    int x;
    while(cin >> x){
        int x_r = rev(x);
        if(isPrime[x] && isPrime[x_r] && x != x_r)
            cout << x << " is emirp.\n";
        else if(isPrime[x])
            cout << x << " is prime.\n";
        else
            cout << x << " is not prime.\n";
    }

}


