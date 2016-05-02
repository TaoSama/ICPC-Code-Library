//
//  Created by TaoSama on 2016-05-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int a1, b1, c1;
int a2, b2, c2;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2) {
        if(b1 && b2) { //存在
            if(a1 * b2 == a2 * b1)
                printf("%d\n", c1 * b2 == c2 * b1 ? -1 : 0); //平行 重合
            else printf("%d\n", 1);
        } else if(!b1 && b2) {
            if(!a1 && c1) printf("%d\n", 0);
            else if(!a1 && !c1) printf("%d\n", -1);
            else printf("%d\n", 1);
        } else if(b1 && !b2) {
            if(!a2 && c2) printf("%d\n", 0);
            else if(!a2 && !c2) printf("%d\n", -1);
            else printf("%d\n", 1);
        } else {
            // x = c / a;
            if(a1 && a2) {
                printf("%d\n", c1 * a2 == c2 * a1 ? -1 : 0);
            } else if(!a1 && a2) {
                printf("%d\n", c1 == 0 ? -1 : 0);
            } else if(a1 && !a2) {
                printf("%d\n", c2 == 0 ? -1 : 0);
            } else {
                printf("%d\n", !c1 && !c2 ? -1 : 0);
            }
        }
    }
    return 0;
}
