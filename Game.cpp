#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
//----------------- FUNCION PROTOTYPE -----------------
//----------------- Data structure  -----------------
struct scoreboard;
void loadRecord(string name, int points);
scoreboard *getLastRecord(scoreboard *temp); // it will give last record by checking condition if null exit or not
void displayAllRecords();
void printSingleRecord(scoreboard *one);
void header();
int menu();
//----------------- INSTRUCTION PANEL -----------------
//----------------- Points -----------------
void calulateScore();
void displayPoints();
//----------------- Vidya -----------------
void displayEnergyLevel();
void calulateEnergyLevel();
void displayRemainingLife();
//----------------- Evil -----------------
void displayEvilEnergy();
void decreaseEvilEnergyLevel();
void increaseEvilEnergyLevel();
void displayEvilRemainingLife();
//----------------- Level number  -----------------
void calulateLevelNumber();
void diplayLevelNumber();
//----------------- GAME MAP EXPLANATION-----------------
void loadGride();
void displayGride();
//----------------- Cursor movement -----------------
void gotoxy(int x, int y);
//----------------- Movement of vidya -----------------
void moveVidyaLeft();
void moveVidyaRight();
void moveVidyaUp();
void moveVidyaDown();
//----------------- Firing and erasing bullet -----------------
void firingBulletRight();
void firingBulletLeft();
void firingBulletUp();
void firingBulletDown();
void eraseBulletRight();
void eraseBulletLeft();
void eraseBulletUp();
void eraseBulletDown();
//----------------- Collesion-----------------
void collesion(int evil_YAxis, int evil_XAxis); // fire collesion
void evilCollesionVidya();                      // vidya and evil collesion
//----------------- Evil movement -----------------
void evilMovement1();       // level one > x-axix
void evilMovement2();       // level one > y-axix
void evilMovement3();       // level two > x-axix
void evilMovement4();       // level two > y-axix
void evilMovement5();       // level two > rand
void evilMovement6();       // level three > x-axix
void evilMovement7();       // level three > x-axix
void evilMovement8();       // level three > y-axix
void evilMovement9();       // level three > y-axix
void evilMovement10();      // level three > rand
void evilMovement11();      // level three > rand
void evilMovement12();      // level four > x-axix
void evilMovement13();      // level four > x-axix
void evilMovement14();      // level four > y-axix
void evilMovement15();      // level four > rand
void evilMovement16();      // level four > rand
void evilMovement17();      // level four > rand
int generateRandomNumber(); // random number
//----------------- Weapon and energy points -----------------
void updateWeaponStatus();
void displayWeapon();
void displayEnergyBoostUp();
//----------------- Vidya movement according to the Level -----------------
void vidyaMovementAccordingLevel();
//----------------- Game staus -----------------
bool gameStatusChecker();
//----------------- File Handling -----------------
void writeFile(string name, int points);
string seperateField(string record, int fieldNumber);
void readFile();
//----------------- GLOBAL DATA STRUCTURE -----------------
//-----------------Gride 2D-Array -----------------
const int yAxis = 130;
const int xAxis = 37;
char gride[xAxis][yAxis];
//----------------- Points -----------------
int pointchecker = 0;
int totalpoints = 0;
//----------------- Level number variabel -----------------
float levelNumberCheck = 0.0; // provde the status of the level number
//----------------- Vidya variables -----------------
int vidyaX = 32;
int vidyaY = 30;
float totalVidyaEnergy = 100;
int remaningLife = 3;
int weaponDecreaseEnergy = 0;
//----------------- Evil variables -----------------
int totalEvilEnergy = 90;
int evilReamingLifeLevel1 = 3;
int evilReamingLifeLevel2 = 3;
int evilReamingLifeLevel3 = 3;
int evilReamingLifeLevel4 = 3;
int evil1X = 23;        // Level one evil > 1 > x
int evil1Y = 30;        // Level one evil > 1 > x
bool flagE1 = true;     // Level one evil > 1 > x
int evilX2 = 25;        // Level one evil > 2 > y
int evilY2 = 41;        // Level one evil > 2 > y
bool flagE2 = true;     // Level one evil > 2 > y
bool stopLevel1 = true; // Level one evil
// game level two
int evilX3 = 1;         // Level two evil > 3 > x
int evilY3 = 24;        // Level two evil > 3 > x
bool flagE3 = true;     // Level two evil > 3 > x
int evilX4 = 9;         // Level two evil > 4 > y
int evilY4 = 39;        // Level two evil > 4 > y
bool flagE4 = true;     // Level two evil > 4 > y
int evilX5 = 9;         // Level two evil > 5 > rand
int evilY5 = 29;        // Level two evil > 5 > rand
bool stopLevel2 = true; // Level two evil
// game level three
int evilX6 = 1;     // Level three evil > 6 > x
int evilY6 = 78;    // Level three evil > 6 > x
bool flagE6 = true; // Level three evil > 6 > x
int evilX7 = 15;    // Level three evil > 7 > x
int evilY7 = 82;    // Level three evil > 7 > x
bool flagE7 = true; // Level three evil > 7 > x
int evilX8 = 6;     // Level three evil > 8 > y
int evilY8 = 93;    // Level three evil > 8 > y
bool flagE8 = true; // Level three evil > 8 > y
int evilX9 = 7;     // Level three evil > 9 > y
int evilY9 = 68;    // Level three evil > 9 > y
bool flagE9 = true; // Level three evil > 9 > y
int evilX10 = 7;    // Level three evil > 10 > rand
int evilY10 = 102;  // Level three evil > 10 > rand
int evilX11 = 14;   // Level three evil > 11 > rand
int evilY11 = 68;   // Level three evil > 11 > rand
bool stopLevel3 = true;
// game level four
bool stopLevel4 = true;
int evilX12 = 17;    // Level four evil > 12 > x
int evilY12 = 81;    // Level four evil > 12 > x
bool flagE12 = true; // Level four evil > 12 > x
int evilX13 = 28;    // Level four evil > 13 > x
int evilY13 = 91;    // Level four evil > 13 > x
bool flagE13 = true; // Level four evil > 13 > x
int evilX14 = 19;    // Level four evil > 14 > y
int evilY14 = 88;    // Level four evil > 14 > y
bool flagE14 = true; // Level four evil > 14 > y
int evilX15 = 34;    // Level four evil > 15 > rand
int evilY15 = 70;    // Level four evil > 15 > rand
int evilX16 = 32;    // Level four evil > 16 > rand
int evilY16 = 107;   // Level four evil > 16 > rand
int evilX17 = 24;    // Level four evil > 17 > rand
int evilY17 = 78;    // Level four evil > 17 > rand
//----------------- store perivous value -----------------
char previousItem = ' ';
char previousItem1 = ' ';
char previousItem2 = ' ';
char previousItem3 = ' ';
char previousItem4 = ' ';
//-----------------game status checker -----------------
bool gameStatus = true;
//----------------- linked-list -----------------
struct scoreboard
{
    string name;
    int points;
    scoreboard *next;
};
scoreboard *head = NULL;
//-----------------MAIN FUNCTION -----------------
int main()
{
    while (true)
    {
        header();
        cout << "Menu > " << endl;
        cout << "------------------------------" << endl;
        char op = menu();
        int finalPoints = 0;
        string playerName;
        if (op == '1')
        {
            header();
            cout << "Menu > Play Game " << endl;
            cout << "------------------------------" << endl;
            cout << "Enter your name : ";
            cin >> playerName;

            system("cls");
            loadGride();    // load grid function called
            displayGride(); // display grid fnction called
            gotoxy(vidyaY, vidyaX);
            cout << "V";            // vidya agent
            displayWeapon();        // display weapon function called
            displayEnergyBoostUp(); // display energy boost up  point
            while (gameStatus)
            {
                vidyaMovementAccordingLevel();
                calulateLevelNumber();
                increaseEvilEnergyLevel();
                // Panel Box
                displayEnergyLevel();
                displayRemainingLife();
                displayEvilEnergy();
                diplayLevelNumber();
                updateWeaponStatus();
                displayPoints();
                displayEvilRemainingLife();
                // Evil Movement
                evilCollesionVidya();
                finalPoints = totalpoints;
                evilMovement1();  // level one evil
                evilMovement2();  // level one evil
                evilMovement3();  // level two evil
                evilMovement4();  // level two evil
                evilMovement5();  // level two evil
                evilMovement6();  // level three evil
                evilMovement7();  // level three evil
                evilMovement8();  // level three evil
                evilMovement9();  // level three evil
                evilMovement10(); // level three evil
                evilMovement11(); // level three evil
                evilMovement12(); // level four evil
                evilMovement13(); // level four evil
                evilMovement14(); // level four evil
                evilMovement15(); // level four evil
                evilMovement16(); // level four evil
                evilMovement17(); // level four evil
                Sleep(200);
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveVidyaLeft(); // move vidya in left direction
                }
                else if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveVidyaRight(); // move vidya in rigth direction
                }
                else if (GetAsyncKeyState(VK_UP))
                {
                    moveVidyaUp(); // move vidya in up direction
                }
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    moveVidyaDown(); // move vidya in down direction
                }
                else if (GetAsyncKeyState(VK_ESCAPE))
                {
                    gameStatus = false; // to close game
                }
                else if (GetAsyncKeyState('Q'))
                {
                    Beep(10000, 40);
                    firingBulletRight(); // fire in right direction with number Q
                }
                else if (GetAsyncKeyState('W'))
                {
                    Beep(10000, 40);
                    firingBulletLeft(); // fire in left direction with number W
                }
                else if (GetAsyncKeyState('E'))
                {
                    Beep(10000, 40);
                    firingBulletUp(); // fire in up direction with number E
                }
                else if (GetAsyncKeyState('R'))
                {
                    Beep(10000, 40);
                    firingBulletDown(); // fire in down direction with number R
                }
                else
                {
                }
                gameStatus = gameStatusChecker(); // turn off the game
            }
            writeFile(playerName, finalPoints);
        } // end of play game option
        else if (op == '2')
        {
            header();
            cout << "Menu > Table points" << endl;
            cout << "------------------------------" << endl;
            readFile();
            displayAllRecords();
            cout << "Press any key to continue...";
            getch();
        } // end of table points option
        else if (op == '3')
        {
            header();
            cout << "Menu > Instruction" << endl;
            cout << "------------------------------" << endl;
            cout << "Players:-" << endl;
            cout << "V -> Vidyakali" << endl;
            cout << "E -> Evil" << endl;
            cout << "W -> Weapon" << endl;
            cout << "F -> Food" << endl;
            cout << "Rules:-" << endl;
            cout << "Every step without weapons reduces 0.50% energy" << endl;
            cout << "Every step with weapons reduces 1 % energy" << endl;
            cout << "Weapons load up reduce 2 % energy" << endl;
            cout << "Energy point boost uptos 20 % energy" << endl;
            cout << "Weapon pickup give points according to game level (In level one evergy weapon give 10 points)" << endl;
            cout << "Press any key to exit...";
            getch();
        } // end of instruction option
        else if (op == '4')
        {
            header();
            cout << "Menu > About" << endl;
            cout << "------------------------------" << endl;
            cout << "Instructor     : Dr Awais Hassan" << endl;
            cout << "Special Thanks : Maida Shahid" << endl;
            cout << "Developer      : Muhammad Hammad Hassan" << endl;
            cout << "Email Address  : mhhjutt@gmail.com " << endl;
            cout << "Press any key to continue...";
            getch();
        } // end of about option
        else if (op == '5')
        {
            header();
            cout << "Menu > Exit" << endl;
            cout << "------------------------------" << endl;
            cout << "Press any key to exit...";
            getch();
            break;

        } // end of exit option
        else
        {
            cout << "Invalid option" << endl;
            cout << "Press any key to continue...";
            getch();
        }
    }
    header();
    cout << "Thank you so much...Take Care...ALLAH Hafiz...";
} // end of main function
//----------------- FUNCION DEFINITION -----------------
void header()
{
    system("cls");
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||                                     ||||||||||||||" << endl;
    cout << "||||||||||||||                                     ||||||||||||||" << endl;
    cout << "|||||||                     VidyaKali                     |||||||" << endl;
    cout << "||||||||||||||                                     ||||||||||||||" << endl;
    cout << "||||||||||||||                                     ||||||||||||||" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "-----------------------------------------------------------------" << endl;
} // end of function
int menu()
{
    char option;
    cout << "Choose a option" << endl;
    cout << "1. PLay Game" << endl;
    cout << "2. Leading Board" << endl;
    cout << "3. Instruction" << endl;
    cout << "4. About" << endl;
    cout << "5. Exit" << endl;
    cout << "Press a number...";
    cin >> option;
    return option;
} // end of function
//----------------- INSTRUCTION PANEL -----------------
//----------------- Points -----------------
void calulateScore()
{
    if (pointchecker == 0)
    {
        totalpoints += 5;
    }
    if (pointchecker == 1) // First Level
    {
        totalpoints += 5;
    }
    else if (pointchecker == 2) // Second Level
    {
        totalpoints += 10;
    }
    else if (pointchecker == 3) // Third Level
    {
        totalpoints += 20;
    }
    else if (pointchecker == 4) // Fourth Level
    {
        totalpoints += 30;
    }
} // end of function
void displayPoints()
{
    gotoxy(120, 2);
    cout << totalpoints;
} // end of function
//----------------- Vidya -----------------
void displayEnergyLevel()
{
    gotoxy(120, 5);
    cout << totalVidyaEnergy;
} // end of function
void calulateEnergyLevel()
{
    if (pointchecker == 0)
    {
        totalVidyaEnergy = totalVidyaEnergy - 0.50;
    }
    else if (pointchecker == 1 || pointchecker == 2 || pointchecker == 3 || pointchecker == 4)
    {
        totalVidyaEnergy = totalVidyaEnergy - 1;
    }
    if (totalVidyaEnergy <= 0)
    {
        remaningLife -= 1;
        totalVidyaEnergy += 100;
    }
    if ((vidyaY == 10 && vidyaX == 32) || (vidyaY == 10 && vidyaX == 25) || (vidyaY == 10 && vidyaX == 20) || (vidyaY == 9 && vidyaX == 5) || (vidyaY == 51 && vidyaX == 5) || (vidyaY == 45 && vidyaX == 9) || (vidyaY == 76 && vidyaX == 3) || (vidyaY == 76 && vidyaX == 5) || (vidyaY == 76 && vidyaX == 7) || (vidyaY == 77 && vidyaX == 12) || (vidyaY == 83 && vidyaX == 19) || (vidyaY == 73 && vidyaX == 23) || (vidyaY == 79 && vidyaX == 27) || (vidyaY == 80 && vidyaX == 29) || (vidyaY == 79 && vidyaX == 34) || (vidyaY == 96 && vidyaX == 32) || (vidyaY == 51 && vidyaX == 19) || (vidyaY == 51 && vidyaX == 21) || (vidyaY == 46 && vidyaX == 20) || (vidyaY == 29 && vidyaX == 27) || (vidyaY == 52 && vidyaX == 34)) // weapon loaded and one step move
    {
        totalVidyaEnergy = totalVidyaEnergy - 2.00;
    }
    if ((vidyaY == 7 && vidyaX == 12) || (vidyaY == 9 && vidyaX == 12) || (vidyaY == 11 && vidyaX == 12) || (vidyaY == 9 && vidyaX == 13) || (vidyaY == 32 && vidyaX == 12) || (vidyaY == 33 && vidyaX == 12) || (vidyaY == 33 && vidyaX == 13) || (vidyaY == 101 && vidyaX == 12) || (vidyaY == 102 && vidyaX == 12) || (vidyaY == 103 && vidyaX == 12) || (vidyaY == 102 && vidyaX == 13) || (vidyaY == 103 && vidyaX == 13))
    {
        totalVidyaEnergy = totalVidyaEnergy + 20;
    }
} // end of function
void displayRemainingLife()
{
    gotoxy(121, 8);
    cout << remaningLife;
} // end of function
//----------------- Evil -----------------
void displayEvilEnergy()
{
    gotoxy(120, 11);
    cout << totalEvilEnergy;
} // end of function
void decreaseEvilEnergyLevel()
{
    // decrease the evil energy accoring to level number
    if (levelNumberCheck == 1)
    { // first level
        totalEvilEnergy -= 10;
        Beep(1000, 30);
    }
    else if (levelNumberCheck == 2)
    { // second level
        totalEvilEnergy -= 7;
        Beep(1000, 30);
    }
    else if (levelNumberCheck == 3)
    { // third level
        totalEvilEnergy -= 5;
        Beep(1000, 30);
    }
    else if (levelNumberCheck == 4)
    { // third level
        totalEvilEnergy -= 3;
        Beep(1000, 30);
    }
    // stop evils movement
    if (evilReamingLifeLevel1 == 0)
    {
        stopLevel1 = false;
    }
    if (evilReamingLifeLevel2 == 0)
    {
        stopLevel2 = false;
    }
    if (evilReamingLifeLevel3 == 0)
    {
        stopLevel3 = false;
    }
    if (evilReamingLifeLevel4 == 0)
    {
        stopLevel4 = false;
    }
} // end of function
void increaseEvilEnergyLevel()
{
    if (totalEvilEnergy <= 0 && levelNumberCheck == 1)
    { // 1st level
        totalEvilEnergy = 90;
        evilReamingLifeLevel1 -= 1;
    }
    if (totalEvilEnergy <= 0 && levelNumberCheck == 2)
    { // 2nd level
        totalEvilEnergy = 90;
        evilReamingLifeLevel2 -= 1;
    }
    else if (totalEvilEnergy <= 0 && levelNumberCheck == 3)
    { // 3rd level
        totalEvilEnergy = 90;
        evilReamingLifeLevel3 -= 1;
    }
    else if (totalEvilEnergy <= 0 && levelNumberCheck == 4)
    { // 4th level
        totalEvilEnergy = 90;
        evilReamingLifeLevel4 -= 1;
    }
} // end of function
void displayEvilRemainingLife()
{
    gotoxy(121, 14);
    if (levelNumberCheck == 1)
    {
        cout << evilReamingLifeLevel1;
    }
    else if (levelNumberCheck == 2)
    {
        cout << evilReamingLifeLevel2;
    }
    else if (levelNumberCheck == 3)
    {
        cout << evilReamingLifeLevel3;
    }
    else if (levelNumberCheck == 4)
    {
        cout << evilReamingLifeLevel4;
    }
} // end of function
//----------------- Level number -----------------
void calulateLevelNumber()
{
    if ((vidyaX >= 17 && vidyaX <= 37) && (vidyaY >= 0 && vidyaY <= 60))
    { // level one
        levelNumberCheck = 1;
    }
    else if ((vidyaX >= 0 && vidyaX <= 15) && (vidyaY >= 0 && vidyaY <= 61))
    { // level two
        levelNumberCheck = 2;
    }
    else if ((vidyaX >= 0 && vidyaX <= 15) && (vidyaY >= 66 && vidyaY <= 130))
    { // level three
        levelNumberCheck = 3;
    }
    else if ((vidyaX >= 17 && vidyaX <= 37) && (vidyaY >= 67 && vidyaY <= 130))
    { // level four
        levelNumberCheck = 4;
    }
} // end of function
void diplayLevelNumber()

