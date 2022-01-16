
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
vector<int>isPrime(1041,1);


void sieve(void){
    isPrime[0] = 0;

    for(int i = 2;i*i <= 1040;i++){
        if(isPrime[i])
            for(int j = 2 * i;j<=1040;j+=i){
                isPrime[j] = 0;
            }
    }
}


int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    map<char,int>mp;
    for(int i = 1;i<=26;i++){
        mp.insert({'a'+i-1,i});
    }
    for(int i = 1;i<=26;i++){
        mp.insert({'A'+i-1,i+26});
    }

    sieve();


    string s;
    while(cin >> s){
        int sum = 0;
        for(int i = 0;i<s.length();i++){
            sum += mp[s[i]];
        }

        if(isPrime[sum])
            cout << "It is a prime word.\n";
        else
            cout << "It is not a prime word.\n";
    }

}


