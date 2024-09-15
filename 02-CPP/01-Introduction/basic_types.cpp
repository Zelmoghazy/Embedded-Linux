#include <iostream>
#include <cstdint>

int main(void)
{
    // boolean, true or false
    bool b = true;
    // 8 bits ASCII char
    char c = 'a';
    // array of chars ended by \0
    char* s = (const char*)"a C string";

    std::string t = "a C++ string";// class provided by the STL

    // 8 bits signed integer
    char ch = -3;

    // 8 bits unsigned integer
    unsigned char cu = 4;

    // 16 bits signed integer
    short int sh = -444;

    // 16 bits unsigned integer
    unsigned short su = 444;

    short si = -444; // int is optional

    // 32 bits signed integer
    int i = -123456;

    unsigned int iu = 1234567; // 32 bits signed integer

    // 32 or 64 bits (ptr size)
    long l = 0L;

    // 32 or 64 bits (ptr size)
    unsigned long lu = 0UL;

    // 64 bits signed integer
    long long ll = 0LL;

    unsigned long long llu = 0ULL; // 64 bits unsigned integer

    // 32 (23+7+1) bits float
    float f = 1.23f;

    // 64 (52+11+1) bits float
    double d = 1.23E34;

    // 8 bits, replaces char
    int8_t c8 = -3;

    // 8 bits, replaces unsigned char
    uint8_t c8u = 4;

    // 16 bits, replaced short
    int16_t s16 = -444;

    // 16 bits, replaced unsigned short
    uint16_t s16u = 444;

    int32_t si32 = -0674; // 32 bits, replaced int

    uint32_t si32u = 0674; // 32 bits, replaced unsigned int

    int64_t si64 = -0x1bc;// 64 bits, replaced long long

    uint64_t si64u = 0x1bc;// 64 bits, replaced unsigned long long

}