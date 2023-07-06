#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const char* question) : question(question)
	{
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be tree letters");

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

	int getNumStrike(const std::string& guessNumber)
	{
		int numStrike = 0;

		for (int i = 0; i < guessNumber.size(); i++)
		{
			if (guessNumber[i] == question[i])
			{
				numStrike++;
			}
		}
		return numStrike;
	}

	int getNumBall(const std::string& guessNumber)
	{
		int numBall = 0;

		for (int i = 0; i < guessNumber.size(); i++)
		{
			for (int j = 0; j < question.size(); j++)
			{
				if (i == j)
					continue;

				if (guessNumber[i] == question[j])
				{
					numBall++;
					break;
				}
			}
		}
		return numBall;
	}

	GuessResult guess(const std::string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		return { false, (getNumStrike(guessNumber)), (getNumBall(guessNumber)) };
	}
private:
	string question;
};
