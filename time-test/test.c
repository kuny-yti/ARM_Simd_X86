#include <stdio.h>
#include <time.h>
#include "test.h"

#ifndef X86_TEST
#include <avx2neon.h>
#else
#include <immintrin.h>
#endif

#define LOOP_CNT	10000
#define FUNC_CNT	10
int i = 0;

unsigned long long GetClockBootTime()
{
    unsigned long long res;
    struct timespec ts;
    if (0 != clock_gettime(CLOCK_MONOTONIC, &ts)) {
		printf("erro\n");
        return 0;
    }
	res = (ts.tv_sec * 1000000000ull + ts.tv_nsec);
    return res;
}

unsigned long long GetClockBootTimeDelta()
{
    unsigned long long delta = 0;
    unsigned long long start = GetClockBootTime();
    unsigned long long now = 0;
    for (i = 0; i < 32; i++) {
        now = GetClockBootTime();
        delta += (now - start);
        start = now;
    }
    delta >>= 5;

    return delta;
}

char res[1024];
char a[1024];
char b[1024];
char c[1024];

void init_data()
{
	for (i = 0; i < 512; i++) {
		res[i] = i;
		a[i] = i;
		b[i] = i;
		c[i] = i;
	}
}

int test_mm_cmpestrs()
{
    __m128i X;
    __m128i Y;
    int r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmpestrs(X, i, Y,i, 0);
        r = _mm_cmpestrs(X, i, Y,i, 1);
        r = _mm_cmpestrs(X, i, Y,i, 2);
        r = _mm_cmpestrs(X, i, Y,i, 4);
        r = _mm_cmpestrs(X, i, Y,i, 5);
        r = _mm_cmpestrs(X, i, Y,i, 6);
        r = _mm_cmpestrs(X, i, Y,i, 1);
        r = _mm_cmpestrs(X, i, Y,i, 2);
        r = _mm_cmpestrs(X, i, Y,i, 5);
        r = _mm_cmpestrs(X, i, Y,i, 6);
    }
    return 0;
}
int test_mm_cmpestrz()
{
    __m128i X;
    __m128i Y;
    int r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmpestrz(X, i, Y,i, 0);
        r = _mm_cmpestrz(X, i, Y,i, 1);
        r = _mm_cmpestrz(X, i, Y,i, 2);
        r = _mm_cmpestrz(X, i, Y,i, 4);
        r = _mm_cmpestrz(X, i, Y,i, 5);
        r = _mm_cmpestrz(X, i, Y,i, 6);
        r = _mm_cmpestrz(X, i, Y,i, 1);
        r = _mm_cmpestrz(X, i, Y,i, 2);
        r = _mm_cmpestrz(X, i, Y,i, 5);
        r = _mm_cmpestrz(X, i, Y,i, 6);
    }
    return 0;
}
int test_mm_cmpistrs()
{
    __m128i X;
    __m128i Y;
    int r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmpistrs(X, Y, 0);
        r = _mm_cmpistrs(X, Y,  1);
        r = _mm_cmpistrs(X, Y,  2);
        r = _mm_cmpistrs(X, Y,  4);
        r = _mm_cmpistrs(X, Y,  5);
        r = _mm_cmpistrs(X, Y,  6);
        r = _mm_cmpistrs(X, Y,  1);
        r = _mm_cmpistrs(X, Y,  2);
        r = _mm_cmpistrs(X, Y,  5);
        r = _mm_cmpistrs(X, Y,  6);
    }
    return 0;
}
int test_mm_cmpistrz()
{
    __m128i X;
    __m128i Y;
    int r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmpistrz(X, Y, 0);
        r = _mm_cmpistrz(X, Y,  1);
        r = _mm_cmpistrz(X, Y,  2);
        r = _mm_cmpistrz(X, Y,  4);
        r = _mm_cmpistrz(X, Y,  5);
        r = _mm_cmpistrz(X, Y,  6);
        r = _mm_cmpistrz(X, Y,  1);
        r = _mm_cmpistrz(X, Y,  2);
        r = _mm_cmpistrz(X, Y,  5);
        r = _mm_cmpistrz(X, Y,  6);
    }
    return 0;
}

