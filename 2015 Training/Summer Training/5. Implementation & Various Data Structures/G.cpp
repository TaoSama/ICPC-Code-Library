//
//  Created by TaoSama on 2015-07-24
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

char s[300];
bool error;

struct Node {
    bool used;
    int v;
    Node *ls, *rs;
    Node(): used(0), ls(0), rs(0) {}
} *root;

Node* newNode() {return new Node();}

void addNode(int v, char* s) {
    Node *u = root;
//    cout << v << ' ';
    for(int i = 0; s[i]; ++i) {
//      cout << s[i];
        if(s[i] == 'L') {
            if(u->ls == NULL) u->ls = newNode();
            u = u->ls;
        } else if(s[i] == 'R') {
            if(u->rs == NULL) u->rs = newNode();
            u = u->rs;
        }
    }
//    cout << endl;
    if(u->used) error = true;
    u->v = v;
    u->used = true;
}

bool read() {
    error = false;
    root = newNode();
    while(scanf("%s", s) == 1) {
        if(!strcmp(s, "()")) return true;
        int v; sscanf(s + 1, "%d", &v);
        addNode(v, strchr(s, ',') + 1);
    }
    return false;
}

void bfs() {
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    while(q.size() && !error) {
        Node* u = q.front(); q.pop();
        if(!u->used) {
            error = true;
            break;
        }
        ans.push_back(u->v);
        if(u->ls) q.push(u->ls);
        if(u->rs) q.push(u->rs);
    }
    if(error) cout << "not complete\n";
    else {
        for(int i = 0; i < ans.size(); ++i) {
            if(i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(read()) {
        bfs();
    }
    return 0;
}
