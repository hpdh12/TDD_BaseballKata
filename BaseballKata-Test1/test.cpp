#include "pch.h"
#include "../BaseballKata/baseball.cpp"

#include <string>
using namespace std;

TEST(BaseballGame, TryGameTest) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}