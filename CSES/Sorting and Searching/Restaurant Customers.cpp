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

signed main() {
    fastio();

    int n;
    cin >> n;

    vi ent(n), sai(n);

    for (int i = 0; i < n; i++) {
        cin >> ent[i] >> sai[i];
    }

    sort(all(ent));
    sort(all(sai));

    int i = 0, j = 0;
    int ans = 0;
    int cont = 0;

    while (i < n) {
        if (ent[i] < sai[j]) {
            cont++;
            ans = max(cont, ans);
            i++;
        } else if (ent[i] > sai[j]) {
            cont--;
            j++;
        } else {
            i++;
            j++;
        }
    }

    cout << ans << endl;
    
    return 0;
}