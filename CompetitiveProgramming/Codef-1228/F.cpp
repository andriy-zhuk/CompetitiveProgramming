#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <stack>
#include <cmath>
#include <iterator>
#include <string.h>

using namespace std;
#ifndef DEBUGING
ostream cnull(NULL);
#define cerr cnull
#endif // !DEBUGING

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;
int n;
#define prev petro

int used[200005];
int prev[200005];
vector<int> g[200005];

void dfs(int u, int d)
{
	used[u] = d;
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		if (!used[v])
		{
			prev[v] = u;
			dfs(v, d + 1);
		}
	}
}


int find()
{
	int st = 0;
	FILL(used, 0);
	dfs(0, 1);
	FOR(i, 0, n)
	{
		if (used[st] < used[i])
			st = i;
	}
	FILL(used, 0);
	FILL(prev, -1);
	dfs(st,1);
	int fn = 0;
	FOR(i, 0, n)
	{
		if (used[fn] < used[i])
			fn = i;
	}

	vector<int> ka;
	while (fn != st)
	{
		ka.PB(fn);
		fn = prev[fn];
	}
	return ka[ka.size() / 2];
}
int cnt[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	if (n == 2) {
		int x, y;
		cin >> x >> y;
		cout << 2 << endl;
		cout << x << ' '  << y << endl;
		return 0;
	}
	FOR(i, 0, (1 << n) - 3)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}

	int root = find();

	FOR(i, 0, (1<<n)-2)
	{
		cnt[g[i].size()]++;
		if (g[i].size() == 0 || g[i].size() > 4)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	int lysty = (1 << (n - 1));
	int roots = 1;
	int inshi = (1 << n) - 2 - lysty;

	if (cnt[2] == roots && cnt[3] == inshi && cnt[1] == lysty)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<int> bad;
	FOR(i, 0, (1<<n)-2)
	{
		if (SZ(g[i]) == 2)
		{
			bad.PB(i);
		}
	}
	if (bad.size() == 2)
	{
		cnt[2]--;
		cnt[1]++;
		cnt[3]++;
		if (cnt[2] == roots && cnt[3] == inshi && cnt[1] == lysty)
		{
			cout << 2 << endl;
			cout << 1 + bad[0] << ' ' << bad[1] + 1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	} 
	if (bad.size() > 2)
	{
		cout << 0 << endl;
		return 0;
	}
	bad.clear();
	FOR(i, 0, (1<<n)-2)
	{
		if (SZ(g[i]) == 4)
		{
			bad.PB(i);
		}
	}
	if (bad.size() == 1)
	{
		cnt[4]--;
		cnt[3] += 2;
		if (cnt[2] == roots && cnt[3] == inshi && cnt[1] == lysty)
		{
			cout << 1 << endl;
			cout << bad.back()+1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	if (bad.size() != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	cnt[2]++;
	
	if (cnt[2] == roots && cnt[3] == inshi && cnt[1] == lysty)
	{
		cout << 1 << endl;
		cout << root+1 << endl;
		return 0;
	}
	else
	{	
		cout << 0 << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}

