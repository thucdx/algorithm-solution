//============================================================================
// Name        : FFT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
unsigned int bit_reversed(unsigned int x)
{
    x = (x & 0x55555555) <<  1 | (x & 0xAAAAAAAA) >>  1;
    x = (x & 0x33333333) <<  2 | (x & 0xCCCCCCCC) >>  2;
    x = (x & 0x0F0F0F0F) <<  4 | (x & 0xF0F0F0F0) >>  4;
    x = (x & 0x00FF00FF) <<  8 | (x & 0xFF00FF00) >>  8;
    x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;

    return x;
}

int main()
{
    int x = 0x01234567;
    int y = bit_reversed(x);

    printf("%x\n", bit_reversed(x));
    printf("%x\n", bit_reversed(y));

    return 0;
}
