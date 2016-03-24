//
//  Created by TaoSama on 2015-05-30
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e4 + 10;

set<int> maxS, minS;
set<int>::iterator iter;
queue<int> q;
int n;

void add(int x) {
    if(maxS.empty()) {
        maxS.insert(x);
        return;
    }
    iter = maxS.begin();
    if(x > (*iter)) maxS.insert(x);
    else minS.insert(x);
    while(minS.size() > maxS.size()) {
        iter = minS.end(); --iter;
        maxS.insert(*iter);
        minS.erase(iter);
    }
    while(maxS.size() > minS.size() + 1) {
        iter = maxS.begin();
        minS.insert(*iter);
        maxS.erase(iter);
    }
}

void del() {
    int x = q.front(); q.pop();
    iter = minS.find(x);
    if(iter != minS.end()) minS.erase(iter);
    else {
        iter = maxS.find(x);
        maxS.erase(iter);
    }

    while(minS.size() > maxS.size()) {
        iter = minS.end(); --iter;
        maxS.insert(*iter);
        minS.erase(iter);
    }
    while(maxS.size() > minS.size() + 1) {
        iter = maxS.begin();
        minS.insert(*iter);
        maxS.erase(iter);
    }
}

int query() {
    return *maxS.begin();
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1) {
        printf("Case #%d:\n", ++kase);
        minS.clear(); maxS.clear();
        while(q.size()) q.pop();

        char op[10]; int x;
        while(n--) {
            scanf("%s", op);
            if(op[0] == 'i') {
                scanf("%d", &x);
                q.push(x);
                add(x);
            } else if(op[0] == 'o') del();
            else printf("%d\n", query());
        }
    }
    return 0;
}
