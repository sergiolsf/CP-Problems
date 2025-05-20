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

int n, t; 
vi a;

bool f(int c) {
    int cont = 0;
    for (auto e: a) {
        cont += c/e;
        if (cont >= t) return true; 
    }
    return false;
}

signed main() {
    fastio();
    cin >> n >> t;
    a.resize(n);
    for (auto &i: a) cin >> i;

    int lo = 0, hi = 1;
    while (!f(hi)) hi *= 2;
    
    while (hi-lo > 1) {
        int m = (hi+lo)/2;
        if (f(m)) hi = m;
        else lo = m;
    }

    cout << hi << endl;
  
    return 0;
}