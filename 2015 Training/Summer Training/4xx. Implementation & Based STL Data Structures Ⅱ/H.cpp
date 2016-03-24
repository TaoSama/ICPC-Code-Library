//
//  Created by TaoSama on 2015-07-21
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

string line;
typedef pair<string, string> P;
map<string, string> mp;
set<P> shelf, returned;

void readShelf() {
    while(getline(cin, line) && line != "END") {
        string author, title;
        int quote = 0;
        for(int i = 0; i < line.size(); ++i) {
            if(quote < 2) title += line[i];
            else author += line[i];
            if(line[i] == '"' && ++quote == 2) i += 4;
        }
//        cout << author << '\n' << title << endl;
        shelf.insert({author, title});
        mp[title] = author;
//        prln(mp[title]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    readShelf();
    string op, title;
    while(cin >> op && op != "END") {
        if(op[0] == 'S') {
            for(auto &i : returned) {
                auto cur = shelf.lower_bound(i);
                if(cur == shelf.begin()) {
                    cout << "Put " << i.second << " first\n";
                } else {
                    --cur;
                    cout << "Put " << i.second << " after " << cur->second << '\n';
                }
                shelf.insert(i);
            }
            returned.clear();
            cout << "END\n";
        } else {
            cin.get();  //eat the space
            getline(cin, title);
//          pr(mp[title]); prln(title);
            if(op[0] == 'B') shelf.erase({mp[title], title});
            else returned.insert({mp[title], title});
        }
    }
    return 0;
}

/*
"The Canterbury Tales" by Chaucer, G.
"The Canterbury Taless" by Chaucer, B.
"Algorithms" by Sedgewick, R.
"The C Programming Language" by Kernighan, B. and Ritchiee, D.
"The C Programming Languag" by Kernighan, B. and Ritchiee, D.
"The D Programming Language" by Kernighan, B. and Ritchiee, D.
"A House for Mr. Biswas" by Naipaul, V.S.
"A Congo Diary" by Naipaul, V.S.
END
BORROW "Algorithms"
BORROW "The C Programming Language"
BORROW "The C Programming Languag"
BORROW "The Canterbury Taless"
SHELVE
RETURN "Algorithms"
SHELVE
RETURN "The C Programming Languag"
SHELVE
BORROW "The C Programming Languag"
BORROW "The Canterbury Taless"
BORROW "A House for Mr. Biswas"
RETURN "The Canterbury Taless"
SHELVE
RETURN "The C Programming Language"
RETURN "A House for Mr. Biswas"
SHELVE
END
*/

/*
END
Put "Algorithms" after "A House for Mr. Biswas"
END
Put "The C Programming Languag" after "The Canterbury Tales"
END
Put "The Canterbury Taless"  first
END
Put "The C Programming Language" after "The Canterbury Tales"
Put "A House for Mr. Biswas" after "A Congo Diary"
END
*/