int test_mm_cmp_epi16_mask()
{
    __m128i X;
    __m128i Y;
    __mmask8 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmp_epi16_mask(X, Y, 0);
        r = _mm_cmp_epi16_mask(X, Y, 1);
        r = _mm_cmp_epi16_mask(X, Y, 2);
        r = _mm_cmp_epi16_mask(X, Y, 4);
        r = _mm_cmp_epi16_mask(X, Y, 5);
        r = _mm_cmp_epi16_mask(X, Y, 6);
        r = _mm_cmp_epi16_mask(X, Y, 1);
        r = _mm_cmp_epi16_mask(X, Y, 2);
        r = _mm_cmp_epi16_mask(X, Y, 5);
        r = _mm_cmp_epi16_mask(X, Y, 6);
    }
    return 0;
}
int test_mm_mask_cmp_epi16_mask()
{
    __m128i X;
    __m128i Y;
    __mmask8 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 0);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 1);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 2);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 4);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 5);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 6);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 1);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 2);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 5);
        r = _mm_mask_cmp_epi16_mask((__mmask8)i, X, Y, 6);
    }
    return 0;
}
int test_mm256_cmp_epi16_mask()
{
    __m256i X;
    __m256i Y;
    __mmask16 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm256_cmp_epi16_mask(X, Y, 0);
        r = _mm256_cmp_epi16_mask(X, Y, 1);
        r = _mm256_cmp_epi16_mask(X, Y, 2);
        r = _mm256_cmp_epi16_mask(X, Y, 4);
        r = _mm256_cmp_epi16_mask(X, Y, 5);
        r = _mm256_cmp_epi16_mask(X, Y, 6);
        r = _mm256_cmp_epi16_mask(X, Y, 1);
        r = _mm256_cmp_epi16_mask(X, Y, 2);
        r = _mm256_cmp_epi16_mask(X, Y, 5);
        r = _mm256_cmp_epi16_mask(X, Y, 6);
    }
    return 0;
}
int test_mm256_mask_cmp_epi16_mask()
{
    __m256i X;
    __m256i Y;
    __mmask16 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 0);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 1);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 2);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 4);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 5);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 6);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 1);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 2);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 5);
        r = _mm256_mask_cmp_epi16_mask((__mmask16)i, X, Y, 6);
    }
    return 0;
}
int test_mm512_cmp_epi16_mask()
{
    __m512i X;
    __m512i Y;
    __mmask32 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm512_cmp_epi16_mask(X, Y, 0);
        r = _mm512_cmp_epi16_mask(X, Y, 1);
        r = _mm512_cmp_epi16_mask(X, Y, 2);
        r = _mm512_cmp_epi16_mask(X, Y, 4);
        r = _mm512_cmp_epi16_mask(X, Y, 5);
        r = _mm512_cmp_epi16_mask(X, Y, 6);
        r = _mm512_cmp_epi16_mask(X, Y, 1);
        r = _mm512_cmp_epi16_mask(X, Y, 2);
        r = _mm512_cmp_epi16_mask(X, Y, 5);
        r = _mm512_cmp_epi16_mask(X, Y, 6);
    }
    return 0;
}
int test_mm512_mask_cmp_epi16_mask()
{
    __m512i X;
    __m512i Y;
    __mmask32 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 0);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 1);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 2);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 4);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 5);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 6);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 1);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 2);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 5);
        r = _mm512_mask_cmp_epi16_mask((__mmask32)i, X, Y, 6);
    }
    return 0;
}

