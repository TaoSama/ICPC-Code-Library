//
//  Created by TaoSama on 2015-10-10
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

int n;
vector<int> v;
map<int, int> mp;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  vector<int> vv; vv.push_back(1); vv.push_back(2);
//  vv.insert(vv.begin(), 3);
//  for(auto v : vv) printf("%d ", v); puts("");

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        char op[10]; int x, top = -1;
        v.clear(); mp.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", op);
            printf("Operation #%d: ", i);
            if(!strcmp(op, "Add")) {
                scanf("%d", &x);
                if(mp.count(x)) puts("same priority.");
                else {
                    v.push_back(x);
                    mp[x] = 0;
                    puts("success.");
                }
            } else if(!strcmp(op, "Close")) {
                scanf("%d", &x);
                if(!mp.count(x)) puts("invalid priority.");
                else {
                    v.erase(find(v.begin(), v.end(), x));
                    printf("close %d with %d.\n", x, mp[x]);
                    mp.erase(x);
                }
            } else if(!strcmp(op, "Chat")) {
                scanf("%d", &x);
                if(!v.size()) puts("empty.");
                else {
                    if(~top) mp[top] += x;
                    else mp[v[0]] += x;
                    puts("success.");
                }
            } else if(!strcmp(op, "Rotate")) {
                scanf("%d", &x);
                if(x < 0 || x > v.size()) puts("out of range.");
                else {
                    int tmp = v[x - 1];
                    v.erase(v.begin() + x - 1);
                    v.insert(v.begin(), tmp);
                    puts("success.");
                }
            } else if(!strcmp(op, "Prior")) {
                if(!v.size()) puts("empty.");
                else {
                    int idx = 0;
                    for(int k = 0; k < v.size(); ++k)
                        if(v[k] > v[idx]) idx = k;
                    int tmp = v[idx];
                    v.erase(v.begin() + idx);
                    v.insert(v.begin(), tmp);
                    puts("success.");
                }
            } else if(!strcmp(op, "Choose")) {
                scanf("%d", &x);
                if(!mp.count(x)) puts("invalid priority.");
                else {
                    v.erase(find(v.begin(), v.end(), x));
                    v.insert(v.begin(), x);
                    puts("success.");
                }
            } else if(!strcmp(op, "Top")) {
                scanf("%d", &x);
                if(!mp.count(x)) puts("invalid priority.");
                else {
                    top = x;
                    puts("success.");
                }
            } else {
                if(~top) {
                    top = -1;
                    puts("success.");
                } else puts("no such person.");
            }
        }
        int tmp;
        if(~top) {
            tmp = mp[top];
            if(tmp) printf("Bye %d: %d\n", top, tmp);
        }
        for(int k = 0; k < v.size(); ++k) {
            if(v[k] == top) continue;
            tmp = mp[v[k]];
            if(tmp) printf("Bye %d: %d\n", v[k], tmp);
        }
    }
    return 0;
}
