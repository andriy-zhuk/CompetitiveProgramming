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
//#include <queue> 
//
//using namespace std;
//
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
//typedef unsigned long long ULL;
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
//const LL MOD = INF + 7;
//
//int b, l, d;
//vector<int> bookScore;
//vector<int> signupTime;
//vector<double> euristic;
//vector<double> suma;
//struct library
//{
//	int id;
//	vector<int> books;
//	bool operator<(const library& l)
//	{
//		return -euristic[id] <-euristic[l.id];
//	}
//};
//
//vector<library> libs;
//vector<int> booksPerDay;
//vector<int> bcnt;
//
//
//vector<library> answer;
//vector<library> toprint;
//
//bool cmp(int i, int j)
//{
//	return 1.0 * pow(bcnt[i], 1) * 1.0 / pow(bookScore[i], 5.90) < 1.0 * pow(bcnt[j], 1) * 1.0 / pow(bookScore[j], 5.9);
//}
//
//
//LL score()
//{
//	vector<bool> used(b, false);
//	vector<pair<int, int> > inUse;
//	int last = signupTime[answer[0].id];
//	FOR(i, 0, answer.size())
//	{
//		toprint.PB({ answer[i].id, vector<int>() });
//	}
//	FOR(day, 0, d)
//	{
//		if (day == last)
//		{
//			if (inUse.size() < answer.size())
//			{
//				int idOfNext = answer[inUse.size()].id;
//				inUse.PB(MP(0, idOfNext));
//				if (inUse.size() < answer.size())
//				{
//					int next = answer[inUse.size()].id;
//					last += signupTime[next];
//				}
//			}
//		}
//
//		FOR(i, 0, inUse.size())
//		{
//			int id = inUse[i].second;
//			int l = inUse[i].first;
//			int r = min(l + booksPerDay[id], (int)answer[i].books.size());
//			while (l != r)
//			{
//				int book = answer[i].books[l];
//				if (used[book] == true)
//				{
//					l++, r = min(r + 1, (int)answer[i].books.size());
//					continue;
//				}
//				used[book] = true;
//				toprint[i].books.PB(book);
//				l++;
//			}
//			inUse[i].first = r;
//		}
//	}
//
//	LL ret = 0;
//	FOR(i, 0, used.size())
//	{
//		if (used[i])
//		{
//			ret += bookScore[i];
//		}
//	}
//	return ret;
//}
//
//void read()
//{
//	bookScore.clear();
//	libs.clear();
//	answer.clear();
//	booksPerDay.clear();
//	signupTime.clear();
//	toprint.clear();
//	cin >> b >> l >> d;
//	libs.resize(l);
//	euristic.resize(l, 0);
//	suma.resize(l, 0);
//	bcnt.resize(b, 0);
//	FOR(i, 0, b)
//	{
//		int x;
//		cin >> x;
//		bookScore.PB(x);
//	}
//	FOR(i, 0, l)
//	{
//		int x, y, z;
//		cin >> x >> y >> z;
//		signupTime.PB(y);
//		booksPerDay.PB(z);
//		libs[i].id = i;
//		FOR(j, 0, x)
//		{
//			int y;
//			cin >> y;
//			libs[i].books.PB(y);
//			bcnt[y]++;
//		}
//	}
//	FOR(i, 0, l)
//	{
//		sort(ALL(libs[i].books), &cmp);
//		FOR(j, 0, libs[i].books.size())
//		{
//			int b = libs[i].books[j];
//			double y = 1.0 * bookScore[b] / sqrt(bcnt[b]);
//			suma[i] += y;
//		}
//	}
//	FOR(i, 0, l)
//	{
//		euristic[i] = log(1.0 * suma[i] * suma[i] / sqrt(signupTime[i]) / signupTime[i] * sqrt(booksPerDay[i]));
//	}
//}
//
//const string input[5] = { "b_read_on.txt", "c_incunabula.txt", "d_tough_choices.txt", "e_so_many_books.txt", "f_libraries_of_the_world.txt" };
//const string output[5] = { "b_out.txt", "c_out.txt", "d_out.txt", "e_out.txt", "f_out.txt" };
//int main()
//{
//	ios_base::sync_with_stdio(0);
//
//	for (int i = 3; i < 5; i++) {
//		freopen(input[i].c_str(), "r", stdin);
//		freopen(output[i].c_str(), "w", stdout);
//		libs.clear();
//
//		read();
//		answer = libs;
//		sort(ALL(answer));
//		cerr << score() << '\n';
//
//		answer.clear();
//		for (auto& x : toprint)
//		{
//			if (x.books.size())
//			{
//				answer.PB({ x.id, x.books });
//			}
//		}
//		libs = answer;
//		cerr << score() << endl;
//		cout << answer.size() << '\n';
//		for (auto x : answer) {
//			cout << x.id << " " << x.books.size() << '\n';
//			if (x.books.size())
//			{
//				for (auto y : x.books) {
//					cout << y << " ";
//				}
//				cout << '\n';
//			}
//		}
//		fclose(stdin);
//		fclose(stdout);
//	}
//
//
//	return 0;
//}
//
