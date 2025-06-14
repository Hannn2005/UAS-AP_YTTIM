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
 ScratchLottery() {
        safeRevealed = 0;
        generateBoard();
    }

    void generateBoard() {
        srand(time(0));
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 5; ++j) {
                board[i][j] = '*';
                revealed[i][j] = false;
                data[i][j] = 0;
            }

        int bombsPlaced = 0;
        while (bombsPlaced < 2) {
            int r = rand() % 4;
            int c = rand() % 5;
            if (data[r][c] == 0) {
                data[r][c] = 1;
                bombsPlaced++;
            }
        }
    }

 void displayBoard() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }

    bool guess(int row, int col) {
        if (row < 0 || row >= 4 || col < 0 || col >= 5) {
            cout << "Posisi tidak valid! Masukkan baris [0-3] dan kolom [0-4].\n";
            return true;
        }

        if (revealed[row][col]) {
            cout << "Kotak telah dibuka sebelumnya!\n";
            return true;
        }
        revealed[row][col] = true;
        if (data[row][col] == 1) {
            board[row][col] = 'X';
            displayBoard();
            cout << "BOOM! Anda menemukan bom! Permainan berakhir.\n";
            return false;
        } else {
            board[row][col] = 'O';
            safeRevealed++;
            cout << "Kotak Aman\n";
            displayBoard();
            return true;
        }
    }

    bool isGameOver() {
        return safeRevealed == 18;
    }
};

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
