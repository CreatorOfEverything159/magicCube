#include <iostream>

using namespace std;

const int N = 4;

const int cube[N][N] = {
        { 11,  8,  5, 10 },
        {  2, 13, 16,  3 },
        { 14,  1,  4, 15 },
        {  7, 12,  9,  6 }
};

void encryptMessage(const char *mess) {
    char eMess[N][N];
    for (int c = 0; c < 16; c++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (c + 1 == cube[i][j]) {
                    eMess[i][j] = NULL != mess[c] ? mess[c] : ' ';
                }

    for (auto & eMas : eMess)
        for (char eMa : eMas)
            cout << eMa;
}

void decryptMessage(char *mess) {
    int z;
    for (int c = 0; c < 16; c++) {
        z = 0;
        for (auto i : cube)
            for (int j = 0; j < 4; j++) {
                z++;
                if (c + 1 == i[j])
                    cout << mess[z - 1];
            }
    }
}

int main() {
    char a[N * N], b[N * N];

    cout<<"Enter encoding message: ";
    cin.getline(a, N * N);
    encryptMessage(a);

    cout<<"\n";

    cout<<"Enter decoding message: ";
    cin.getline(b, N * N);
    decryptMessage(b);

    return 0;
}