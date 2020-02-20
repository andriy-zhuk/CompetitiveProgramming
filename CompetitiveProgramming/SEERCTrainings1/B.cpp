//#pragma GCC optimize("Ofast")
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <iomanip>
//#include <string>
//#include <deque>
//#include <stack>
//#include <cmath>
//#include <iterator>
//#include <string.h>
//
//using namespace std;
//#ifndef DEBUGING
//ostream cnull(NULL);
//#define cerr cnull
//#endif // !DEBUGING
//
//#define PB push_back
//#define MP make_pair
//#define f first
//#define s second
//#define FOR(i,a,b) for (int i = a; i < b; ++i)
//#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
//#define FILL(a, b) memset(a, b, sizeof a)
//#define ALL(a) a.begin(), a.end()
//#define SZ(a) (int)a.size()
//
//typedef long long LL;
//typedef pair<int, int> PII;
//typedef vector<LL> VI;
//typedef pair<LL, LL> PLL;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//
//const LL mod = INF + 7;
//const int MAGIC = 1000000;
//struct node
//{
//	int y;
//	int val;
//	int sub;
//	int l, r;
//	node()
//	{
//		y = rand() % MAGIC;
//		val = 0;
//		sub = 0;
//		l = -1;
//		r = -1;
//	}
//	node(int v)
//	{
//		val = v;
//		sub = 1;
//		y = rand() % MAGIC;
//		l = -1;
//		r = -1;
//	}
//};
//
//struct DD
//{
//	node t[200005];
//	int vcount = 1;
//
//	int getSubtree(int v)
//	{
//		if (v == -1)
//			return 0;
//		return t[v].sub;
//	}
//	int getId(int v)
//	{
//		if (v == -1)
//			return 0;
//		return getSubtree(t[v].l) + 1;
//	}
//	void update(int v)
//	{
//		if (v == -1)
//			return;
//		t[v].sub = getSubtree(t[v].l) + getSubtree(t[v].r)+1;
//	}
//
//	int merge(int u, int v)
//	{
//		if (u == -1)
//			return v;
//		if (v == -1)
//			return u;
//		if (t[u].y > t[v].y)
//		{
//			t[u].r = merge(t[u].r, v);
//			update(u);
//			return u;
//		}
//		else
//		{
//			t[v].l = merge(u, t[v].l);
//			update(v);
//			return v;
//		}
//	}
//	
//	PII split(int u, int key)
//	{
//		if (u == -1)
//			return MP(-1, -1);
//		if (getId(u) <= key)
//		{
//			PII cur = split(t[u].r, key - getId(u));
//			t[u].r = cur.first;
//			update(u);
//			return MP(u, cur.second);
//		}
//		else
//		{
//			PII cur = split(t[u].l, key);
//			t[u].l = cur.second;
//			update(u);
//			return MP(cur.first, u);
//		}
//	}
//	void dfs(int u)
//	{
//		if (u == -1)
//			return;
//		dfs(t[u].l);
//		cout << t[u].val << ' ';
//		dfs(t[u].r);
//	}
//
//} q;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int n, m;
//	cin >> n >> m;
//	int root = q.vcount++;
//	q.t[root] = node(1);
//	FOR(i, 1, n)
//	{
//		int cur = q.vcount++;
//		q.t[cur] = node(i+1);
//		root = q.merge(root, cur);
//	}
//	FOR(i, 0, m)
//	{
//		int l, r;
//		cin >> l >> r;
//
//		PII a = q.split(root, l - 1);
//
//		PII b = q.split(a.second, r - l + 1);
//
//		root = q.merge(b.first, a.first);
//		root = q.merge(root, b.second);
//	}
//
//	q.dfs(root);
//	cout << endl;
//
//	return 0;
//}
//
