#ifndef SCORE_HH_
#define SCORE_HH_
#include <vector>
#include <algorithm>
using namespace std;

namespace score {
	extern int score;
	extern vector<int> scoreList;
	bool compareScores(int first,int second);
	void addScore();
	int matchScore();
}

#endif