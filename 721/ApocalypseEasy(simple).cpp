#line 2 "ApocalypseEasy.cpp"
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <limits>
using namespace std;

int N, dist[55][55], f[105][105], C[55];
int Q[105], fr, re, chk[105], P[105];
vector <int> G[55];

class ApocalypseEasy {
public:
	bool bfs() {
		for (int i = 0; i <= N + N + 1; i++) chk[i] = 0;
		Q[fr = re = 0] = 0;
		chk[0] = 1;
		while (fr <= re) {
			int x = Q[fr++];
			for (int y = 0; y <= N + N + 1; y++) {
				if (f[x][y] && !chk[y]) {
					chk[y] = 1;
					Q[++re] = y;
					P[y] = x;
				}
			}
		}
		if (!chk[N + N + 1]) return 0;
		int p = N + N + 1;
		while (p > 0) {
			int q = P[p];
			f[q][p]--; f[p][q]++;
			p = q;
		}
		return 1;
	}
	int maximalSurvival(vector <int> p, vector <int> position, int t) {
		N = p.size() + 1;
		for (int i = 0; i < p.size(); i++) {
			G[i + 1].push_back(p[i]);
			G[p[i]].push_back(i + 1);
		}
		for (int i = 0; i < N; i++) C[i] = 0;
		for (int i = 0; i < position.size(); i++) {
			C[position[i]] = 1;
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dist[i][j] = 0;
		for (int i = 0; i < N; i++) {
			Q[fr = re = 0] = i;
			while (fr <= re) {
				int x = Q[fr++];
				for (int j = 0; j < G[x].size(); j++) {
					int y = G[x][j];
					if (dist[i][y] == 0) {
						dist[i][y] = dist[i][x] + 1;
						Q[++re] = y;
					}
				}
			}
		}
		for (int i = 0; i <= N + N + 1; i++) for (int j = 0; j <= N + N + 1; j++) f[i][j] = 0;
		for (int i = 0; i < N; i++) {
			if (C[i]) {
				f[0][i + 1] = 1;
				for (int j = 0; j < N; j++) {
					if (dist[i][j] <= t) f[i + 1][N + j + 1] = 1;
				}
			}
			else f[N + i + 1][N + N + 1] = 1;
		}
		int ans = 0;
		while (bfs()) ans++;
		return ans;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing ApocalypseEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516681964;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ApocalypseEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,2};
				int position[] = {2,3};
				int t = 1;
				_expected = 1;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 1:
			{
				int p[] = {0,1,2};
				int position[] = {2,3};
				int t = 2;
				_expected = 2;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 2:
			{
				int p[] = {0,0,0,1,2,3};
				int position[] = {1,2,3};
				int t = 1;
				_expected = 3;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 3:
			{
				int p[] = {0,1,2,3,4,5,6,7,8,9};
				int position[] = {0,1,2,3,4,5,6};
				int t = 50;
				_expected = 4;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 4:
			{
				int p[] = {0,0,0,0,0};
				int position[] = {0,1,2};
				int t = 2;
				_expected = 3;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			case 5:
			{
				int p[] = {0};
				int position[] = {0,1};
				int t = 1;
				_expected = 0;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
			/*case 6:
			{
				int p[] = ;
				int position[] = ;
				int t = ;
				_expected = ;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int position[] = ;
				int t = ;
				_expected = ;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}*/
			/*case 8:
			{
				int p[] = ;
				int position[] = ;
				int t = ;
				_expected = ;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
