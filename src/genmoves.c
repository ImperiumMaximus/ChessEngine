#include <genmoves.h>

uint8_t first_row_attacks[64 * 8]= {
    //first column
    0xFE,   // 0b11111110, index: 0b0[000000]0
    0x02,   // 0b00000010, index: 0b0[000001]0
    0x06,   // 0b00000110  index: 0b0[000010]0
    0x02,   // 0b00000010, index: 0b0[000011]0
    0x0E,   // 0b00001110, index: 0b0[000100]0
    0x02,   // 0b00000010, index: 0b0[000101]0
    0x06,   // 0b00000110, index: 0b0[000110]0
    0x02,   // 0b00000010, index: 0b0[000111]0
    0x1E,   // 0b00011110, index: 0b0[001000]0
    0x02,   // 0b00000010, index: 0b0[001001]0
    0x06,   // 0b00000110, index: 0b0[001010]0
    0x02,   // 0b00000010, index: 0b0[001011]0
    0x0E,   // 0b00001110, index: 0b0[001100]0
    0x02,   // 0b00000010, index: 0b0[001101]0
    0x06,   // 0b00000110, index: 0b0[001110]0
    0x02,   // 0b00000010, index: 0b0[001111]0
    0x3E,   // 0b00111110, index: 0b0[010000]0
    0x02,   // 0b00000010, index: 0b0[010001]0
    0x06,   // 0b00000110, index: 0b0[010010]0
    0x02,   // 0b00000010, index: 0b0[010011]0
    0x0E,   // 0b00001110, index: 0b0[010100]0
    0x02,   // 0b00000010, index: 0b0[010101]0
    0x06,   // 0b00000110, index: 0b0[010110]0
    0x02,   // 0b00000010, index: 0b0[010111]0
    0x1E,   // 0b00011110, index: 0b0[011000]0
    0x02,   // 0b00000010, index: 0b0[011001]0
    0x06,   // 0b00000110, index: 0b0[011010]0
    0x02,   // 0b00000010, index: 0b0[011011]0
    0x0E,   // 0b00001110, index: 0b0[011100]0
    0x02,   // 0b00000010, index: 0b0[011101]0
    0x06,   // 0b00000110, index: 0b0[011110]0
    0x02,   // 0b00000010, index: 0b0[011111]0
    0x7E,   // 0b01111110, index: 0b0[100000]0
    0x02,   // 0b00000010, index: 0b0[100001]0
    0x06,   // 0b00000110, index: 0b0[100010]0
    0x02,   // 0b00000010, index: 0b0[100011]0
    0x0E,   // 0b00001110, index: 0b0[100100]0
    0x02,   // 0b00000010, index: 0b0[100101]0
    0x06,   // 0b00000110, index: 0b0[100110]0
    0x02,   // 0b00000010, index: 0b0[100111]0
    0x1E,   // 0b00011110, index: 0b0[101000]0
    0x02,   // 0b00000010, index: 0b0[101001]0
    0x06,   // 0b00000110, index: 0b0[101010]0
    0x02,   // 0b00000010, index: 0b0[101011]0
    0x0E,   // 0b00001110, index: 0b0[101100]0
    0x02,   // 0b00000010, index: 0b0[101101]0
    0x06,   // 0b00000110, index: 0b0[101110]0
    0x02,   // 0b00000010, index: 0b0[101111]0
    0x3E,   // 0b00111110, index: 0b0[110000]0
    0x02,   // 0b00000010, index: 0b0[110001]0
    0x06,   // 0b00000110, index: 0b0[110010]0
    0x02,   // 0b00000010, index: 0b0[110011]0
    0x0E,   // 0b00001110, index: 0b0[110100]0
    0x02,   // 0b00000010, index: 0b0[110101]0
    0x06,   // 0b00000110, index: 0b0[110110]0
    0x02,   // 0b00000010, index: 0b0[110111]0
    0x1E,   // 0b00011110, index: 0b0[111000]0
    0x02,   // 0b00000010, index: 0b0[111001]0
    0x06,   // 0b00000110, index: 0b0[111010]0
    0x02,   // 0b00000010, index: 0b0[111011]0
    0x0E,   // 0b00001110, index: 0b0[111100]0
    0x02,   // 0b00000010, index: 0b0[111101]0
    0x06,   // 0b00000110, index: 0b0[111110]0
    0x02,   // 0b00000010, index: 0b0[111111]0

    //second column
    0xFD,   // 0b11111101, index: 0b0[000000]0
    0xFD,   // 0b11111101, index: 0b0[000001]0
    0x05,   // 0b00000101  index: 0b0[000010]0
    0x05,   // 0b00000101, index: 0b0[000011]0
    0x0D,   // 0b00001101, index: 0b0[000100]0
    0x0D,   // 0b00001101, index: 0b0[000101]0
    0x05,   // 0b00000101, index: 0b0[000110]0
    0x05,   // 0b00000101, index: 0b0[000111]0
    0x1D,   // 0b00011101, index: 0b0[001000]0
    0x1D,   // 0b00011101, index: 0b0[001001]0
    0x05,   // 0b00000101, index: 0b0[001010]0
    0x05,   // 0b00000101, index: 0b0[001011]0
    0x0D,   // 0b00001101, index: 0b0[001100]0
    0x0D,   // 0b00001101, index: 0b0[001101]0
    0x05,   // 0b00000101, index: 0b0[001110]0
    0x05,   // 0b00000101, index: 0b0[001111]0
    0x3D,   // 0b00111101, index: 0b0[010000]0
    0x3D,   // 0b00111101, index: 0b0[010001]0
    0x05,   // 0b00000101, index: 0b0[010010]0
    0x05,   // 0b00000101, index: 0b0[010011]0
    0x0D,   // 0b00001101, index: 0b0[010100]0
    0x0D,   // 0b00001101, index: 0b0[010101]0
    0x05,   // 0b00000101, index: 0b0[010110]0
    0x05,   // 0b00000101, index: 0b0[010111]0
    0x1D,   // 0b00011101, index: 0b0[011000]0
    0x1D,   // 0b00011101, index: 0b0[011001]0
    0x05,   // 0b00000101, index: 0b0[011010]0
    0x05,   // 0b00000101, index: 0b0[011011]0
    0x0D,   // 0b00001101, index: 0b0[011100]0
    0x0D,   // 0b00001101, index: 0b0[011101]0
    0x05,   // 0b00000101, index: 0b0[011110]0
    0x05,   // 0b00000101, index: 0b0[011111]0
    0x7D,   // 0b01111101, index: 0b0[100000]0
    0x7D,   // 0b01111101, index: 0b0[100001]0
    0x05,   // 0b00000101, index: 0b0[100010]0
    0x05,   // 0b00000101, index: 0b0[100011]0
    0x0D,   // 0b00001101, index: 0b0[100100]0
    0x0D,   // 0b00001101, index: 0b0[100101]0
    0x05,   // 0b00000101, index: 0b0[100110]0
    0x05,   // 0b00000101, index: 0b0[100111]0
    0x1D,   // 0b00011101, index: 0b0[101000]0
    0x1D,   // 0b00011101, index: 0b0[101001]0
    0x05,   // 0b00000101, index: 0b0[101010]0
    0x05,   // 0b00000101, index: 0b0[101011]0
    0x0D,   // 0b00001101, index: 0b0[101100]0
    0x0D,   // 0b00001101, index: 0b0[101101]0
    0x05,   // 0b00000101, index: 0b0[101110]0
    0x05,   // 0b00000101, index: 0b0[101111]0
    0x3D,   // 0b00111101, index: 0b0[110000]0
    0x3D,   // 0b00111101, index: 0b0[110001]0
    0x05,   // 0b00000101, index: 0b0[110010]0
    0x05,   // 0b00000101, index: 0b0[110011]0
    0x0D,   // 0b00001101, index: 0b0[110100]0
    0x0D,   // 0b00001101, index: 0b0[110101]0
    0x05,   // 0b00000101, index: 0b0[110110]0
    0x05,   // 0b00000101, index: 0b0[110111]0
    0x1D,   // 0b00011101, index: 0b0[111000]0
    0x1D,   // 0b00011101, index: 0b0[111001]0
    0x05,   // 0b00000101, index: 0b0[111010]0
    0x05,   // 0b00000101, index: 0b0[111011]0
    0x0D,   // 0b00001101, index: 0b0[111100]0
    0x0D,   // 0b00001101, index: 0b0[111101]0
    0x05,   // 0b00000101, index: 0b0[111110]0
    0x05,   // 0b00000101, index: 0b0[111111]0

    //third column
    0xFB,   // 0b11111011, index: 0b0[000000]0
    0xFA,   // 0b11111010, index: 0b0[000001]0
    0xFB,   // 0b11111011  index: 0b0[000010]0
    0xFA,   // 0b11111010, index: 0b0[000011]0
    0x0B,   // 0b00001011, index: 0b0[000100]0
    0x0A,   // 0b00001010, index: 0b0[000101]0
    0x0B,   // 0b00001011, index: 0b0[000110]0
    0x0A,   // 0b00001010, index: 0b0[000111]0
    0x1B,   // 0b00011011, index: 0b0[001000]0
    0x1A,   // 0b00011010, index: 0b0[001001]0
    0x1B,   // 0b00011011, index: 0b0[001010]0
    0x1A,   // 0b00011010, index: 0b0[001011]0
    0x0B,   // 0b00001011, index: 0b0[001100]0
    0x0A,   // 0b00001010, index: 0b0[001101]0
    0x0B,   // 0b00001011, index: 0b0[001110]0
    0x0A,   // 0b00001010, index: 0b0[001111]0
    0x3B,   // 0b00111011, index: 0b0[010000]0
    0x3A,   // 0b00111010, index: 0b0[010001]0
    0x3B,   // 0b00111011, index: 0b0[010010]0
    0x3A,   // 0b00111010, index: 0b0[010011]0
    0x0B,   // 0b00001011, index: 0b0[010100]0
    0x0A,   // 0b00001010, index: 0b0[010101]0
    0x0B,   // 0b00001011, index: 0b0[010110]0
    0x0A,   // 0b00001010, index: 0b0[010111]0
    0x1B,   // 0b00011011, index: 0b0[011000]0
    0x1A,   // 0b00011010, index: 0b0[011001]0
    0x1B,   // 0b00011011, index: 0b0[011010]0
    0x1A,   // 0b00011010, index: 0b0[011011]0
    0x0B,   // 0b00001011, index: 0b0[011100]0
    0x0A,   // 0b00001010, index: 0b0[011101]0
    0x0B,   // 0b00001011, index: 0b0[011110]0
    0x0A,   // 0b00001010, index: 0b0[011111]0
    0x7B,   // 0b01111011, index: 0b0[100000]0
    0x7A,   // 0b01111010, index: 0b0[100001]0
    0x7B,   // 0b01111011, index: 0b0[100010]0
    0x7A,   // 0b01111010, index: 0b0[100011]0
    0x0B,   // 0b00001011, index: 0b0[100100]0
    0x0A,   // 0b00001010, index: 0b0[100101]0
    0x0B,   // 0b00001011, index: 0b0[100110]0
    0x0A,   // 0b00001010, index: 0b0[100111]0
    0x1B,   // 0b00011011, index: 0b0[101000]0
    0x1A,   // 0b00011010, index: 0b0[101001]0
    0x1B,   // 0b00011011, index: 0b0[101010]0
    0x1A,   // 0b00011010, index: 0b0[101011]0
    0x0B,   // 0b00001011, index: 0b0[101100]0
    0x0A,   // 0b00001010, index: 0b0[101101]0
    0x0B,   // 0b00001011, index: 0b0[101110]0
    0x0A,   // 0b00001010, index: 0b0[101111]0
    0x3B,   // 0b00111011, index: 0b0[110000]0
    0x3A,   // 0b00111010, index: 0b0[110001]0
    0x3B,   // 0b00111011, index: 0b0[110010]0
    0x3A,   // 0b00111010, index: 0b0[110011]0
    0x0B,   // 0b00001011, index: 0b0[110100]0
    0x0A,   // 0b00001010, index: 0b0[110101]0
    0x0B,   // 0b00001011, index: 0b0[110110]0
    0x0A,   // 0b00001010, index: 0b0[110111]0
    0x1B,   // 0b00011011, index: 0b0[111000]0
    0x1A,   // 0b00011010, index: 0b0[111001]0
    0x1B,   // 0b00011011, index: 0b0[111010]0
    0x1A,   // 0b00011010, index: 0b0[111011]0
    0x0B,   // 0b00001011, index: 0b0[111100]0
    0x0A,   // 0b00001010, index: 0b0[111101]0
    0x0B,   // 0b00001011, index: 0b0[111110]0
    0x0A,   // 0b00001010, index: 0b0[111111]0

    //fourth column
    0xF7,   // 0b11110111, index: 0b0[000000]0
    0xF6,   // 0b11110110, index: 0b0[000001]0
    0xF4,   // 0b11110100  index: 0b0[000010]0
    0xF4,   // 0b11110100, index: 0b0[000011]0
    0xF7,   // 0b11110111, index: 0b0[000100]0
    0xF6,   // 0b11110110, index: 0b0[000101]0
    0xF4,   // 0b11110100, index: 0b0[000110]0
    0xF4,   // 0b11110100, index: 0b0[000111]0
    0x17,   // 0b00010111, index: 0b0[001000]0
    0x16,   // 0b00010110, index: 0b0[001001]0
    0x14,   // 0b00010100, index: 0b0[001010]0
    0x14,   // 0b00010100, index: 0b0[001011]0
    0x17,   // 0b00010111, index: 0b0[001100]0
    0x16,   // 0b00010110, index: 0b0[001101]0
    0x14,   // 0b00010100, index: 0b0[001110]0
    0x14,   // 0b00010100, index: 0b0[001111]0
    0x37,   // 0b00110111, index: 0b0[010000]0
    0x36,   // 0b00110110, index: 0b0[010001]0
    0x34,   // 0b00110100, index: 0b0[010010]0
    0x34,   // 0b00110100, index: 0b0[010011]0
    0x37,   // 0b00110111, index: 0b0[010100]0
    0x36,   // 0b00110110, index: 0b0[010101]0
    0x34,   // 0b00110100, index: 0b0[010110]0
    0x34,   // 0b00110100, index: 0b0[010111]0
    0x17,   // 0b00010111, index: 0b0[011000]0
    0x16,   // 0b00010110, index: 0b0[011001]0
    0x14,   // 0b00010100, index: 0b0[011010]0
    0x14,   // 0b00010100, index: 0b0[011011]0
    0x17,   // 0b00010111, index: 0b0[011100]0
    0x16,   // 0b00010110, index: 0b0[011101]0
    0x14,   // 0b00010100, index: 0b0[011110]0
    0x14,   // 0b00010100, index: 0b0[011111]0
    0x77,   // 0b01110111, index: 0b0[100000]0
    0x76,   // 0b01110110, index: 0b0[100001]0
    0x74,   // 0b01110100, index: 0b0[100010]0
    0x74,   // 0b01110100, index: 0b0[100011]0
    0x77,   // 0b01110111, index: 0b0[100100]0
    0x76,   // 0b01110110, index: 0b0[100101]0
    0x74,   // 0b01110100, index: 0b0[100110]0
    0x74,   // 0b01110100, index: 0b0[100111]0
    0x17,   // 0b00010111, index: 0b0[101000]0
    0x16,   // 0b00010110, index: 0b0[101001]0
    0x14,   // 0b00010100, index: 0b0[101010]0
    0x14,   // 0b00010100, index: 0b0[101011]0
    0x17,   // 0b00010111, index: 0b0[101100]0
    0x16,   // 0b00010110, index: 0b0[101101]0
    0x14,   // 0b00010100, index: 0b0[101110]0
    0x14,   // 0b00010100, index: 0b0[101111]0
    0x27,   // 0b00110111, index: 0b0[110000]0
    0x26,   // 0b00110110, index: 0b0[110001]0
    0x24,   // 0b00110100, index: 0b0[110010]0
    0x24,   // 0b00110100, index: 0b0[110011]0
    0x27,   // 0b00110111, index: 0b0[110100]0
    0x26,   // 0b00110110, index: 0b0[110101]0
    0x24,   // 0b00110100, index: 0b0[110110]0
    0x24,   // 0b00110100, index: 0b0[110111]0
    0x17,   // 0b00010111, index: 0b0[111000]0
    0x16,   // 0b00010110, index: 0b0[111001]0
    0x14,   // 0b00010100, index: 0b0[111010]0
    0x14,   // 0b00010100, index: 0b0[111011]0
    0x17,   // 0b00010111, index: 0b0[111100]0
    0x16,   // 0b00010110, index: 0b0[111101]0
    0x14,   // 0b00010100, index: 0b0[111110]0
    0x14,   // 0b00010100, index: 0b0[111111]0

    //fifth column
    0xEF,   // 0b11101111, index: 0b0[000000]0
    0xEE,   // 0b11101110, index: 0b0[000001]0
    0xEC,   // 0b11101100  index: 0b0[000010]0
    0xEC,   // 0b11101100, index: 0b0[000011]0
    0xE8,   // 0b11101000, index: 0b0[000100]0
    0xE8,   // 0b11101000, index: 0b0[000101]0
    0xE8,   // 0b11101000, index: 0b0[000110]0
    0xE8,   // 0b11101000, index: 0b0[000111]0
    0xEF,   // 0b11101111, index: 0b0[001000]0
    0xEE,   // 0b11101110, index: 0b0[001001]0
    0xEC,   // 0b11101100, index: 0b0[001010]0
    0xEC,   // 0b11101100, index: 0b0[001011]0
    0xE8,   // 0b11101000, index: 0b0[001100]0
    0xE8,   // 0b11101000, index: 0b0[001101]0
    0xE8,   // 0b11101000, index: 0b0[001110]0
    0xE8,   // 0b11101000, index: 0b0[001111]0
    0x2F,   // 0b00101111, index: 0b0[010000]0
    0x2E,   // 0b00101110, index: 0b0[010001]0
    0x2C,   // 0b00101100, index: 0b0[010010]0
    0x2C,   // 0b00101100, index: 0b0[010011]0
    0x28,   // 0b00101000, index: 0b0[010100]0
    0x28,   // 0b00101000, index: 0b0[010101]0
    0x28,   // 0b00101000, index: 0b0[010110]0
    0x28,   // 0b00101000, index: 0b0[010111]0
    0x2F,   // 0b00101111, index: 0b0[011000]0
    0x2E,   // 0b00101110, index: 0b0[011001]0
    0x2C,   // 0b00101100, index: 0b0[011010]0
    0x2C,   // 0b00101100, index: 0b0[011011]0
    0x28,   // 0b00101000, index: 0b0[011100]0
    0x28,   // 0b00101000, index: 0b0[011101]0
    0x28,   // 0b00101000, index: 0b0[011110]0
    0x28,   // 0b00101000, index: 0b0[011111]0
    0x6F,   // 0b01101111, index: 0b0[100000]0
    0x6E,   // 0b01101110, index: 0b0[100001]0
    0x6C,   // 0b01101100, index: 0b0[100010]0
    0x6C,   // 0b01101100, index: 0b0[100011]0
    0x68,   // 0b01101000, index: 0b0[100100]0
    0x68,   // 0b01101000, index: 0b0[100101]0
    0x68,   // 0b01101000, index: 0b0[100110]0
    0x68,   // 0b01101000, index: 0b0[100111]0
    0x6F,   // 0b01101111, index: 0b0[101000]0
    0x6E,   // 0b01101110, index: 0b0[101001]0
    0x6C,   // 0b01101100, index: 0b0[101010]0
    0x6C,   // 0b01101100, index: 0b0[101011]0
    0x68,   // 0b01101000, index: 0b0[101100]0
    0x68,   // 0b01101000, index: 0b0[101101]0
    0x68,   // 0b01101000, index: 0b0[101110]0
    0x68,   // 0b01101000, index: 0b0[101111]0
    0x2F,   // 0b00101111, index: 0b0[110000]0
    0x2E,   // 0b00101110, index: 0b0[110001]0
    0x2C,   // 0b00101100, index: 0b0[110010]0
    0x2C,   // 0b00101100, index: 0b0[110011]0
    0x28,   // 0b00101000, index: 0b0[110100]0
    0x28,   // 0b00101000, index: 0b0[110101]0
    0x28,   // 0b00101000, index: 0b0[110110]0
    0x28,   // 0b00101000, index: 0b0[110111]0
    0x2F,   // 0b00101111, index: 0b0[111000]0
    0x2E,   // 0b00101110, index: 0b0[111001]0
    0x2C,   // 0b00101100, index: 0b0[111010]0
    0x2C,   // 0b00101100, index: 0b0[111011]0
    0x28,   // 0b00101000, index: 0b0[111100]0
    0x28,   // 0b00101000, index: 0b0[111101]0
    0x28,   // 0b00101000, index: 0b0[111110]0
    0x28,   // 0b00101000, index: 0b0[111111]0

    //sixth column
    0xDF,   // 0b11011111, index: 0b0[000000]0
    0xDE,   // 0b11011110, index: 0b0[000001]0
    0xDC,   // 0b11011100  index: 0b0[000010]0
    0xDC,   // 0b11011100, index: 0b0[000011]0
    0xD8,   // 0b11011000, index: 0b0[000100]0
    0xD8,   // 0b11011000, index: 0b0[000101]0
    0xD8,   // 0b11011000, index: 0b0[000110]0
    0xD8,   // 0b11011000, index: 0b0[000111]0
    0xD0,   // 0b11010000, index: 0b0[001000]0
    0xD0,   // 0b11010000, index: 0b0[001001]0
    0xD0,   // 0b11010000, index: 0b0[001010]0
    0xD0,   // 0b11010000, index: 0b0[001011]0
    0xD0,   // 0b11010000, index: 0b0[001100]0
    0xD0,   // 0b11010000, index: 0b0[001101]0
    0xD0,   // 0b11010000, index: 0b0[001110]0
    0xD0,   // 0b11010000, index: 0b0[001111]0
    0xDF,   // 0b11011111, index: 0b0[010000]0
    0xDE,   // 0b11011110, index: 0b0[010001]0
    0xDC,   // 0b11011100, index: 0b0[010010]0
    0xDC,   // 0b11011100, index: 0b0[010011]0
    0xD8,   // 0b11011000, index: 0b0[010100]0
    0xD8,   // 0b11011000, index: 0b0[010101]0
    0xD8,   // 0b11011000, index: 0b0[010110]0
    0xD8,   // 0b11011000, index: 0b0[010111]0
    0xD8,   // 0b11010000, index: 0b0[011000]0
    0xD8,   // 0b11010000, index: 0b0[011001]0
    0xD8,   // 0b11010000, index: 0b0[011010]0
    0xD8,   // 0b11010000, index: 0b0[011011]0
    0xD8,   // 0b11010000, index: 0b0[011100]0
    0xD8,   // 0b11010000, index: 0b0[011101]0
    0xD8,   // 0b11010000, index: 0b0[011110]0
    0xD8,   // 0b11010000, index: 0b0[011111]0
    0x5F,   // 0b01011111, index: 0b0[100000]0
    0x5E,   // 0b01011110, index: 0b0[100001]0
    0x5C,   // 0b01011100, index: 0b0[100010]0
    0x5C,   // 0b01011100, index: 0b0[100011]0
    0x58,   // 0b01011000, index: 0b0[100100]0
    0x58,   // 0b01011000, index: 0b0[100101]0
    0x58,   // 0b01011000, index: 0b0[100110]0
    0x58,   // 0b01011000, index: 0b0[100111]0
    0x50,   // 0b01010000, index: 0b0[101000]0
    0x50,   // 0b01010000, index: 0b0[101001]0
    0x50,   // 0b01010000, index: 0b0[101010]0
    0x50,   // 0b01010000, index: 0b0[101011]0
    0x50,   // 0b01010000, index: 0b0[101100]0
    0x50,   // 0b01010000, index: 0b0[101101]0
    0x50,   // 0b01010000, index: 0b0[101110]0
    0x50,   // 0b01010000, index: 0b0[101111]0
    0x5F,   // 0b01011111, index: 0b0[110000]0
    0x5E,   // 0b01011110, index: 0b0[110001]0
    0x5C,   // 0b01011100, index: 0b0[110010]0
    0x5C,   // 0b01011100, index: 0b0[110011]0
    0x58,   // 0b01011000, index: 0b0[110100]0
    0x58,   // 0b01011000, index: 0b0[110101]0
    0x58,   // 0b01011000, index: 0b0[110110]0
    0x58,   // 0b01011000, index: 0b0[110111]0
    0x50,   // 0b01010000, index: 0b0[111000]0
    0x50,   // 0b01010000, index: 0b0[111001]0
    0x50,   // 0b01010000, index: 0b0[111010]0
    0x50,   // 0b01010000, index: 0b0[111011]0
    0x50,   // 0b01010000, index: 0b0[111100]0
    0x50,   // 0b01010000, index: 0b0[111101]0
    0x50,   // 0b01010000, index: 0b0[111110]0
    0x50,   // 0b01010000, index: 0b0[111111]0

    //seventh column
    0xBF,   // 0b10111111, index: 0b0[000000]0
    0xBE,   // 0b10111110, index: 0b0[000001]0
    0xBC,   // 0b10111100  index: 0b0[000010]0
    0xBC,   // 0b10111100, index: 0b0[000011]0
    0xB8,   // 0b10111000, index: 0b0[000100]0
    0xB8,   // 0b10111000, index: 0b0[000101]0
    0xB8,   // 0b10111000, index: 0b0[000110]0
    0xB8,   // 0b10111000, index: 0b0[000111]0
    0xB0,   // 0b10110000, index: 0b0[001000]0
    0xB0,   // 0b10110000, index: 0b0[001001]0
    0xB0,   // 0b10110000, index: 0b0[001010]0
    0xB0,   // 0b10110000, index: 0b0[001011]0
    0xB0,   // 0b10110000, index: 0b0[001100]0
    0xB0,   // 0b10110000, index: 0b0[001101]0
    0xB0,   // 0b10110000, index: 0b0[001110]0
    0xB0,   // 0b10110000, index: 0b0[001111]0
    0xA0,   // 0b10100000, index: 0b0[010000]0
    0xA0,   // 0b10100000, index: 0b0[010001]0
    0xA0,   // 0b10100000, index: 0b0[010010]0
    0xA0,   // 0b10100000, index: 0b0[010011]0
    0xA0,   // 0b10100000, index: 0b0[010100]0
    0xA0,   // 0b10100000, index: 0b0[010101]0
    0xA0,   // 0b10100000, index: 0b0[010110]0
    0xA0,   // 0b10100000, index: 0b0[010111]0
    0xA0,   // 0b10100000, index: 0b0[011000]0
    0xA0,   // 0b10100000, index: 0b0[011001]0
    0xA0,   // 0b10100000, index: 0b0[011010]0
    0xA0,   // 0b10100000, index: 0b0[011011]0
    0xA0,   // 0b10100000, index: 0b0[011100]0
    0xA0,   // 0b10100000, index: 0b0[011101]0
    0xA0,   // 0b10100000, index: 0b0[011110]0
    0xA0,   // 0b10100000, index: 0b0[011111]0
    0xBF,   // 0b10111111, index: 0b0[100000]0
    0xBE,   // 0b10111110, index: 0b0[100001]0
    0xBC,   // 0b10111100, index: 0b0[100010]0
    0xBC,   // 0b10111100, index: 0b0[100011]0
    0xB8,   // 0b10111000, index: 0b0[100100]0
    0xB8,   // 0b10111000, index: 0b0[100101]0
    0xB8,   // 0b10111000, index: 0b0[100110]0
    0xB8,   // 0b10111000, index: 0b0[100111]0
    0xB0,   // 0b10110000, index: 0b0[101000]0
    0xB0,   // 0b10110000, index: 0b0[101001]0
    0xB0,   // 0b10110000, index: 0b0[101010]0
    0xB0,   // 0b10110000, index: 0b0[101011]0
    0xB0,   // 0b10110000, index: 0b0[101100]0
    0xB0,   // 0b10110000, index: 0b0[101101]0
    0xB0,   // 0b10110000, index: 0b0[101110]0
    0xB0,   // 0b10110000, index: 0b0[101111]0
    0xA0,   // 0b10100000, index: 0b0[110000]0
    0xA0,   // 0b10100000, index: 0b0[110001]0
    0xA0,   // 0b10100000, index: 0b0[110010]0
    0xA0,   // 0b10100000, index: 0b0[110011]0
    0xA0,   // 0b10100000, index: 0b0[110100]0
    0xA0,   // 0b10100000, index: 0b0[110101]0
    0xA0,   // 0b10100000, index: 0b0[110110]0
    0xA0,   // 0b10100000, index: 0b0[110111]0
    0xA0,   // 0b10100000, index: 0b0[111000]0
    0xA0,   // 0b10100000, index: 0b0[111001]0
    0xA0,   // 0b10100000, index: 0b0[111010]0
    0xA0,   // 0b10100000, index: 0b0[111011]0
    0xA0,   // 0b10100000, index: 0b0[111100]0
    0xA0,   // 0b10100000, index: 0b0[111101]0
    0xA0,   // 0b10100000, index: 0b0[111110]0
    0xA0,   // 0b10100000, index: 0b0[111111]0

    //eighth column
    0x7F,   // 0b01111111, index: 0b1[000000]0
    0x7E,   // 0b01111110, index: 0b1[000001]0
    0x7C,   // 0b01111100  index: 0b1[000010]0
    0x7C,   // 0b01111100, index: 0b1[000011]0
    0x78,   // 0b01111000, index: 0b1[000100]0
    0x78,   // 0b01111000, index: 0b1[000101]0
    0x78,   // 0b01111000, index: 0b1[000110]0
    0x78,   // 0b01111000, index: 0b1[000111]0
    0x70,   // 0b01110000, index: 0b1[001000]0
    0x70,   // 0b01110000, index: 0b1[001001]0
    0x70,   // 0b01110000, index: 0b1[001010]0
    0x70,   // 0b01110000, index: 0b1[001011]0
    0x70,   // 0b01110000, index: 0b1[001100]0
    0x70,   // 0b01110000, index: 0b1[001101]0
    0x70,   // 0b01110000, index: 0b1[001110]0
    0x70,   // 0b01110000, index: 0b1[001111]0
    0x60,   // 0b01100000, index: 0b1[010000]0
    0x60,   // 0b01100000, index: 0b1[010001]0
    0x60,   // 0b01100000, index: 0b1[010010]0
    0x60,   // 0b01100000, index: 0b1[010011]0
    0x60,   // 0b01100000, index: 0b1[010100]0
    0x60,   // 0b01100000, index: 0b1[010101]0
    0x60,   // 0b01100000, index: 0b1[010110]0
    0x60,   // 0b01100000, index: 0b1[010111]0
    0x60,   // 0b01100000, index: 0b1[011000]0
    0x60,   // 0b01100000, index: 0b1[011001]0
    0x60,   // 0b01100000, index: 0b1[011010]0
    0x60,   // 0b01100000, index: 0b1[011011]0
    0x60,   // 0b01100000, index: 0b1[011100]0
    0x60,   // 0b01100000, index: 0b1[011101]0
    0x60,   // 0b01100000, index: 0b1[011110]0
    0x60,   // 0b01100000, index: 0b1[011111]0
    0x40,   // 0b01000000, index: 0b1[100000]0
    0x40,   // 0b01000000, index: 0b1[100001]0
    0x40,   // 0b01000000, index: 0b1[100010]0
    0x40,   // 0b01000000, index: 0b1[100011]0
    0x40,   // 0b01000000, index: 0b1[100100]0
    0x40,   // 0b01000000, index: 0b1[100101]0
    0x40,   // 0b01000000, index: 0b1[100110]0
    0x40,   // 0b01000000, index: 0b1[100111]0
    0x40,   // 0b01000000, index: 0b1[101000]0
    0x40,   // 0b01000000, index: 0b1[101001]0
    0x40,   // 0b01000000, index: 0b1[101010]0
    0x40,   // 0b01000000, index: 0b1[101011]0
    0x40,   // 0b01000000, index: 0b1[101100]0
    0x40,   // 0b01000000, index: 0b1[101101]0
    0x40,   // 0b01000000, index: 0b1[101110]0
    0x40,   // 0b01000000, index: 0b1[101111]0
    0x40,   // 0b01000000, index: 0b1[110000]0
    0x40,   // 0b01000000, index: 0b1[110001]0
    0x40,   // 0b01000000, index: 0b1[110010]0
    0x40,   // 0b01000000, index: 0b1[110011]0
    0x40,   // 0b01000000, index: 0b1[110100]0
    0x40,   // 0b01000000, index: 0b1[110101]0
    0x40,   // 0b01000000, index: 0b1[110110]0
    0x40,   // 0b01000000, index: 0b1[110111]0
    0x40,   // 0b01000000, index: 0b1[111000]0
    0x40,   // 0b01000000, index: 0b1[111001]0
    0x40,   // 0b01000000, index: 0b1[111010]0
    0x40,   // 0b01000000, index: 0b1[111011]0
    0x40,   // 0b01000000, index: 0b1[111100]0
    0x40,   // 0b01000000, index: 0b1[111101]0
    0x40,   // 0b01000000, index: 0b1[111110]0
    0x40,   // 0b01000000, index: 0b1[111111]0
};

