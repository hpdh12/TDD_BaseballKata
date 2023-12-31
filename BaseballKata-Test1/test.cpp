#include "pch.h"
#include "../BaseballKata/baseball.cpp"

#include <string>
using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string  guessNumber)
	{
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Return2strikes)
{
	vector<string> questions = { "124", "143", "423" };

	for (auto question : questions) {
		GuessResult result = game.guess(question);

		EXPECT_FALSE(result.solved);
		EXPECT_EQ(2, result.strikes);
		EXPECT_EQ(0, result.balls);
	}
}

TEST_F(BaseballFixture, Return1strikesAnd2Balls)
{
	vector<string> questions = { "213", "132", "321" };

	for (auto question : questions) {
		GuessResult result = game.guess(question);

		EXPECT_FALSE(result.solved);
		EXPECT_EQ(1, result.strikes);
		EXPECT_EQ(2, result.balls);
	}
}