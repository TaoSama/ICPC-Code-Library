//
//  Created by TaoSama on 2017-02-23
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s, t;
int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> t) {
        string round[2] = {s, t};
        cout << round[0] << ' ' << round[1] << endl;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> s >> t;
            if(round[0] == s) swap(round[0], t);
            else if(round[1] == s) swap(round[1], t);
            cout << round[0] << ' ' << round[1] << endl;
        }
    }

    return 0;
}
