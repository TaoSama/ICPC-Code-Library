//
//  Created by TaoSama on 2017-02-26
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 5000 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
string val[N][5];
int cc[N][1005][2];

map<string, int> mp;

int op(int x, string& type, int y) {
    if(type == "OR") return x | y;
    else if(type == "XOR") return x ^ y;
    return x & y;
}

void get(int idx, int i, int& a0, int& a1) {
    a0 = cc[idx][i][0];
    a1 = cc[idx][i][1];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) {
            string s; cin >> s; mp[s] = i;
            cin >> s >> s;
            if(isdigit(s[0])) {
                val[i][0] = s, val[i][1] = "X";
                for(int j = 0; j < m; ++j) cc[i][j][0] = cc[i][j][1] = val[i][0][j];
            } else {
                val[i][0] = s;
                cin >> val[i][1] >> val[i][2];
            }
        }
//        for(int i = 1; i <= n; ++i){
//          if(val[i][1] == "X") cout << val[i][0] << endl;
//          else cout << val[i][0] << ' ' << val[i][1] << ' ' << val[i][2] << endl;
//        }

        string minv(m, '0'), maxv(m, '0');
        for(int i = 0; i < m; ++i) {
            int sum0 = 0, sum1 = 0;
            for(int j = 1; j <= n; ++j) {
                if(val[j][1] == "X") sum0 += val[j][0][i], sum1 += val[j][0][i];
                else {
                    int a0 = 0, a1 = 1, b0 = 0, b1 = 1;
                    if(val[j][0] != "?") get(mp[val[j][0]], i, a0, a1);
                    if(val[j][2] != "?") get(mp[val[j][2]], i, b0, b1);
                    cc[j][i][0] = op(a0, val[j][1], b0);
                    cc[j][i][1] = op(a1, val[j][1], b1);
                    sum0 += cc[j][i][0];
                    sum1 += cc[j][i][1];
                }
            }
            if(sum1 > sum0) maxv[i] = '1', minv[i] = '0';
            else if(sum0 > sum1) maxv[i] = '0', minv[i] = '1';
        }
        cout << minv << endl;
        cout << maxv << endl;
    }

    return 0;
}
