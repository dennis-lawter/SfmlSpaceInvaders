#ifndef SCORE_HH_
#define SCORE_HH_
#include <vector>
#include <algorithm>
#include <fstream>
#include "GameText.hpp"
#include "resources.hh"
using namespace std;

namespace score {
	extern int score;
	extern vector<int> scoreList;
	extern int currentLives;
	extern int roundNumber;
	extern double speedModifier;
	extern double roundMultiplier;
	extern int scoreBonus;
	extern int scoreBonusMultiplier;

	void loadScores();
	void saveScores();
	bool compareScores(int first, int second);
	void addScore();
	int matchScore();

	string getScoreTextString(bool currentScoreVisible = true);
	GameText getScoreTextBlock(bool currentScoreVisible = true);
}

#endif
