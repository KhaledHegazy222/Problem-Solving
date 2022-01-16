

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

map<char,int>digits;
map<int,char>digitss;


void convert_to_dec(string number,int old_base){
    ll fact = 1;
    ll res = 0;
    for(int i = number.size() - 1;i>= 0;i--){
        res += fact * digits[number[i]];
        fact *= old_base;
    }
    cout << to_string(res) << endl;
}


void convert_from_dec(string number,int new_base){
    ll num = atoll(number.c_str());
    string res = "";
    while(num){
        int x = num % new_base;
        res.push_back(digitss[x]);
        num /= new_base;
    }
    reverse(all(res));
    cout << res << endl;

}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    for(int i = 0;i<10;i++){
        digits.insert({'0'+i,i});
        digitss.insert({i,'0'+i});
    }    
    for(int i = 0;i<26;i++){
        digits.insert({'A'+i,i+10});
        digitss.insert({i+10,'A'+i});
    }    


    int t;
    cin >> t;
    int x;
    string n;
    cin >> n >> x;
    if(t == 1){
        convert_to_dec(n,x);
    }
    else {
        convert_from_dec(n,x);
    }


}