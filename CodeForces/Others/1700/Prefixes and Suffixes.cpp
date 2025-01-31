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

vi prefix_function(string s) {
    int n = (int)s.length();
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
    string s;
    cin >> s;
    int n = s.size();

    vi pi = prefix_function(s), count(n+1, 0);

    for (int i = 0; i < n; i++) {
        count[pi[i]]++;
    }

    for (int i = n-1; i > 0; i--) {
        count[pi[i-1]] += count[i];
    }

    for (int i = 0; i < n; i++) {
        count[i]++;
    }

    int j = pi[n-1];
    vector<pii> vp;
    while (j > 0) {
        vp.push_back({j, count[j]});
        j = pi[j-1];
    }

    vp.push_back({n, 1});

    sort(all(vp));

    cout << vp.size() << endl;

    for (auto e: vp) {
        cout << e.first << " " << e.second << endl;
    }
        
    return 0;
}