#include "LoadGame.h"

void SaveGame() {
    string filename;
    GotoXY(65, 20);
    cout << "Nhap ten file de luu game: ";
    GotoXY(65, 21);
    cin >> filename;
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                file << _A[i][j].c << " ";  
            }
            file << "\n";
        }
        file << (_TURN ? 1 : 0) << "\n"; 
        file.close();
        GotoXY(65, 30);
        cout << "Game da duoc luu" << endl;
    }
    else {
        cerr << "Khong the mo file de luu!" << endl;
    }
}


// Load game 
void LoadGame() {
    string filename;
    GotoXY(65, 20);
    cout << "Nhap ten file de load game: ";
    GotoXY(65, 21);
    cin >> filename;
    clearScreen();
    ShowBlinkingCursor(true);
    system("color 70");
    fixConsoleWindow();
    ResetData(); 
    vienPlayer(); 
    DrawBoard(BOARD_SIZE);  
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                int value;
                file >> value;
                if (value == -1) {
                    GotoXY(_A[i][j].x, _A[i][j].y);
                    printf("%c", X());
                }
                if (value == 1) {
                    GotoXY(_A[i][j].x, _A[i][j].y);
                    printf("%c", O());
                }
                
            }
        }

        // Đọc lượt chơi tiếp theo
        int turn;
        file >> turn;
        _TURN = (turn == 1);  // Nếu giá trị là 1, lượt của người chơi thứ nhất

        file.close();

        bool validEnter = true;
        while (true) {
            char command = getInput(); // Lấy đầu vào từ phím
            if (command) {
                command = toupper(command);
                if (command == 27) { // ESC để thoát
                    ExitGame();
                    break;  // Thoát khỏi vòng lặp mà không quay lại menu
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
                            break; // Quân X đã được vẽ
                        case 1:
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
                                    break;  // Thoát vòng lặp mà không quay lại menu
                                }
                                else {
                                    StartGame();
                                    break;
                                }
                            }
                        }
                        validEnter = true; // Mở khóa
                    }
                    else if (command == 'L') {
                        clearScreen();
                        SaveGame();
                        clearScreen();
                        break;  // Quay lại vòng lặp chơi game sau khi lưu
                    }
                }
            }
            Sleep(100);
        }

    }
    else {
        cerr << "Khong the mo file de load!" << endl;
    }
}
