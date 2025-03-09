#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<vector<char>> grid;

void p1(int i, int j) {
    grid[i][j] = 'I';
    grid[i][j+1] = 'I';
    grid[i][j+2] = 'I';
    grid[i][j+3] = 'I';
    grid[i][j+4] = 'I';
}

void p2(int i, int j) {
    grid[i][j] = 'L';
    grid[i][j+1] = 'L';
    grid[i][j+2] = 'L';
    grid[i][j+3] = 'L';
    grid[i][j+4] = 'N';
    grid[i][j+5] = 'N';
    grid[i][j+6] = 'N';
    grid[i][j+7] = 'P';
    grid[i][j+8] = 'P';
    grid[i][j+9] = 'P';

    grid[i+1][j] = 'L';
    grid[i+1][j+1] = 'I';
    grid[i+1][j+2] = 'I';
    grid[i+1][j+3] = 'I';
    grid[i+1][j+4] = 'I';
    grid[i+1][j+5] = 'I';
    grid[i+1][j+6] = 'N';
    grid[i+1][j+7] = 'N';
    grid[i+1][j+8] = 'P';
    grid[i+1][j+9] = 'P';
}

void p3(int i, int j) {
    grid[i][j] = 'U';
    grid[i][j+1] = 'U';
    grid[i][j+2] = 'U';
    grid[i][j+3] = 'P';
    grid[i][j+4] = 'P';

    grid[i+1][j] = 'U';
    grid[i+1][j+1] = 'Y';
    grid[i+1][j+2] = 'U';
    grid[i+1][j+3] = 'P';
    grid[i+1][j+4] = 'P';

    grid[i+2][j] = 'Y';
    grid[i+2][j+1] = 'Y';
    grid[i+2][j+2] = 'Y';
    grid[i+2][j+3] = 'Y';
    grid[i+2][j+4] = 'P';
}

void p4(int i, int j) {
    grid[i][j] = 'U';
    grid[i][j+1] = 'U';
    grid[i][j+2] = 'U';
    grid[i][j+3] = 'P';
    grid[i][j+4] = 'P';

    grid[i+1][j] = 'U';
    grid[i+1][j+1] = 'Y';
    grid[i+1][j+2] = 'U';
    grid[i+1][j+3] = 'P';
    grid[i+1][j+4] = 'P';

    grid[i+2][j] = 'Y';
    grid[i+2][j+1] = 'Y';
    grid[i+2][j+2] = 'Y';
    grid[i+2][j+3] = 'Y';
    grid[i+2][j+4] = 'P';

    grid[i+3][j] = 'I';
    grid[i+3][j+1] = 'I';
    grid[i+3][j+2] = 'I';
    grid[i+3][j+3] = 'I';
    grid[i+3][j+4] = 'I';

}

void p4linha(int i, int j) {
    grid[i][j] = 'I';
    grid[i][j+1] = 'I';
    grid[i][j+2] = 'I';
    grid[i][j+3] = 'I';
    grid[i][j+4] = 'I';

    grid[i+1][j] = 'Y';
    grid[i+1][j+1] = 'Y';
    grid[i+1][j+2] = 'Y';
    grid[i+1][j+3] = 'Y';
    grid[i+1][j+4] = 'P';

    grid[i+2][j] = 'U';
    grid[i+2][j+1] = 'Y';
    grid[i+2][j+2] = 'U';
    grid[i+2][j+3] = 'P';
    grid[i+2][j+4] = 'P';

    grid[i+3][j] = 'U';
    grid[i+3][j+1] = 'U';
    grid[i+3][j+2] = 'U';
    grid[i+3][j+3] = 'P';
    grid[i+3][j+4] = 'P';
}

