//
//  Created by TaoSama on 2015-07-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, unknown;
bool have[25][15];
string a[25][15];

bool calc(int i, int j) {
    string& s = a[i][j];
    int ret = 0, k = 0, tmp = 0;
    char op = '+';
    while(k < s.size()) {
        if(isdigit(s[k])) tmp = tmp * 10 + s[k] - '0';
        else if(isalpha(s[k])) {
			int x = s[k] - 'A', y = s[k + 1] - '0';
			if(!have[x][y]) return false;
			if(op == '+') ret += atoi(a[x][y].c_str());
			else ret -= atoi(a[x][y].c_str());
			k ++;
        }
        else {
        	if(op == '+') ret += tmp;
			else ret -= tmp;
			tmp = 0;
			op = s[k];
        }
        k++;
    }
    char buf[105];  sprintf(buf, "%d", ret);
    a[i][j] = string(buf);
    have[i][j] = true;
    unknown--;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m && (n || m)) {
        memset(have, false, sizeof have);

        unknown = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if(isdigit(a[i][j][0])) have[i][j] = true;
                else {
                	a[i][j] += '+'; //convenience for calculation
					unknown++;
                }
            }
        }

        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(!have[i][j] && calc(i, j))
                        changed = true;
                }
            }
        }

        if(unknown) {
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    if(!have[i][j]) {
                        cout << char('A' + i) << char('0' + j) << ": ";
                        for(int k = 0; k < a[i][j].size() - 1; ++k) cout << a[i][j][k];
                        cout << '\n';
                    }
        } else {
            cout << " ";
            for(int i = 0; i < m; ++i) cout << setw(6) << i; cout << '\n';
            for(int i = 0; i < n; ++i) {
                cout << char('A' + i);
                for(int j = 0; j < m; ++j) {
                    cout << setw(6) << atoi(a[i][j].c_str());
                }
                cout << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
