#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <regex>

using namespace std;

typedef struct
{
    unsigned int A : 16;
    unsigned int B : 4;
    unsigned int C : 4;
    unsigned int D : 8;

    unsigned int E : 16;
    unsigned int F : 4;
    unsigned int G : 4;
    unsigned int H : 8;

} bitPacking;

union convertFloatAndInt
{
    double numberDouble;
    uint64_t number_uint64;
};

int StringToInt(char* str);
uint8_t ReverseBits(uint8_t num);
void practiceSwitchCase(int num);
void swapChars(char* a, char* b);
void printNumberOfOnesInNumber();
void printNumberInBinary(size_t const size, const void* ptr);
void printFactorial();
unsigned int calculateFactorial(unsigned int number);
unsigned long long calculateFibonacciNumber(unsigned int number);
void reverseString(char* str);
void printIsPrime(unsigned int number);
void swapInt(int* a, int* b);
void pattern_search_stream(uint8_t* bytes, uint32_t pattern);
void pattern_search(string str, string pattern);
void pattern_search_regx(string str, string pattern);
uint32_t rotateWord(const uint32_t & word);

#endif