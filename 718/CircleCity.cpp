#line 2 "CircleCity.cpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
typedef long long ll;
typedef unsigned long long ull;
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 
const int MAXN = 2005;
int dist[MAXN], n;
class CircleCity {
public:
	int f(int X, vector <int> D) {
		int s = 0, cnt = 1;
		for (auto &L : D) {
			s += L;
			if (s > X) {
				cnt++;
				s = 0;
			}
		}
		return cnt;
	}
	int findMin(vector <int> _dist, int k) {
		n = _dist.size();
		for (int i = 0; i < n; i++) dist[i] = _dist[i];
		int lo = 0, hi = 1e9, ans = 1e9;
		while (lo <= hi) {
			int md = (lo + hi) / 2;
			int ok = 0;
			for (int i = 0; !ok && i < n; i++) {
				vector <int> D = {};
				for (int j = 0; j < n - 1; j++) {
					D.push_back(_dist[(i + j) % n]);
				}
				if (f(md, D) <= k) ok = 1;
			}
			if (ok) {
				hi = md - 1;
				ans = min(ans, md);
			}
			else lo = md + 1;
		}
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
		cout << "Testing CircleCity (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499908324;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc;
		istringstream(argv[1]) >> _tc;
		CircleCity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist[] = {3,5,4};
				int k = 2;
				_expected = 3;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 1:
			{
				int dist[] = {3,5,4};
				int k = 3;
				_expected = 0;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 2:
			{
				int dist[] = {1,2,3,4,5,6,5,4,3,2,1};
				int k = 5;
				_expected = 5;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 3:
			{
				int dist[] = {1, 100, 1,1,1, 100, 1, 100, 1,1,1, 100, 1};
				int k = 4;
				_expected = 3;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 4:
			{
				int dist[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7};
				int k = 6;
				_expected = 8;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 5:
			{
				int dist[] = {
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000
				             };
				int k = 7;
				_expected = 9000000;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			/*case 6:
			{
				int dist[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int dist[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}*/
			/*case 8:
			{
				int dist[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
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
