#pragma once
#include "pch.h"
class BulgarianGame
{
public:
	BulgarianGame();
	void Draw();
	void Update();
	void MoveQuestions();
	bool CheckIfExitPressed();
	int target;
	vector<vector<string>> questions;
	vector<string> holder;
	vector<int> rightAnswer;
	int counter;
	int Answer;
	bool questionAnswered;
	bool BulgarianGameClose;
	string question;
	string choiceOne;
	string choiceTwo;
	string choiceThree;
	bool correct;
	int randomNum;
	int points;
	int timer;
	int targetTime;
	int timeholder;
private:
	Rectangle firstChoice;
	Rectangle secondChoice;
	Rectangle thirdChoice;
	Rectangle Exit;
	
	Font font;



};