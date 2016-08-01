//
//  Created by TaoSama on 2016-07-24
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    map<string, set<string> > folders, files;
    while(cin >> s) {
        int cnt = 0;
        string folderName;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '\\') {
                ++cnt;
                if(cnt == 2) {
                    folderName = s.substr(0, i);
                } else if(cnt > 2) folders[folderName].insert(s.substr(0, i));
            }
        }
        files[folderName].insert(s);
    }
    int a = 0, b = 0;
    for(auto p : folders) a = max(a, (int)p.second.size());
    for(auto p : files) b = max(b, (int)p.second.size());
    cout << a << ' ' << b << endl;

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
