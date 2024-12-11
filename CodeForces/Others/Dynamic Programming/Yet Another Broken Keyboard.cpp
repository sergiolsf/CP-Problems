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

vector<bool> alf(27, false);

signed main() {
    fastio();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;


    for (int i = 0; i < k; i++) {
        char l;
        cin >> l;
        alf[l-'a'] = true;
    }

    int count = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (alf[s[i]-'a']) {
            count++;
        } else {
            ans += ((count+1)*count) /2;
            count = 0;
        }
    }

    ans += ((count+1)*count) /2;

    cout << ans << endl;    
    return 0;
}