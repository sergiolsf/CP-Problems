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

bool verifica(vector<char> v, int k) {
    for (int i = 0; i <= v.size()-k; i++) {
        int l = i;
        int r = i+k-1;
        bool flag = false;
        while (l < r) {
            if (v[l] != v[r]) flag = true;
            l++;
            r--;
        }
        if (!flag) return false;
    }
    return true;
}

signed main() {
    fastio();
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<char> vc (n);
    for (int i = 0; i < n; i++) {
        vc[i] = s[i];
    }
    int ans = 0;
    sort(all(vc));
    do {
        ans += verifica(vc, k);
    } while (next_permutation(vc.begin(), vc.end()));

    cout << ans << endl;
    return 0;
}