#line 2 "FiveRooks.cpp"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
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

struct MaxFlowDinic {
	typedef int flow_t;
	struct Edge {
		int next;
		size_t inv; /* inverse edge index */
		flow_t res; /* residual */
	};
	int n;
	vector<vector<Edge>> G;
	vector<int> q, l, start;

	void init(int _n) {
		n = _n;
		G.resize(n);
		for (int i = 0; i < n; i++) G[i].clear();
	}
	void add_edge(int s, int e, flow_t cap, flow_t caprev = 0) {
		Edge forward{ e, G[e].size(), cap };
		Edge reverse{ s, G[s].size(), caprev };
		G[s].push_back(forward);
		G[e].push_back(reverse);
	}
	bool assign_level(int source, int sink) {
		int t = 0;
		memset(&l[0], 0, sizeof(l[0]) * l.size());
		l[source] = 1;
		q[t++] = source;
		for (int h = 0; h < t && !l[sink]; h++) {
			int cur = q[h];
			for (const auto& e : G[cur]) {
				if (l[e.next] || e.res == 0) continue;
				l[e.next] = l[cur] + 1;
				q[t++] = e.next;
			}
		}
		return l[sink] != 0;
	}
	flow_t block_flow(int cur, int sink, flow_t current) {
		if (cur == sink) return current;
		for (int& i = start[cur]; i < G[cur].size(); i++) {
			auto& e = G[cur][i];
			if (e.res == 0 || l[e.next] != l[cur] + 1) continue;
			if (flow_t res = block_flow(e.next, sink, min(e.res, current))) {
				e.res -= res;
				G[e.next][e.inv].res += res;
				return res;
			}
		}
		return 0;
	}
	flow_t solve(int source, int sink) {
		q.resize(n);
		l.resize(n);
		start.resize(n);
		flow_t ans = 0;
		while (assign_level(source, sink)) {
			memset(&start[0], 0, sizeof(start[0]) * n);
			while (flow_t flow = block_flow(source, sink, numeric_limits<flow_t>::max()))
				ans += flow;
		}
		return ans;
	}
};

class FiveRooks {
public:
	vector <int> find(vector <string> board) {
		vector <int> ans;
		MaxFlowDinic f;
		f.init(8 + 8 + 3);
		int sink = 8 + 8 + 1;
		int s1 = 0, s2 = 8 + 8 + 2;
		f.add_edge(s2, s1, 5);
		for (int i = 0; i < 8; i++) {
			f.add_edge(s1, i + 1, 1);
			f.add_edge(8 + i + 1, sink, 1);
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {
					f.add_edge(i + 1, 8 + j + 1, 1);
				}
			}
		}
		int flow = f.solve(s2, sink);
		for (int i = 1; i <= 8; i++) {
			for (auto &e : f.G[i]) {
				int j = e.next - 8;
				if (1 <= j && j <= 8 && e.res == 0) {
					ans.push_back(i - 1);
					ans.push_back(j - 1);
					break;
				}
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
		cout << "Testing FiveRooks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515587174;
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
		FiveRooks _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "R.......",
				                 "........",
				                 "........",
				                 "........"
				                 };
				int __expected[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {
				                 "R.R.R.R.",
				                 ".R.R.R.R",
				                 "R.R.R.R.",
				                 ".R.RRR.R",
				                 "R.R.R.R.",
				                 ".R.R.R.R",
				                 "R.R.R.R.",
				                 ".R.R.R.R"
				                 };
				int __expected[] = {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR",
				                 "RRRRRRRR"
				                 };
				int __expected[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {
				                 ".RRRRRR.",
				                 "RRRRRRRR",
				                 "....RRRR",
				                 "...RRRR.",
				                 "..RRRR..",
				                 ".RRRR...",
				                 "RRRR....",
				                 "RRR....."
				                 };
				int __expected[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {
				                 ".RRRRRR.",
				                 "RRRRRRRR",
				                 "....RRRR",
				                 "...RRRR.",
				                 "..RRRR..",
				                 ".RRRR...",
				                 "RRRRRRRR",
				                 ".RRRRRR."
				                 };
				int __expected[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = 
				                 {
				                 ".RRRRRR.",
				                 "RRRRRRRR",
				                 ".RRRR...",
				                 "..RRRR..",
				                 "...RRRR.",
				                 "....RRRR",
				                 "RRRRRRRR",
				                 ".RRRRRR."
				                 };
				int __expected[] = {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
