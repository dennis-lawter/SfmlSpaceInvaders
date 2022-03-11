#include "score.hh"

namespace score {
	int currentLives = 2;
	int score = 0;
	int roundNumber = 1;
	double speedModifier = 0;
	double roundMultiplier = 0.005;
	int scoreBonus = 10; // 8 is minimum
	int scoreBonusMultiplier = 10;

	vector<int> scoreList = { 0,0,0,0,0,0,0,0,0,0 };


	bool compareScores(int first, int second) {
		return first > second;
	}

	void loadScores() {
		ifstream loadScore;
		loadScore.open(resources::highScoresFileName);
		if (!loadScore.fail()) {
			scoreList = {};
			int scorePlace;
			while (!loadScore.eof()) {
				loadScore >> scorePlace;
				scoreList.push_back(scorePlace);
			}
		}
		loadScore.close();
		while (scoreList.size() > 10) {
			scoreList.pop_back();
		}
		while (scoreList.size() < 10) {
			scoreList.push_back(0);
		}
		sort(scoreList.begin(), scoreList.end(), compareScores);
	}

	void saveScores() {
		ofstream saveScore;
		saveScore.open(resources::highScoresFileName, ofstream::trunc);
		if (!saveScore.fail()) {
			for (int x : scoreList) {
				saveScore << x << endl;
			}
		}
		saveScore.close();
	}

	void addScore() {
		scoreList.push_back(score);
		sort(scoreList.begin(), scoreList.end(), compareScores);
		while (scoreList.size() > 10) {
			scoreList.pop_back();
		}
		saveScores();
	}

	int matchScore() {
		if (score == 0) {
			return -1;
		}
		for (int i = scoreList.size() - 1; i >= 0; i--) {
			if (score == scoreList[i]) {
				return i;
			}
		}
		return -1;
	}
}
