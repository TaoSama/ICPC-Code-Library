//
//  Created by TaoSama on 2015-07-22
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

string s, t;
set<string> addr;

void parse(string& s, string& user, string& mta) {
    int p = s.find('@');
    user = s.substr(0, p);
    mta = s.substr(p + 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s && s != "*") {
        int n; cin >> s >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> t;
            addr.insert(t + "@" + s);
        }
    }

    while(cin >> s && s != "*") {
        string user1, mta1, user2, mta2;
        parse(s, user1, mta1);

        vector<string> mta;
        map<string, vector<string> > to;
        set<string> vis;
        while(cin >> t && t != "*") {
            if(vis.count(t)) continue;   //erase the duplicate
            vis.insert(t);
            parse(t, user2, mta2);

            if(!to.count(mta2)) {
                mta.push_back(mta2);
                to[mta2] = vector<string>();
            }
            to[mta2].push_back(t);
        }
        getline(cin, t); //eat the '\n'

        string data;
        while(getline(cin, t) && t != "*") data += "     " + t + "\n";

        for(auto &cur : mta) {
            cout << "Connection between " << mta1 << " and " << cur << '\n';
            cout << "     HELO " << mta1 << '\n' << "     250\n";
            cout << "     MAIL FROM:<" << s << ">\n     250\n";
            bool ok = false;
            for(auto &each : to[cur]) {
                cout << "     RCPT TO:<" << each << ">\n";
                if(addr.count(each)) {
                    ok = true;
                    cout << "     250\n";
                } else cout << "     550\n";
            }
            if(ok) {
                cout << "     DATA\n     354\n";
                cout << data << "     .\n     250\n";
            }
            cout << "     QUIT\n     221\n";
        }
    }
    return 0;
}
