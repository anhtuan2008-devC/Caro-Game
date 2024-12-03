#include "Menu.h"

int x = 50;
int y = 5;

// Hàm vẽ hộp chứa nội dung
void box(int x, int y, int w, int h, string nd) {
    // Vẽ bên trong hộp
    x--; y--;
    for (int iy = y; iy < y + h; iy++) {
        for (int ix = x; ix < x + w; ix++) {
            GotoXY(ix, iy);
            cout << " ";
        }
    }

    // Hiển thị nội dung trong hộp
    GotoXY(x + 5, y + 2); // Vị trí hiển thị nội dung trong hộp
    cout << nd;

    // Vẽ viền trên và dưới của hộp
    for (int ix = x; ix < x + w; ix++) {
        GotoXY(ix, y); // Viền trên
        cout << char(196); // ─
        GotoXY(ix, y + h - 1); // Viền dưới
        cout << char(196); // ─
    }

    // Vẽ viền trái và phải của hộp
    for (int iy = y; iy < y + h; iy++) {
        GotoXY(x, iy); // Viền trái
        cout << char(179); // │
        GotoXY(x + w - 1, iy); // Viền phải
        cout << char(179); // │
    }

    // Vẽ các góc của hộp
    GotoXY(x, y); // Góc trên bên trái
    cout << char(218); // ┌
    GotoXY(x + w - 1, y); // Góc trên bên phải
    cout << char(191); // ┐
    GotoXY(x, y + h - 1); // Góc dưới bên trái
    cout << char(192); // └
    GotoXY(x + w - 1, y + h - 1); // Góc dưới bên phải
    cout << char(217); // ┘
}

void PorE() {
    system("color 70");
    box(50, 7, 27, 5, "Player VS Player");
    box(50, 12, 27, 5, "Player VS Environment");
    box(50, 17, 27, 5, "Back");
    int selection = 0; 
    while (true) {
        setColor(7); // Đặt lại màu mặc định
        char ch = _getch(); // Đọc ký tự từ người dùng

        if (ch == 27) { // Phím Escape để thoát
            choseSound();
            clearScreen();
            xuLyMenu();
            break;
        }
        moveSound();
        if (ch == 13) { // Phím Enter để xác nhận lựa chọn
            switch (selection) {
            case 0:
                choseSound();
                clearScreen();
                PlayWithPlayer();
                break;
            case 1:
                choseSound();
                clearScreen();
                PlayWithBot();
                break;
            case 2:
                choseSound();
                clearScreen();
                xuLyMenu();
                break;
            }
        }
        // Dùng các phím mũi tên lên/xuống để di chuyển trong menu
        if (ch == 72 or ch == 'w' or ch == 'W') { // Phím mũi ten len (ASCII 72)
            if (selection > 0) {
                selection--;
            }
        }
        else if (ch == 80 or ch == 's' or ch == 'S') { // Phím mũi tên xuống (ASCII 80)
            if (selection < 2) {
                selection++;
            }
        }

        // Đổi màu cho ô được chọn
        for (int i = 0; i < 3; i++) {
            setColor(i == selection ? 124 : 112); // Màu đỏ (12) cho ô được chọn
            switch (i) {
            case 0: box(50, 7, 27, 5, "Player VS Player"); break;
            case 1: box(50, 12, 27, 5, "Player VS Environment"); break;
            case 2: box(50, 17, 27, 5, "Back"); break;
            }
            Sleep(10);
        }
    }

}


// Hàm hiển thị trợ giúp
void menuHelp() {
    clearScreen();
    system("color 70");
    GotoXY(20, 5);
    cout << "Nhan Enter: de chon/danh caro." << endl;
    GotoXY(20, 6);
    cout << "Nhan Up hoac W: de di chuyen len." << endl;
    GotoXY(20, 7);
    cout << "Nhan Down hoac S: de di chuyen xuong" << endl;
    GotoXY(20, 8);
    cout << "Nhan Right hoac D: de di chuyen sang phai" << endl;
    GotoXY(20, 9);
    cout << "Nhan Left hoac A: de di chuyen sang trai";
    GotoXY(20, 10);
    cout << "Nhan L de luu game " << endl;
    GotoXY(20, 11);
    cout << "-----------------------------------------";
    GotoXY(20, 12);
    cout << "About us:";
    GotoXY(20, 13);
    cout << "24CTT3 Class of US, VNU-HCM";
    GotoXY(20, 14);
    cout << "16th Group";
    GotoXY(20, 15);
    cout << "Lecturer: Truong Toan Thinh";
    GotoXY(20, 20);
    cout << "Nhan Enter de quay ve menu chinh...";

    // Đợi người dùng nhấn Enter 1 lần để quay lại menu chính
    cin.ignore(); // Bỏ qua ký tự newline còn lại trong bộ đệm
    //cin.get();    // Đợi người dùng nhấn Enter
    choseSound();
    // Quay lại menu chính sau khi người dùng nhấn Enter
    clearScreen();
    hienthimenu();
}

