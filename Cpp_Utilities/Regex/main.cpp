#include <iostream>
#include <chrono>
#include "RegexUtilities.h"

using namespace std;

int main()
{
    std::string testText = "-1/2+10/5-7/8";
    printf("Original String: %s\n", testText.c_str());

    std::string mathPatern = "[0-9]{1,2}/[0-9]{1,2}";
    auto matches = Regex::PrintAllMatches(testText, mathPatern);

    for (auto it = matches.begin(); it != matches.end(); it++)
    {
        printf("Found Str: %s, at location: %u\n", it->first.c_str(), it->second);
    }

    auto beforeMatch = Regex::GetEverythingBeforeMatch(testText, mathPatern);
    //printf("Found Before Match: %s\n", beforeMatch.c_str());

    auto afterMatch = Regex::GetEverythingAfterMatch(testText, mathPatern);
    //printf("Found After Match: %s\n", afterMatch.c_str());

    auto matchSegs = Regex::GetBeforeAfterAndMatch(testText, mathPatern);
    printf("Match: %s, Before Match: %s, After Match: %s\n", matchSegs.match.c_str(), matchSegs.before.c_str(), matchSegs.after.c_str());

    return 0;
}
