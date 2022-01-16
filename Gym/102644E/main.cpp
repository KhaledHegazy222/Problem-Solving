#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 4294967296;

 int valid( int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}


vector<vector<unsigned int>> matMul(vector<vector<unsigned int>>a,vector<vector<unsigned int>>b){
    unsigned int r1 = a.size();
    unsigned int c1 = a[0].size();
    unsigned int r2 = b.size();
    unsigned int c2 = b[0].size();

    vector<vector<unsigned int>>ret(r1,vector<unsigned int>(c2));
    for(unsigned int i = 0;i<r1;i++){
        for(unsigned int j = 0;j<c1;j++){
            for(unsigned int k = 0;k < c2;k++){
                ret[i][k] = ret[i][k] + a[i][j] * b[j][k];
            }
        }
    }
    return ret;
}


vector<vector<unsigned int>> power(vector<vector<unsigned int>>b,unsigned int p){
    unsigned int d = b.size();
    vector<vector<unsigned int>>ret(d,vector<unsigned int>(d));
    for(unsigned int i = 0;i<d;i++){
        for(unsigned int j = 0;j<d;j++){
            ret[i][j] = (i == j);
        }
    }
    while(p){
        if(p & 1)
            ret = matMul(ret,b);
        b = matMul(b,b);
        p >>= 1;
    }
    return ret;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    unsigned int k;
    cin >> k;
    k++;
    vector<vector<unsigned int>>a(1,vector<unsigned int>(65));
    a[0][0] = 1;
    vector<vector<unsigned int>>Mat(65,vector<unsigned int>(65));
    for( int i = 0;i<8;i++){
        for( int j = 0;j<8;j++){
            for( int di : {2,-2,1,-1}){
                for( int dj : {2,-2,1,-1}){
                    if(abs(di) == abs(dj))
                        continue;
                     int ii = i + di;
                     int jj = j + dj;
                    if(valid(ii,jj)){
                        Mat[i * 8 + j][ii * 8 + jj] = 1;
                    }
                }
            }
        }
    }
    
    for( int i = 0;i<65;i++){
        Mat[i][64] = 1;
    }
    Mat = power(Mat,k);
    a = matMul(a,Mat);
    cout << a[0][64] << endl;
}   



