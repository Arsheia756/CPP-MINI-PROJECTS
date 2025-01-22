#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 30;
const int height = 30;
int x, y, liveX, liveY, score;
enum direction { Stop = 0, Left, Right, Up, Down };
direction dir;
int tailX[100], tailY[100];
int ntail = 0;
bool gamePaused = false;
//function for text color
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//function to move cursor on particular position
void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//funtion to hide cursor
void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
//function of the game title
void DisplayTitle() {
    system("cls");
    SetColor(10); 
    cout << "\t\t======================\n";
    cout << " \t\t    SNAKE GAME\n";
    cout << "\t\t======================\n";
    SetColor(7); 
    cout << "\t\tGAME CONTROLS: \n";
    cout << "\t\tW : Up\n\t\tA : Left\n \t\tS : Down\n \t\tD : Right\n \t\tX - Exit\n";
    cout << "\t\tPress enter to start...\n";
    _getch();
}


void Setup() {
    gameOver = false;
    dir = Stop;
    x = width / 2;
    y = height / 2;
    liveX = rand() % width;
    liveY = rand() % height;
    score = 0;
    ntail = 0;
}
	
  void Draw() {
  	SetCursorPosition(0, 0);
  	   SetColor(14);
    for (int i = 0; i < width + 2; i++)
        cout << "##";//upper boundry
    

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "###";//left boundry
            if (i == y && j == x){
            	SetColor(10);
                cout << "O";//snake head
            }
            else if (i == liveY && j == liveX){
            	SetColor(12);
                cout << "M";//food pellets
            }
            else {
                bool print = false;
                for (int k = 0; k < ntail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                    	SetColor(11);
                        cout << "o";//snake tail
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "###";//right boundry
        }

        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "##";//lower boundry
    cout << endl;

    cout << "Score: " << score << endl;
}


void Input() {
    if (_kbhit()) {
    
        switch (_getch()) {
            case 'a':
                dir = (dir != Right) ? Left : dir;
                break;
            case 'd':
                dir = (dir != Left) ? Right : dir;
                break;
            case 's':
                dir = (dir != Up) ? Down : dir;
                break;
            case 'w':
                dir = (dir != Down) ? Up : dir;
                break;
            case 'g':
                gameOver = true;
                break;
            case 'p':
                gamePaused = !gamePaused;
                break;
        }
    }
}

void Logic() {
    if (gamePaused) return;

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < ntail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case Up:
            y--;
            break;
        case Down:
            y++;
            break;
        default:
            break;
    }
     if (x >= width || x < 0 || y >= height || y < 0)// collision with boundries
        gameOver = true;
		//collision with snake's tail
    for (int i = 0; i < ntail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
            break;
        }
    }

    if (x == liveX && y == liveY) {
        score += 2;
        liveX = rand() % width;
        liveY = rand() % height;
        ntail++;
    }
}

int main() {
	HideCursor();
    DisplayTitle();
    Setup();
   
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
     cout << "Game Over! Your final score is: " << score << endl;
    return 0;
}

