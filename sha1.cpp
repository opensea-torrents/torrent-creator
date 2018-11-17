
//#include <iostream>
#include <cstdint>
#include <cstring>
extern "C"
{
void sha1(uint8_t* memory_buffer)
{
    const int max_data = 16777216;
    // length is stored at 16777216 + 4 bytes
    size_t length = memory_buffer[max_data] << 24 | memory_buffer[max_data + 1] << 16 | memory_buffer[max_data + 2] << 8 | memory_buffer[max_data + 3];
    
    size_t blockstart;
    int32_t i, j;
    uint32_t W[80];
    uint32_t H0 = 0x67452301;
    uint32_t H1 = 0xEFCDAB89;
    uint32_t H2 = 0x98BADCFE;
    uint32_t H3 = 0x10325476;
    uint32_t H4 = 0xC3D2E1F0;
    uint32_t A, B, C, D, E;
    uint32_t n;
    uint32_t temp;

    int32_t padCount = 14 - (((length >> 2) + 1) & 15);
    if (padCount < 0)
        padCount += 16;

    size_t total_size = (length >> 2) + 1 + padCount + 2;
    uint32_t* word_array = new uint32_t[total_size];

    size_t word_count = 0;
    int32_t lengthMinus3 = (int32_t)length - 3;
    for (i = 0; i < lengthMinus3; i += 4)
    {
        word_array[word_count] = memory_buffer[i] << 24 | memory_buffer[i + 1] << 16 | memory_buffer[i + 2] << 8 | memory_buffer[i + 3];
        ++word_count;
    }

    switch (length & 3)
    {
    case 0:
        i = 0x080000000;
        break;
    case 1:
        i = memory_buffer[length - 1] << 24 | 0x0800000;
        break;
    case 2:
        i = memory_buffer[length - 2] << 24 | memory_buffer[length - 1] << 16 | 0x08000;
        break;
    case 3:
        i = memory_buffer[length - 3] << 24 | memory_buffer[length - 2] << 16 | memory_buffer[length - 1] << 8 | 0x80;
        break;
    }

    word_array[word_count++] = i;

    memset(&word_array[word_count], 0, padCount * 4 /*sizeof(uint32_t)*/);
    word_count += padCount;
    //for (i = 0; i < padCount; ++i)
    //    word_array[word_count++] = 0;

    word_array[word_count++] = length >> 29;
    word_array[word_count] = (length << 3) & 0x0ffffffff;

    for (blockstart = 0; blockstart < total_size; blockstart += 16)
    {
        memcpy(W, &word_array[blockstart], 16 * 4);
        //W[0] = word_array[blockstart];
        //W[1] = word_array[blockstart + 1];
        //W[2] = word_array[blockstart + 2];
        //W[3] = word_array[blockstart + 3];
        //W[4] = word_array[blockstart + 4];
        //W[5] = word_array[blockstart + 5];
        //W[6] = word_array[blockstart + 6];
        //W[7] = word_array[blockstart + 7];
        //W[8] = word_array[blockstart + 8];
        //W[9] = word_array[blockstart + 9];
        //W[10] = word_array[blockstart + 10];
        //W[11] = word_array[blockstart + 11];
        //W[12] = word_array[blockstart + 12];
        //W[13] = word_array[blockstart + 13];
        //W[14] = word_array[blockstart + 14];
        //W[15] = word_array[blockstart + 15];

        n = W[13] ^ W[8] ^ W[2] ^ W[0];
        W[16] = ((n << 1) | (n >> 31));
        n = W[14] ^ W[9] ^ W[3] ^ W[1];
        W[17] = ((n << 1) | (n >> 31));
        n = W[15] ^ W[10] ^ W[4] ^ W[2];
        W[18] = ((n << 1) | (n >> 31));
        n = W[16] ^ W[11] ^ W[5] ^ W[3];
        W[19] = ((n << 1) | (n >> 31));
        n = W[17] ^ W[12] ^ W[6] ^ W[4];
        W[20] = ((n << 1) | (n >> 31));
        n = W[18] ^ W[13] ^ W[7] ^ W[5];
        W[21] = ((n << 1) | (n >> 31));
        n = W[19] ^ W[14] ^ W[8] ^ W[6];
        W[22] = ((n << 1) | (n >> 31));
        n = W[20] ^ W[15] ^ W[9] ^ W[7];
        W[23] = ((n << 1) | (n >> 31));
        n = W[21] ^ W[16] ^ W[10] ^ W[8];
        W[24] = ((n << 1) | (n >> 31));
        n = W[22] ^ W[17] ^ W[11] ^ W[9];
        W[25] = ((n << 1) | (n >> 31));
        n = W[23] ^ W[18] ^ W[12] ^ W[10];
        W[26] = ((n << 1) | (n >> 31));
        n = W[24] ^ W[19] ^ W[13] ^ W[11];
        W[27] = ((n << 1) | (n >> 31));
        n = W[25] ^ W[20] ^ W[14] ^ W[12];
        W[28] = ((n << 1) | (n >> 31));
        n = W[26] ^ W[21] ^ W[15] ^ W[13];
        W[29] = ((n << 1) | (n >> 31));
        n = W[27] ^ W[22] ^ W[16] ^ W[14];
        W[30] = ((n << 1) | (n >> 31));
        n = W[28] ^ W[23] ^ W[17] ^ W[15];
        W[31] = ((n << 1) | (n >> 31));
        n = W[29] ^ W[24] ^ W[18] ^ W[16];
        W[32] = ((n << 1) | (n >> 31));
        n = W[30] ^ W[25] ^ W[19] ^ W[17];
        W[33] = ((n << 1) | (n >> 31));
        n = W[31] ^ W[26] ^ W[20] ^ W[18];
        W[34] = ((n << 1) | (n >> 31));
        n = W[32] ^ W[27] ^ W[21] ^ W[19];
        W[35] = ((n << 1) | (n >> 31));
        n = W[33] ^ W[28] ^ W[22] ^ W[20];
        W[36] = ((n << 1) | (n >> 31));
        n = W[34] ^ W[29] ^ W[23] ^ W[21];
        W[37] = ((n << 1) | (n >> 31));
        n = W[35] ^ W[30] ^ W[24] ^ W[22];
        W[38] = ((n << 1) | (n >> 31));
        n = W[36] ^ W[31] ^ W[25] ^ W[23];
        W[39] = ((n << 1) | (n >> 31));
        n = W[37] ^ W[32] ^ W[26] ^ W[24];
        W[40] = ((n << 1) | (n >> 31));
        n = W[38] ^ W[33] ^ W[27] ^ W[25];
        W[41] = ((n << 1) | (n >> 31));
        n = W[39] ^ W[34] ^ W[28] ^ W[26];
        W[42] = ((n << 1) | (n >> 31));
        n = W[40] ^ W[35] ^ W[29] ^ W[27];
        W[43] = ((n << 1) | (n >> 31));
        n = W[41] ^ W[36] ^ W[30] ^ W[28];
        W[44] = ((n << 1) | (n >> 31));
        n = W[42] ^ W[37] ^ W[31] ^ W[29];
        W[45] = ((n << 1) | (n >> 31));
        n = W[43] ^ W[38] ^ W[32] ^ W[30];
        W[46] = ((n << 1) | (n >> 31));
        n = W[44] ^ W[39] ^ W[33] ^ W[31];
        W[47] = ((n << 1) | (n >> 31));
        n = W[45] ^ W[40] ^ W[34] ^ W[32];
        W[48] = ((n << 1) | (n >> 31));
        n = W[46] ^ W[41] ^ W[35] ^ W[33];
        W[49] = ((n << 1) | (n >> 31));
        n = W[47] ^ W[42] ^ W[36] ^ W[34];
        W[50] = ((n << 1) | (n >> 31));
        n = W[48] ^ W[43] ^ W[37] ^ W[35];
        W[51] = ((n << 1) | (n >> 31));
        n = W[49] ^ W[44] ^ W[38] ^ W[36];
        W[52] = ((n << 1) | (n >> 31));
        n = W[50] ^ W[45] ^ W[39] ^ W[37];
        W[53] = ((n << 1) | (n >> 31));
        n = W[51] ^ W[46] ^ W[40] ^ W[38];
        W[54] = ((n << 1) | (n >> 31));
        n = W[52] ^ W[47] ^ W[41] ^ W[39];
        W[55] = ((n << 1) | (n >> 31));
        n = W[53] ^ W[48] ^ W[42] ^ W[40];
        W[56] = ((n << 1) | (n >> 31));
        n = W[54] ^ W[49] ^ W[43] ^ W[41];
        W[57] = ((n << 1) | (n >> 31));
        n = W[55] ^ W[50] ^ W[44] ^ W[42];
        W[58] = ((n << 1) | (n >> 31));
        n = W[56] ^ W[51] ^ W[45] ^ W[43];
        W[59] = ((n << 1) | (n >> 31));
        n = W[57] ^ W[52] ^ W[46] ^ W[44];
        W[60] = ((n << 1) | (n >> 31));
        n = W[58] ^ W[53] ^ W[47] ^ W[45];
        W[61] = ((n << 1) | (n >> 31));
        n = W[59] ^ W[54] ^ W[48] ^ W[46];
        W[62] = ((n << 1) | (n >> 31));
        n = W[60] ^ W[55] ^ W[49] ^ W[47];
        W[63] = ((n << 1) | (n >> 31));
        n = W[61] ^ W[56] ^ W[50] ^ W[48];
        W[64] = ((n << 1) | (n >> 31));
        n = W[62] ^ W[57] ^ W[51] ^ W[49];
        W[65] = ((n << 1) | (n >> 31));
        n = W[63] ^ W[58] ^ W[52] ^ W[50];
        W[66] = ((n << 1) | (n >> 31));
        n = W[64] ^ W[59] ^ W[53] ^ W[51];
        W[67] = ((n << 1) | (n >> 31));
        n = W[65] ^ W[60] ^ W[54] ^ W[52];
        W[68] = ((n << 1) | (n >> 31));
        n = W[66] ^ W[61] ^ W[55] ^ W[53];
        W[69] = ((n << 1) | (n >> 31));
        n = W[67] ^ W[62] ^ W[56] ^ W[54];
        W[70] = ((n << 1) | (n >> 31));
        n = W[68] ^ W[63] ^ W[57] ^ W[55];
        W[71] = ((n << 1) | (n >> 31));
        n = W[69] ^ W[64] ^ W[58] ^ W[56];
        W[72] = ((n << 1) | (n >> 31));
        n = W[70] ^ W[65] ^ W[59] ^ W[57];
        W[73] = ((n << 1) | (n >> 31));
        n = W[71] ^ W[66] ^ W[60] ^ W[58];
        W[74] = ((n << 1) | (n >> 31));
        n = W[72] ^ W[67] ^ W[61] ^ W[59];
        W[75] = ((n << 1) | (n >> 31));
        n = W[73] ^ W[68] ^ W[62] ^ W[60];
        W[76] = ((n << 1) | (n >> 31));
        n = W[74] ^ W[69] ^ W[63] ^ W[61];
        W[77] = ((n << 1) | (n >> 31));
        n = W[75] ^ W[70] ^ W[64] ^ W[62];
        W[78] = ((n << 1) | (n >> 31));
        n = W[76] ^ W[71] ^ W[65] ^ W[63];
        W[79] = ((n << 1) | (n >> 31));

        A = H0;
        B = H1;
        C = H2;
        D = H3;
        E = H4;

        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[0] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[1] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[2] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[3] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[4] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[5] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[6] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[7] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[8] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[9] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[10] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[11] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[12] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[13] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[14] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[15] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[16] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[17] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[18] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (~B & D)) + E + W[19] + 0x5A827999) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;

        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[20] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[21] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[22] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[23] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[24] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[25] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[26] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[27] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[28] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[29] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[30] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[31] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[32] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[33] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[34] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[35] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[36] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[37] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[38] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[39] + 0x6ED9EBA1) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;

        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[40] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[41] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[42] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[43] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[44] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[45] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[46] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[47] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[48] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[49] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[50] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[51] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[52] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[53] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[54] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[55] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[56] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[57] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[58] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + ((B & C) | (B & D) | (C & D)) + E + W[59] + 0x8F1BBCDC) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;

        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[60] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[61] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[62] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[63] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[64] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[65] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[66] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[67] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[68] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[69] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[70] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[71] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[72] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[73] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[74] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[75] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[76] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[77] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[78] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;
        temp = (((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + W[79] + 0xCA62C1D6) & 0x0ffffffff;
        E = D;
        D = C;
        C = (B << 30) | (B >> 2);
        B = A;
        A = temp;

        // overflow
        H0 += A;
        H1 += B;
        H2 += C;
        H3 += D;
        H4 += E;
    }

    delete[] word_array;

    memory_buffer[max_data + 4] = H0 >> 24;
    memory_buffer[max_data + 5] = (H0 >> 16) & 0xff;
    memory_buffer[max_data + 6] = (H0 >> 8) & 0xff;
    memory_buffer[max_data + 7] = H0 & 0xff;

    memory_buffer[max_data + 8] = H1 >> 24;
    memory_buffer[max_data + 9] = (H1 >> 16) & 0xff;
    memory_buffer[max_data + 10] = (H1 >> 8) & 0xff;
    memory_buffer[max_data + 11] = H1 & 0xff;

    memory_buffer[max_data + 12] = H2 >> 24;
    memory_buffer[max_data + 13] = (H2 >> 16) & 0xff;
    memory_buffer[max_data + 14] = (H2 >> 8) & 0xff;
    memory_buffer[max_data + 15] = H2 & 0xff;

    memory_buffer[max_data + 16] = H3 >> 24;
    memory_buffer[max_data + 17] = (H3 >> 16) & 0xff;
    memory_buffer[max_data + 18] = (H3 >> 8) & 0xff;
    memory_buffer[max_data + 19] = H3 & 0xff;

    memory_buffer[max_data + 20] = H4 >> 24;
    memory_buffer[max_data + 21] = (H4 >> 16) & 0xff;
    memory_buffer[max_data + 22] = (H4 >> 8) & 0xff;
    memory_buffer[max_data + 23] = H4 & 0xff;
}
}
/*
int main()
{
    uint8_t result[20];

    uint8_t src[] = {98};

    sha1(src, 0, result);

    char res[41];
    for (int i = 0; i < 20; ++i)
        sprintf(res + i * 2, "%02x", (int32_t)result[i]);

    res[40] = '\0';
    std::cout << res << std::endl;
}
*/