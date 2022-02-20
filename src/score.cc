#include "score.hh"

namespace score {
	int score = 0;
	vector<int> scoreList = { 0,0,0,0,0,0,0,0,0,0 };
	bool compareScores(int first, int second) {
		return first > second;
	}
	void addScore() {
		score::scoreList.push_back(score::score);
		sort(score::scoreList.begin(), score::scoreList.end(), score::compareScores);
		score::scoreList.pop_back();
	}
}