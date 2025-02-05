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

signed main() {
    fastio();
    int v;
    cin >> v; 

    vi a(10);
    int menor = 1e9;

    for (int i = 1; i <= 9; i++) {
        cin >> a[i];
        menor = min(a[i], menor);
    }

    if (menor > v) {
        cout << -1 << endl;
        return 0;
    }

    vector<pii> g (v+1, {0,0});

    for (int i = 1; i <= v; i++) {
        for (int j = 9; j >= 1; j--) {
            int e = a[j];
            if (i - e >= 0) {
                if(g[i].first < g[i-e].first+1) {
                    g[i].first = g[i-e].first + 1;
                    g[i].second = e;
                }
            }
        }  
    }

    int i = v;
    vi cont(10, 0);

    while (i != 0) {
        if (g[i].second == 0) break;
        for (int j = 9; j >= 1; j--) {
            if (g[i].second == a[j]) {
                cont[j]++;
                break;
            }
        }
        i -= g[i].second;
    }

    for (int j = 9; j >= 1; j--) {
        while (cont[j]) {
            cout << j;
            cont[j]--;
        }
    }

    cout << endl;

    return 0;
}