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
#define moo cout
#define big long long

vector<pair<int,int>> original;
set<pair<int,int>> to_remove;
vector<pair<int,int>> remove_list;


int n;
int m;
int k;

int connections;

int par[200005];
int sz[200005];

int root(int x) {
    if (par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}

void join(int x, int y) {
    int r_x = root(x);
    int r_y = root(y);
    if (r_x == r_y) return;
    if (sz[r_x] < sz[r_y]) {
        swap(r_x, r_y);
        swap(x, y);
    }
    sz[r_x] += sz[r_y];
    par[r_y] = r_x;
}

void create_DSU() {
    for (auto edge: original) {
        if (to_remove.find(edge) != to_remove.end()) continue;
        int u = get<0>(edge);
        int v = get<1>(edge);
        if (root(u) != root(v)) {
            connections--;
            join(u,v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);
    // Create n separate components


    eat >> n;
    eat >> m;
    eat >> k;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u;
        int v;
        eat >> u >> v;
        original.push_back({u,v}); // (u->v)
    }

    for (int i = 0; i < k; i++) {
        int u;
        int v;
        eat >> u >> v;
        to_remove.insert({u,v});
        to_remove.insert({v,u});
        remove_list.push_back({u,v});
    }
    // Create DSU without any connections

    fill(sz, sz + n + 1, 1);
    connections = n;
    create_DSU();
    vector<int> ret;
    ret.push_back(connections);
    for (int i = k-1; i > 0; i--) {
        // add in reverse order
        tuple<int,int> edge = remove_list[i];
        int u = get<0>(edge);
        int v = get<1>(edge);
        if (root(u) != root(v)) {
            connections--;
            join(u,v);
        }
        ret.push_back(connections);
    }

    for (int i = k-1; i > 0; i--) {
        moo << ret[i] << " ";

    }
    moo << ret[0] << endl;

}