{
    gotoxy(120, 17);
    cout << levelNumberCheck;
} // end of function
//----------------- GAME BOARD EXPLANATION-----------------
void loadGride()
{
    string record;
    fstream load;
    load.open("Gride.txt", ios::in);
    for (int x = 0; x < xAxis; x++)
    {
        getline(load, record);
        for (int y = 0; y < yAxis; y++)
        {
            gride[x][y] = record[y];
        }
    }
    load.close();
} // end of function
void displayGride()
{
    for (int x = 0; x < xAxis; x++)
    {
        for (int y = 0; y < yAxis; y++)
        {
            cout << gride[x][y];
        }
        cout << endl;
    }
} // end of function
//----------------- Cursor movement -----------------
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
} // end of function
//----------------- Movement of vidya -----------------
void moveVidyaLeft()
{
    if (gride[vidyaX][vidyaY - 1] == ' ')
    {
        calulateEnergyLevel();
        gride[vidyaX][vidyaY] = ' ';
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaY--;
        gotoxy(vidyaY, vidyaX);
        cout << "V";
    }
} // end of function
void moveVidyaRight()
{
    if (gride[vidyaX][vidyaY + 1] == ' ')
    {
        calulateEnergyLevel();
        gride[vidyaX][vidyaY] = ' ';
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaY++;
        gotoxy(vidyaY, vidyaX);
        cout << "V";
    }
} // end of function
void moveVidyaUp()
{
    if (gride[vidyaX - 1][vidyaY] == ' ')
    {
        calulateEnergyLevel();
        gride[vidyaX][vidyaY] = ' ';
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaX--;
        gotoxy(vidyaY, vidyaX);
        cout << "V";
    }
} // end of function
void moveVidyaDown()
{
    if (gride[vidyaX + 1][vidyaY] == ' ')
    {
        calulateEnergyLevel();
        gride[vidyaY][vidyaX] = ' ';
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaX++;
        gotoxy(vidyaY, vidyaX);
        cout << "V";
    }
} // end of function
//----------------- Firing and erasing bullet -----------------
void firingBulletRight()
{
    previousItem1 = gride[vidyaX][vidyaY + 3];
    previousItem2 = gride[vidyaX][vidyaY + 6];
    previousItem3 = gride[vidyaX][vidyaY + 9];
    previousItem4 = gride[vidyaX][vidyaY + 12];
    gotoxy(vidyaY + 3, vidyaX);
    cout << ".";
    gotoxy(vidyaY + 6, vidyaX);
    cout << ".";
    gotoxy(vidyaY + 9, vidyaX);
    cout << ".";
    gotoxy(vidyaY + 12, vidyaX);
    cout << ".";
    collesion(evil1Y, evil1X);
    collesion(evilY2, evilX2);
    collesion(evilY3, evilX3);
    collesion(evilY4, evilX4);
    collesion(evilY5, evilX5);
    collesion(evilY6, evilX6);
    collesion(evilY7, evilX7);
    collesion(evilY8, evilX8);
    collesion(evilY9, evilX9);
    collesion(evilY10, evilX10);
    collesion(evilY11, evilX11);
    collesion(evilY12, evilX12);
    collesion(evilY13, evilX13);
    collesion(evilY14, evilX14);
    collesion(evilY15, evilX15);
    collesion(evilY16, evilX16);
    collesion(evilY17, evilX17);
    eraseBulletRight();
} // end of function
void firingBulletLeft()
{
    previousItem1 = gride[vidyaX][vidyaY - 3];
    previousItem2 = gride[vidyaX][vidyaY - 6];
    previousItem3 = gride[vidyaX][vidyaY - 9];
    previousItem4 = gride[vidyaX][vidyaY - 12];
    gotoxy(vidyaY - 3, vidyaX);
    cout << ".";
    gotoxy(vidyaY - 6, vidyaX);
    cout << ".";
    gotoxy(vidyaY - 9, vidyaX);
    cout << ".";
    gotoxy(vidyaY - 12, vidyaX);
    cout << ".";
    collesion(evil1Y, evil1X);
    collesion(evilY2, evilX2);
    collesion(evilY3, evilX3);
    collesion(evilY4, evilX4);
    collesion(evilY5, evilX5);
    collesion(evilY6, evilX6);
    collesion(evilY7, evilX7);
    collesion(evilY8, evilX8);
    collesion(evilY9, evilX9);
    collesion(evilY10, evilX10);
    collesion(evilY11, evilX11);
    collesion(evilY12, evilX12);
    collesion(evilY13, evilX13);
    collesion(evilY14, evilX14);
    collesion(evilY15, evilX15);
    collesion(evilY16, evilX16);
    collesion(evilY17, evilX17);
    eraseBulletLeft();
} // end of function
void firingBulletUp()
{
    previousItem1 = gride[vidyaX + 1][vidyaY];
    previousItem2 = gride[vidyaX + 2][vidyaY];
    previousItem3 = gride[vidyaX + 3][vidyaY];
    previousItem4 = gride[vidyaX + 4][vidyaY];
    gotoxy(vidyaY, vidyaX + 1);
    cout << ".";
    gotoxy(vidyaY, vidyaX + 2);
    cout << ".";
    gotoxy(vidyaY, vidyaX + 3);
    cout << ".";
    gotoxy(vidyaY, vidyaX + 4);
    cout << ".";
    collesion(evil1Y, evil1X);
    collesion(evilY2, evilX2);
    collesion(evilY3, evilX3);
    collesion(evilY4, evilX4);
    collesion(evilY5, evilX5);
    collesion(evilY6, evilX6);
    collesion(evilY7, evilX7);
    collesion(evilY8, evilX8);
    collesion(evilY9, evilX9);
    collesion(evilY10, evilX10);
    collesion(evilY11, evilX11);
    collesion(evilY12, evilX12);
    collesion(evilY13, evilX13);
    collesion(evilY14, evilX14);
    collesion(evilY15, evilX15);
    collesion(evilY16, evilX16);
    collesion(evilY17, evilX17);
    eraseBulletUp();
} // end of function
void firingBulletDown()
{
    previousItem1 = gride[vidyaX - 1][vidyaY];
    previousItem2 = gride[vidyaX - 2][vidyaY];
    previousItem3 = gride[vidyaX - 3][vidyaY];
    previousItem4 = gride[vidyaX - 4][vidyaY];
    gotoxy(vidyaY, vidyaX - 1);
    cout << ".";
    gotoxy(vidyaY, vidyaX - 2);
    cout << ".";
    gotoxy(vidyaY, vidyaX - 3);
    cout << ".";
    gotoxy(vidyaY, vidyaX - 4);
    cout << ".";
    collesion(evil1Y, evil1X);
    collesion(evilY2, evilX2);
    collesion(evilY3, evilX3);
    collesion(evilY4, evilX4);
    collesion(evilY5, evilX5);
    collesion(evilY6, evilX6);
    collesion(evilY7, evilX7);
    collesion(evilY8, evilX8);
    collesion(evilY9, evilX9);
    collesion(evilY10, evilX10);
    collesion(evilY11, evilX11);
    collesion(evilY12, evilX12);
    collesion(evilY13, evilX13);
    collesion(evilY14, evilX14);
    collesion(evilY15, evilX15);
    collesion(evilY16, evilX16);
    collesion(evilY17, evilX17);
    eraseBulletDown();
} // end of function
void eraseBulletRight()
{
    Sleep(300);
    gotoxy(vidyaY + 3, vidyaX);
    cout << previousItem1;
    gotoxy(vidyaY + 6, vidyaX);
    cout << previousItem2;
    gotoxy(vidyaY + 9, vidyaX);
    cout << previousItem3;
    gotoxy(vidyaY + 12, vidyaX);
    cout << previousItem4;
} // end of function
void eraseBulletLeft()
{
    Sleep(300);
    gotoxy(vidyaY - 3, vidyaX);
    cout << previousItem1;
    gotoxy(vidyaY - 6, vidyaX);
    cout << previousItem2;
    gotoxy(vidyaY - 9, vidyaX);
    cout << previousItem3;
    gotoxy(vidyaY - 12, vidyaX);
    cout << previousItem4;
} // end of function
void eraseBulletUp()
{
    Sleep(300);
    gotoxy(vidyaY, vidyaX + 1);
    cout << previousItem1;
    gotoxy(vidyaY, vidyaX + 2);
    cout << previousItem2;
    gotoxy(vidyaY, vidyaX + 3);
    cout << previousItem3;
    gotoxy(vidyaY, vidyaX + 4);
    cout << previousItem4;
} // end of function
void eraseBulletDown()
{
    Sleep(300);
    gotoxy(vidyaY, vidyaX - 1);
    cout << previousItem1;
    gotoxy(vidyaY, vidyaX - 2);
    cout << previousItem2;
    gotoxy(vidyaY, vidyaX - 3);
    cout << previousItem3;
    gotoxy(vidyaY, vidyaX - 4);
    cout << previousItem4;
} // end of function
//----------------- Collesion-----------------
void collesion(int evil_YAxis, int evil_XAxis)
{

    if ((evil_YAxis == vidyaY + 12 && evil_XAxis == vidyaX) || (evil_YAxis == vidyaY + 9 && evil_XAxis == vidyaX) || (evil_YAxis == vidyaY + 6 && evil_XAxis == vidyaX) || (evil_YAxis == vidyaY + 3 && evil_XAxis == vidyaX))
    {
        decreaseEvilEnergyLevel();
        calulateScore();
    }
    else if ((evil_YAxis == vidyaY - 12 && evil_XAxis == vidyaX) || (evil_YAxis == vidyaY - 9 && evil_XAxis == vidyaX) || (evil_YAxis == vidyaY - 6 && evil_XAxis == vidyaX) || (evil_YAxis == vidyaY - 3 && evil_XAxis == vidyaX))
    {
        decreaseEvilEnergyLevel();
        calulateScore();
    }
    else if ((evil_YAxis == vidyaY && evil_XAxis == vidyaX + 1) || (evil_YAxis == vidyaY && evil_XAxis == vidyaX + 2) || (evil_YAxis == vidyaY && evil_XAxis == vidyaX + 3) || (evil_YAxis == vidyaY && evil_XAxis == vidyaX + 4))
    {
        decreaseEvilEnergyLevel();
        calulateScore();
    }
    else if ((evil_YAxis == vidyaY && evil_XAxis == vidyaX - 1) || (evil_YAxis == vidyaY && evil_XAxis == vidyaX - 2) || (evil_YAxis == vidyaY && evil_XAxis == vidyaX - 3) || (evil_YAxis == vidyaY && evil_XAxis == vidyaX - 4))
    {
        decreaseEvilEnergyLevel();
        calulateScore();
    }
} // end of function
void evilCollesionVidya()
{
    if (evil1X == vidyaX && evil1Y == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX2 == vidyaX && evilY2 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX3 == vidyaX && evilY3 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX4 == vidyaX && evilY4 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX5 == vidyaX && evilY5 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX6 == vidyaX && evilY6 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX7 == vidyaX && evilY7 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX8 == vidyaX && evilY8 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX9 == vidyaX && evilY9 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX10 == vidyaX && evilY10 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX11 == vidyaX && evilY11 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX12 == vidyaX && evilY12 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX13 == vidyaX && evilY13 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX14 == vidyaX && evilY14 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX15 == vidyaX && evilY15 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX16 == vidyaX && evilY16 == vidyaY)
    {
        remaningLife -= 1;
    }
    else if (evilX17 == vidyaX && evilY17 == vidyaY)
    {
        remaningLife -= 1;
    }
} // end of function
//----------------- Evil Movement -----------------
void evilMovement1()
{ // x-axis movement
    if (stopLevel1 == true)
    {
        char preItem;
        collesion(evil1Y, evil1X);
        if (gride[evil1X][evil1Y + 1] == '|' || gride[evil1X][evil1Y + 1] == '%')
        {
            flagE1 = false;
        }
        else if (gride[evil1X][evil1Y - 1] == '|' || gride[evil1X][evil1Y - 1] == '%')
        {
            flagE1 = true;
        }
        if (flagE1 == true)
        {
            if (gride[evil1X][evil1Y + 1] == ' ')
            {
                preItem = gride[evil1X][evil1Y];
                evil1Y = evil1Y + 1;
                gotoxy(evil1Y, evil1X);
                cout << 'E';
                gotoxy(evil1Y - 1, evil1X);
                cout << preItem;
            }
        }
        else if (flagE1 == false)
        {
            if (gride[evil1X][evil1Y - 1] == ' ')
            {
                preItem = gride[evil1X][evil1Y];
                evil1Y = evil1Y - 1;
                gotoxy(evil1Y, evil1X);
                cout << 'E';
                gotoxy(evil1Y + 1, evil1X);
                cout << preItem;
            }
        }
    }
    else
    {
        collesion(evil1Y, evil1X);
        gotoxy(evil1Y, evil1X);
        cout << " ";
    }
} // end of function
void evilMovement2()
{ // y-axis movement
    if (stopLevel1 == true)
    {
        char preItem;
        collesion(evilY2, evilX2);
        if (gride[evilX2 + 1][evilY2] == '-' || gride[evilX2 + 1][evilY2] == '#')
        {
            flagE2 = false;
        }
        else if (gride[evilX2 - 1][evilY2] == '-' || gride[evilX2 - 1][evilY2] == '#')
        {
            flagE2 = true;
        }
        if (flagE2 == true)
        {
            if (gride[evilX2 + 1][evilY2] == ' ')
            {
                preItem = gride[evilX2][evilY2];
                evilX2 = evilX2 + 1;
                gotoxy(evilY2, evilX2);
                cout << 'E';
                gotoxy(evilY2, evilX2 - 1);
                cout << preItem;
            }
        }
        else if (flagE2 == false)
        {
            if (gride[evilX2 - 1][evilY2] == ' ')
            {
                preItem = gride[evilX2][evilY2];
                evilX2 = evilX2 - 1;
                gotoxy(evilY2, evilX2);
                cout << 'E';
                gotoxy(evilY2, evilX2 + 1);
                cout << preItem;
            }
        }
    }
    else
    {
        collesion(evilY2, evilX2);
        gotoxy(evilY2, evilX2);
        cout << " ";
    }
} // end of function
void evilMovement3()
{ // x-axis movement
    if (stopLevel2 == true)
    {
        collesion(evilY3, evilX3);
        if (gride[evilX3][evilY3 + 1] == '|' || gride[evilX3][evilY3 + 1] == '#')
        {
            flagE3 = false;
        }
        else if (gride[evilX3][evilY3 - 1] == '|' || gride[evilX3][evilY3 - 1] == '#')
        {
            flagE3 = true;
        }
        if (flagE3 == true)
        {
            if (gride[evilX3][evilY3 + 1] == ' ')
            {
                previousItem = gride[evilX3][evilY3];
                evilY3 = evilY3 + 1;
                gotoxy(evilY3, evilX3);
                cout << 'E';
                gotoxy(evilY3 - 1, evilX3);
                cout << previousItem;
            }
        }
        else if (flagE3 == false)
        {
            if (gride[evilX3][evilY3 - 1] == ' ')
            {
                previousItem = gride[evilX3][evilY3];
                evilY3 = evilY3 - 1;
                gotoxy(evilY3, evilX3);
                cout << 'E';
                gotoxy(evilY3 + 1, evilX3);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY3, evilX3);
        gotoxy(evilY3, evilX3);
        cout << " ";
    }
} // end of function
void evilMovement4()
{ // y-axis movement
    if (stopLevel2 == true)
    {
        collesion(evilY4, evilX4);
        if (gride[evilX4 + 1][evilY4] == '-' || gride[evilX4 + 1][evilY4] == '#')
        {
            flagE4 = false;
        }
        else if (gride[evilX4 - 1][evilY4] == '-' || gride[evilX4 - 1][evilY4] == '#')
        {
            flagE4 = true;
        }
        if (flagE4 == true)
        {
            if (gride[evilX4 + 1][evilY4] == ' ')
            {
                previousItem = gride[evilX4][evilY4];
                evilX4 = evilX4 + 1;
                gotoxy(evilY4, evilX4);
                cout << 'E';
                gotoxy(evilY4, evilX4 - 1);
                cout << previousItem;
            }
        }
        else if (flagE4 == false)
        {
            if (gride[evilX4 - 1][evilY4] == ' ')
            {
                previousItem = gride[evilX4][evilY4];
                evilX4 = evilX4 - 1;
                gotoxy(evilY4, evilX4);
                cout << 'E';
                gotoxy(evilY4, evilX4 + 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY4, evilX4);
        gotoxy(evilY4, evilX4);
        cout << " ";
    }
} // end of function
void evilMovement5()
{ // rand
    if (stopLevel2 == true)
    {
        int value = generateRandomNumber();
        if (value == 1)
        {
            if (gride[evilX5][evilY5 - 1] == ' ')
            {
                previousItem = gride[evilX5][evilY5];
                evilY5 = evilY5 - 1;
                gotoxy(evilY5, evilX5);
                cout << 'E';
                gotoxy(evilY5 + 1, evilX5);
                cout << previousItem;
            }
        }
        if (value == 2)
        {
            if (gride[evilX5][evilY5 + 1] == ' ')
            {
                previousItem = gride[evilX5][evilY5];
                evilY5 = evilY5 + 1;
                gotoxy(evilY5, evilX5);
                cout << 'E';
                gotoxy(evilY5 - 1, evilX5);
                cout << previousItem;
            }
        }
        if (value == 3)
        {
            if (gride[evilX5 - 1][evilY5] == ' ')
            {
                previousItem = gride[evilX5][evilY5];
                evilX5 = evilX5 - 1;
                gotoxy(evilY5, evilX5);
                cout << 'E';
                gotoxy(evilY5, evilX5 + 1);
                cout << previousItem;
            }
        }
        if (value == 4)
        {
            if (gride[evilX5 + 1][evilY5] == ' ')
            {
                previousItem = gride[evilX5][evilY5];
                evilX5 = evilX5 + 1;
                gotoxy(evilY5, evilX5);
                cout << 'E';
                gotoxy(evilY5, evilX5 - 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY5, evilX5);
        gotoxy(evilY5, evilX5);
        cout << " ";
    }
} // end of function
void evilMovement6()
{ // x-axix
    if (stopLevel3 == true)
    {
        collesion(evilY6, evilX6);
        if (gride[evilX6][evilY6 + 1] == '|' || gride[evilX6][evilY6 + 1] == '#')
        {
            flagE6 = false;
        }
        else if (gride[evilX6][evilY6 - 1] == '|' || gride[evilX6][evilY6 - 1] == '#')
        {
            flagE6 = true;
        }
        if (flagE6 == true)
        {
            if (gride[evilX6][evilY6 + 1] == ' ')
            {
                previousItem = gride[evilX6][evilY6];
                evilY6 = evilY6 + 1;
                gotoxy(evilY6, evilX6);
                cout << 'E';
                gotoxy(evilY6 - 1, evilX6);
                cout << previousItem;
            }
        }
        else if (flagE6 == false)
        {
            if (gride[evilX6][evilY6 - 1] == ' ')
            {
                previousItem = gride[evilX6][evilY6];
                evilY6 = evilY6 - 1;
                gotoxy(evilY6, evilX6);
                cout << 'E';
                gotoxy(evilY6 + 1, evilX6);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY6, evilX6);
        gotoxy(evilY6, evilX6);
        cout << " ";
    }
} // end of function
void evilMovement7()
{ // x-axix
    if (stopLevel3 == true)
    {
        collesion(evilY7, evilX7);
        if (gride[evilX7][evilY7 + 1] == '|' || gride[evilX7][evilY7 + 1] == '#')
        {
            flagE7 = false;
        }
        else if (gride[evilX7][evilY7 - 1] == '|' || gride[evilX7][evilY7 - 1] == '#')
        {
            flagE7 = true;
        }
        if (flagE7 == true)
        {
            if (gride[evilX7][evilY7 + 1] == ' ')
            {
                previousItem = gride[evilX7][evilY7];
                evilY7 = evilY7 + 1;
                gotoxy(evilY7, evilX7);
                cout << 'E';
                gotoxy(evilY7 - 1, evilX7);
                cout << previousItem;
            }
        }
        else if (flagE7 == false)
        {
            if (gride[evilX7][evilY7 - 1] == ' ')
            {
                previousItem = gride[evilX7][evilY7];
                evilY7 = evilY7 - 1;
                gotoxy(evilY7, evilX7);
                cout << 'E';
                gotoxy(evilY7 + 1, evilX7);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY7, evilX7);
        gotoxy(evilY7, evilX7);
        cout << " ";
    }
} // end of function
void evilMovement8()
{ // y-axix
    if (stopLevel3 == true)
    {
        collesion(evilY8, evilX8);
        if (gride[evilX8 + 1][evilY8] == '-' || gride[evilX8 + 1][evilY8] == '#')
        {
            flagE8 = false;
        }
        else if (gride[evilX8 - 1][evilY8] == '-' || gride[evilX8 - 1][evilY8] == '#')
        {
            flagE8 = true;
        }
        if (flagE8 == true)
        {
            if (gride[evilX8 + 1][evilY8] == ' ')
            {
                previousItem = gride[evilX8][evilY8];
                evilX8 = evilX8 + 1;
                gotoxy(evilY8, evilX8);
                cout << 'E';
                gotoxy(evilY8, evilX8 - 1);
                cout << previousItem;
            }
        }
        else if (flagE8 == false)
        {
            if (gride[evilX8 - 1][evilY8] == ' ')
            {
                previousItem = gride[evilX8][evilY8];
                evilX8 = evilX8 - 1;
                gotoxy(evilY8, evilX8);
                cout << 'E';
                gotoxy(evilY8, evilX8 + 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY8, evilX8);
        gotoxy(evilY8, evilX8);
        cout << " ";
    }
} // end of function
void evilMovement9()
{ // y-axix
    if (stopLevel3 == true)
    {
        collesion(evilY9, evilX9);
        if (gride[evilX9 + 1][evilY9] == '-' || gride[evilX9 + 1][evilY9] == '#')
        {
            flagE9 = false;
        }
        else if (gride[evilX9 - 1][evilY9] == '-' || gride[evilX9 - 1][evilY9] == '#')
        {
            flagE9 = true;
        }
        if (flagE9 == true)
        {
            if (gride[evilX9 + 1][evilY9] == ' ')
            {
                previousItem = gride[evilX9][evilY9];
                evilX9 = evilX9 + 1;
                gotoxy(evilY9, evilX9);
                cout << 'E';
                gotoxy(evilY9, evilX9 - 1);
                cout << previousItem;
            }
        }
        else if (flagE9 == false)
        {
            if (gride[evilX9 - 1][evilY9] == ' ')
            {
                previousItem = gride[evilX9][evilY9];
                evilX9 = evilX9 - 1;
                gotoxy(evilY9, evilX9);
                cout << 'E';
                gotoxy(evilY9, evilX9 + 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY9, evilX9);
        gotoxy(evilY9, evilX9);
        cout << " ";
    }
} // end of function
void evilMovement10()
{ // rand
    if (stopLevel3 == true)
    {
        int value = generateRandomNumber();
        if (value == 1)
        {
            if (gride[evilX10][evilY10 - 1] == ' ')
            {
                previousItem = gride[evilX10][evilY10];
                evilY10 = evilY10 - 1;
                gotoxy(evilY10, evilX10);
                cout << 'E';
                gotoxy(evilY10 + 1, evilX10);
                cout << previousItem;
            }
        }
        if (value == 2)
        {
            if (gride[evilX10][evilY10 + 1] == ' ')
            {
                previousItem = gride[evilX10][evilY10];
                evilY10 = evilY10 + 1;
                gotoxy(evilY10, evilX10);
                cout << 'E';
                gotoxy(evilY10 - 1, evilX10);
                cout << previousItem;
            }
        }
        if (value == 3)
        {
            if (gride[evilX10 - 1][evilY10] == ' ')
            {
                previousItem = gride[evilX10][evilY10];
                evilX10 = evilX10 - 1;
                gotoxy(evilY10, evilX10);
                cout << 'E';
                gotoxy(evilY10, evilX10 + 1);
                cout << previousItem;
            }
        }
        if (value == 4)
        {
            if (gride[evilX10 + 1][evilY10] == ' ')
            {
                previousItem = gride[evilX10][evilY10];
                evilX10 = evilX10 + 1;
                gotoxy(evilY10, evilX10);
                cout << 'E';
                gotoxy(evilY10, evilX10 - 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY10, evilX10);
        gotoxy(evilY10, evilX10);
        cout << " ";
    }
} // end of function
void evilMovement11()
{ // rand
    if (stopLevel3 == true)
    {
        int value = generateRandomNumber();
        if (value == 1)
        {
            if (gride[evilX11][evilY11 - 1] == ' ')
            {
                previousItem = gride[evilX11][evilY11];
                evilY11 = evilY11 - 1;
                gotoxy(evilY11, evilX11);
                cout << 'E';
                gotoxy(evilY11 + 1, evilX11);
                cout << previousItem;
            }
        }
        if (value == 2)
        {
            if (gride[evilX11][evilY11 + 1] == ' ')
            {
                previousItem = gride[evilX11][evilY11];
                evilY11 = evilY11 + 1;
                gotoxy(evilY11, evilX11);
                cout << 'E';
                gotoxy(evilY11 - 1, evilX11);
                cout << previousItem;
            }
        }
        if (value == 3)
        {
            if (gride[evilX11 - 1][evilY11] == ' ')
            {
                previousItem = gride[evilX11][evilY11];
                evilX11 = evilX11 - 1;
                gotoxy(evilY11, evilX11);
                cout << 'E';
                gotoxy(evilY11, evilX11 + 1);
                cout << previousItem;
            }
        }
        if (value == 4)
        {
            if (gride[evilX11 + 1][evilY11] == ' ')
            {
                previousItem = gride[evilX11][evilY11];
                evilX11 = evilX11 + 1;
                gotoxy(evilY11, evilX11);
                cout << 'E';
                gotoxy(evilY11, evilX11 - 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY11, evilX11);
        gotoxy(evilY11, evilX11);
        cout << " ";
    }
} // end of function
void evilMovement12()
{ // x-axix
    if (stopLevel4 == true)
    {
        collesion(evilY12, evilX12);
        if (gride[evilX12][evilY12 + 1] == '|' || gride[evilX12][evilY12 + 1] == '#')
        {
            flagE12 = false;
        }
        else if (gride[evilX12][evilY12 - 1] == '|' || gride[evilX12][evilY12 - 1] == '#')
        {
            flagE12 = true;
        }
        if (flagE12 == true)
        {
            if (gride[evilX12][evilY12 + 1] == ' ')
            {
                previousItem = gride[evilX12][evilY12];
                evilY12 = evilY12 + 1;
                gotoxy(evilY12, evilX12);
                cout << 'E';
                gotoxy(evilY12 - 1, evilX12);
                cout << previousItem;
            }
        }
        else if (flagE12 == false)
        {
            if (gride[evilX12][evilY12 - 1] == ' ')
            {
                previousItem = gride[evilX12][evilY12];
                evilY12 = evilY12 - 1;
                gotoxy(evilY12, evilX12);
                cout << 'E';
                gotoxy(evilY12 + 1, evilX12);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY12, evilX12);
        gotoxy(evilY12, evilX12);
        cout << " ";
    }
} // end of function
void evilMovement13()
{ // x-axix
    if (stopLevel4 == true)
    {
        collesion(evilY13, evilX13);
        if (gride[evilX13][evilY13 + 1] == '|' || gride[evilX13][evilY13 + 1] == '#')
        {
            flagE13 = false;
        }
        else if (gride[evilX13][evilY13 - 1] == '|' || gride[evilX13][evilY13 - 1] == '#')
        {
            flagE13 = true;
        }
        if (flagE13 == true)
        {
            if (gride[evilX13][evilY13 + 1] == ' ')
            {
                previousItem = gride[evilX13][evilY13];
                evilY13 = evilY13 + 1;
                gotoxy(evilY13, evilX13);
                cout << 'E';
                gotoxy(evilY13 - 1, evilX13);
                cout << previousItem;
            }
        }
        else if (flagE13 == false)
        {
            if (gride[evilX13][evilY13 - 1] == ' ')
            {
                previousItem = gride[evilX13][evilY13];
                evilY13 = evilY13 - 1;
                gotoxy(evilY13, evilX13);
                cout << 'E';
                gotoxy(evilY13 + 1, evilX13);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY13, evilX13);
        gotoxy(evilY13, evilX13);
        cout << " ";
    }
} // end of function
void evilMovement14()
{ // y-axix
    if (stopLevel4 == true)
    {
        collesion(evilY14, evilX14);
        if (gride[evilX14 + 1][evilY14] == '-' || gride[evilX14 + 1][evilY14] == '#')
        {
            flagE14 = false;
        }
        else if (gride[evilX14 - 1][evilY14] == '-' || gride[evilX14 - 1][evilY14] == '#')
        {
            flagE14 = true;
        }
        if (flagE14 == true)
        {
            if (gride[evilX14 + 1][evilY14] == ' ')
            {
                previousItem = gride[evilX14][evilY14];
                evilX14 = evilX14 + 1;
                gotoxy(evilY14, evilX14);
                cout << 'E';
                gotoxy(evilY14, evilX14 - 1);
                cout << previousItem;
            }
        }
        else if (flagE14 == false)
        {
            if (gride[evilX14 - 1][evilY14] == ' ')
            {
                previousItem = gride[evilX14][evilY14];
                evilX14 = evilX14 - 1;
                gotoxy(evilY14, evilX14);
                cout << 'E';
                gotoxy(evilY14, evilX14 + 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY14, evilX14);
        gotoxy(evilY14, evilX14);
        cout << " ";
    }
} // end of function
void evilMovement15()
{ // rand
    if (stopLevel4 == true)
    {
        int value = generateRandomNumber();
        if (value == 1)
        {
            if (gride[evilX15][evilY15 - 1] == ' ')
            {
                previousItem = gride[evilX15][evilY15];
                evilY15 = evilY15 - 1;
                gotoxy(evilY15, evilX15);
                cout << 'E';
                gotoxy(evilY15 + 1, evilX15);
                cout << previousItem;
            }
        }
        if (value == 2)
        {
            if (gride[evilX15][evilY15 + 1] == ' ')
            {
                previousItem = gride[evilX15][evilY15];
                evilY15 = evilY15 + 1;
                gotoxy(evilY15, evilX15);
                cout << 'E';
                gotoxy(evilY15 - 1, evilX15);
                cout << previousItem;
            }
        }
        if (value == 3)
        {
            if (gride[evilX15 - 1][evilY15] == ' ')
            {
                previousItem = gride[evilX15][evilY15];
                evilX15 = evilX15 - 1;
                gotoxy(evilY15, evilX15);
                cout << 'E';
                gotoxy(evilY15, evilX15 + 1);
                cout << previousItem;
            }
        }
        if (value == 4)
        {
            if (gride[evilX15 + 1][evilY15] == ' ')
            {
                previousItem = gride[evilX15][evilY15];
                evilX15 = evilX15 + 1;
                gotoxy(evilY15, evilX15);
                cout << 'E';
                gotoxy(evilY15, evilX15 - 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY15, evilX15);
        gotoxy(evilY15, evilX15);
        cout << " ";
    }
} // end of function
void evilMovement16()
{ // rand
    if (stopLevel4 == true)
    {
        int value = generateRandomNumber();
        if (value == 1)
        {
            if (gride[evilX16][evilY16 - 1] == ' ')
            {
                previousItem = gride[evilX16][evilY16];
                evilY16 = evilY16 - 1;
                gotoxy(evilY16, evilX16);
                cout << 'E';
                gotoxy(evilY16 + 1, evilX16);
                cout << previousItem;
            }
        }
        if (value == 2)
        {
            if (gride[evilX16][evilY16 + 1] == ' ')
            {
                previousItem = gride[evilX16][evilY16];
                evilY16 = evilY16 + 1;
                gotoxy(evilY16, evilX16);
                cout << 'E';
                gotoxy(evilY16 - 1, evilX16);
                cout << previousItem;
            }
        }
        if (value == 3)
        {
            if (gride[evilX16 - 1][evilY16] == ' ')
            {
                previousItem = gride[evilX16][evilY16];
                evilX16 = evilX16 - 1;
                gotoxy(evilY16, evilX16);
                cout << 'E';
                gotoxy(evilY16, evilX16 + 1);
                cout << previousItem;
            }
        }
        if (value == 4)
        {
            if (gride[evilX16 + 1][evilY16] == ' ')
            {
                previousItem = gride[evilX16][evilY16];
                evilX16 = evilX16 + 1;
                gotoxy(evilY16, evilX16);
                cout << 'E';
                gotoxy(evilY16, evilX16 - 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY16, evilX16);
        gotoxy(evilY16, evilX16);
        cout << " ";
    }
} // end of function
void evilMovement17()
{ // rand
    if (stopLevel4 == true)
    {
        int value = generateRandomNumber();
        if (value == 1)
        {
            if (gride[evilX17][evilY17 - 1] == ' ')
            {
                previousItem = gride[evilX17][evilY17];
                evilY17 = evilY17 - 1;
                gotoxy(evilY17, evilX17);
                cout << 'E';
                gotoxy(evilY17 + 1, evilX17);
                cout << previousItem;
            }
        }
        if (value == 2)
        {
            if (gride[evilX17][evilY17 + 1] == ' ')
            {
                previousItem = gride[evilX17][evilY17];
                evilY17 = evilY17 + 1;
                gotoxy(evilY17, evilX17);
                cout << 'E';
                gotoxy(evilY17 - 1, evilX17);
                cout << previousItem;
            }
        }
        if (value == 3)
        {
            if (gride[evilX17 - 1][evilY17] == ' ')
            {
                previousItem = gride[evilX17][evilY17];
                evilX17 = evilX17 - 1;
                gotoxy(evilY17, evilX17);
                cout << 'E';
                gotoxy(evilY17, evilX17 + 1);
                cout << previousItem;
            }
        }
        if (value == 4)
        {
            if (gride[evilX17 + 1][evilY17] == ' ')
            {
                previousItem = gride[evilX17][evilY17];
                evilX17 = evilX17 + 1;
                gotoxy(evilY17, evilX17);
                cout << 'E';
                gotoxy(evilY17, evilX17 - 1);
                cout << previousItem;
            }
        }
    }
    else
    {
        collesion(evilY17, evilX17);
        gotoxy(evilY17, evilX17);
        cout << " ";
    }
} // end of function
int generateRandomNumber()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
} // end of function
//----------------- vidya movement according to the Level -----------------
void vidyaMovementAccordingLevel()
{

    if (evilReamingLifeLevel1 == 0 && levelNumberCheck == 1)
    {
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaX = 15;
        vidyaY = 24;
        gotoxy(24, 15);
        cout << "V";
    }
    else if (evilReamingLifeLevel2 == 0 && levelNumberCheck == 2)
    {
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaX = 1;
        vidyaY = 68;
        gotoxy(68, 1);
        cout << "V";
    }
    else if (evilReamingLifeLevel3 == 0 && levelNumberCheck == 3)
    {
        gotoxy(vidyaY, vidyaX);
        cout << " ";
        vidyaX = 17;
        vidyaY = 69;
        gotoxy(69, 17);
        cout << "V";
    }
    else if (evilReamingLifeLevel4 == 0 && levelNumberCheck == 4)
    {
        // winning movement
    }
} // end of function
//----------------- Weapon and energy points -----------------
void updateWeaponStatus()
{
    if (vidyaY == 30 && vidyaX == 32)
    {
        gotoxy(118, 33);
        cout << "1 Bullet";
        gotoxy(121, 34);
        cout << "==";
        gotoxy(118, 35);
        cout << "5 Points";
        pointchecker = 0;
    }
    else if (vidyaY == 10 && vidyaX == 32 || vidyaY == 10 && vidyaX == 25 || vidyaY == 10 && vidyaX == 20 || vidyaY == 51 && vidyaX == 21 || vidyaY == 52 && vidyaX == 34 || vidyaY == 46 && vidyaX == 20 || vidyaY == 29 && vidyaX == 27) // weapon loaded and one Enemy
    {                                                                                                                                                                                                                                      // 1st zone
        gotoxy(118, 33);
        cout << "1 Bullet";
        gotoxy(121, 34);
        cout << "==";
        gotoxy(118, 35);
        cout << "10 Points";
        pointchecker = 1;
    }
    else if (vidyaY == 9 && vidyaX == 5 || vidyaY == 51 && vidyaX == 5 || vidyaY == 45 && vidyaX == 9)
    { // 2nd zone
        gotoxy(118, 33);
        cout << "1 Bullet";
        gotoxy(121, 34);
        cout << "==";
        gotoxy(118, 35);
        cout << "20 Points";
        pointchecker = 2;
    }
    else if (vidyaY == 76 && vidyaX == 3 || vidyaY == 76 && vidyaX == 5 || vidyaY == 76 && vidyaX == 7 || vidyaY == 77 && vidyaX == 12)
    { // 3rd zone
        gotoxy(118, 33);
        cout << "1 Bullet";
        gotoxy(121, 34);
        cout << "==";
        gotoxy(118, 35);
        cout << "30 Points";
        pointchecker = 3;
    }
    else if (vidyaY == 83 && vidyaX == 19 || vidyaY == 73 && vidyaX == 23 || vidyaY == 79 && vidyaX == 27 || vidyaY == 80 && vidyaX == 29 || vidyaY == 79 && vidyaX == 34 || vidyaY == 96 && vidyaX == 32)
    { // 4th zone
        gotoxy(118, 33);
        cout << "1 Bullet";
        gotoxy(121, 34);
        cout << "==";
        gotoxy(118, 35);
        cout << "40 Points";
        pointchecker = 4;
    }
} // end of function
void displayWeapon()
{
    gotoxy(10, 32); // 1st zone
    cout << "W";    // weapon no 1
    gotoxy(10, 25);
    cout << "W"; // weapon no 2
    gotoxy(10, 20);
    cout << "W"; // weapon no 3
    gotoxy(51, 19);
    cout << "W"; // weapon no 4
    gotoxy(51, 21);
    cout << "W"; // weapon no 5
    gotoxy(52, 34);
    cout << "W"; // weapon no 6
    gotoxy(46, 20);
    cout << "W"; // weapon no 7
    gotoxy(29, 27);
    cout << "W";  // weapon no 8
    gotoxy(9, 5); // 2nd zone
    cout << "W";  // weapon no 9
    gotoxy(51, 5);
    cout << "W"; // weapon no 10
    gotoxy(45, 9);
    cout << "W";   // weapon no 11
    gotoxy(76, 3); // 3rd zone
    cout << "W";   // weapon no 12
    gotoxy(76, 5);
    cout << "W"; // weapon no 13
    gotoxy(76, 7);
    cout << "W"; // weapon no 14
    gotoxy(77, 12);
    cout << "W";    // weapon no 15
    gotoxy(83, 19); // 4th zone
    cout << "W";    // weapon no 16
    gotoxy(73, 23);
    cout << "W"; // weapon no 17
    gotoxy(79, 27);
    cout << "W"; // weapon no 18
    gotoxy(80, 29);
    cout << "W"; // weapon no 19
    gotoxy(79, 34);
    cout << "W"; // weapon no 20
    gotoxy(96, 32);
    cout << "W"; // weapon no 21
} // end of function
void displayEnergyBoostUp()
{
    gotoxy(7, 12);
    cout << "F"; // energy point 1
    gotoxy(9, 12);
    cout << "F"; // energy point 2
    gotoxy(11, 12);
    cout << "F"; // energy point 3
    gotoxy(9, 13);
    cout << "F"; // energy point 4
    gotoxy(32, 12);
    cout << "F"; // energy point 5
    gotoxy(33, 12);
    cout << "F"; // energy point 6
    gotoxy(33, 13);
    cout << "F"; // energy point 7
    gotoxy(101, 12);
    cout << "F"; // energy point 8
    gotoxy(102, 12);
    cout << "F"; // energy point 9
    gotoxy(103, 12);
    cout << "F"; // energy point 10
    gotoxy(102, 13);
    cout << "F"; // energy point 11
} // end of function
//----------------- Game staus -----------------
bool gameStatusChecker()
{
    if (remaningLife == 0)
    {
        return false; // game off
    }
    else if (evilReamingLifeLevel4 == 0)
    {
        return false; // game off
    }
    return true; // game on ha
} // end of function
void writeFile(string name, int points)
{
    fstream append;
    append.open("vidyakali.txt", ios::app);
    append << "\n"
           << name << "," << points;
    append.close();
} // end of function
void readFile()
{
    string record;
    fstream read;
    read.open("vidyakali.txt", ios::in);
    while (!read.eof())
    {
        getline(read, record);
        string name = seperateField(record, 1);
        int points = stoi(seperateField(record, 2));
        loadRecord(name, points);
    }
    read.close();
} // end of function
string seperateField(string record, int fieldNumber)
{
    int count = 1;
    string value;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            count++;
        }
        else if (count == fieldNumber)
        {
            value = value + record[i];
        }
    }
    return value;
} // end of function
void loadRecord(string name, int points)
{
    scoreboard *record = new scoreboard;
    record->name = name;
    record->points = points;
    if (head == NULL)
    {
        head = record;
    }
    else
    {
        scoreboard *temp = getLastRecord(head); // head means that it store first record
        temp->next = record;
    }
} // end of function
scoreboard *getLastRecord(scoreboard *temp) // it will give last record by checking condition if null exit or not
{
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
} // end of function
void printSingleRecord(scoreboard *one)
{
    cout << one->name << "\t\t" << one->points << endl;
} // end of function
void displayAllRecords()
{
    cout << "Player\t\t Points" << endl;
    scoreboard *temp = head;
    while (temp != NULL)
    {
        printSingleRecord(temp);
        temp = temp->next;
    }
} // end of function