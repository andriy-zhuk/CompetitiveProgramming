//#include <iostream>
//#include <fstream>
//#include <numeric>
//#include <stdio.h>
//#include <cmath>
//#include <queue>
//#include <iomanip>
//#include <algorithm>
//#include <vector>
//#include <set>
//#include <stack>
//#include <map>
//#include <deque>
//#include <bitset>
//#include <cstring>
//#include <sstream>
//#include <cinttypes>
//
//#define f first
//#define s second
//#define ll long long
//#define ull unsigned long long
//#define ld long double
//#define pb push_back
//#define all(x) x.begin(),x.end()
//#define mp make_pair
//#define y0 eto
//#define y1 mezhdy
//#define y2 nami
//#define left extermination
//#define right dismemberment
//
//using namespace std;
//
//void runtime() { cout << fixed << setprecision(5) << 1.0 * clock() / CLOCKS_PER_SEC << endl; }
//
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//
//template <class T>void read(vector<T>& a, ll n) { T x; a.clear(); for (ll i = 0; i < n; i++) { cin >> x; a.pb(x); } }
//template <class T>void write(vector<T>& a) { for (T x : a) cout << x << " "; cout << endl; }
//
//const int N = 42787470;
//
//int n;
//vector<int> res;
//
//int ftree[N];
//
//void add(int x, int d)
//{
//	for (int i = x; i < N; i |= i + 1)
//		ftree[i] += d;
//}
//
//int sum(int x)
//{
//	int res = 0;
//	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
//		res += ftree[i];
//	return res;
//}
//int sum(int l, int r)
//{
//	return sum(r) - sum(l - 1);
//}
//int curva[N];
//
//
//int main()
//{
//	auto startTime = clock();
//	ios_base::sync_with_stdio(false);
//	//    freopen("INPUT.txt","r",stdin);
//
//	int cnt = -1;
//	for (int i = 3; i < N; i += 2)
//	{
//		cnt++;
//		if (cnt % 3)
//			add(i, 1), curva[i]++;
//	}
//
//	res.pb(2);
//	res.pb(3);
//
//	int pos = 3;
//
//	while (res.size() <= 2169951)
//	{
//		while (curva[pos] == 0) pos++;
//		//while (sum(pos, pos) == 0) pos++;
//		int cur = pos;
//		res.pb(cur);
//		vector<int> v;
//		int x = pos + 1;
//		while (x < N)
//		{
//			int l = x;
//			int r = 41887470;
//
//			if (sum(l, r) < cur) break;
//
//			if (sum(l, l + 31) >= cur)
//				r = l + 31;
//			else if (sum(l, l + 2047) >= cur)
//				r = l + 2047;
//
//			while (r != l)
//			{
//				int mid = (r + l) / 2;
//				if (sum(x, mid) < cur)
//					l = mid + 1;
//				else
//					r = mid;
//			}
//			add(l, -1), curva[l]--;
//			x = l + 1;
//		}
//		pos++;
//	}
//	cout << (double)(clock()-startTime)/CLOCKS_PER_SEC << endl;
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int ans = 1;
//		int pos = 0;
//		int n;
//		//cin >> n;
//		n = 1000000000 - rand() % 64;
//		n--;
//		while (1)
//		{
//			ans++;
//			n--;
//			n -= n / res[pos];
//			pos++;
//			if (res[pos] > n)
//			{
//				ans += n;
//				break;
//			}
//		}
//		cout << ans << endl;
//
//	}
//
//
//}
