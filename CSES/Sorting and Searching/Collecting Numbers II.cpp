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

const int MAX_N = 200'005;

int pos[MAX_N];
int num[MAX_N];

int ans = 1, n, m;

void modifica(int a, int b) {
    if (num[a] < n) {
        if (b > pos[num[a]+1] && a < pos[num[a]+1]) ans--;
        else if (b < pos[num[a]+1] && a > pos[num[a]+1]) ans++;
    }
    if (num[a] > 1) {
        if (b < pos[num[a]-1] && a > pos[num[a]-1]) ans--;
        else if (b > pos[num[a]-1] && a < pos[num[a]-1]) ans++;
    }
}

signed main() {
    fastio();
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x] = i;
        num[i] = x;
    }

    for (int i = 1; i < n; i++) {
        if (pos[i+1] < pos[i]) ans++;
    }

    while (m--) {
        int a, b; cin >> a >> b;
        swap(num[a], num[b]);
        swap(pos[num[a]], pos[num[b]]);

        if (abs(num[a]-num[b]) == 1) {
            if (num[a] > num[b] && a > b) ans--;
            else if (num[b] > num[a] && b > a) ans--;
            else ans++;
        }

        modifica(a, b);
        modifica(b, a);        

        cout << ans << endl;
    }

  
    return 0;
}