struct {
    uint64_t bit_mask;
    uint64_t diag_mask_ex;
    uint64_t anti_diag_mask_ex;
    uint64_t column_mask_ex;
} square_attacks[64] = {
    // first rank
    { .bit_mask = 0x0000000000000001, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x0000000000000001, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0000000000000002, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x0000000000000102, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0000000000000004, .diag_mask_ex = 0x0000804020100804,
        .anti_diag_mask_ex = 0x0000000000010204, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0000000000000008, .diag_mask_ex = 0x0000008040201008,
        .anti_diag_mask_ex = 0x0000000001020408, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0000000000000010, .diag_mask_ex = 0x0000000080402010,
        .anti_diag_mask_ex = 0x0000000102040810, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0000000000000020, .diag_mask_ex = 0x0000000000804020,
        .anti_diag_mask_ex = 0x0000010204081020, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0000000000000040, .diag_mask_ex = 0x0000000000008040,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0000000000000080, .diag_mask_ex = 0x0000000000000080,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x8080808080808080 },

    // second rand
    { .bit_mask = 0x0000000000000100, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x0000000000000102, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0000000000000200, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x0000000000010204, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0000000000000400, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x0000000001020408, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0000000000000800, .diag_mask_ex = 0x0000804020100804,
        .anti_diag_mask_ex = 0x0000000102040810, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0000000000001000, .diag_mask_ex = 0x0000008040201008,
        .anti_diag_mask_ex = 0x0000010204081020, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0000000000002000, .diag_mask_ex = 0x0000000080402010,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0000000000004000, .diag_mask_ex = 0x0000000000804020,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0000000000008000, .diag_mask_ex = 0x0000000000008040,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x8080808080808080 },

    // third rank
    { .bit_mask = 0x0000000000010000, .diag_mask_ex = 0x2010080402010000,
        .anti_diag_mask_ex = 0x0000000000010204, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0000000000020000, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x0000000001020408, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0000000000040000, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x0000000102040810, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0000000000080000, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x0000010204081020, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0000000000100000, .diag_mask_ex = 0x0000804020100804,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0000000000200000, .diag_mask_ex = 0x0000008040201008,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0000000000400000, .diag_mask_ex = 0x0000000080402010,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0000000000800000, .diag_mask_ex = 0x0000000000804020,
        .anti_diag_mask_ex = 0x0408102040800000, .column_mask_ex = 0x8080808080808080 },

    // fourth rank
    { .bit_mask = 0x0000000001000000, .diag_mask_ex = 0x1008040201000000,
        .anti_diag_mask_ex = 0x0000000001020408, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0000000002000000, .diag_mask_ex = 0x2010080402010000,
        .anti_diag_mask_ex = 0x0000000102040810, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0000000004000000, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x0000010204081020, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0000000008000000, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0000000010000000, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0000000020000000, .diag_mask_ex = 0x0000804020100804,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0000000040000000, .diag_mask_ex = 0x0000008040201008,
        .anti_diag_mask_ex = 0x0408102040800000, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0000000080000000, .diag_mask_ex = 0x0000000080402010,
        .anti_diag_mask_ex = 0x0810204080000000, .column_mask_ex = 0x8080808080808080 },

    // fifth rank
    { .bit_mask = 0x0000000100000000, .diag_mask_ex = 0x0804020100000000,
        .anti_diag_mask_ex = 0x0000000102040810, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0000000200000000, .diag_mask_ex = 0x1008040201000000,
        .anti_diag_mask_ex = 0x0000010204081020, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0000000400000000, .diag_mask_ex = 0x2010080402010000,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0000000800000000, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0000001000000000, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0000002000000000, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x0408102040800000, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0000004000000000, .diag_mask_ex = 0x0000804020100804,
        .anti_diag_mask_ex = 0x0810204080000000, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0000008000000000, .diag_mask_ex = 0x0000008040201008,
        .anti_diag_mask_ex = 0x1020408000000000, .column_mask_ex = 0x8080808080808080 },

    // sixth rank
    { .bit_mask = 0x0000010000000000, .diag_mask_ex = 0x0402010000000000,
        .anti_diag_mask_ex = 0x0000010204081020, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0000020000000000, .diag_mask_ex = 0x0804020100000000,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0000040000000000, .diag_mask_ex = 0x1008040201000000,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0000080000000000, .diag_mask_ex = 0x2010080402010000,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0000100000000000, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x0408102040800000, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0000200000000000, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x0810204080000000, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0000400000000000, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x1020408000000000, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0000800000000000, .diag_mask_ex = 0x0000804020100804,
        .anti_diag_mask_ex = 0x2040800000000000, .column_mask_ex = 0x8080808080808080 },

    // seventh rank
    { .bit_mask = 0x0001000000000000, .diag_mask_ex = 0x0201000000000000,
        .anti_diag_mask_ex = 0x0001020408102040, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0002000000000000, .diag_mask_ex = 0x0402010000000000,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0004000000000000, .diag_mask_ex = 0x0804020100000000,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0008000000000000, .diag_mask_ex = 0x1008040201000000,
        .anti_diag_mask_ex = 0x0408102040800000, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x0010000000000000, .diag_mask_ex = 0x2010080402010000,
        .anti_diag_mask_ex = 0x0810204080000000, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x0020000000000000, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x1020408000000000, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x0040000000000000, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x2040800000000000, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x0080000000000000, .diag_mask_ex = 0x0080402010080402,
        .anti_diag_mask_ex = 0x4080000000000000, .column_mask_ex = 0x8080808080808080 },

    //eigth rank
    { .bit_mask = 0x0100000000000000, .diag_mask_ex = 0x0100000000000000,
        .anti_diag_mask_ex = 0x0102040810204080, .column_mask_ex = 0x0101010101010101 },

    { .bit_mask = 0x0200000000000000, .diag_mask_ex = 0x0201000000000000,
        .anti_diag_mask_ex = 0x0204081020408000, .column_mask_ex = 0x0202020202020202 },

    { .bit_mask = 0x0400000000000000, .diag_mask_ex = 0x0402010000000000,
        .anti_diag_mask_ex = 0x0408102040800000, .column_mask_ex = 0x0404040404040404 },

    { .bit_mask = 0x0800000000000000, .diag_mask_ex = 0x0804020100000000,
        .anti_diag_mask_ex = 0x0810204080000000, .column_mask_ex = 0x0808080808080808 },

    { .bit_mask = 0x1000000000000000, .diag_mask_ex = 0x1008040201000000,
        .anti_diag_mask_ex = 0x1020408000000000, .column_mask_ex = 0x1010101010101010 },

    { .bit_mask = 0x2000000000000000, .diag_mask_ex = 0x2010080402010000,
        .anti_diag_mask_ex = 0x2040800000000000, .column_mask_ex = 0x2020202020202020 },

    { .bit_mask = 0x4000000000000000, .diag_mask_ex = 0x4020100804020100,
        .anti_diag_mask_ex = 0x4080000000000000, .column_mask_ex = 0x4040404040404040 },

    { .bit_mask = 0x8000000000000000, .diag_mask_ex = 0x8040201008040201,
        .anti_diag_mask_ex = 0x8000000000000000, .column_mask_ex = 0x8080808080808080 },
};

