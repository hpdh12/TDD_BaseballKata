#include <string>
#include <stdexcept>

using namespace std;

class Baseball
{
public:
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

	void guess(const std::string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
	}
};
