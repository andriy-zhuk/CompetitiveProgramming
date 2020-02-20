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
string s;
int p1[200005];
int p2[200005];

set<PII> answer;

set<int> pos1[200005];
set<int> pos2[200005];

void solve()
{
	FOR(i, 0, 200005)
	{
		pos1[i].clear();
		pos2[i].clear();
		p1[i] = p2[i] = 0;
	}
	FOR(i, 1, n+1)
	{
		p1[i] = p1[i - 1];
		p2[i] = p2[i - 1];
		if (s[i-1] == 'R')
		{
			p1[i] += 1;
			pos1[p1[i]].insert(i);
		}
		else
		{
			p2[i] += 1;
			pos2[p2[i]].insert(i);
		}
	}

	FOR(g, 1, n+1)
	{
		int cur = 0;
		bool ok = true;
		PII score = MP(0, 0);
		while (cur < n)
		{
			int pl1 = p1[cur] + g;
			int pl2 = p2[cur] + g;

			auto it1 = pos1[pl1].begin();
			auto it2 = pos2[pl2].begin();

			int v1 = n+2;
			if (it1 != pos1[pl1].end())
			{
				v1 = *it1;
			}
			int v2 = n+2;
			if (it2 != pos2[pl2].end())
			{
				v2 = *it2;
			}
			if (v1 < v2)
			{
				score.first++;
			}
			else
			{
				score.second++;
			}
			cur = min(v1, v2);
		}
		if (cur == n+2 || score.first == score.second)
		{
			continue;
		}
		answer.insert(MP(g, max(score.first, score.second)));
	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s;
	
	solve();
	FOR(i, 0, n)
	{
		if (s[i] == 'R')
		{
			s[i] = 'S';
		}
		else
		{
			s[i] = 'R';
		}
	}
	//solve(); 
	cout << answer.size() << endl;
	for (auto &iter: answer)
	{
		cout << iter.first << ' ' << iter.second << endl;
	}
	return 0;
}

