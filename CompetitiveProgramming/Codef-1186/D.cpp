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
const LL mod = INF + 6;

pair<int, int> read()
{
	string s;
	getline(cin, s);
	getline(cin, s, '.');
	int ff = atoi(s.c_str());
	int ss;
	cin >> ss;
	if (0 == ss)
		return MP(ff, 0);
	if (s[0] == '-') {
		ff--;
		ss = 100000 - ss;
	}
	//cout << ff << ' ' << ss << endl;
	return MP(ff, ss);
}
int n;

PII sum;
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		//cout << sum.first << '+' << sum.second << endl;
		PII cur = read();
		if (cur.second == 0)
		{
			cout << cur.first << endl;
			continue;
		}
		if (sum.first > 0 || sum.first == 0 && sum.second > 0)
		{
			if (cur.first < 0)
			{
				cout << cur.first << endl;
			}
			else
			{
				cout << cur.first << endl;
			}
			sum.second -= cur.second;
		}
		else
		{
			if (cur.first < 0)
			{
				cout << cur.first + 1<< endl;
			}
			else
			{
				cout << cur.first + 1 << endl;
			}
			sum.second += (100000 - cur.second);
		}
		if (sum.second < 0)
		{
			sum.first--;
			sum.second += 100000;
		}
		if (sum.second >= 100000)
		{
			sum.first++;
			sum.second -= 100000;
		}
	}
	if (sum.first != 0 || sum.second != 0)
	{
		return -1;
	}


	return 0;
}