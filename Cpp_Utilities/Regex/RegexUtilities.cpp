#include "RegexUtilities.h"

std::vector<std::pair<std::string, uint32_t>> Regex::PrintAllMatches(std::string text, const std::string & pattern)
{
	std::vector<std::pair<std::string, uint32_t>> ret;
	std::smatch match;
	std::regex r(pattern);
	uint32_t currentLocation = 0;
	while (std::regex_search(text, match, r))
	{
		std::string strMatch(match.str(0));
		currentLocation += match.position(0);
		ret.emplace_back(std::make_pair(strMatch, currentLocation));

		// Keep track of the current location since we will be chopping off the string every iteration
		currentLocation += strMatch.size();

		// suffix to find the rest of the string.
		text = match.suffix().str();
	}

	return ret;
}

std::string Regex::GetEverythingBeforeMatch(std::string & text, const std::string & pattern)
{
	std::string ret = "";
	std::smatch match;
	std::string regexCompletePattern = "(.*?)(?=" + pattern + ")";
	std::regex r(regexCompletePattern);
	if (std::regex_search(text, match, r))
	{
		ret = std::string(match.str(0));
	}

	return ret;
}

std::string Regex::GetEverythingAfterMatch(std::string & text, const std::string & pattern)
{
	std::string ret = "";
	std::smatch match;
	std::string regexCompletePattern = pattern + "(.*)";
	std::regex r(regexCompletePattern);
	if (std::regex_search(text, match, r))
	{
		ret = std::string(match[1]);
	}

	return ret;
}

Regex::MatchSegments Regex::GetBeforeAfterAndMatch(std::string & text, const std::string & pattern)
{
	Regex::MatchSegments ret = {"", "", ""};
	std::smatch match;
	std::string regexBeforeMatch = "(.*?)(?=" + pattern + ")";
	std::string regexAfterMatch = pattern + "(.*)";
	
	// Get Match Pattern
	std::regex r(pattern);
	if (std::regex_search(text, match, r))
	{
		ret.match = std::string(match.str(0));
	}
	else
	{
		// Match wasn't found exit
		return ret;
	}

	// Get everything Before Match Pattern
	r = regexBeforeMatch;
	if (std::regex_search(text, match, r))
	{
		ret.before = std::string(match.str(0));
	}

	// Get everything After Match Pattern
	r = regexAfterMatch;
	if (std::regex_search(text, match, r))
	{
		ret.after = std::string(match[1]);
	}

	return ret;
}