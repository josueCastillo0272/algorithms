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

int n;

vector<int> adj[200005];
int dp[200005][2];
void dfs(int node, int par) {
    dp[node][0] = 0;
    int best = 0;
    // solve for children
    for (auto child: adj[node]) {
        if (child == par) continue;
        dfs(child, node);
        best += max(dp[child][0], dp[child][1]);
    }

    dp[node][0] = best;
    dp[node][1] = 0;
    for (auto child: adj[node]) {
        if (child == par) continue;
        int curr = 1 + dp[child][0] + (best - max(dp[child][0], dp[child][1]));
        dp[node][1] = max(dp[node][1], curr);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n;

    for (int i = 0; i < n-1; i ++) { 
        int a, b;
        eat >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout << max(dp[1][1], dp[1][0]) << endl;


}