uint64_t genmoves_row_attacks(uint64_t occ, uint32_t pos) {
    uint32_t file = pos & 7;
    uint32_t rkx8 = pos & 56;
    occ = (occ >> rkx8) & 2 * 63;
    uint64_t attacks = first_row_attacks[4 * occ + file];
    return attacks << rkx8;
}

uint64_t genmoves_diag_attacks(uint64_t occ, uint32_t pos) {
    uint64_t forward, reverse;
    forward  = occ & square_attacks[pos].diag_mask_ex;
    reverse  = __builtin_bswap64(forward);
    forward -= square_attacks[pos].bit_mask;
    reverse -= __builtin_bswap64(square_attacks[pos].bit_mask);
    forward ^= __builtin_bswap64(reverse);
    forward &= square_attacks[pos].diag_mask_ex;
    return forward;
}

uint64_t genmoves_anti_diag_attacks(uint64_t occ, uint32_t pos) {
    uint64_t forward, reverse;
    forward  = occ & square_attacks[pos].anti_diag_mask_ex;
    reverse  = __builtin_bswap64(forward);
    forward -= square_attacks[pos].bit_mask;
    reverse -= __builtin_bswap64(square_attacks[pos].bit_mask);
    forward ^= __builtin_bswap64(reverse);
    forward &= square_attacks[pos].anti_diag_mask_ex;
    return forward;
}

uint64_t genmoves_column_attacks(uint64_t occ, uint32_t pos) {
    uint64_t forward, reverse;
    forward  = occ & square_attacks[pos].column_mask_ex;
    reverse  = __builtin_bswap64(forward);
    forward -= square_attacks[pos].bit_mask;
    reverse -= __builtin_bswap64(square_attacks[pos].bit_mask);
    forward ^= __builtin_bswap64(reverse);
    forward &= square_attacks[pos].column_mask_ex;
    return forward;
}