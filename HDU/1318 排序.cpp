#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

set<string> s;
set<string>::iterator iter;
string x;

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	bool isDict = true;
	while(cin >> x) {
		if(x == "XXXXXX") {
			isDict = !isDict;
			if(isDict) s.clear();
			continue;
		}
		if(isDict) s.insert(x);
		else {
			bool ok = true;
			sort(x.begin(), x.end());
			do {
				if((iter = s.find(x)) != s.end()) {
					ok = false;
					cout << *iter << endl;
				}
			} while(next_permutation(x.begin(), x.end()));
			if(ok)	cout << "NOT A VALID WORD" << endl;
			cout << "******" << endl;
		}
	}
	return 0;
}