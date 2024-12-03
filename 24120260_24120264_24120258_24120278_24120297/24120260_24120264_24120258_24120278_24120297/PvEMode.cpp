#include "PvEMode.h"

void BotMove() {
    srand(static_cast<unsigned>(time(0))); // Khởi tạo seed cho random
    int x, y;
    do {
        x = rand() % BOARD_SIZE; // Random tọa độ x
        y = rand() % BOARD_SIZE; // Random tọa độ y
    } while (_A[x][y].c != 0);   // Kiểm tra ô có trống hay không

    _A[x][y].c = 1; // Máy luôn đánh O (giá trị 1)
    GotoXY(_A[x][y].x + 1, _A[x][y].y);
    cout << O(); // Hiển thị nước đi của máy
}

void PlayWithBot() {
    ShowBlinkingCursor(true);
    system("color 70");
    fixConsoleWindow();
    StartGame();
    int x = 0, y = 0; // Tọa độ bắt đầu (trên bàn cờ)
    bool isPlaying = true;
    int result;

    while (isPlaying) {
        if (_TURN) {
            // Lượt người chơi
            bool validMove = false;
            while (!validMove) {
                GotoXY(_A[x][y].x, _A[x][y].y); // Di chuyển con trỏ đến vị trí hiện tại
                char key = _getch(); // Đợi người chơi nhập phím

                switch (key) {
                case 72: // Mũi tên lên
                    if (x > 0) { x--; moveSound(); }
                    break;
                case 80: // Mũi tên xuống
                    if (x < BOARD_SIZE - 1) { x++; moveSound(); }
                    break;
                case 75: // Mũi tên trái
                    if (y > 0) { y--; moveSound(); }
                    break;
                case 77: // Mũi tên phải
                    if (y < BOARD_SIZE - 1) { y++; moveSound(); }
                    break;
                case 13: // Phím Enter
                    if (_A[x][y].c == 0) { // Nếu ô trống
                        _A[x][y].c = -1; // Người chơi luôn đánh X (giá trị -1)
                        GotoXY(_A[x][y].x + 1, _A[x][y].y);
                        cout << X(); // Hiển thị nước đi
                        choseSound();
                        validMove = true; // Thoát khỏi vòng lặp
                    }
                    break;
                default:
                    break;
                }
            }
            _TURN = false;
        }
        else {
            // Lượt máy
            BotMove();
            _TURN = true;
        }

        // Kiểm tra trạng thái trò chơi
        result = TestBoard();
        if (result != 2) {
            isPlaying = false;
        }
    }

    // Kết thúc trò chơi
    GotoXY(0, BOARD_SIZE * 2 + 3);
    if (result == -1) {
        cout << "You win!";
    }
    else if (result == 1) {
        cout << "Bot wins!";
    }
    else {
        cout << "It's a draw!";
    }
    cout << endl;
    system("pause");
}
