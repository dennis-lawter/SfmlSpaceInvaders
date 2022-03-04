#include "score.hh"

namespace score {
	int currentLives = 2;
	int score = 0;		
	int roundNumber = 1;
	double speedModifier = 0;
	double roundMultiplier = .005;

	vector<int> scoreList = { 0,0,0,0,0,0,0,0,0,0 };

	bool compareScores(int first, int second) {
		return first > second;
	}

	void addScore() {
		scoreList.push_back(score);
		sort(scoreList.begin(), scoreList.end(), compareScores);
		scoreList.pop_back();
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