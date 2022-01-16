#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string bigIntsAdd(string a,string b){
    string finalsum; 
    int carry=0;  
    int i = a.size()-1,j=b.size()-1; 
    while((i>=0) and (j>=0)){     
        int x = (a[i]-'0') + (b[j]-'0') + carry; 
        finalsum.push_back((x%10) + '0');
        carry = x/10;     
        i--;              
        j--;
    }
    while(i>=0){          
        int x = (a[i]-'0') + carry;
        finalsum.push_back((x%10) + '0');
        carry = x/10;  
        i--;
    }
    while(j>=0){      
        int x = (b[j]-'0') + carry;
        finalsum.push_back((x%10) + '0');
        carry = x/10; 
        j--;
    }
    while(carry){   
        finalsum.push_back((carry%10) + '0'); 
        carry=carry/10;       
    }
    reverse(all(finalsum));
    return finalsum;
}

const int N = 1e4;

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    string fib[N] = {"1","1"};
    for(int i = 2;i<N;i++){
        fib[i] = bigIntsAdd(fib[i-1],fib[i-2]);
    }

    int n;
    while(cin >> n){
        cout << fib[n - 1] << endl;
    }

}

// 218922995834555169026