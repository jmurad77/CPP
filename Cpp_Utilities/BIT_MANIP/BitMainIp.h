#ifndef BIT_MAN_IP_H
#define BIT_MAN_IP_H

#include <stdint.h>
#include <stdio.h>
#include <map>

using namespace std;

namespace Man_IP
{
	uint32_t* GenMaskMap();
	void Delete_G_Mask();
	map<uint8_t, uint32_t> GenMaskWordMap();
	void SetBit(uint32_t& number, uint8_t bitPos);
	void UnSetBit(uint32_t& number, uint8_t bitPos);
	void ToggleBit(uint32_t& number, uint8_t bitPos);
	uint32_t GetMaskedData(uint32_t data, uint8_t startPos, uint8_t endPos);
	void PrintBinary(uint32_t number);
}
#endif