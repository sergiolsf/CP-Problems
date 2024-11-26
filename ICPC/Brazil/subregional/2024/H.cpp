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

string M, N;
int szM, szN;
vi possibleN;

void searchN(int i, int val, int pot) {
    if (i < 0) {
        if (val > 0) possibleN.push_back(val);
        return;
    }

    if (N[i] == '*') {
        searchN(i-1, val, pot*2);
        searchN(i-1, val+pot, pot*2);
    } else if (N[i] == '1') {
        searchN(i-1, val+pot, pot*2);
    } else {
        searchN(i-1, val, pot*2);
    }
    return;
}

bool searchM(int i, int n, int val, int pot) {
    if (i < 0) {

        if (val == 0) {
            return true;
        }
        return false;

    }

    if (M[i] == '*') {

        if (searchM(i-1, n, val, (pot*2)%n)) {
            cout << 0;
            return true;
        }
         if (searchM(i-1, n, (val+pot)%n, (pot*2)%n)) {
            cout << 1;
            return true;
        }

    } else if (M[i] == '1') {

        if (searchM(i-1, n, (val+pot)%n, (pot*2)%n)) {
            cout << 1;
            return true;
        }

    } else {

        if (searchM(i-1, n, val, (pot*2)%n)) {
            cout << 0;
            return true;
        }

    }
    return false;
}

signed main() {
    fastio();
    cin >> M >> N;

    szN = N.size();
    szM = M.size();

    searchN(szN-1, 0, 1);

    for (auto n: possibleN) {
        if (searchM(szM-1, n, 0, 1)) break;
    }

    cout << endl;

    return 0;
}