void p5(int i, int j) {
    grid[i][j] = 'W';
    grid[i][j+1] = 'W';
    grid[i][j+2] = 'T';
    grid[i][j+3] = 'T';
    grid[i][j+4] = 'T';

    grid[i+1][j] = 'Y';
    grid[i+1][j+1] = 'W';
    grid[i+1][j+2] = 'W';
    grid[i+1][j+3] = 'T';
    grid[i+1][j+4] = 'V';

    grid[i+2][j] = 'Y';
    grid[i+2][j+1] = 'Y';
    grid[i+2][j+2] = 'W';
    grid[i+2][j+3] = 'T';
    grid[i+2][j+4] = 'V';

    grid[i+3][j] = 'Y';
    grid[i+3][j+1] = 'L';
    grid[i+3][j+2] = 'V';
    grid[i+3][j+3] = 'V';
    grid[i+3][j+4] = 'V';

    grid[i+4][j] = 'Y';
    grid[i+4][j+1] = 'L';
    grid[i+4][j+2] = 'L';
    grid[i+4][j+3] = 'L';
    grid[i+4][j+4] = 'L';
}

void caso2cima(int i, int w) {
    int j = 4;
    grid[i][1] = 'P';
    grid[i][2] = 'P';
    grid[i][3] = 'P';
    for (int k = 0; k < w; k++) {
        grid[i][j] = 'N';
        grid[i][j+1] = 'N';
        grid[i][j+2] = 'N';
        grid[i][j+3] = 'Y';
        grid[i][j+4] = 'N';
        grid[i][j+5] = 'N';
        grid[i][j+6] = 'Y';
        grid[i][j+7] = 'Y';
        grid[i][j+8] = 'Y';
        grid[i][j+9] = 'Y';
        j+=10;
    }
    grid[i][j] = 'P';
    grid[i][j+1] = 'P';
}

void caso2baixo(int i, int w) {
    int j = 3;
    grid[i][1] = 'P';
    grid[i][2] = 'P';
    for (int k = 0; k < w; k++) {
        grid[i][j] = 'N';
        grid[i][j+1] = 'N';
        grid[i][j+2] = 'Y';
        grid[i][j+3] = 'Y';
        grid[i][j+4] = 'Y';
        grid[i][j+5] = 'Y';
        grid[i][j+6] = 'N';
        grid[i][j+7] = 'N';
        grid[i][j+8] = 'N';
        grid[i][j+9] = 'Y';
        j+=10;
    }
    grid[i][j] = 'P';
    grid[i][j+1] = 'P';
    grid[i][j+2] = 'P';
}

signed main() {
    fastio();
    int h, w; cin >> h >> w;
    bool troca = false;
    if (h%5 == 0) {
        swap(h,w);
        troca = true;
    } else if (w%5 != 0) {
        cout << "no\n";
        return 0;
    }

    grid.resize(h+1, vector<char> (w+1));

    if (h == 1) {
        if (w != 5) {
            cout << "no\n";
            return 0;
        }
        else p1(1,1);
    } else if (h == 2) {
        if (w == 5) {
            cout << "no\n";
            return 0;
        } else if (w%10 == 0) {
            for (int i = 1; i < w; i += 10) {
                p2(1, i);
            }
        } else {
            caso2cima(1, w/10);
            caso2baixo(2, w/10);
        }
    } else {
        int r = h%5;
        int q = h/5;
        int i = 1;
        if (r == 1) {
            i += 6;
            q--;
            bool flag = false;
            for (int k = 1; k < w; k += 5) {
                if (flag) {
                    p5(1, k);
                    p1(6, k);
                } else {
                    p1(1, k);
                    p5(2, k);
                }
                flag = !flag;
            }
        } else if (r == 2) {
            i += 7;
            q--;
            int hh = 1;
            int c = w/10;
            if (w%10){
                p1(1,1); p5(2, 1); p1(7, 1);
                hh=6;
            }
            for (int k = 0; k < c; k++) {
                p2(1, k*10+hh);
                p5(3, k*10+hh);
                p5(3, k*10+hh+5);
            }

        } else if (r == 3) {
            i += 3;
            for (int k = 1; k < w; k += 5) {
                p3(1, k);
            }
        } else if (r == 4) {
            i += 4;
            bool flag = false;
            for (int k = 1; k < w; k += 5) {
                if (flag) {
                    p4linha(1, k);
                } else {
                    p4(1, k);
                }
                flag = !flag;
            }
        }

        for (; i < h; i += 5) {
            for (int k = 1; k < w; k += 5) {
                p5(i, k);
            }
        }
    }

    cout << "yes\n";
    if (!troca) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else {
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                cout << grid[j][i];
            }
            cout << endl;
        }
    }




    return 0;
}
