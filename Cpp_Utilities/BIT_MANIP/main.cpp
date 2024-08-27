// StudingInterviews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BitMainIp.h"

int main()
{
    printf("<><><><><> Print Binary Number 0x77 <><><><><>\n");
    uint32_t number = 0x77;
    Man_IP::PrintBinary(number);
    printf("<><><><><> SET  BIT 3 <><><><><>\n");
    Man_IP::SetBit(number, 3);
    Man_IP::PrintBinary(number);

    printf("<><><><><> UNSET  BIT 3 <><><><><>\n");
    Man_IP::UnSetBit(number, 3);
    Man_IP::PrintBinary(number);

    printf("<><><><><> TOGGLE  BIT 1 <><><><><>\n");
    Man_IP::ToggleBit(number, 1);
    Man_IP::PrintBinary(number);

    printf("<><><><><> Get Data Mask 0x777, start pos: 0, end pos: 4 <><><><><>\n");
    uint32_t data = Man_IP::GetMaskedData(0x777, 0, 4);
    Man_IP::PrintBinary(data);

    printf("<><><><><> END <><><><><>\n");
    
    return 0;
}
