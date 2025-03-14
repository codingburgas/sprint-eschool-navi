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
    {"Коя от думите е съществително собствено?", "дърво", "София", "вода"},
    {"Кой от глаголите е в минало свършено време?", "пея", "пях", "ще пея"},
    {"Кой от следните изрази съдържа правописна грешка?", "ходих на училище", "щте уча утре", "писах домашното"},
    {"Какво е син в изречението: Той е моят син?", "прилагателно име", "съществително нарицателно", "съществително собствено"},
    {"В кой ред всички думи са съюзи?", "и, но, защото", "с, на, в", "бързо, силно, красиво"},
    {"Как се нарича дума, която замества съществително име?", "глагол", "местоимение", "наречие"},
    {"Какво означава думата антоним?", "дума с противоположно значение", "дума със същото значение", "дума, която назовава предмет"},
    {"Коя е вярната форма?", "по-хубав", "най-хубаф", "най-хубав"},
    {"Какъв вид изречение е: Колко е красиво небето!?", "въпросително", "възклицателно", "съобщително"},
    {"Кое от изброените е сложно съставно изречение?", "Аз пея и танцувам.", "Когато завали, ще останем вкъщи.", "Играя футбол."},
    {"Какъв вид дума е бързо в изречението: Той бяга бързо?", "наречие", "прилагателно", "съществително"},
    {"Кое от изреченията е отрицателно?", "Той е умен.", "Аз не съм гладен.", "Навън е слънчево."},
    {"Коя дума има значение, противоположно на щастлив?", "радостен", "весел", "тъжен"},
    {"Каква е формата на говорим в изречението: Ние говорим български?", "1 л., мн. ч., сегашно време", "3 л., ед. ч., минало време", "2 л., мн. ч., бъдеще време"},
    {"Коя дума е съставна?", "самотен", "светло-зелен", "дърво"},
    {"Кой е авторът на Под игото?", "Иван Вазов", "Елин Пелин", "Христо Ботев"},
    {"Кой е основният герой в Бай Ганьо?", "Гочоолу", "Бай Ганьо", "Дочоолу"},
    {"Какъв жанр е Немили-недраги на Иван Вазов?", "роман", "повест", "разказ"},
    {"Коя творба е написана от Елин Пелин?", "Гераците", "Ветрената мелница", "Дядо Йоцо гледа"},
    {"Кой герой в Опълченците на Шипка говори за орловия балкан?", "Левски", "Вазов", "Лирическият говорител"},
    {"Коя е основната тема в Дядо Йоцо гледа?", "патриотизъм и надежда", "любов и раздяла", "приятелство"},
    {"Коя е основната тема на Бай Ганьо?", "националната идентичност", "революционните борби", "любовта"},
    {"Кой от изброените автори е представител на символизма?", "Пейо Яворов", "Иван Вазов", "Елин Пелин"},
    {"Какво означава думата епопея в Епопея на забравените?", "историческа песен", "цикъл от стихотворения", "драма"},
    {"Кой герой е свързан с думите Ако спечеля, печеля за цял народ?", "Левски", "Ботев", "Бенковски"},
    {"Кой е авторът на стихотворението Обесването на Васил Левски?", "Христо Ботев", "Иван Вазов", "Елин Пелин"},
    {"Кой е авторът на разказа По жицата?", "Йордан Йовков", "Иван Вазов", "Димитър Димов"},
    {"Кой е главният герой в Железният светилник?", "Лазар Глаушев", "Иван Селямсъзът", "Иво Андреев"},
    {"Какъв жанр е Тютюн на Димитър Димов?", "роман", "новела", "разказ"},
    {"Какъв тип разказвачески стил използва Йордан Йовков?", "лиричен реализъм", "символизъм", "експресионизъм"},
    {"Какво означава думата метафора?", "пряко сравнение", "образно сравнение", "повторение"},
    {"Какво е ода?", "стихотворение в прослава", "тъжно стихотворение", "кратък разказ"},
    {"Какво е епитет?", "сравнение", "художествено определение", "глагол"},
    {"Кой от следните автори е творил през Възраждането?", "Христо Ботев", "Гео Милев", "Елин Пелин"},
    {"Каква е темата на стихотворението Майце си от Ботев?", "майчината обич", "самотата и разочарованието", "войната"},
    {"Какъв е литературният род на Опълченците на Шипка?", "лирика", "епос", "драма"},
    {"Какво е градация в литературата?", "засилване на емоцията", "повторение на думи", "антитеза"},
    {"Какъв е жанрът на Балкански синдром от Станислав Стратиев?", "роман", "драма", "новела"},
    {"Какво е хипербола?", "преувеличение", "омаловажаване", "сравнение"},
    {"Какво е алитерация?", "повторение на една и съща съгласна в няколко думи", "сравнение между два предмета", "противопоставяне на думи"},
    {"Кой е основният конфликт в Тютюн на Димитър Димов?", "любов и омраза", "капитализъм и човешки съдби", "приятелство и предателство"},
    {"Коя е основната тема в творчеството на Димчо Дебелянов?", "героизъм и слава", "носталгия и тъга", "социална несправедливост"},
    {"Какъв вид рима е гора - зора?", "кръстосана", "обхваната", "пълна"},
    {"Кой герой от Железният светилник се бори за просвета?", "Лазар Глаушев", "Стоян Глаушев", "Кандов"}
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