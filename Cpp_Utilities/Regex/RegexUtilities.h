#ifndef REGEX_UTILITIES_H
#define REGEX_UTILITIES_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>
#include <regex>
#include <vector>

namespace Regex
{
	struct MatchSegments
	{
		std::string before;
		std::string after;
		std::string match;
	};

	std::vector<std::pair<std::string, uint32_t>> PrintAllMatches(std::string text, const std::string & pattern);
	std::string GetEverythingBeforeMatch(std::string & text, const std::string & pattern);
	std::string GetEverythingAfterMatch(std::string & text, const std::string & pattern);
	MatchSegments GetBeforeAfterAndMatch(std::string & text, const std::string & pattern);
}

#endif