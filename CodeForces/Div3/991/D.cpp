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

void solve() {
    string s;
    cin >> s;
    bool flag = true;
    while (flag) {
        flag = false;
        int j;
        for (int i = 0; i < s.size(); i++) {
            j = i+1;
            int k = i;
            while (j < s.size() && s[j]-'0' > s[k]-'0'+1 && s[j]>0) {
                int aux = s[j]-'0'-1;
                s[j] = s[k];
                s[k] = '0'+aux;
                j++;
                k++;
                flag = true;
            }
        }
    }
    cout << s << endl;
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