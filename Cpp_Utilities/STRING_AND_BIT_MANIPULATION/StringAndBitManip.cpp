#include "StringAndBitManip.h"

int StringToInt(char* str)
{
    int ret = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            ret *= 10;
            ret += str[i] - '0';
        }
        else
        {
            break;
        }
    }

    return ret;
}

uint8_t ReverseBits(uint8_t num)
{
    uint8_t ret = 0;
    int bitPos = 0;
    for (int i = 7; i >= 0; i--)
    {
        if ((num >> i) & 1)
        {
            ret |= (1 << bitPos);
        }
        bitPos++;
    }

    return ret;
}

void printNumberOfOnesInNumber()
{
    unsigned int intSize = sizeof(int) * 8;
    std::cout << "size of(int) * 8: " << intSize << std::endl;

    int num, count = 0;

    std::cout << "Enter any number: ";

    std::cin >> num;
    printf("value of num: %d, 0x%X, ", num, num);
    printNumberInBinary(sizeof(num), &num);
    std::cout << std::endl;

    for (int i = 0; i < intSize; i++)
    {
        if (num & 1)
        {
            count++;
        }

        num >>= 1;
    }

    std::cout << "Total number of 1's is: " << count << std::endl;
}

void printNumberInBinary(size_t const size, const void* ptr)
{
    unsigned char* b = (unsigned char*)ptr;
    unsigned char byte;

    std::cout << "0b";
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
}

void printFactorial()
{
    unsigned int num = 0;

    std::cout << "Enter any number: ";
    std::cin >> num;

    unsigned int factorial = calculateFactorial(num);
    std::cout << "Calcualted Factorial of: " << num << " is " << factorial << std::endl;
}

unsigned int calculateFactorial(unsigned int number)
{
    if (number <= 1)
    {
        return 1;
    }
    else
    {
        return calculateFactorial(number - 1) * number;
    }
}

unsigned long long calculateFibonacciNumber(unsigned int number)
{
    if (number == 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else
    {
        return calculateFibonacciNumber(number - 1) + calculateFibonacciNumber(number - 2);
    }
}

void reverseString(char* str)
{
    if (str == NULL)
    {
        return;
    }

    int beginIndex = 0;
    int endIndex = strlen(str) - 1;
    std::cout << "Original String: " << str << ", String Length: " << endIndex + 1 << std::endl;

    while (beginIndex <= endIndex)
    {
        swapChars(&str[beginIndex], &str[endIndex]);

        beginIndex++;
        endIndex--;
    }

    std::cout << "Reversed String: " << str << std::endl;
}

void swapChars(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void practiceSwitchCase(int num)
{
    switch (num)
    {
    case 0:
        std::cout << "Number 0 selected" << std::endl;
        break;
    case 1:
        std::cout << "Number 1 selected" << std::endl;
        break;
    case 2:
        std::cout << "Number 2 selected" << std::endl;
        break;
    default:
        std::cout << "Doesn't Exist" << std::endl;
        break;
    }
}

void printIsPrime(unsigned int number)
{
    if ((number == 1) || (number == 0))
    {
        printf("NUMBER: %u, IS NOT PRIME\n", number);
        return;
    }

    for (unsigned int i = 2; i <= number / 2; i++)
    {
        if ((number % i) == 0)
        {
            printf("NUMBER: %u, IS NOT PRIME\n", number);
            return;
        }
    }
    printf("NUMBER: %u, IS PRIME\n", number);
}

void pattern_search_stream(uint8_t* bytes, uint32_t pattern)
{
    if (bytes == NULL)
    {
        return;
    }
    pattern = rotateWord(pattern);
    uint8_t* patternBytes = reinterpret_cast<uint8_t*>(&pattern);
    printf("Pattern: 0x%X\n", pattern);
    unordered_set<int> structured_byte[256];
    uint32_t byteStreamSize = sizeof(bytes) / sizeof(bytes[0]);

    for (int i = 0; i < byteStreamSize; i++)
    {
        structured_byte[bytes[i]].insert(i);
    }

    queue<int> q_indices;
    for (int ind : structured_byte[patternBytes[0]])
    {
        q_indices.push(ind);
    }

    const int pat_len = 4;
    for (int i = 1; i < pat_len; i++)
    {
        uint8_t byte = patternBytes[i];
        int q_size = q_indices.size();

        // If all the elements in the q run empty there is no pattern to check anymore
        if (q_size == 0)
        {
            break;
        }

        while (q_size--)
        {
            int ind = q_indices.front();
            q_indices.pop();

            if (structured_byte[byte].find(ind + 1) != structured_byte[byte].end())
            {
                q_indices.push(ind + 1);
            }
        }
    }

    while (!q_indices.empty())
    {
        int last_ind = q_indices.front();
        q_indices.pop();
        cout << last_ind - (pat_len - 1) << " ";
    }
    cout << endl;

    return;
}

void pattern_search(string str, string pattern)
{
    unordered_set<int> structured_text[256];

    for (int i = 0; i < str.length(); i++)
    {
        structured_text[str[i]].insert(i);
    }

    queue<int> q_indices;
    for (int ind : structured_text[pattern[0]])
    {
        q_indices.push(ind);
    }

    int pat_len = pattern.length();
    for (int i = 1; i < pat_len; i++)
    {
        char ch = pattern[i];
        int q_size = q_indices.size();

        // If all the elements in the q run empty there is no pattern to check anymore
        if (q_size == 0)
        {
            break;
        }

        while (q_size--)
        {
            int ind = q_indices.front();
            q_indices.pop();

            if (structured_text[ch].find(ind + 1) != structured_text[ch].end())
            {
                q_indices.push(ind + 1);
            }
        }
    }

    while (!q_indices.empty())
    {
        int last_ind = q_indices.front();
        q_indices.pop();
        cout << last_ind - (pat_len - 1) << " ";
    }
    cout << endl;

    return;
}

void pattern_search_regx(string str, string pattern)
{
    smatch match;
    regex r(pattern);

    int currentPos = 0;
    while (regex_search(str, match, r))
    {
        cout << "\nMatched string is " << match.str(0) << endl
            << "and it is found at position "
            << match.position(0) + currentPos << endl;

        currentPos += match.position(0) + pattern.size();

        // suffix to find the rest of the string.
        str = match.suffix().str();
    }

    return;
}

uint32_t rotateWord(const uint32_t & word)
{
    uint32_t ret = (word >> 24) & 0xFF;
    ret |= (word >> 8) & 0xFF00;
    ret |= (word << 8) & 0xFF0000;
    ret |= (word << 24) & 0xFF000000;

    return ret;
}