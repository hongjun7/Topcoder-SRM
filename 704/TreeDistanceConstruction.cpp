#line 2 "TreeDistanceConstruction.cpp"
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
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 
class TreeDistanceConstruction {
public:
	vector <int> construct(vector <int> d) {
		vector <int> ans, v[55];
		int dm = 0;
		for (int i = 0; i < d.size(); i++) {
			v[d[i]].push_back(i);
			dm = max(dm, d[i]);
		}
		int r = 0;
		if (dm & 1) {
			if (v[dm / 2 + 1].size() != 2) return {};
			ans.push_back(v[dm / 2 + 1][0]);
			ans.push_back(v[dm / 2 + 1][1]);
			r = dm / 2 + 1;
		}
		else {
			if (v[dm / 2].size() != 1) return {};
			r = dm / 2;
		}
		for (int i = 0; i < r; i++) if (!v[i].empty()) return {};
		for (int dist = r + 1; dist <= dm; dist++) {
			if (v[dist].size() < 2) return {};
			for (int i = 0; i < v[dist].size(); i++) {
				ans.push_back(v[dist][i]);
				ans.push_back(v[dist - 1][i%v[dist - 1].size()]);
			}
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
		cout << "Testing TreeDistanceConstruction (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486342566;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeDistanceConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {3,2,2,3};
				int __expected[] = {1, 2, 1, 0, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {1,2,2,2};
				int __expected[] = {0, 1, 0, 2, 0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {1,1,1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {1,1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {1,1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 5:
			{
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
