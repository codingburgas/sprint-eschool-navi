#include "../src/EnglishG.h"
#include "../src/charecter.h"

EnglishGame::EnglishGame()
{
    questions = {
    { "What is the plural of 'child'?", "Childs", "Children", "Childes" },
    { "What is the past tense of 'go'?", "goed", "went", "goes" },
    { "How do you form a question in English?", " Add 'do' or 'does' before the subject ", "Change the word order", "Use a comma at the end" },
    { "What is a synonym for 'happy?'", "sad", "joyful", "angry" },
    { "What is an antonym for 'big'?", "small", "huge", "giant" },
    { "What are the three articles in English?", "A, an, the", "He, she, it", "In, on, at" },
    { "How do you spell the number 40 in words?", "Fourty", "Forty", "Fourthy" },
    { "What is the difference between 'there,' 'their,' and 'they're'? ", "There = place, Their = possession, They're = they are ", "They're = place, Their = they are, There = possession", "heir = place, They're = possession, There = they are" },
    { "What is the correct form: 'She go to school' or 'She goes to school'?", "She go to school", " She goes to school", "She going to school" },
    { "How do you form the negative of 'I am happy'?", " I am not happy", "I no happy", "I don't happy" },
    { "What is the past participle of 'write'?", "Wrote", "Writte", "Writing" },
    { "What is the difference between 'since' and 'for'?", "'Since' is for points in time, 'for' is for durations", "They mean the same", "'For' is for points in time, 'since' is for durations" },
    { "How do you make a sentence in the present continuous tense?", "Use 'am/is/are' + verb + -ing", "Use 'do/does' + verb", "Use 'have/has' + verb" },
    { "What is the difference between 'can' and 'could'?", " 'Can' is present, 'could' is past or polite", "'Can' is future, 'could' is past", "They mean the same" },
    { "What is an example of an irregular verb?", "Walk", "Go", "Play" },
    { "What does 'I'll' stand for?", "i will", "i would", "i was" },
    { "When do you use 'much' vs. 'many'?", "'Much' for countable nouns, 'many' for uncountable nouns", "'Much' for uncountable nouns, 'many' for countable nouns ", "They are interchangeable" },
    { "What are the comparative and superlative forms of 'good'?", "Good, more good, most good", "Good, better, best ", "Good, gooder, goodest" },
    { "What is the subject in the sentence: 'Tom plays football every Saturday'?", "Tom", "Plays", "Football" },
    { "What is the difference between 'will' and 'going to' for future tense?", "'Will' is for decisions made now, 'going to' is for planned actions ", "They mean the same", "'Will' is for the past, 'going to' is for the future" },
    { "What is an example of a conditional sentence?", "If it rains, we will stay inside.", "I like apples.", "She runs fast." },
    { "How do you change 'He said, I am tired.' into reported speech?", "He said he was tired. ", "He said I am tired.", "He said he is tired." },
    { "What is the passive voice form of 'She wrote a letter'?", " A letter is written by her.", "A letter was written by her. ", "She writes a letter." },
    { "What is an example of a modal verb?", "Can", "Walk", "Eats" },
    { "How do you use 'used to' in a sentence?", "I used to play soccer when I was younger.", "I use to play soccer now.", "I am used to play soccer." },
    { "What is the difference between 'who' and 'whom'? ", "'Who' is for subjects, 'whom' is for objects", "'Whom' is always correct", "They mean the same" },
    { "How do you form the third conditional?", "If + past perfect, would have + past participle", "If + present, will + base verb", "If + past simple, would + base verb" },        
    { "What is a relative clause?", "A clause that gives extra information about a noun", "A clause that starts with 'if'", "A clause that makes a question" },
    { "What is an example of a phrasal verb with 'take'?", "Take off", "Take tall", "Take chair" },
    { "How do you start a formal letter?", "Dear Sir/Madam", "Hey", "Yo" }, 
    { "What is the structure of a five-paragraph essay?", "Introduction, 3 body paragraphs, conclusion ", "One long paragraph", "Just bullet points" },
    { "What is an example of an idiom?", "It's raining cats and dogs.", "The sky is blue.", " I have two eyes." },
    { "How do you write a polite email?", "Use 'Dear' and 'Best regards' ",  "Use only emojis", "Use all caps" },
    { "How do you close a formal email?", "Best regards", "Bye", "Later" },
    };
    question = "Are you ready";
    choiceOne = "Yes";
    choiceThree = "No";
    srand(time(0));
    font = LoadFont("resourses/arial-unicode-ms.ttf");
    questionAnswered = 1;
    EnglishGameClose = 0;
    rightAnswer = { 2, 2, 1, 3, 1, 1,2,1,2,1,2,1,1,1,2,1,2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1};
    firstChoice = { 150, 200, 150, 50 };
    secondChoice = { 150, 300, 150, 50 };
    thirdChoice = { 150, 400, 150, 50 };
    Exit = { 100, 500, 200, 100 };
    counter = -1;
    correct = 0;
    points = 0;
    target = 20;
    pass = 0;
}
void EnglishGame::Draw()
{
    ClearBackground(RAYWHITE);
    if (counter == target)
    {
        DrawText(TextFormat("Your score is : %d", points), 100, 100, 55, BLACK);
        DrawRectangleRec(Exit, RED);
        DrawText("Exit", 150, 525, 55, WHITE);
    }
    else {
        DrawRectangleRec(firstChoice, RED);
        DrawRectangleRec(secondChoice, RED);
        DrawRectangleRec(thirdChoice, RED);


        DrawText(question.c_str(), 50, 50, 30, BLACK);
        DrawText(choiceOne.c_str(), 350, 210, 20, RED);
        DrawText(choiceTwo.c_str(), 350, 310, 20, RED);
        DrawText(choiceThree.c_str(), 350, 410, 20, RED);

        DrawText(TextFormat("Time ramaining %d", timeholder - targetTime), 50, 100, 30, RED);
    }


}

void EnglishGame::Update()
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
    if (CheckCollisionPointRec(GetMousePosition(), Exit))
    {
        EnglishGameClose = 1;
    }
}
void EnglishGame::MoveQuestions()
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
bool EnglishGame::CheckIfExitPressed()
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