#include "PvPMode.h"

void vienPlayer() {
    //Player X
    for (int i = 0; i < 5; i = i + 4) {
        for (int j = 0; j < 5; j++) {
            GotoXY(_A[i][j].x - 22, _A[i][j].y + 11);
            printf("%c%c%c%c", 196, 196, 196, 196);
        }
    }
    for (int j = 0; j <= 5; j = j + 5) {
        for (int i = 1; i < 4; i++) {
            GotoXY(_A[i][j].x - 23, _A[i][j].y + 11);
            printf("%c", 179);
            GotoXY(_A[i][j].x - 23, _A[i][j].y + 10);
            printf("%c", 179);
            GotoXY(_A[i][j].x - 23, _A[i][j].y + 12);
            printf("%c", 179);
        }
    }
    GotoXY(_A[0][0].x - 23, _A[0][0].y + 11);
    printf("%c", 218);
    GotoXY(_A[4][0].x - 23, _A[4][0].y + 11);
    printf("%c", 192);
    GotoXY(_A[0][5].x - 23, _A[0][5].y + 11);
    printf("%c", 191);
    GotoXY(_A[4][5].x - 23, _A[4][5].y + 11);
    printf("%c", 217);
    //Playẻr O
    for (int i = 0; i < 5; i = i + 4) {
        for (int j = 0; j < 5; j++) {
            GotoXY(_A[i][j].x + 49, _A[i][j].y + 11);
            printf("%c%c%c%c", 196, 196, 196, 196);
        }
    }
    for (int j = 0; j <= 5; j = j + 5) {
        for (int i = 1; i < 4; i++) {
            GotoXY(_A[i][j].x + 49, _A[i][j].y + 11);
            printf("%c", 179);
            GotoXY(_A[i][j].x + 49, _A[i][j].y + 10);
            printf("%c", 179);
            GotoXY(_A[i][j].x + 49, _A[i][j].y + 12);
            printf("%c", 179);
        }
    }
    GotoXY(_A[0][0].x + 49, _A[0][0].y + 11);
    printf("%c", 218);
    GotoXY(_A[4][0].x + 49, _A[4][0].y + 11);
    printf("%c", 192);
    GotoXY(_A[0][5].x + 49, _A[0][5].y + 11);
    printf("%c", 191);
    GotoXY(_A[4][5].x + 49, _A[4][5].y + 11);
    printf("%c", 217);
    turnPlayer();
    choseSound();
}

void turnPlayer() {
    if (!_TURN) {
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(_A[1][4].x+5, _A[1][4].y+9);
        cout << u8R"(
 __  __
 \ \/ /
  \  / 
  /  \ 
 /_/\_\
)";
        SetConsoleOutputCP(437);

        for (int i = 1; i < 4; i = i + 2) {
            for (int j = 1; j < 3; j++) {
                GotoXY(_A[i][j].x + 49, _A[i][j].y + 11);
                printf("%c%c%c%c", ' ', ' ', ' ', ' ');
            }
        }
        for (int j = 1; j < 4; j = j + 2) {
            for (int i = 1; i < 3; i++) {
                GotoXY(_A[i][j].x + 49, _A[i][j].y + 12);
                printf("%c", ' ');
            }
        }
        for (int j = 1; j < 4; j = j + 2) {
            for (int i = 1; i < 2; i++) {
                GotoXY(_A[i][j].x + 49, _A[i][j].y + 13);
                printf("%c", ' ');
            }
        }
        GotoXY(_A[1][1].x + 49, _A[1][1].y + 11);
        printf("%c", ' ');
        GotoXY(_A[3][1].x + 49, _A[3][1].y + 11);
        printf("%c", ' ');
        GotoXY(_A[1][3].x + 49, _A[1][1].y + 11);
        printf("%c", ' ');
        GotoXY(_A[3][3].x + 49, _A[3][1].y + 11);
        printf("%c", ' ');
    }
    else {
        // X
        for (int i = 1; i < 4; i++) {
            for (int j = i; j <= i; j++) {
                GotoXY(_A[i][j].x - 23, _A[i][j].y + 11);
                printf("%c", ' ');
                GotoXY(_A[i][j].x - 23, _A[i][j].y + 12);
                printf("%c", ' ');
                GotoXY(_A[i][j].x - 24, _A[i][j].y + 10);
                printf("%c", ' ');
                GotoXY(_A[i][j].x - 24, _A[i][j].y + 11);
                printf("%c", ' ');
            }
        }
        for (int i = 1; i < 4; i++) {
            for (int j = 4 - i; j >= 4 - i; j--) {
                GotoXY(_A[i][j].x - 23, _A[i][j].y + 11);
                printf("%c", ' ');
                GotoXY(_A[i][j].x - 23, _A[i][j].y + 12);
                printf("%c", ' ');
                GotoXY(_A[i][j].x - 24, _A[i][j].y + 10);
                printf("%c", ' ');
                GotoXY(_A[i][j].x - 24, _A[i][j].y + 11);
                printf("%c", ' ');
            }
        }
        // O
        setColor(121);
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(_A[1][1].x + 49, _A[1][1].y + 9);
        cout << u8R"(
  ___  
 / _ \ 
| | | |
| |_| |
 \___/
)";
        SetConsoleOutputCP(437);
    }
    setColor(112);
}

// Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin) {
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí thích hợp
    switch (pWhoWin) {
    case -1:
        printf("X win!\n");
        break;
    case 1:
        printf("O win!\n");
        break;
    case 0:
        printf("Hai nguoi choi da hoa\n");
        break;
    case 2:
        _TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra
        break;
    }
    GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
    return pWhoWin;
}

int AskContinue() {
    setColor(112);
    box(45, 10, 33, 3, " ");
    GotoXY(46, 10);
    printf("Press Y/N to Play Again/Back"); // Nhập Y để chơi tiếp hoặc nhập N để quay về Menu
    char response = _getch();
    return toupper(response);
}

int PlayWithPlayer() {
    ShowBlinkingCursor(true);
    system("color 70");
    StartGame();
    vienPlayer();
    GotoXY(_A[0][0].x + 1, _A[0][0].y);
    bool validEnter = true;
    while (true) {
        char command = getInput(); // Lấy đầu vào từ phím
        if (command) {
            command = toupper(command);
            if (command == 27) { // ESC để thoát
                ExitGame();
                break;
            }
            else {
                if (command == 'A') {
                    MoveLeft();
                }
                else if (command == 'W') MoveUp();
                else if (command == 'S') MoveDown();
                else if (command == 'D') MoveRight();
                else if (command == 13) { // Nhấn Enter để đánh dấu
                    switch (CheckBoard(_X, _Y)) {
                    case -1:
                        choseSound();
                        vienPlayer();
                        break; // Quân X đã được vẽ
                    case 1:
                        choseSound();
                        vienPlayer();
                        break; // Quân O đã được vẽ
                    case 0:
                        validEnter = false; // Ô đã được đánh dấu
                        break;
                    }
                    if (validEnter) {
                        switch (ProcessFinish(TestBoard())) {
                        case -1: case 1: case 0:
                            if (AskContinue() != 'Y') {
                                ExitGame();
                                return 0;
                            }
                            else StartGame();
                            break;
                        }
                    }
                    validEnter = true; // Mở khóa
                }
                else if (command == 'L') {
                    clearScreen();
                    SaveGame();
                    clearScreen();
                    break;
                }
            }
        }
        Sleep(100);
    }
}