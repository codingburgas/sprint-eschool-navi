#include "../src/MathG.h"

MathGame::MathGame()
{
    questions = {
        { "What is 12 + 7?", "18", "19", "20" },
        { "What is 25 + 14?", "38", "39", "40" },
        { "What is 42 + 36?", "78", "76", "79" },
        { "What is 57 + 24?", "81", "80", "82" },
        { "What is 63 + 29?", "91", "92", "93" },
        { "What is 50 - 23?", "27", "26", "28" },
        { "What is 91 - 36?", "55", "56", "57" },
        { "What is 73 - 28?", "45", "44", "46" },
        { "What is 60 - 19?", "41", "42", "43" },
        { "What is 88 - 52?", "36", "37", "35" },
        { "What is 8 × 7?", "56", "54", "58" },
        { "What is 6 × 9?", "54", "52", "56" },
        { "What is 12 × 5?", "60", "55", "65" },
        { "What is 9 × 4?", "36", "34", "38" },
        { "What is 7 × 11?", "77", "79", "75" },
        { "What is 56 ÷ 8?", "7", "6", "8" },
        { "What is 72 ÷ 9?", "7", "8", "9" },
        { "What is 81 ÷ 9?", "8", "9", "10" },
        { "What is 48 ÷ 6?", "7", "8", "9" },
        { "What is 100 ÷ 5?", "20", "18", "22" },
        { "What is 1/2 of 50?", "24", "25", "26" },
        { "What is 3/4 of 40?", "28", "30", "32" },
        { "What is 0.5 × 60?", "28", "30", "32" },
        { "What is 25% of 80?", "18", "20", "22" },
        { "What is 1/3 of 90?", "30", "28", "32" },
        { "A shop sells 4 pencils for $2 each. How much do 4 pencils cost?", "$6", "$8", "$10" },
        { "Lily had 20 apples and gave 8 away. How many does she have now?", "10", "12", "14" },
        { "A train travels at 60 km/h. How far does it go in 3 hours?", "160 km", "170 km", "180 km" },
        { "A triangle has angles 30° and 60°. What is the third angle?", "80°", "90°", "100°" },
        { "A rope is 45 meters long and is cut into 3 equal pieces. How long is each piece?", "10 m", "15 m", "20 m" },
        { "If 3x = 12, what is x?", "2", "3", "4" },
        { "If x + 5 = 15, what is x?", "8", "10", "12" },
        { "If 2x + 3 = 9, what is x?", "2", "3", "4" },
        { "If y = 4, what is 2y + 6?", "12", "14", "16" },
        { "If x = 5, what is x² + 3?", "23", "28", "30" },
        { "What is the perimeter of a square with sides of 6 cm?", "20 cm", "24 cm", "30 cm" },
        { "What is the area of a rectangle with length 8 cm and width 5 cm?", "30 cm²", "40 cm²", "50 cm²" },
        { "A circle has a radius of 7 cm. What is its diameter?", "12 cm", "14 cm", "16 cm" },
        { "A cube has a side length of 4 cm. What is its volume?", "64 cm³", "60 cm³", "72 cm³" },
        { "A triangle has a base of 10 cm and height of 5 cm. What is its area?", "20 cm²", "25 cm²", "30 cm²" }
    };
    question = "Are you ready";
    choiceOne = "Yes";
    choiceThree = "No";
    srand(time(0));
    font = LoadFont("resourses/arial-unicode-ms.ttf");
    questionAnswered = 1;
    MathGameClose = 0;
    rightAnswer = { 2,2,2,1,2,1,3,1,2,1,1,1,1,1,1,1,2,2,2,1,2,3,3,2,1,2,2,3,2,2,3,2,2,3,1,2,2,2,1,2 };
    firstChoice = { 500, 200, 150, 50 };
    secondChoice = { 500, 300, 150, 50 };
    thirdChoice = { 500, 400, 150, 50 };
    Exit = { 500, 500, 150, 50 };
    counter = -1;
    correct = 0;
    points = 0;
    target = 5;


}
void MathGame::Draw()
{
    ClearBackground(RAYWHITE);
    if (counter == target)
    {
        DrawText(TextFormat("Your score is : %d", points), 500, 325, 50, BLACK);
        DrawRectangleRec(Exit, RED);
    }
    else {
        DrawRectangleRec(firstChoice, RED);
        DrawRectangleRec(secondChoice, RED);
        DrawRectangleRec(thirdChoice, RED);


        DrawText(question.c_str(), 100, 100, 20, BLACK);
        DrawText(choiceOne.c_str(), 320, 410, 20, RED);
        DrawText(choiceTwo.c_str(), 320, 510, 20, RED);
        DrawText(choiceThree.c_str(), 320, 610, 20, RED);

        DrawText(TextFormat("Time ramaining %d", timeholder - targetTime), 500, 100, 30, RED);
    }


}

void MathGame::Update()
{
    timer = GetTime();
    targetTime = GetTime() - 21;
    if (questionAnswered)
    {
        if (!questions.empty())
        {
            randomNum = rand() % questions.size();
            questionAnswered = 0;
            timeholder = timer;
            if (correct) {
                points++;
                correct = 0;
            }
        }
    }
    else if ((timeholder - targetTime) >= 0) {
        if (CheckCollisionPointRec(GetMousePosition(), firstChoice) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { questionAnswered = 1; if (rightAnswer[randomNum] == 1) correct = 1; }
        else if (CheckCollisionPointRec(GetMousePosition(), secondChoice) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { questionAnswered = 1; if (rightAnswer[randomNum] == 2) correct = 1; }
        else if (CheckCollisionPointRec(GetMousePosition(), thirdChoice) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { questionAnswered = 1; if (rightAnswer[randomNum] == 3) correct = 1; }
        MoveQuestions();
    }
    else
    {
        questionAnswered = 1;
        correct = 0;
        MoveQuestions();
    }

}
void MathGame::MoveQuestions()
{
    vector<vector<string>>::iterator it = questions.begin();
    if (randomNum < questions.size())
    {
        advance(it, randomNum);

    }
    else
    {
        return;
    }

    if (it != questions.end() && questionAnswered)
    {
        holder = *it;
        question = holder[0];
        choiceOne = holder[1];
        choiceTwo = holder[2];
        choiceThree = holder[3];
        questions.erase(it);
        counter++;
    }
}
bool MathGame::CheckIfExitPressed()
{
    if (CheckCollisionPointRec(GetMousePosition(), Exit) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (points < 15)
        {
            pass = 1;
        }
        return 0;
    }
    else return 1;
}