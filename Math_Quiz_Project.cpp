#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };


string GetOpTypeSymbol(enOperationType OpType) {
    string arrOp[5] = { "+", "-", "*", "/", "Mix" };
    return arrOp[OpType - 1];
}

string GetQuestionsLevelText(enQuestionsLevel Level) {
    string arrLevel[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrLevel[Level - 1];
}


struct stQuestions {
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool IsAnswerRight = false;
};

struct stQuizz {
    stQuestions QuestionList[100];
    short NumberOfQuestions = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfCorrectAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool IsPassed = false;
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions() { 
    short NumberOfQuestions = 0;
    do {
        cout << "How Many Questions do you want to answer (1 to 10): ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
    return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel() { 
    short QuestionLevel = 0;
    do {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOpType() { 
    short OperationType = 0;
    do {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mult, [4] Div, [5] Mix ? ";
        cin >> OperationType; 
    } while (OperationType < 1 || OperationType > 5);
    return (enOperationType)OperationType;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType) {
    switch (OpType) {
    case enOperationType::Add:  return Number1 + Number2;
    case enOperationType::Sub:  return Number1 - Number2;
    case enOperationType::Mult: return Number1 * Number2;
    case enOperationType::Div:  return Number1 / Number2;
    default: return Number1 + Number2;
    }
}

stQuestions GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType) {
    stQuestions Question;
    if (QuestionLevel == enQuestionsLevel::Mix) QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
    
    if (QuestionLevel == enQuestionsLevel::Easy) {
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
    }
    else if (QuestionLevel == enQuestionsLevel::Med) {
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
    }
    else {
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
    }

    if (OpType == enOperationType::MixOp) Question.OperationType = (enOperationType)RandomNumber(1, 4);
    else Question.OperationType = OpType;

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QuestionLevel;
    return Question;
}

void AskAndCorrectQuestionList(stQuizz& Quizz) {
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {
        Quizz.QuestionList[QuestionNumber] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
        
        cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n";
        cout << Quizz.QuestionList[QuestionNumber].Number1 << " ";
        cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType) << " ";
        cout << Quizz.QuestionList[QuestionNumber].Number2 << " = ";
        
        cin >> Quizz.QuestionList[QuestionNumber].PlayerAnswer;

        if (Quizz.QuestionList[QuestionNumber].PlayerAnswer == Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
            Quizz.QuestionList[QuestionNumber].IsAnswerRight = true;
            Quizz.NumberOfCorrectAnswers++;
            cout << "Right Answer :-) \n";
            system("color 2F");
        }
        else {
            Quizz.QuestionList[QuestionNumber].IsAnswerRight = false;
            Quizz.NumberOfWrongAnswers++;
            cout << "Wrong Answer :-( \n";
            cout << "The correct answer is: " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << "\n";
            system("color 4F");
            cout << "\a";
        }
    }
    Quizz.IsPassed = (Quizz.NumberOfCorrectAnswers >= Quizz.NumberOfWrongAnswers);
}

void PrintQuizzResults(stQuizz Quizz) {
    cout << "\n--------------------------------\n";
    cout << "  Final Quiz Results: " << (Quizz.IsPassed ? "PASS :-)" : "FAIL :-(");
    cout << "\n--------------------------------\n";
    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level    : " << GetQuestionsLevelText(Quizz.QuestionsLevel) << endl;
    cout << "Operation Type     : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Correct Answers    : " << Quizz.NumberOfCorrectAnswers << endl;
    cout << "Wrong Answers      : " << Quizz.NumberOfWrongAnswers << endl;
    cout << "--------------------------------\n";
}

void PlayMathQuiz() {
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOpType();

    AskAndCorrectQuestionList(Quizz);
    PrintQuizzResults(Quizz);
}

void StartGame() {
    char PlayAgain = 'Y';
    do {
        system("cls");
        system("color 0F");
        PlayMathQuiz();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}