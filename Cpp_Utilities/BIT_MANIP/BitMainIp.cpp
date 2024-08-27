#include "BitMainIp.h"

uint32_t* gMasks = Man_IP::GenMaskMap();
map<uint8_t, uint32_t> gMaskWords = Man_IP::GenMaskWordMap();

uint32_t* Man_IP::GenMaskMap()
{
	uint32_t* maskArr = new uint32_t[32];
	for (int i = 0; i < 32; i++)
	{
		uint32_t mask = uint32_t(1 << i);
		maskArr[i] = mask;
	}

	return maskArr;
}

void Man_IP::Delete_G_Mask()
{
	delete[] gMasks;
}

map<uint8_t, uint32_t> Man_IP::GenMaskWordMap()
{
	map<uint8_t, uint32_t> ret;
	uint32_t mask = 0;
	for (int i = 0; i < 32; i++)
	{
		mask |= uint32_t(1 << i);
		ret.insert(make_pair(i, mask));
	}

	return ret;
}

void Man_IP::SetBit(uint32_t& number, uint8_t bitPos)
{
	uint32_t pos = gMasks[bitPos];
	number |= pos;
}

void Man_IP::UnSetBit(uint32_t& number, uint8_t bitPos)
{
	uint32_t pos = gMasks[bitPos];
	number &= ~pos;
}

void Man_IP::ToggleBit(uint32_t& number, uint8_t bitPos)
{
	uint32_t pos = gMasks[bitPos];
	number ^= pos;
}

void Man_IP::PrintBinary(uint32_t number)
{
	printf("Decimal: %d, Hex: 0x%X, Binary: 0b", number, number);
	for (int i = 31; i >= 0; i--)
	{
		uint32_t pos = gMasks[i];
		if (number & pos)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}

uint32_t Man_IP::GetMaskedData(uint32_t data, uint8_t startPos, uint8_t endPos)
{
	if (startPos > endPos)
	{
		return 0;
	}

	uint8_t numberOfBits = 0;
	if (startPos == endPos)
	{
		numberOfBits = endPos - startPos;
	}
	else
	{
		numberOfBits = endPos - startPos - 1;
	}

	data >>= startPos;
	return gMaskWords[numberOfBits] & data;
}