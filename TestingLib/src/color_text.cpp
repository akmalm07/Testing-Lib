
#include "include/color_text.h"


namespace tester
{
	std::string yellow_text(std::string_view text)
	{
		return "\033[33m" + std::string(text) + "\033[0m";
	}

	std::string red_text(std::string_view text)
	{
		return "\033[31m" + std::string(text) + "\033[0m";
	}

	std::string green_text(std::string_view text)
	{
		return "\033[32m" + std::string(text) + "\033[0m";
	}

}