int test_mm_cmp_epi32_mask()
{
    __m128i X;
    __m128i Y;
    __mmask8 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmp_epi32_mask(X, Y, 0);
        r = _mm_cmp_epi32_mask(X, Y, 1);
        r = _mm_cmp_epi32_mask(X, Y, 2);
        r = _mm_cmp_epi32_mask(X, Y, 4);
        r = _mm_cmp_epi32_mask(X, Y, 5);
        r = _mm_cmp_epi32_mask(X, Y, 6);
        r = _mm_cmp_epi32_mask(X, Y, 1);
        r = _mm_cmp_epi32_mask(X, Y, 2);
        r = _mm_cmp_epi32_mask(X, Y, 5);
        r = _mm_cmp_epi32_mask(X, Y, 6);
    }
    return 0;
}
int test_mm_mask_cmp_epi32_mask()
{
    __m128i X;
    __m128i Y;
    __mmask8 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 0);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 1);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 2);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 4);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 5);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 6);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 1);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 2);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 5);
        r = _mm_mask_cmp_epi32_mask((__mmask8)i, X, Y, 6);
    }
    return 0;
}
int test_mm256_cmp_epi32_mask()
{
    __m256i X;
    __m256i Y;
    __mmask16 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm256_cmp_epi32_mask(X, Y, 0);
        r = _mm256_cmp_epi32_mask(X, Y, 1);
        r = _mm256_cmp_epi32_mask(X, Y, 2);
        r = _mm256_cmp_epi32_mask(X, Y, 4);
        r = _mm256_cmp_epi32_mask(X, Y, 5);
        r = _mm256_cmp_epi32_mask(X, Y, 6);
        r = _mm256_cmp_epi32_mask(X, Y, 1);
        r = _mm256_cmp_epi32_mask(X, Y, 2);
        r = _mm256_cmp_epi32_mask(X, Y, 5);
        r = _mm256_cmp_epi32_mask(X, Y, 6);
    }
    return 0;
}
int test_mm256_mask_cmp_epi32_mask()
{
    __m256i X;
    __m256i Y;
    __mmask16 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 0);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 1);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 2);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 4);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 5);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 6);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 1);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 2);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 5);
        r = _mm256_mask_cmp_epi32_mask((__mmask16)i, X, Y, 6);
    }
    return 0;
}
int test_mm512_cmp_epi32_mask()
{
    __m512i X;
    __m512i Y;
    __mmask32 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm512_cmp_epi32_mask(X, Y, 0);
        r = _mm512_cmp_epi32_mask(X, Y, 1);
        r = _mm512_cmp_epi32_mask(X, Y, 2);
        r = _mm512_cmp_epi32_mask(X, Y, 4);
        r = _mm512_cmp_epi32_mask(X, Y, 5);
        r = _mm512_cmp_epi32_mask(X, Y, 6);
        r = _mm512_cmp_epi32_mask(X, Y, 1);
        r = _mm512_cmp_epi32_mask(X, Y, 2);
        r = _mm512_cmp_epi32_mask(X, Y, 5);
        r = _mm512_cmp_epi32_mask(X, Y, 6);
    }
    return 0;
}
int test_mm512_mask_cmp_epi32_mask()
{
    __m512i X;
    __m512i Y;
    __mmask32 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 0);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 1);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 2);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 4);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 5);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 6);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 1);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 2);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 5);
        r = _mm512_mask_cmp_epi32_mask((__mmask32)i, X, Y, 6);
    }
    return 0;
}

int test_mm_cmp_epi64_mask()
{
    __m128i X;
    __m128i Y;
    __mmask8 r;

    for (i = 0; i < LOOP_CNT; ++i) {
        r = _mm_cmp_epi64_mask(X, Y, 0);
        r = _mm_cmp_epi64_mask(X, Y, 1);
        r = _mm_cmp_epi64_mask(X, Y, 2);
        r = _mm_cmp_epi64_mask(X, Y, 4);
        r = _mm_cmp_epi64_mask(X, Y, 5);
        r = _mm_cmp_epi64_mask(X, Y, 6);
        r = _mm_cmp_epi64_mask(X, Y, 1);
        r = _mm_cmp_epi64_mask(X, Y, 2);
        r = _mm_cmp_epi64_mask(X, Y, 5);
        r = _mm_cmp_epi64_mask(X, Y, 6);
    }
    return 0;
}

int test_mm_mask_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm_mask_cmp_epi64_mask(0, __X, __Y,0);
        r = _mm_mask_cmp_epi64_mask(0, __X, __Y, 1);
        r = _mm_mask_cmp_epi64_mask(0, __X, __Y, 2);
        r = _mm_mask_cmp_epi64_mask(0, __X, __Y, 4);
        r = _mm_mask_cmp_epi64_mask(0, __X, __Y, 5);
        r = _mm_mask_cmp_epi64_mask(0, __X, __Y, 6);
    }
    return TRUE;
}
int test_mm256_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm256_cmp_epi64_mask(__X, __Y, 0);
        r = _mm256_cmp_epi64_mask(__X, __Y, 1);
        r = _mm256_cmp_epi64_mask(__X, __Y, 2);
        r = _mm256_cmp_epi64_mask(__X, __Y, 4);
        r = _mm256_cmp_epi64_mask(__X, __Y, 5);
        r = _mm256_cmp_epi64_mask(__X, __Y, 6);
    }
    return TRUE;

}
int test_mm256_mask_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm256_mask_cmp_epi64_mask(0, __X, __Y,0);
        r = _mm256_mask_cmp_epi64_mask(0, __X, __Y, 1);
        r = _mm256_mask_cmp_epi64_mask(0, __X, __Y, 2);
        r = _mm256_mask_cmp_epi64_mask(0, __X, __Y, 4);
        r = _mm256_mask_cmp_epi64_mask(0, __X, __Y, 5);
        r = _mm256_mask_cmp_epi64_mask(0, __X, __Y, 6);
    }
    return TRUE;

}
int test_mm512_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm512_cmp_epi64_mask(__X, __Y, 0);
        r = _mm512_cmp_epi64_mask(__X, __Y, 1);
        r = _mm512_cmp_epi64_mask(__X, __Y, 2);
        r = _mm512_cmp_epi64_mask(__X, __Y, 4);
        r = _mm512_cmp_epi64_mask(__X, __Y, 5);
        r = _mm512_cmp_epi64_mask(__X, __Y, 6);
    }
    return TRUE;

}