// Hàm hiển thị nội dung của menu
void hienthimenu() {
    system("color 70");
    trangtri();
    // Vẽ các hộp với nội dung menu
    box(x, y, 20, 5, "PLAY GAME");
    box(x, y + 5, 20, 5, "LOAD GAME");
    box(x, y + 10, 20, 5, "HELP");
    box(x, y + 15, 20, 5, "SETTING");
    box(x, y + 20, 20, 5, "QUIT");

    // Xử lý nhập liệu cho việc chọn menu
    int selection = 0;
    while (true) {
        setColor(7); // Đặt lại màu mặc định
        char ch = _getch(); // Đọc ký tự từ người dùng
        if (ch == 27) { // Phím Escape để thoát
            clearScreen();
            break;
        }
        moveSound();
        if (ch == 13) { // Phím Enter để xác nhận lựa chọn
            switch (selection) {
            case 0:
                choseSound();
                clearScreen();
                PorE();
                break;
            case 1:
                choseSound();
                clearScreen();
                LoadGame();
                break;
            case 2: {
                choseSound();
                menuHelp(); // Hiển thị trợ giúp
                clearScreen();
                xuLyMenu();
                break;     // Sau khi quay lại, không tiếp tục xử lý menu chính
            }
            case 3:
                choseSound();
                clearScreen();
                cout << "You selected SETTING\n";
                break;
            case 4:
                clearScreen();
                exit(100);
                break;
            }
            break;
        }

        // Dùng các phím mũi tên lên/xuống để di chuyển trong menu
        if (ch == 72 or ch == 'w' or ch == 'W') { // Phím mũi tên lên (ASCII 72)
            if (selection > 0) {
                selection--;
            }
        }
        else if (ch == 80 or ch == 's' or ch == 'S') { // Phím mũi tên xuống (ASCII 80)
            if (selection < 4) {
                selection++;
            }
        }
        // Đổi màu cho ô được chọn
        for (int i = 0; i < 5; i++) {
            setColor(i == selection ? 124 : 112);
            switch (i) {
            case 0: box(x, y, 20, 5, "PLAY GAME"); break;
            case 1: box(x, y + 5, 20, 5, "LOAD GAME"); break;
            case 2: box(x, y + 10, 20, 5, "HELP"); break;
            case 3: box(x, y + 15, 20, 5, "SETTING"); break;
            case 4: box(x, y + 20, 20, 5, "QUIT"); break;
            }
            Sleep(5);
        }
    }
}

void trangtri() {
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    // Lấy chiều rộng và chiều cao của cửa sổ console
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Chiều dài của chữ "CARO" là 7*4 (cho mỗi chữ), cộng thêm 3 khoảng cách giữa các chữ (3 khoảng trống)
    int textWidth = 7 * 4 + 3 * 3;  // 7 ký tự cho mỗi chữ và 3 khoảng cách giữa các chữ
    int textHeight = 5;  // Chữ "CARO" có 5 dòng (theo kích thước chữ)

    // Tính toán vị trí để căn giữa chữ "CARO" theo chiều ngang
    int startX = (consoleWidth - textWidth) / 2;
    int startY = 0;  // Đặt ở dòng đầu tiên (dòng 0)

    // Di chuyển đến vị trí căn giữa trên dòng đầu tiên
    setColor(124);
    GotoXY(startX, startY);
    
        int x = 25, y = 0;
        SetConsoleOutputCP(CP_UTF8);
        setColor(124);
        GotoXY(_A[1][4].x + 5, _A[1][4].y + 9);
        cout << u8R"(
 __  __ _____ _   _ _   _ 
|  \/  | ____| \ | | | | |
| |\/| |  _| |  \| | | | |
| |  | | |___| |\  | |_| |
|_|  |_|_____|_| \_|\___/ 
)";
        SetConsoleOutputCP(437);
        setColor(112);
    // Reset màu sắc về mặc định
}
int xuLyMenu() {
    ShowBlinkingCursor(false);
    hienthimenu(); // Hiển thị menu
    return 0;
}