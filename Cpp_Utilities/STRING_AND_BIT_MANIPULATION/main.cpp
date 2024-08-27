#include <iostream>
#include <chrono>
#include "StringAndBitManip.h"

using namespace std;

int main()
{
    printf("<><><><> STARTING STRING AND BIT MANIPULATION <><><><>\n");
    string text = "Welcome to Geeks for Geeks and even more Geeks";
    string pattern = "Geek";

    auto start = chrono::high_resolution_clock::now();
    pattern_search(text, pattern);
    auto end = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    double finalTime = time_taken * 1e-9;
    printf("PATTERN SEACH USING LIST/QUEUES TIME TAKEN(s): %f\n", finalTime);

    start = chrono::high_resolution_clock::now();
    pattern_search_regx(text, pattern);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    finalTime = time_taken * 1e-9;
    printf("\nPATTERN SEARCH USING REGEX TIME TAKEN(s): %f\n\n", finalTime);

    printf("<><><><> PATTERN SEARCH DATA BYTES <><><><>\n");
    uint8_t data[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE, 0xD0, 0x0D};
    uint32_t bytePattern = 0xCAFED00D;
    pattern_search_stream(data, bytePattern);

    printf("<><><><> END <><><><>\n");

    return 0;
}
