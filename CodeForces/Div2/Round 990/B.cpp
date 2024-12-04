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
}

void solve() {
    int n;
    map<char, int> mp;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if(mp.count(s[i])) {
            mp[s[i]]++;
        } else {
            mp[s[i]] = 1;
        }
    }

    int minimum, maximum;
    char letter_min, letter_max;
    bool first = true;

    for (auto e: mp) {
        if (first) {
            minimum = e.second;
            maximum = e.second;
            letter_min = e.first;
            letter_max = e.first;
            first = false;
        }
        if (minimum > e.second) {
            minimum = e.second;
            letter_min = e.first;
        }
        if (maximum < e.second) {
            maximum = e.second;
            letter_max = e.first;
        }
    }
    first = true;
    bool secon = false;
    if (letter_min == letter_max) secon = true;

    for (int i = 0; i < n; i++) {
        if (secon && s[i] != letter_max) {
            secon = false;
            cout << letter_max;
        } else if (first && s[i] == letter_min && s[i] != letter_max) {
            first = false;
            cout << letter_max;
        } else {
            cout << s[i];
        }
    }
    cout << endl;
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