int test_mm_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask16        r = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm_cmp_epu8_mask(__X, __Y, 0);
        r = _mm_cmp_epu8_mask(__X, __Y, 1);
        r = _mm_cmp_epu8_mask(__X, __Y, 2);
        r = _mm_cmp_epu8_mask(__X, __Y, 4);
        r = _mm_cmp_epu8_mask(__X, __Y, 5);
        r = _mm_cmp_epu8_mask(__X, __Y, 6);
    }
    return TRUE;

}
int test_mm_mask_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask16        r = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm_mask_cmp_epu8_mask(0, __X, __Y, 0);
        r = _mm_mask_cmp_epu8_mask(0, __X, __Y, 1);
        r = _mm_mask_cmp_epu8_mask(0, __X, __Y, 2);
        r = _mm_mask_cmp_epu8_mask(0, __X, __Y, 4);
        r = _mm_mask_cmp_epu8_mask(0, __X, __Y, 5);
        r = _mm_mask_cmp_epu8_mask(0, __X, __Y, 6);
    }
    return TRUE;
}
int test_mm256_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask32        r = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm256_cmp_epu8_mask(__X, __Y, 0);
        r = _mm256_cmp_epu8_mask(__X, __Y, 1);
        r = _mm256_cmp_epu8_mask(__X, __Y, 2);
        r = _mm256_cmp_epu8_mask(__X, __Y, 4);
        r = _mm256_cmp_epu8_mask(__X, __Y, 5);
        r = _mm256_cmp_epu8_mask(__X, __Y, 6);
    }
    return TRUE;
}
int test_mm256_mask_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask32        r = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm256_mask_cmp_epu8_mask(0, __X, __Y, 0);
        r = _mm256_mask_cmp_epu8_mask(0, __X, __Y, 1);
        r = _mm256_mask_cmp_epu8_mask(0, __X, __Y, 2);
        r = _mm256_mask_cmp_epu8_mask(0, __X, __Y, 4);
        r = _mm256_mask_cmp_epu8_mask(0, __X, __Y, 5);
        r = _mm256_mask_cmp_epu8_mask(0, __X, __Y, 6);
    }
    return TRUE;
}
int test_mm512_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask64        r = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm512_cmp_epu8_mask(__X, __Y, 0);
        r = _mm512_cmp_epu8_mask(__X, __Y, 1);
        r = _mm512_cmp_epu8_mask(__X, __Y, 2);
        r = _mm512_cmp_epu8_mask(__X, __Y, 4);
        r = _mm512_cmp_epu8_mask(__X, __Y, 5);
        r = _mm512_cmp_epu8_mask(__X, __Y, 6);
    }
    return TRUE;
}
int test_mm512_mask_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask64        r = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < LOOP_CNT; ++i)
    {
        r = _mm512_mask_cmp_epu8_mask(0, __X, __Y, 0);
        r = _mm512_mask_cmp_epu8_mask(0, __X, __Y, 1);
        r = _mm512_mask_cmp_epu8_mask(0, __X, __Y, 2);
        r = _mm512_mask_cmp_epu8_mask(0, __X, __Y, 4);
        r = _mm512_mask_cmp_epu8_mask(0, __X, __Y, 5);
        r = _mm512_mask_cmp_epu8_mask(0, __X, __Y, 6);
    }
    return TRUE;
}

#define mmCmpPD(X, Y, O, I)\
    O = _mm_cmp_pd(X, Y, I);
