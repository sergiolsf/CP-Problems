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

signed main() {
    fastio();
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int misha = max(3*(a / 10), a- ((a/250) * c));
    int vasya = max(3*(b / 10), b-((b/250) * d));

    if (misha > vasya) cout << "Misha\n";
    else if (misha < vasya) cout << "Vasya\n";
    else cout << "Tie\n";
    
    return 0;
}