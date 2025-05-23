#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, k; 
vi a;

bool g(int s) {
    int cont = 1;
    int sum = 0;
    for (auto e: a) {
        if (e > s) return false;
        if (sum + e > s) {
            sum = e;
            cont++;
        } else sum += e;
    }
    return (cont <= k);
}

signed main() {
    fastio();
    cin >> n >> k;
    a.resize(n);
    for (auto &i: a) cin >> i;

    int lo = 0, hi = 1;
    while (!g(hi)) hi *= 2;

    while (hi-lo > 1) {
        int m = (hi+lo)/2;
        if (g(m)) hi = m;
        else lo = m;
    }

    cout << hi << endl;
  
    return 0;
}