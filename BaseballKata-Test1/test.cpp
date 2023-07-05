#include "pch.h"
#include "../BaseballKata/baseball.cpp"

#include <string>
using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
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
}