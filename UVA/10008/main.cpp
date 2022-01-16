

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MAX 100000

using namespace std;

bool srt(pair<char,int>a,pair<char,int>b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int n;
    cin >> n;
    cin.ignore(10,'\n');
    vector<pair<char,int>>alpha(26);
    for(int i = 0;i<26;i++){
        alpha[i].first = i + 'a';
        alpha[i].second = 0;
    }
    while(n--){
        string line;
        getline(cin,line);
        for(int i = 0;i<line.size();i++){
            if(isalpha(line[i])){
                alpha[tolower(line[i])-'a'].second++;
            }
        }
    }

    sort(all(alpha),srt);

    for(int i = 0;i<26;i++){
        if(alpha[i].second){
            cout << (char) toupper(alpha[i].first) << " " << alpha[i].second << endl;
        }
    }

    
}

