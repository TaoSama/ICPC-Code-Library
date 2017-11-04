#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class ExploringNumbers {
public:
    bool isPrime(int x) {
        for(int i = 2; i * i <= x; ++i) if(x % i == 0) return false;
        return x != 1;
    }
    int numberOfSteps(int n) {
        set<int> s; s.insert(n);
        vector<int> v(1, n);
        while(true) {
            if(isPrime(v.back())) break;
            char buf[100]; sprintf(buf, "%d", v.back());
            int x = 0;
            for(int i = 0; buf[i]; ++i) x += (buf[i] - '0') * (buf[i] - '0');
            if(s.count(x)) return -1;
            v.push_back(x);
            s.insert(x);
        }
        return v.size();
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { 5 }, {1} },
        { { 57 }, {4} },
        { { 1 }, { -1} },
        { { 6498501 }, {2} },
        { { 989113 }, {6} },
        { { 12366 }, { -1} },
        // Your custom test goes here:
        { {999999999 }, {0} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    int p0;

    int run(ExploringNumbers* x) {
        return x->numberOfSteps(p0);
    }
    void print() {
        //Tester::printArgs(p0);
    }
};

int main() {
    return Tester::runTests<ExploringNumbers>(
               getTestCases<input, Tester::output<int>>(), disabledTest,
               250, 1460473202, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
