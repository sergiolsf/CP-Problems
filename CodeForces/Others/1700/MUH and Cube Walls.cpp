#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1e10;

vi prefix_function(vi s) {
    int n = (int)s.size();
    vi pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


signed main() {
    fastio();
    int n, w;
    cin >> n >> w;
    vi a(n), b(w);
    vector<int> A, B;
    int ant = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            A.push_back(INF);
        }
        else A.push_back(a[i]-ant);
        ant = a[i];
    }

    int menor = INF;
    ant = 0;
    for (int i = 0; i < w; i++) {
        cin >> b[i];
        if (i != 0) B.push_back(b[i]-ant);
        ant = b[i];
        menor = min(menor, b[i]);
    }

    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    if (w > n) {
        cout << 0 << endl;
        return 0;
    }


    vi S = B;
    S.push_back(INF);
    for (auto e: A) {
        S.push_back(e);
    }

    vi pi = prefix_function(S);

    int ans = 0;

    for (int i = w+1; i < w+n; i++) {
        int j = i-2*w+1;
        if ((pi[i] == w-1) && (b[0]-menor <= a[j])) {
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}