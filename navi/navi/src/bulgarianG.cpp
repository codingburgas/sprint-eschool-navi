#include "bulgarianG.h"
BulgarianGame::BulgarianGame()
{
    questions = {
    { "Which of the words is a proper noun?", "tree", "Sofia", "water" },
    { "Which of the verbs is in past perfect tense?", "sing", "sang", "will sing" },
    { "Which of the following expressions contains a spelling mistake?", "I went to school", "I will study tomorrow", "I did my homework" },
    { "What is 'son' in the sentence: 'He is my son'?", "adjective", "common noun", "proper noun" },
    { "In which row are all the words conjunctions?", "and, but, because", "with, on, in", "fast, strong, beautiful" }
    };        /*{
    {"��� �� ������ � ������������� ���������?", "�����", "�����", "����"},
    {"��� �� ��������� � � ������ �������� �����?", "���", "���", "�� ���"},
    {"��� �� �������� ������ ������� ���������� ������?", "����� �� �������", "��� ��� ����", "����� ���������"},
    {"����� � ��� � �����������: ��� � ���� ���?", "������������ ���", "������������� �����������", "������������� ���������"},
    {"� ��� ��� ������ ���� �� �����?", "�, ��, ������", "�, ��, �", "�����, �����, �������"},
    {"��� �� ������ ����, ����� �������� ������������� ���?", "������", "�����������", "�������"},
    {"����� �������� ������ �������?", "���� � �������������� ��������", "���� ��� ������ ��������", "����, ����� �������� �������"},
    {"��� � ������� �����?", "��-�����", "���-�����", "���-�����"},
    {"����� ��� ��������� �: ����� � ������� ������!?", "������������", "�������������", "�����������"},
    {"��� �� ���������� � ������ �������� ���������?", "�� ��� � ��������.", "������ ������, �� ������� �����.", "����� ������."},
    {"����� ��� ���� � ����� � �����������: ��� ���� �����?", "�������", "������������", "�������������"},
    {"��� �� ����������� � �����������?", "��� � ����.", "�� �� ��� ������.", "����� � ��������."},
    {"��� ���� ��� ��������, �������������� �� �������?", "��������", "�����", "�����"},
    {"����� � ������� �� ������� � �����������: ��� ������� ���������?", "1 �., ��. �., ������� �����", "3 �., ��. �., ������ �����", "2 �., ��. �., ������ �����"},
    {"��� ���� � ��������?", "�������", "������-�����", "�����"},
    {"��� � ������� �� ��� �����?", "���� �����", "���� �����", "������ �����"},
    {"��� � ��������� ����� � ��� �����?", "�������", "��� �����", "�������"},
    {"����� ���� � ������-������� �� ���� �����?", "�����", "������", "������"},
    {"��� ������ � �������� �� ���� �����?", "��������", "��������� �������", "���� ���� �����"},
    {"��� ����� � ����������� �� ����� ������ �� ������� ������?", "������", "�����", "����������� ���������"},
    {"��� � ��������� ���� � ���� ���� �����?", "����������� � �������", "����� � �������", "�����������"},
    {"��� � ��������� ���� �� ��� �����?", "������������ �����������", "�������������� �����", "�������"},
    {"��� �� ���������� ������ � ������������ �� ����������?", "���� ������", "���� �����", "���� �����"},
    {"����� �������� ������ ������ � ������ �� �����������?", "����������� �����", "����� �� �������������", "�����"},
    {"��� ����� � ������� � ������ ��� �������, ������ �� ��� �����?", "������", "�����", "���������"},
    {"��� � ������� �� ��������������� ���������� �� ����� ������?", "������ �����", "���� �����", "���� �����"},
    {"��� � ������� �� ������� �� ������?", "������ ������", "���� �����", "������� �����"},
    {"��� � �������� ����� � ��������� ���������?", "����� �������", "���� ����������", "��� �������"},
    {"����� ���� � ����� �� ������� �����?", "�����", "������", "������"},
    {"����� ��� ������������� ���� �������� ������ ������?", "������� ��������", "����������", "��������������"},
    {"����� �������� ������ ��������?", "����� ���������", "������� ���������", "����������"},
    {"����� � ���?", "������������� � ��������", "����� �������������", "������ ������"},
    {"����� � ������?", "���������", "������������ �����������", "������"},
    {"��� �� �������� ������ � ������ ���� ������������?", "������ �����", "��� �����", "���� �����"},
    {"����� � ������ �� ��������������� ����� �� �� �����?", "��������� ����", "�������� � ���������������", "�������"},
    {"����� � ������������� ��� �� ����������� �� �����?", "������", "����", "�����"},
    {"����� � �������� � ������������?", "��������� �� ��������", "���������� �� ����", "��������"},
    {"����� � ������ �� ��������� ������� �� ��������� ��������?", "�����", "�����", "������"},
    {"����� � ���������?", "�������������", "�������������", "���������"},
    {"����� � ����������?", "���������� �� ���� � ���� �������� � ������� ����", "��������� ����� ��� ��������", "���������������� �� ����"},
    {"��� � ��������� �������� � ����� �� ������� �����?", "����� � ������", "����������� � ������� �����", "����������� � ������������"},
    {"��� � ��������� ���� � ������������ �� ����� ���������?", "�������� � �����", "��������� � ����", "�������� ���������������"},
    {"����� ��� ���� � ���� - ����?", "����������", "���������", "�����"},
    {"��� ����� �� ��������� ��������� �� ���� �� ��������?", "����� �������", "����� �������", "������"}
    };*/
    question = "Are you ready";
    choiceOne = "Yes";
    choiceThree = "No";
    srand(time(0));
    font = LoadFont("resourses\arial-unicode-ms.ttf");
    questionAnswered = 1;
    BulgarianGameClose = 0;
    rightAnswer = { 1, 3, 2, 1, 2, 2 };
    firstChoice = { 500, 200, 150, 50 };
    secondChoice = { 500, 300, 150, 50 };
    thirdChoice = { 500, 400, 150, 50 };
    Exit = { 500, 500, 150, 50 };
    counter = 0;
    correct = 0;
    points = 0;
    target = questions.size();
}
void BulgarianGame::Draw()
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

void BulgarianGame::Update()
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
    else if ((timeholder - targetTime)>=0) {
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
void BulgarianGame::MoveQuestions()
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
bool BulgarianGame::CheckIfExitPressed()
{
    if (CheckCollisionPointRec(GetMousePosition(), Exit) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))return 0;
    else return 1;
}