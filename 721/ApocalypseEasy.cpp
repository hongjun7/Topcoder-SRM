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
int N, C[55], f[2555][2555], Q[2555], fr, re, chk[2555], P[2555];
vector <int> g[55];
class ApocalypseEasy {
public:
	bool bfs(int s, int e) {
		for (int i = 0; i <= e; i++) chk[i] = 0;
		Q[fr = re = 0] = s;
		chk[s] = 1;
		while (fr <= re) {
			int x = Q[fr++];
			for (int i = 0; i <= e; i++) {
				if (f[x][i] && !chk[i]) {
					chk[i] = 1;
					Q[++re] = i;
					P[i] = x;
				}
			}
		}
		if (!chk[e]) return 0;
		int p = e;
		while (p != s) {
			int q = P[p];
			f[q][p]--; f[p][q]++;
			p = q;
		}
		return 1;
	}
	int maximalSurvival(vector <int> p, vector <int> position, int t) {
		N = p.size() + 1;
		for (int i = 0; i < N; i++) {
			g[i].clear();
			C[i] = 0;
		}
		for (int i = 0; i < p.size(); i++) {
			g[i + 1].push_back(p[i]);
			g[p[i]].push_back(i + 1);
		}
		for (int i = 0; i < position.size(); i++) {
			C[position[i]] = 1;
			f[0][position[i] + 1] = 1;
		}
		for (int time = 0; time < t; time++) {
			for (int x = 0; x < N; x++) {
				f[time*N + x + 1][(time + 1)*N + x + 1] = 100;
				for (int i = 0; i < g[x].size(); i++) {
					int y = g[x][i];
					f[time*N + x + 1][(time + 1)*N + y + 1] = 100;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (!C[i]) f[t*N + i + 1][(t + 1)*N + 1] = 1;
		}
		int ans = 0;
		while (bfs(0, (t + 1)*N + 1)) ans++;
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
		int T = time(NULL)-1516666171;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc = 4;
		istringstream(argv[1]) >> _tc;
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
			case 6:
			{
				int p[] = { 0, 0, 1, 2, 1, 1, 3, 0, 2, 3, 0, 1, 0, 1, 1, 0, 2, 3, 3, 0, 0, 0, 1, 3, 0, 2, 3, 0, 1, 2, 3, 3, 2, 3, 2, 2, 1 };
				int position[] = { 6, 9, 32, 33, 23, 8, 30 };
				int t = 1;
				_expected = 4;
				_received = _obj.maximalSurvival(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(position, position+sizeof(position)/sizeof(int)), t); break;
			}
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
