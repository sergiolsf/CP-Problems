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

vi minimum, maximum, number, p, r;

int get(int a) {
    return (p[a] == a ? a : get(p[a]));
}

void uniao(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
        minimum[a] = min(minimum[a], minimum[b]);
        maximum[a] = max(maximum[a], maximum[b]);
        number[a] = number[a] + number[b];
    } else {
        p[a] = b;
        minimum[b] = min(minimum[a], minimum[b]);
        maximum[b] = max(maximum[a], maximum[b]);
        number[b] = number[a] + number[b];
    }
}

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    minimum.resize(n+1);
    maximum.resize(n+1);
    number.resize(n+1, 1);
    p.resize(n+1);
    r.resize(n+1, 0);

    for (int i = 1; i <= n; i++) p[i] = minimum[i] = maximum[i] = i;

    for (int i = 1; i <= m; i++) {
        string s;
        int u, v;
        cin >> s >> u;
        if (s == "union") {
            cin >> v;
            uniao(u,v);
        } else {
            u = get(u);
            cout << minimum[u] << " " << maximum[u] << " " << number[u] << endl;
        }
    }
  
    return 0;
}