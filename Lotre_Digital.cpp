#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ScratchLottery {
private:
    char board[4][5];
    bool revealed[4][5];
    int data[4][5];
    int safeRevealed;

public:

int main() {
    system ("clear");
    ScratchLottery game;
    int row, col;

    cout << "Selamat Datang di Lotre Gosok (HALAL)\n";

    while (true) {
        cout << "Masukkan tebakan anda (baris dan kolom) : ";
        cin >> row >> col;

        if (!cin) { // salah input
            cout << "Input tidak valid. Gunakan angka.\n";
            cin.clear();
            cin.ignore(); // hapus \n buffer
            continue;
        }

        if (!game.guess(row, col)) { // kita buka bom
            break;
        }

        if (game.isGameOver()) { // menang
            cout << "Selamat anda menang!\n";
            game.displayBoard();
            break;
        }
    }

    return 0;
}
