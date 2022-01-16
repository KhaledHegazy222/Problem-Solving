
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

map<char,int>digits;
map<int,char>digitss;


string convert_to_dec(string number,int old_base){
    ll fact = 1;
    ll res = 0;
    for(int i = number.size() - 1;i>= 0;i--){
        res += fact * digits[number[i]];
        fact *= old_base;
    }
    string ret = to_string(res);
    return ret;
}


string convert_from_dec(string number,int new_base){
    ll num = atoll(number.c_str());
    string res = "";
    while(num){
        int x = num % new_base;
        res.push_back(digitss[x]);
        num /= new_base;
    }
    reverse(all(res));
    return res;

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



    int n;
    cin >> n;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<n;j++){
            string s = to_string(i*j);
            string p = convert_from_dec(s,n);
            cout << p << " ";
        }
        cout << endl;
    }


}