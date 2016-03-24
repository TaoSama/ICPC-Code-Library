//
//  Created by TaoSama on 2015-08-02
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
#include <sstream>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cnt;
string me, name[205];
map<string, int> mp;
struct P {
    int v; string name;
    bool operator<(const P& rhs) const {
        return v > rhs.v || v == rhs.v && name < rhs.name;
    }
} a[205];

int ID(string &x) {
    if(mp.count(x)) return mp[x];
    else {
        name[++cnt] = x;
        return mp[x] = cnt;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> me) {
        cnt = 0; mp[me] = ++cnt; a[1].name = me;
        int n; cin >> n; cin.get();
        for(int i = 1; i <= n; ++i) {
            string line, x; getline(cin, line);
            vector<string> z;
            stringstream ss(line);
            while(ss >> x) z.push_back(x);
            if(z.size() == 4) {
                string &u = z[0];
                int uu = ID(u);
                string &v = z[2]; v.pop_back(); v.pop_back();
                int vv = ID(v);
                a[vv].name = v; a[uu].name = u;
                if(uu == 1) a[vv].v += 5;
                if(vv == 1) a[uu].v += 5;
            } else {
                string &u = z[0];
                int uu = ID(u);
                string &v = z[3]; v.pop_back(); v.pop_back();
                int vv = ID(v);
                a[uu].name = u; a[vv].name = v;
                if(z[1][0] == 'p') {
                    if(uu == 1) a[vv].v += 15;
                    if(vv == 1) a[uu].v += 15;
                } else {
                    if(uu == 1) a[vv].v += 10;
                    if(vv == 1) a[uu].v += 10;
                }
            }
        }
        sort(a + 1, a + 1 + cnt);
        for(int i = 1; i <= cnt; ++i) {
            if(a[i].name == me) continue;
            cout << a[i].name << '\n';
        }
    }
    return 0;
}
