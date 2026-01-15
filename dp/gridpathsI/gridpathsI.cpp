#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define eat cin
#define big long long
#define endl "\n"
const int MOD = 1000000007;

vector<string> grid;
// vector<vector<int>> path_count;
int path_count[1005][1005];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n;
    for (int i = 0; i < n; i++) {
        string row;
        eat >> row;
        grid.push_back(row);
    }

    path_count[0][0] = (grid[0][0] == '*') ? 0 : 1;

    for (int row = 0; row<n; row++) {
        for (int col = 0; col <n; col++) {
            if (grid[row][col] == '*') continue;
            if (row > 0) path_count[row][col] += path_count[row-1][col];
            if (col > 0) path_count[row][col] += path_count[row][col-1];

            path_count[row][col] %= MOD;
        }
    }
    cout << path_count[n-1][n-1] << endl;



}