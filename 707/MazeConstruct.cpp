#line 2 "MazeConstruct.cpp"
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
class MazeConstruct {
public:
	vector <string> solve(vector <string> ans, int k) {
		int s = ans.size();
		for (int i = 1; i < ans[0].size(); i += 2) {
			if (i % 4 == 1) {
				for (int j = 0; j < s - 1; j++) {
					ans[j][i] = '#';
				}
			}
			else {
				for (int j = s - 1; j >= 1; j--) {
					ans[j][i] = '#';
					k -= 2;
					if (k < 0) return {};
					if (k == 0) return ans;
				}
			}
		}
		return {};
	}
	vector <string> construct(int k) {
		vector <string> ans;
		ans.push_back("");
		k++;
		for (int i = 0; k && i < 50; i++) ans[0] += ".", k--;
		if (k == 0) return ans;
		for (int i = 1; k && i < 50; i++) {
			ans.push_back(ans[0]);
			k--;
		}
		if (k == 0) return ans;
		vector <string> res = solve(ans, k);
		if (res.size() == 0) {
			ans.pop_back();
			k++;
			res = solve(ans, k);
		}
		return res;
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
		cout << "Testing MazeConstruct (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485828003;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MazeConstruct _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 99;
				string __expected[] = {"...." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 1:
			{
				int k = 4;
				string __expected[] = {"...", "...", "..." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 2:
			{
				int k = 100;
				string __expected[] = {"..#..", "#.#..", "..#..", ".#...", "....." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			/*case 3:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}*/
			/*case 4:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}*/
			/*case 5:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
