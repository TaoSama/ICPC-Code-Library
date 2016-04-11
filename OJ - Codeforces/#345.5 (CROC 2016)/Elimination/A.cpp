//
//  Created by TaoSama on 2016-03-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

//0, 3 <-> 1, 2

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string a, b, tmp;
    cin >> tmp; a += tmp;
    cin >> tmp; a += tmp;
    cin >> tmp; b += tmp;
    cin >> tmp; b += tmp;

    set<string> s;
    queue<string> q;
    q.push(a); s.insert(a);
    while(q.size()) {
        string u = q.front(), v; q.pop();
        if(u == b) {
            puts("YES");
            return 0;
        }
        int p = u.find('X');
        if(p == 0 || p == 3) {
            v = u;
            swap(v[p], v[1]);
            if(!s.count(v)) {
                s.insert(v);
                q.push(v);
            }
            v = u;
            swap(v[p], v[2]);
            if(!s.count(v)) {
                s.insert(v);
                q.push(v);
            }
        } else {
            v = u;
            swap(v[p], v[0]);
            if(!s.count(v)) {
                s.insert(v);
                q.push(v);
            }
            v = u;
            swap(v[p], v[3]);
            if(!s.count(v)) {
                s.insert(v);
                q.push(v);
            }
        }
    }
    puts("NO");
    return 0;
}
