
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
#define PI (acos(-1))

using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;

map<int,string>roman_letters;


void init(void){

    roman_letters.insert({1,"I"});
    roman_letters.insert({2,"II"});
    roman_letters.insert({3,"III"});
    roman_letters.insert({4,"IV"});
    roman_letters.insert({5,"V"});
    roman_letters.insert({6,"VI"});
    roman_letters.insert({7,"VII"});
    roman_letters.insert({8,"VIII"});
    roman_letters.insert({9,"IX"});
    roman_letters.insert({10,"X"});

    
    roman_letters.insert({20,"XX"});
    roman_letters.insert({30,"XXX"});
    roman_letters.insert({40,"XL"});
    roman_letters.insert({50,"L"});
    roman_letters.insert({60,"LX"});
    roman_letters.insert({70,"LXX"});
    roman_letters.insert({80,"LXXX"});
    roman_letters.insert({90,"XC"});
    roman_letters.insert({100,"C"});
    
    roman_letters.insert({200,"CC"});
    roman_letters.insert({300,"CCC"});
    roman_letters.insert({400,"CD"});
    roman_letters.insert({500,"D"});
    roman_letters.insert({600,"DC"});
    roman_letters.insert({700,"DCC"});
    roman_letters.insert({800,"DCCC"});
    roman_letters.insert({900,"CM"});
    roman_letters.insert({1000,"M"});
    
    roman_letters.insert({2000,"MM"});
    roman_letters.insert({3000,"MMM"});
}




string to_roman(int num){
    string res = "";
    int digits = 1000;
    while(digits > 0){
        int x = (num / digits) * digits;
        res = res + roman_letters[x];
        num %= digits;
        digits /= 10;
    }
    return res;
}



int to_dec(string roman){
    int res = 0;
    for(int i = 1;i<4000;i++){
        if(roman == to_roman(i))
            return i;
    }
}


int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    
    #ifndef offline_vs_code
        //freopen("baklava.in","r",stdin);
    #endif 

    init();

    string s;
    while(cin >> s){
        if(isdigit(s[0])){
            int num = stoi(s);
            cout << to_roman(num);
        }
        else
            cout << to_dec(s);

        cout << '\n';
    }



}