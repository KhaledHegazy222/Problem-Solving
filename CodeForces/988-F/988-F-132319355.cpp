#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define MSET(c, v) memset(c, v, sizeof(c))
#define debug(x) cout << #x << " is " << x << endl
    
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 998244353;
const ll llInf = 4e18;
const int inf = 1e9;
    
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

const int maxn = 2e3 + 400;

ll dp[maxn][maxn];

int a,n,m;

int rain[maxn];

ll c[maxn];

vector<pair<ll,int> >umb[maxn];

ll solve(int i, int j) {
    if(rain[i] && j == 0) 
        return llInf;
    if(i == a)
        return 0;
    ll &ans = dp[i][j];
    if(ans != -1) {
        return ans;
    }
    ans = llInf;
    ans = min(ans, solve(i + 1, 0));
    ans = min(ans, solve(i + 1, j) + c[j]);

    for(auto &x : umb[i]) {
        ans = min(ans, solve(i + 1, x.second) + x.first);
    }

    return ans;
}

void solveTestCase(int test) {
    cin >> a >> n >> m;
    for(int i = 1; i <= n; i++) {
        int l,r;
        cin >> l >> r;
        rain[l + 1]++;
        rain[r + 1]--;
    }

    for(int i = 1; i <= a; i++) {
        rain[i] += rain[i - 1];
    }

    MSET(dp, -1);

    for(int i = 1; i <= m; i++) {
        int p;
        cin >> p >> c[i];
        umb[p].push_back({c[i], i});
    }

    auto ans = solve(0, 0);
    if(ans >= llInf)
        ans = -1;
    cout << ans << endl;


}

int main() {
    ios::sync_with_stdio(false);
    int test = 1;
    // cin >> test;
    for(int t = 1; t <= test; t++) {
        solveTestCase(t);
    }

    return 0;
}