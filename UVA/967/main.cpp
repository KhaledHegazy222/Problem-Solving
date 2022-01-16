#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e6 + 6;
vector<bool>isPrime(N,1);
vector<int>primes;
 
int com[N];

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i * i < N;i++)
        if(isPrime[i])
            for(int j = 2 * i;j < N;j += i)
                isPrime[j] = 0;
 
    for(int i = 0;i<N;i++) 
        if(isPrime[i])
            primes.push_back(i);
 
 
}


int circular(int p){
    string s = to_string(p);
    if(s.size() == 1)
        return isPrime[p];

    for(int i = 0;i<10;i++){
        char x = s[0]  ;
        s = s.substr(1);
        s.push_back(x);
        p = stoi(s);
        if(!isPrime[p])
            return 0;
    }
    return 1;
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    sieve();

    for(auto elem : primes){
        com[elem] = circular(elem);
    }

    for(int i = 1;i<N;i++)
        com[i] += com[i - 1];
    
    while(1){
        int l,r;
        cin >> l;
        if(!~l)
            return 0;
        cin >> r;
        if(r < l)
            swap(l,r);
        int res = com[r] - com[l - 1];
        if(!res){
            cout << "No Circular Primes.\n";
            continue;
        }

        if(res == 1)
            cout << res << " Circular Prime.\n";
        else
            cout << res << " Circular Primes.\n";

    }





}