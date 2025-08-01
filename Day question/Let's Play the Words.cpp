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

const int INF = 1'000'000'000'000'000'000;

void solve() {
    int n; cin >> n;
    map<string, int> mp;
    set<int> X, Y;
    int A = 0, F = 0, x = 0, y = 0, B = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        string S = s;
        reverse(all(S));
        mp[s] = i;

        if (s[0] == s[s.size()-1] && s[0] == '0') A++;
        else if (s[0] == s[s.size()-1] && s[0] == '1') B++;
        else if (s[0] == '0') {
            if (mp.count(S)) {
                y--;
                F++;
                Y.erase(mp[S]);
            } else {
                x++;
                X.insert(i);
            }
        } else {
            if (mp.count(S)) {
                x--;
                F++;
                X.erase(mp[S]);
            } else {
                y++;
                Y.insert(i);
            }
        }
    }

    if (x+y+F == 0 && A && B) {
        cout << "-1\n";
        return;
    }

    int ans = INF;
    int mudax = 0, muday = 0;

    if (x == y || x-1 == y) ans = 0;
    else if (x < y) {
        int aa = (y-x+1)/2;
        if (aa < ans) {
            muday = aa; mudax = 0;
            ans = aa;
        }
    } else {
        int aa = (x-y)/2;
        if (aa < ans) {
            muday = 0; mudax = aa;
            ans = aa;
        }
    }

    if (x == y || x-1 == y) ans = 0;
    else if (x < y) {
        int aa = (y-x)/2;
        if (aa < ans) {
            muday = aa; mudax = 0;
            ans = aa;
        }
    } else {
        int aa = (x-y+1)/2;
        if (aa < ans) {
            muday = 0; mudax = aa;
            ans = aa;
        }
    }

    cout << ans << endl;
    if (ans == 0) cout << endl;
    
    int i = 1;
    for (auto e: X) {
        if (mudax < i) break;
        cout << e << (i == mudax ? "\n" : " ");
        i++;
    }
    
    for (auto e: Y) {
        if (muday < i) break;
        cout << e << (i == muday ? "\n" : " ");
        i++;
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}