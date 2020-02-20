////#pragma GCC optimize("Ofast")
////#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define PB push_back
//#define MP make_pair
//#define EB emplace_back
//#define f first
//#define s second
//#define FOR(i,a,b) for (int i = a; i < (b); ++i)
//#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
//#define FILL(a, b) memset(a, b, sizeof a)
//#define ALL(a) a.begin(), a.end()
//#define SZ(a) ((int)a.size())
//#define bitc(n) __builtin_popcount(n)
//#define MAGIC0 mt19937 rnd(time(0)); //rnd()
//
//typedef long long LL;
//typedef unsigned long long ULL;
//typedef vector<int> VI;
//typedef pair<int, int> PII;
//typedef pair<LL, LL> PLL;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 1e6 + 7;
//const double PI = acos(-1.);
//const double EPS = 1e-7;
//const int MAXN = 5 * 100007;
//
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//
//struct WaveletTree
//{
//	VI pref;
//	LL mn = 1, mx = LINF;
//	WaveletTree* left = nullptr;
//	WaveletTree* right = nullptr;
//	WaveletTree(LL a, LL b) : mn(a), mx(b), pref(1, 0) {}
//	void add(LL el)
//	{
//		LL mid = (mn + mx) >> 1;
//		if (pref.empty())
//		{
//			pref.PB(0);
//		}
//		auto f = [&mid](LL el)
//		{
//			return el <= mid;
//		};
//		pref.PB(pref.back() + f(el));
//		if (mn == mx)
//		{
//			return;
//		}
//		if (f(el))
//		{
//			if (left == nullptr)
//			{
//				left = new WaveletTree(mn, mid);
//			}
//			left->add(el);
//		}
//		else
//		{
//			if (right == nullptr)
//			{
//				right = new WaveletTree(mid + 1, mx);
//			}
//			right->add(el);
//		}
//	}
//	LL kth(int l, int r, int k)
//	{
//		// cout << "\n";
//		// cout << mn << " " << mx << " " << l << " " << r << " " << k << "\n";
//		if (l > r)
//		{
//			return 0;
//		}
//		if (mn == mx)
//		{
//			return mn;
//		}
//		int lb = pref[l - 1], rb = pref[r];
//		// cout << lb << " " << rb << "\n";
//		int toLeft = rb - lb;
//		if (k <= toLeft)
//		{
//			return left->kth(lb + 1, rb, k);
//		}
//		else
//		{
//			return right->kth(l - lb, r - rb, k - toLeft);
//		}
//	}
//};
//
//int main()
//{
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	//freopen("roads.in", "r", stdin);
//	//freopen("roads.out", "w", stdout);
//	LL n;
//	WaveletTree t(1, LINF);
//	int cnt = 0;
//	while (cin >> n)
//	{
//		if (n == 0)
//		{
//			if (cnt % 2 == 0)
//			{
//				LL a = t.kth(1, cnt, cnt / 2);
//				LL b = a + t.kth(1, cnt, cnt / 2 + 1);
//				cout << b / 2 << '.' << (b % 2) * 5 << endl;
//			}
//			else
//			{
//				cout << t.kth(1, cnt, cnt / 2 + 1) << "\n";
//			}
//		}
//		else
//		{
//			t.add(n);
//			++cnt;
//		}
//	}
//
//	return 0;
//}