int test_mm_cmp_pd()
{
    unsigned int i = 0;
    __m128d __X;
    __m128d __Y;
    __m128d __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD

#define mmCmpPD(X, Y, O, I)\
    O = _mm256_cmp_pd(X, Y, I);
int test_mm256_cmp_pd()
{
    unsigned int i = 0;
    __m256d __X;
    __m256d __Y;
    __m256d __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD

#define mmCmpPD(X, Y, O, I)\
    O = _mm_cmp_pd_mask(X, Y, I);
int test_mm_cmp_pd_mask()
{
    unsigned int i = 0;
    __m128d __X;
    __m128d __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}

#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm_mask_cmp_pd_mask(0, X, Y, I);
int test_mm_mask_cmp_pd_mask()
{
    unsigned int i = 0;
    __m128d __X;
    __m128d __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}

#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm256_cmp_pd_mask(X, Y, I);
int test_mm256_cmp_pd_mask()
{
    unsigned int i = 0;
    __m256d __X;
    __m256d __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm256_mask_cmp_pd_mask(0, X, Y, I);
int test_mm256_mask_cmp_pd_mask()
{
    unsigned int i = 0;
    __m256d __X;
    __m256d __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm512_cmp_pd_mask(X, Y, I);
int test_mm512_cmp_pd_mask()
{
    unsigned int i = 0;
    __m512d __X;
    __m512d __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm512_mask_cmp_pd_mask(0, X, Y, I);
int test_mm512_mask_cmp_pd_mask()
{
    unsigned int i = 0;
    __m512d __X;
    __m512d __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD

#define mmCmpPD(X, Y, O, I)\
    O = _mm_cmp_ps(X, Y, I);
int test_mm_cmp_ps()
{
    unsigned int i = 0;
    __m128 __X;
    __m128 __Y;
    __m128 __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD

#define mmCmpPD(X, Y, O, I)\
    O = _mm256_cmp_ps(X, Y, I);
int test_mm256_cmp_ps()
{
    unsigned int i = 0;
    __m256 __X;
    __m256 __Y;
    __m256 __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD

#define mmCmpPD(X, Y, O, I)\
    O = _mm_cmp_ps_mask(X, Y, I);
int test_mm_cmp_ps_mask()
{
    unsigned int i = 0;
    __m128 __X;
    __m128 __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}

#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm_mask_cmp_ps_mask(0, X, Y, I);
int test_mm_mask_cmp_ps_mask()
{
    unsigned int i = 0;
    __m128 __X;
    __m128 __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}

#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm256_cmp_ps_mask(X, Y, I);
int test_mm256_cmp_ps_mask()
{
    unsigned int i = 0;
    __m256 __X;
    __m256 __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm256_mask_cmp_ps_mask(0, X, Y, I);
int test_mm256_mask_cmp_ps_mask()
{
    unsigned int i = 0;
    __m256 __X;
    __m256 __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm512_cmp_ps_mask(X, Y, I);
int test_mm512_cmp_ps_mask()
{
    unsigned int i = 0;
    __m512 __X;
    __m512 __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
#define mmCmpPD(X, Y, O, I)\
    O = _mm512_mask_cmp_ps_mask(0, X, Y, I);
int test_mm512_mask_cmp_ps_mask()
{
    unsigned int i = 0;
    __m512 __X;
    __m512 __Y;
    unsigned char __O;
    for (i = 0; i < LOOP_CNT; ++i)
    {
        mmCmpPD(__X, __Y, __O, 0);
        mmCmpPD(__X, __Y, __O, 1);
        mmCmpPD(__X, __Y, __O, 2);
        mmCmpPD(__X, __Y, __O, 3);
        mmCmpPD(__X, __Y, __O, 4);
        mmCmpPD(__X, __Y, __O, 5);
        mmCmpPD(__X, __Y, __O, 6);
        mmCmpPD(__X, __Y, __O, 7);
        mmCmpPD(__X, __Y, __O, 8);
        mmCmpPD(__X, __Y, __O, 9);
        mmCmpPD(__X, __Y, __O, 10);
        mmCmpPD(__X, __Y, __O, 11);
        mmCmpPD(__X, __Y, __O, 12);
        mmCmpPD(__X, __Y, __O, 13);
        mmCmpPD(__X, __Y, __O, 14);
        mmCmpPD(__X, __Y, __O, 15);
        mmCmpPD(__X, __Y, __O, 16);
        mmCmpPD(__X, __Y, __O, 17);
        mmCmpPD(__X, __Y, __O, 18);
        mmCmpPD(__X, __Y, __O, 19);
        mmCmpPD(__X, __Y, __O, 20);
        mmCmpPD(__X, __Y, __O, 21);
        mmCmpPD(__X, __Y, __O, 22);
        mmCmpPD(__X, __Y, __O, 23);
        mmCmpPD(__X, __Y, __O, 24);
        mmCmpPD(__X, __Y, __O, 25);
        mmCmpPD(__X, __Y, __O, 26);
        mmCmpPD(__X, __Y, __O, 27);
        mmCmpPD(__X, __Y, __O, 28);
        mmCmpPD(__X, __Y, __O, 29);
        mmCmpPD(__X, __Y, __O, 30);
        mmCmpPD(__X, __Y, __O, 31);
    }
    return TRUE;
}
#undef mmCmpPD
void RunTest(InstructionTest test)
{
	unsigned long long delta = 0, start = 0, end = 0, time = 0;
	const char *ret = "UNKNOWN!";
	delta = GetClockBootTimeDelta();
	start = GetClockBootTime();
    switch (test) {
    case UT_MM_CMPESTRS:
        ret = "MM_CMPESTRS";
        test_mm_cmpestrs();
        break;
    case UT_MM_CMPESTRZ:
        ret = "MM_CMPESTRZ";
        test_mm_cmpestrz();
        break;
    case UT_MM_CMPISTRS:
        ret = "MM_CMPISTRS";
        test_mm_cmpistrs();
        break;
    case UT_MM_CMPISTRZ:
        ret = "MM_CMPISTRZ";
        test_mm_cmpistrz();
        break;

    case UT_MM_CMP_EPI16_MASK:
        ret = "MM_CMP_EPI16_MASK";
        test_mm_cmp_epi16_mask();
        break;
    case UT_MM_MASK_CMP_EPI16_MASK:
        ret = "MM_MASK_CMP_EPI16_MASK";
        test_mm_mask_cmp_epi16_mask();
        break;
    case UT_MM256_CMP_EPI16_MASK:
        ret = "MM256_CMP_EPI16_MASK";
        test_mm256_cmp_epi16_mask();
        break;
    case UT_MM256_MASK_CMP_EPI16_MASK:
        ret = "MM256_MASK_CMP_EPI16_MASK";
        test_mm256_mask_cmp_epi16_mask();
        break;
    case UT_MM512_CMP_EPI16_MASK:
        ret = "MM512_CMP_EPI16_MASK";
        test_mm512_cmp_epi16_mask();
        break;
    case UT_MM512_MASK_CMP_EPI16_MASK:
        ret = "MM512_MASK_CMP_EPI16_MASK";
        test_mm512_mask_cmp_epi16_mask();
        break;

    case UT_MM_CMP_EPI32_MASK:
        ret = "MM_CMP_EPI32_MASK";
        test_mm_cmp_epi32_mask();
        break;
    case UT_MM_MASK_CMP_EPI32_MASK:
        ret = "MM_MASK_CMP_EPI32_MASK";
        test_mm_mask_cmp_epi32_mask();
        break;
    case UT_MM256_CMP_EPI32_MASK:
        ret = "MM256_CMP_EPI32_MASK";
        test_mm256_cmp_epi32_mask();
        break;
    case UT_MM256_MASK_CMP_EPI32_MASK:
        ret = "MM256_MASK_CMP_EPI32_MASK";
        test_mm256_mask_cmp_epi32_mask();
        break;
    case UT_MM512_CMP_EPI32_MASK:
        ret = "MM512_CMP_EPI32_MASK";
        test_mm512_cmp_epi32_mask();
        break;
    case UT_MM512_MASK_CMP_EPI32_MASK:
        ret = "MM512_MASK_CMP_EPI32_MASK";
        test_mm512_mask_cmp_epi32_mask();
        break;

    case UT_MM_CMP_EPI64_MASK:
        ret = "MM_CMP_EPI64_MASK";
        test_mm_cmp_epi64_mask();
        break;

    case UT_MM_MASK_CMP_EPI64_MASK:
        ret = "MM_MASK_CMP_EPI64_MASK";
        test_mm_mask_cmp_epi64_mask();
        break;
    case UT_MM256_CMP_EPI64_MASK:
        ret = "MM256_CMP_EPI64_MASK";
        test_mm256_cmp_epi64_mask();
        break;
    case UT_MM256_MASK_CMP_EPI64_MASK:
        ret = "MM256_MASK_CMP_EPI64_MASK";
        test_mm256_mask_cmp_epi64_mask();
        break;
    case UT_MM512_CMP_EPI64_MASK:
        ret = "MM512_CMP_EPI64_MASK";
        test_mm512_cmp_epi64_mask();
        break;
    case UT_MM_CMP_EPU8_MASK:
        ret = "MM_CMP_EPU8_MASK";
        test_mm_cmp_epu8_mask();
        break;
    case UT_MM_MASK_CMP_EPU8_MASK:
        ret = "MM_MASK_CMP_EPU8_MASK";
        test_mm_mask_cmp_epu8_mask();
        break;
    case UT_MM256_CMP_EPU8_MASK:
        ret = "MM256_CMP_EPU8_MASK";
        test_mm256_cmp_epu8_mask();
        break;
    case UT_MM256_MASK_CMP_EPU8_MASK:
        ret = "MM256_MASK_CMP_EPU8_MASK";
        test_mm256_mask_cmp_epu8_mask();
        break;
    case UT_MM512_CMP_EPU8_MASK:
        ret = "MM512_CMP_EPU8_MASK";
        test_mm512_cmp_epu8_mask();
        break;
    case UT_MM512_MASK_CMP_EPU8_MASK:
        ret = "MM512_MASK_CMP_EPU8_MASK";
        test_mm512_mask_cmp_epu8_mask();
        break;

    case UT_MM_CMP_PD:
        ret = "MM_CMP_PD";
        test_mm_cmp_pd();
        break;
    case UT_MM256_CMP_PD:
        ret = "MM256_CMP_PD";
        test_mm256_cmp_pd();
        break;
    case UT_MM_CMP_PD_MASK:
        ret = "MM_CMP_PD_MASK";
        test_mm_cmp_pd_mask();
        break;
    case UT_MM_MASK_CMP_PD_MASK:
        ret = "MM_MASK_CMP_PD_MASK";
        test_mm_mask_cmp_pd_mask();
        break;
    case UT_MM256_CMP_PD_MASK:
        ret = "MM256_CMP_PD_MASK";
        test_mm256_cmp_pd_mask();
        break;
    case UT_MM256_MASK_CMP_PD_MASK:
        ret = "MM256_MASK_CMP_PD_MASK";
        test_mm256_mask_cmp_pd_mask();
        break;
    case UT_MM512_CMP_PD_MASK:
        ret = "MM512_CMP_PD_MASK";
        test_mm512_cmp_pd_mask();
        break;

    case UT_MM512_MASK_CMP_PD_MASK:
        ret = "MM512_MASK_CMP_PD_MASK";
        test_mm512_mask_cmp_pd_mask();
        break;

    case  UT_MM_CMP_PS:
        ret = "MM_CMP_PS";
        test_mm_cmp_ps();
        break;

    case UT_MM256_CMP_PS:
        ret = "MM256_CMP_PS";
        test_mm256_cmp_ps();
        break;

    case  UT_MM_CMP_PS_MASK:
        ret = "MM_CMP_PS_MASK";
        test_mm_cmp_ps_mask();
        break;

    case  UT_MM_MASK_CMP_PS_MASK:
        ret = "MM_MASK_CMP_PS_MASK";
        test_mm_mask_cmp_ps_mask();
        break;

    case  UT_MM256_CMP_PS_MASK:
        ret = "MM256_CMP_PS_MASK";
        test_mm256_cmp_ps_mask();
        break;

    case UT_MM256_MASK_CMP_PS_MASK:
        ret = "MM256_MASK_CMP_PS_MASK";
        test_mm256_mask_cmp_ps_mask();
        break;

    case  UT_MM512_CMP_PS_MASK:
        ret = "MM512_CMP_PS_MASK";
        test_mm512_cmp_ps_mask();
        break;

    case UT_MM512_MASK_CMP_PS_MASK:
        ret = "MM512_MASK_CMP_PS_MASK";
        test_mm512_mask_cmp_ps_mask();
        break;
    default:
        break;
	}
	end = GetClockBootTime();
	time = end - start - delta;
	double average = 1.0 * time / 100000;
	printf("%s:  tick:%lld, time:%lf ns\n", ret, time, average);
}
