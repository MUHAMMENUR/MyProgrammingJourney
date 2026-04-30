#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stReadInfo {
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResult {
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWinTheRound(stReadInfo RoundInfo) {
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) return enWinner::Draw;
    switch (RoundInfo.PlayerChoice) {
        case enGameChoice::Stone:
            return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player;
        case enGameChoice::Paper:
            return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player;
        case enGameChoice::Scissors:
            return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player;
    }
    return enWinner::Player;
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes) {
    if (PlayerWinTimes > ComputerWinTimes) return enWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes) return enWinner::Computer;
    else return enWinner::Draw;
}

string ChoiceName(enGameChoice Choice) {
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player", "Computer", "No Winner (Draw)" };
    return arrWinnerName[Winner - 1];
}

enGameChoice ReadPlayer1Choice() {
    short Choice;
    do {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

void PrintRoundResults(stReadInfo RoundInfo) {
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}

stGameResult PlayGame(short HowManyRounds) {
    stReadInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWinTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player) {
            system("color 2F"); // أخضر للفوز
            Player1WinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer) {
            system("color 4F"); // أحمر للخسارة
            ComputerWinTimes++;
            cout << "\a"; // صوت تنبيه عند الخسارة
        }
        else {
            system("color 6F"); // أصفر للتعادل
            DrawTimes++;
        }

        PrintRoundResults(RoundInfo);
    }

    stGameResult FinalResults;
    FinalResults.GameRounds = HowManyRounds;
    FinalResults.PlayerWinTimes = Player1WinTimes;
    FinalResults.ComputerWinTimes = ComputerWinTimes;
    FinalResults.DrawTimes = DrawTimes;
    FinalResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    FinalResults.WinnerName = WinnerName(FinalResults.GameWinner);

    return FinalResults;
}

void StartGame() {
    char PlayAgain = 'Y';
    do {
        system("cls");
        system("color 0F");
        short RoundsCount;
        cout << "How many rounds 1 to 10? ";
        cin >> RoundsCount;

        stGameResult GameResults = PlayGame(RoundsCount); 
        
        cout << "\n-------------------------------------------------\n";
        cout << "                  GAME OVER                      \n";
        cout << "-------------------------------------------------\n";
        cout << "Game Rounds        : " << GameResults.GameRounds << endl;
        cout << "Player Win Times   : " << GameResults.PlayerWinTimes << endl;
        cout << "Computer Win Times : " << GameResults.ComputerWinTimes << endl;
        cout << "Draw Times         : " << GameResults.DrawTimes << endl;
        cout << "Final Winner       : " << GameResults.WinnerName << endl;
        cout << "-------------------------------------------------\n";

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}