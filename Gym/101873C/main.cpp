
#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define fast cin.tie(0), ios::sync_with_stdio(0), cout.tie(0)
#define ll long long

using namespace std;
ll inValid = 1e10 + 5;
const int N = 2e3 + 3;
int t[N], p[N], mvTim;

int head[N], nxt[N], to[N], n, m, ne;
void init()
{
	memset(head, -1, (n + 1) * sizeof head[0]);
	ne = 0;
}

void addEdge(int u, int v)
{
	nxt[ne] = head[u];
	to[ne] = v;
	head[u] = ne++;
}
void addBiEdge(int u, int v)
{
	addEdge(u, v);
	addEdge(v, u);
}

int solve(int idx, int remain)
{
	if (remain <= 0)
	{
		if (remain || idx)
			return 1e9;
		return 0;
	}

	int ret = solve(idx, remain - t[idx]) + p[idx];

	for (int e = head[idx]; ~e; e = nxt[e])
	{
		int v = to[e];
		ret = min(ret, p[v] + solve(v, remain - t[v] - mvTim));
	}
	return ret;
}

ll dp[N][N];

ll solve2(int idx, int rem)
{
	if (rem < t[idx])
		return inValid + 5;
	if (rem == t[idx])
	{
		if (!idx)
			return p[idx];
		return inValid + 5;
	}
	ll &ret = dp[idx][rem];
	if (~ret)
		return ret;
	ret = p[idx];
	ll x = solve2(idx, rem - t[idx]);
	for (int e = head[idx]; ~e; e = nxt[e])
	{
		int v = to[e];
		x = min(x, solve2(v, rem - t[idx] - mvTim));
	}
	return ret += x;
}

int main(void)
{
#ifdef Khaled
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	fast;
	memset(dp, -1, sizeof dp);
	int x;
	cin >> x >> n >> m >> mvTim;
	init();
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		addBiEdge(--u, --v);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> p[i];
	}
	//int res = solve(0,x - t[0]) + p[0];
	ll res2 = solve2(0, x);
	if (res2 >= inValid)
		return puts("It is a trap.") * 0;
	cout << res2 << endl;
}