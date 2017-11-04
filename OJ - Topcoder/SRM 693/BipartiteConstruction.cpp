#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class BipartiteConstruction {
    public:
    vector<int> construct(int K) {
        return vector<int>();
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x ){ return x < 0;}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 2 }, { {3,8,1,7,4,3,0} } },
    { { 5 }, { {1,0,0,0,0,0} } },
    { { 0 }, { {2,1,0} } },
    { { 2333333 }, { {20,93,195,195,211,87,114,369,390,216,195,305,17,370,356,308,150,263,20,153,331,79,344,108,114,257,245,289,211,388,388,359,293,263,219,131,201,293,279,204,97,367,90,279,308,324,323,359,338,63,26,318,218,226,164,361,276,388,343,149,17,336,88,161,76,237,136,278,302,107,271,15,382,45,338,264,78,150,220,341,180,20,252,94,114,161} } },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    #define DISABLE_COLORS
    
    #include "tester.cpp"
    struct input {
        int p0;

        vector<int> run(BipartiteConstruction* x) {
            return x->construct(p0);
        }
        void print() {
            //Tester::printArgs(p0);
        }
    };

    int main() {
        return Tester::runTests<BipartiteConstruction>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest,
            600, 1466874387, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
