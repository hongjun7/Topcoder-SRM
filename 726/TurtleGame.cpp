#line 2 "TurtleGame.cpp"
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

class TurtleGame {
public:
	string getwinner(vector <string> board) {
		int cnt = 0;
		for (auto &row : board) {
			for (auto &x : row) {
				if (x == '.') cnt++;
			}
		}
		cnt -= board.size() + board[0].size() - 1;
		string ans;
		if (cnt & 1) ans = "Win";
		else ans = "Lose";
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
		cout << "Testing TurtleGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1516021671;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TurtleGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"..",
				                  ".."};
				_expected = "Win";
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"...",
				                  ".#.",
				                  ".#.",
				                  "..."};
				_expected = "Lose";
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".##",
				                  "..#",
				                  "#.."};
				_expected = "Lose";
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"....",
				                  "...#",
				                  "#...",
				                  "...."};
				_expected = "Win";
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"...#.",
				                  "....#",
				                  "#....",
				                  "..##."};
				_expected = "Win";
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"..........",
				                  "........#."};
				_expected = "Lose";
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getwinner(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
