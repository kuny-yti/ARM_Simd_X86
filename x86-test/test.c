#include "test.h"
#include <immintrin.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "testdata.h"

int comp_return(const void *src, const void *dst, const unsigned long len)
{
    return (0 == memcmp(src, dst, len) ? TRUE : FALSE);
}

const char *RunTest(InstructionTest test, int *flag)
{
    const char *ret = "UNKNOWN!";
    switch (test) {
    case UT_MM_CMPESTRS:
        ret = "MM_CMPESTRS";
        *flag = test_mm_cmpestrs();
        break;
    case UT_MM_CMPESTRZ:
        ret = "MM_CMPESTRZ";
        *flag = test_mm_cmpestrz();
        break;
    case UT_MM_CMPISTRS:
        ret = "MM_CMPISTRS";
        *flag = test_mm_cmpistrs();
        break;
    case UT_MM_CMPISTRZ:
        ret = "MM_CMPISTRZ";
        *flag = test_mm_cmpistrz();
        break;

    case UT_MM_CMP_EPI16_MASK:
        ret = "MM_CMP_EPI16_MASK";
        *flag = test_mm_cmp_epi16_mask();
        break;
    case UT_MM_MASK_CMP_EPI16_MASK:
        ret = "MASK_CMP_EPI16_MASK";
        *flag = test_mm_mask_cmp_epi16_mask();
        break;
    case UT_MM256_CMP_EPI16_MASK:
        ret = "MM256_CMP_EPI16_MASK";
        *flag = test_mm256_cmp_epi16_mask();
        break;
    case UT_MM256_MASK_CMP_EPI16_MASK:
        ret = "MM256_MASK_CMP_EPI16_MASK";
        *flag = test_mm256_mask_cmp_epi16_mask();
        break;
    case UT_MM512_CMP_EPI16_MASK:
        ret = "MM512_CMP_EPI16_MASK";
        *flag = test_mm512_cmp_epi16_mask();
        break;
    case UT_MM512_MASK_CMP_EPI16_MASK:
        ret = "MM512_MASK_CMP_EPI16_MASK";
        *flag = test_mm512_mask_cmp_epi16_mask();
        break;

    case UT_MM_CMP_EPI32_MASK:
        ret = "MM_CMP_EPI32_MASK";
        *flag = test_mm_cmp_epi32_mask();
        break;
    case UT_MM_MASK_CMP_EPI32_MASK:
        ret = "MASK_CMP_EPI32_MASK";
        *flag = test_mm_mask_cmp_epi32_mask();
        break;
    case UT_MM256_CMP_EPI32_MASK:
        ret = "MM256_CMP_EPI32_MASK";
        *flag = test_mm256_cmp_epi32_mask();
        break;
    case UT_MM256_MASK_CMP_EPI32_MASK:
        ret = "MM256_MASK_CMP_EPI32_MASK";
        *flag = test_mm256_mask_cmp_epi32_mask();
        break;
    case UT_MM512_CMP_EPI32_MASK:
        ret = "MM512_CMP_EPI32_MASK";
        *flag = test_mm512_cmp_epi32_mask();
        break;
    case UT_MM512_MASK_CMP_EPI32_MASK:
        ret = "MM512_MASK_CMP_EPI32_MASK";
        *flag = test_mm512_mask_cmp_epi32_mask();
        break;

    case UT_MM_CMP_EPI64_MASK:
        ret = "MM_CMP_EPI64_MASK";
        *flag = test_mm_cmp_epi64_mask();
        break;

    case UT_MM_MASK_CMP_EPI64_MASK:
        ret = "MM_MASK_CMP_EPI64_MASK";
        *flag = test_mm_mask_cmp_epi64_mask();
        break;
    case UT_MM256_CMP_EPI64_MASK:
        ret = "MM256_CMP_EPI64_MASK";
        *flag = test_mm256_cmp_epi64_mask();
        break;
    case UT_MM256_MASK_CMP_EPI64_MASK:
        ret = "MM256_MASK_CMP_EPI64_MASK";
        *flag = test_mm256_mask_cmp_epi64_mask();
        break;
    case UT_MM512_CMP_EPI64_MASK:
        ret = "MM512_CMP_EPI64_MASK";
        *flag = test_mm512_cmp_epi64_mask();
        break;
    case UT_MM_CMP_EPU8_MASK:
        ret = "MM_CMP_EPU8_MASK";
        *flag = test_mm_cmp_epu8_mask();
        break;
    case UT_MM_MASK_CMP_EPU8_MASK:
        ret = "MM_MASK_CMP_EPU8_MASK";
        *flag = test_mm_mask_cmp_epu8_mask();
        break;
    case UT_MM256_CMP_EPU8_MASK:
        ret = "MM256_CMP_EPU8_MASK";
        *flag = test_mm256_cmp_epu8_mask();
        break;
    case UT_MM256_MASK_CMP_EPU8_MASK:
        ret = "MM256_MASK_CMP_EPU8_MASK";
        *flag = test_mm256_mask_cmp_epu8_mask();
        break;
    case UT_MM512_CMP_EPU8_MASK:
        ret = "MM512_CMP_EPU8_MASK";
        *flag = test_mm512_cmp_epu8_mask();
        break;
    case UT_MM512_MASK_CMP_EPU8_MASK:
        ret = "MM512_MASK_CMP_EPU8_MASK";
        *flag = test_mm512_mask_cmp_epu8_mask();
        break;

    case UT_MM_CMP_PD:
        ret = "MM_CMP_PD";
        *flag = test_mm_cmp_pd();
        break;
    case UT_MM256_CMP_PD:
        ret = "MM256_CMP_PD";
        *flag = test_mm256_cmp_pd();
        break;
    case UT_MM_CMP_PD_MASK:
        ret = "MM_CMP_PD_MASK";
        *flag = test_mm_cmp_pd_mask();
        break;
    case UT_MM_MASK_CMP_PD_MASK:
        ret = "MM_MASK_CMP_PD_MASK";
        *flag = test_mm_mask_cmp_pd_mask();
        break;
    case UT_MM256_CMP_PD_MASK:
        ret = "MM256_CMP_PD_MASK";
        *flag = test_mm256_cmp_pd_mask();
        break;
    case UT_MM256_MASK_CMP_PD_MASK:
        ret = "MM256_MASK_CMP_PD_MASK";
        *flag = test_mm256_mask_cmp_pd_mask();
        break;
    case UT_MM512_CMP_PD_MASK:
        ret = "MM512_CMP_PD_MASK";
        *flag = test_mm512_cmp_pd_mask();
        break;

    case UT_MM512_MASK_CMP_PD_MASK:
        ret = "MM512_MASK_CMP_PD_MASK";
        *flag = test_mm512_mask_cmp_pd_mask();
        break;

    case  UT_MM_CMP_PS:
        ret = "MM_CMP_PS";
        *flag = test_mm_cmp_ps();
        break;

    case UT_MM256_CMP_PS:
        ret = "MM256_CMP_PS";
        *flag = test_mm256_cmp_ps();
        break;

    case  UT_MM_CMP_PS_MASK:
        ret = "MM_CMP_PS_MASK";
        *flag = test_mm_cmp_ps_mask();
        break;

    case  UT_MM_MASK_CMP_PS_MASK:
        ret = "MM_MASK_CMP_PS_MASK";
        *flag = test_mm_mask_cmp_ps_mask();
        break;

    case  UT_MM256_CMP_PS_MASK:
        ret = "MM256_CMP_PS_MASK";
        *flag = test_mm256_cmp_ps_mask();
        break;

    case UT_MM256_MASK_CMP_PS_MASK:
        ret = "MM256_MASK_CMP_PS_MASK";
        *flag = test_mm256_mask_cmp_ps_mask();
        break;

    case  UT_MM512_CMP_PS_MASK:
        ret = "MM512_CMP_PS_MASK";
        *flag = test_mm512_cmp_ps_mask();
        break;

    case UT_MM512_MASK_CMP_PS_MASK:
        ret = "MM512_MASK_CMP_PS_MASK";
        *flag = test_mm512_mask_cmp_ps_mask();
        break;
    default:
        break;
    }
    return ret;
}

#define aSizeOf(B) (sizeof(B) / sizeof(B[0]))

int test_mm_cmpestrs()
{
    uint i = 0;
    int  expect = 0;

    __m128i __X;
    __m128i __Y;
    for (i = 0; i < aSizeOf(g_test_mm_cmpestrs_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmpestrs_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmpestrs_data[i].b, sizeof(__Y));
        expect = _mm_cmpestrs(__X, g_test_mm_cmpestrs_data[i].la,
                              __Y, g_test_mm_cmpestrs_data[i].lb, 1);
        if (expect != g_test_mm_cmpestrs_data[i].expect)
            return FALSE;
    }
    return TRUE;
}
int test_mm_cmpestrz()
{
    uint i = 0;
    int  expect = 0;

    __m128i __X;
    __m128i __Y;
    for (i = 0; i < aSizeOf(g_test_mm_cmpestrz_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmpestrz_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmpestrz_data[i].b, sizeof(__Y));
        expect = _mm_cmpestrz(__X, g_test_mm_cmpestrz_data[i].la,
                              __Y, g_test_mm_cmpestrz_data[i].lb, 1);

        if (expect != g_test_mm_cmpestrz_data[i].expect)
            return FALSE;
    }
    return TRUE;
}
int test_mm_cmpistrs()
{
    uint i = 0;
    int  expect = 0;

    __m128i __X ;
    __m128i __Y ;
    for (i = 0; i < aSizeOf(g_test_mm_cmpistrs_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmpistrs_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmpistrs_data[i].b, sizeof(__Y));
        expect = _mm_cmpistrs(__X, __Y, 1);

        if (expect != g_test_mm_cmpestrs_data[i].expect)
            return FALSE;
    }
    return TRUE;
}
int test_mm_cmpistrz()
{
    uint i = 0;
    int  expect = 0;

    __m128i __X;
    __m128i __Y;
    for (i = 0; i < aSizeOf(g_test_mm_cmpistrz_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmpistrz_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmpistrz_data[i].b, sizeof(__Y));
        expect = _mm_cmpistrz(__X, __Y, 1);

        if (expect != g_test_mm_cmpistrz_data[i].expect)
            return FALSE;
    }
    return TRUE;
}

int test_mm_cmp_epi16_mask()
{
    uint            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < aSizeOf(g_test_mm_cmp_epi16_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_epi16_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_epi16_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm_cmp_epi16_mask_data[i].expect;

        r = _mm_cmp_epi16_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm_cmp_epi16_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_cmp_epi16_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_cmp_epi16_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_cmp_epi16_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_cmp_epi16_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm_mask_cmp_epi16_mask()
{
    uint            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    const __mmask8 *mask = 0;
    __m128i __X ;
    __m128i __Y ;

    for (i = 0; i < aSizeOf(g_test_mm_mask_cmp_epi16_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_mask_cmp_epi16_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_mask_cmp_epi16_mask_data[i].b, sizeof(__Y));
        mask   = g_test_mm_mask_cmp_epi16_mask_data[i].mask;
        expect = g_test_mm_mask_cmp_epi16_mask_data[i].expect;

        r = _mm_mask_cmp_epi16_mask(mask[0], __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm_mask_cmp_epi16_mask(mask[1], __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_mask_cmp_epi16_mask(mask[2], __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_mask_cmp_epi16_mask(mask[3], __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_mask_cmp_epi16_mask(mask[4], __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_mask_cmp_epi16_mask(mask[5], __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm256_cmp_epi16_mask()
{
    uint             i = 0;
    __mmask16        r = 0;
    const __mmask16 *expect = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < aSizeOf(g_test_mm256_cmp_epi16_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_epi16_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_epi16_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm256_cmp_epi16_mask_data[i].expect;

        r = _mm256_cmp_epi16_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm256_cmp_epi16_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm256_cmp_epi16_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm256_cmp_epi16_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm256_cmp_epi16_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm256_cmp_epi16_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm256_mask_cmp_epi16_mask()
{
    uint            i = 0;
    __mmask16       r = 0;
    const __mmask16 *expect = 0;
    const __mmask16 *mask = 0;
    __m256i __X ;
    __m256i __Y ;

    for (i = 0; i < aSizeOf(g_test_mm256_mask_cmp_epi16_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_mask_cmp_epi16_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_mask_cmp_epi16_mask_data[i].b, sizeof(__Y));
        mask   = g_test_mm256_mask_cmp_epi16_mask_data[i].mask;
        expect = g_test_mm256_mask_cmp_epi16_mask_data[i].expect;

        r = _mm256_mask_cmp_epi16_mask(mask[0], __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm256_mask_cmp_epi16_mask(mask[1], __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm256_mask_cmp_epi16_mask(mask[2], __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm256_mask_cmp_epi16_mask(mask[3], __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm256_mask_cmp_epi16_mask(mask[4], __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm256_mask_cmp_epi16_mask(mask[5], __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm512_cmp_epi16_mask()
{
    uint             i = 0;
    __mmask32        r = 0;
    const __mmask32 *expect = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < aSizeOf(g_test_mm512_cmp_epi16_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_cmp_epi16_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_cmp_epi16_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm512_cmp_epi16_mask_data[i].expect;

        r = _mm512_cmp_epi16_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_cmp_epi16_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_cmp_epi16_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_cmp_epi16_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_cmp_epi16_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_cmp_epi16_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm512_mask_cmp_epi16_mask()
{
    uint            i = 0;
    __mmask32       r = 0;
    const __mmask32 *expect = 0;
    const __mmask32 *mask = 0;
    __m512i __X ;
    __m512i __Y ;

    for (i = 0; i < aSizeOf(g_test_mm512_mask_cmp_epi16_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_mask_cmp_epi16_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_mask_cmp_epi16_mask_data[i].b, sizeof(__Y));
        mask   = g_test_mm512_mask_cmp_epi16_mask_data[i].mask;
        expect = g_test_mm512_mask_cmp_epi16_mask_data[i].expect;

        r = _mm512_mask_cmp_epi16_mask(mask[0], __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_mask_cmp_epi16_mask(mask[1], __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_mask_cmp_epi16_mask(mask[2], __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_mask_cmp_epi16_mask(mask[3], __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_mask_cmp_epi16_mask(mask[4], __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_mask_cmp_epi16_mask(mask[5], __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}

int test_mm_cmp_epi32_mask()
{
    uint            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < aSizeOf(g_test_mm_cmp_epi32_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_epi32_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_epi32_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm_cmp_epi32_mask_data[i].expect;

        r = _mm_cmp_epi32_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm_cmp_epi32_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_cmp_epi32_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_cmp_epi32_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_cmp_epi32_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_cmp_epi32_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm_mask_cmp_epi32_mask()
{
    uint            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    const __mmask8 *mask = 0;
    __m128i __X ;
    __m128i __Y ;

    for (i = 0; i < aSizeOf(g_test_mm_mask_cmp_epi32_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_mask_cmp_epi32_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_mask_cmp_epi32_mask_data[i].b, sizeof(__Y));
        mask   = g_test_mm_mask_cmp_epi32_mask_data[i].mask;
        expect = g_test_mm_mask_cmp_epi32_mask_data[i].expect;

        r = _mm_mask_cmp_epi32_mask(mask[0], __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm_mask_cmp_epi32_mask(mask[1], __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_mask_cmp_epi32_mask(mask[2], __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_mask_cmp_epi32_mask(mask[3], __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_mask_cmp_epi32_mask(mask[4], __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_mask_cmp_epi32_mask(mask[5], __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm256_cmp_epi32_mask()
{
    uint             i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < aSizeOf(g_test_mm256_cmp_epi32_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_epi32_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_epi32_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm256_cmp_epi32_mask_data[i].expect;

        r = _mm256_cmp_epi32_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm256_cmp_epi32_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm256_cmp_epi32_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm256_cmp_epi32_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm256_cmp_epi32_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm256_cmp_epi32_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm256_mask_cmp_epi32_mask()
{
    uint            i = 0;
    __mmask8       r = 0;
    const __mmask8 *expect = 0;
    const __mmask8 *mask = 0;
    __m256i __X ;
    __m256i __Y ;

    for (i = 0; i < aSizeOf(g_test_mm256_mask_cmp_epi32_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_mask_cmp_epi32_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_mask_cmp_epi32_mask_data[i].b, sizeof(__Y));
        mask   = g_test_mm256_mask_cmp_epi32_mask_data[i].mask;
        expect = g_test_mm256_mask_cmp_epi32_mask_data[i].expect;

        r = _mm256_mask_cmp_epi32_mask(mask[0], __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm256_mask_cmp_epi32_mask(mask[1], __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm256_mask_cmp_epi32_mask(mask[2], __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm256_mask_cmp_epi32_mask(mask[3], __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm256_mask_cmp_epi32_mask(mask[4], __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm256_mask_cmp_epi32_mask(mask[5], __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm512_cmp_epi32_mask()
{
    uint             i = 0;
    __mmask16        r = 0;
    const __mmask16 *expect = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < aSizeOf(g_test_mm512_cmp_epi32_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_cmp_epi32_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_cmp_epi32_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm512_cmp_epi32_mask_data[i].expect;

        r = _mm512_cmp_epi32_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_cmp_epi32_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_cmp_epi32_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_cmp_epi32_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_cmp_epi32_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_cmp_epi32_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm512_mask_cmp_epi32_mask()
{
    uint            i = 0;
    __mmask16       r = 0;
    const __mmask16 *expect = 0;
    const __mmask16 *mask = 0;
    __m512i __X ;
    __m512i __Y ;

    for (i = 0; i < aSizeOf(g_test_mm512_mask_cmp_epi32_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_mask_cmp_epi32_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_mask_cmp_epi32_mask_data[i].b, sizeof(__Y));
        mask   = g_test_mm512_mask_cmp_epi32_mask_data[i].mask;
        expect = g_test_mm512_mask_cmp_epi32_mask_data[i].expect;

        r = _mm512_mask_cmp_epi32_mask(mask[0], __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_mask_cmp_epi32_mask(mask[1], __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_mask_cmp_epi32_mask(mask[2], __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_mask_cmp_epi32_mask(mask[3], __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_mask_cmp_epi32_mask(mask[4], __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_mask_cmp_epi32_mask(mask[5], __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}

int test_mm_cmp_epi64_mask()
{
    uint            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < aSizeOf(g_test_mm_cmp_epi64_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_epi64_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_epi64_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm_cmp_epi64_mask_data[i].expect;

        r = _mm_cmp_epi64_mask(__X, __Y, 0);
        if (r != expect[0])
            return FALSE;
        r = _mm_cmp_epi64_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_cmp_epi64_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_cmp_epi64_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_cmp_epi64_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_cmp_epi64_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}


int test_mm_mask_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    __mmask8        m = 0;
    const __mmask8 *expect = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < aSizeOf(g_test_mm_mask_cmp_epi64_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_mask_cmp_epi64_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_mask_cmp_epi64_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm_mask_cmp_epi64_mask_data[i].expect;
        m = g_test_mm_mask_cmp_epi64_mask_data[i].m;

        r = _mm_mask_cmp_epi64_mask(m, __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm_mask_cmp_epi64_mask(m, __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_mask_cmp_epi64_mask(m, __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_mask_cmp_epi64_mask(m, __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_mask_cmp_epi64_mask(m, __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_mask_cmp_epi64_mask(m, __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm256_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < aSizeOf(g_test_mm256_cmp_epi64_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_epi64_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_epi64_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm256_cmp_epi64_mask_data[i].expect;

        r = _mm256_cmp_epi64_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm256_cmp_epi64_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm256_cmp_epi64_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm256_cmp_epi64_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm256_cmp_epi64_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm256_cmp_epi64_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm256_mask_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    __mmask8        m = 0;
    const __mmask8 *expect = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < aSizeOf(g_test_mm256_mask_cmp_epi64_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_mask_cmp_epi64_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_mask_cmp_epi64_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm256_mask_cmp_epi64_mask_data[i].expect;
        m = g_test_mm256_mask_cmp_epi64_mask_data[i].m;

        r = _mm256_mask_cmp_epi64_mask(m, __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm256_mask_cmp_epi64_mask(m, __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm256_mask_cmp_epi64_mask(m, __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm256_mask_cmp_epi64_mask(m, __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm256_mask_cmp_epi64_mask(m, __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm256_mask_cmp_epi64_mask(m, __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm512_cmp_epi64_mask()
{
    unsigned int            i = 0;
    __mmask8        r = 0;
    const __mmask8 *expect = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < aSizeOf(g_test_mm512_cmp_epi64_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_cmp_epi64_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_cmp_epi64_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm512_cmp_epi64_mask_data[i].expect;

        r = _mm512_cmp_epi64_mask(__X, __Y, 0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_cmp_epi64_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_cmp_epi64_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_cmp_epi64_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_cmp_epi64_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_cmp_epi64_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}

int test_mm_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask16        r = 0;
    const __mmask16 *expect = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < aSizeOf(g_test_mm_cmp_epu8_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_epu8_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_epu8_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm_cmp_epu8_mask_data[i].expect;

        r = _mm_cmp_epu8_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm_cmp_epu8_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm_cmp_epu8_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm_cmp_epu8_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm_cmp_epu8_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm_cmp_epu8_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm_mask_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask16        r = 0;
    __mmask16        m = 0;
    const __mmask16 *expect = 0;
    __m128i __X;
    __m128i __Y;

    for (i = 0; i < aSizeOf(g_test_mm_mask_cmp_epu8_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_mask_cmp_epu8_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_mask_cmp_epu8_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm_mask_cmp_epu8_mask_data[i].expect;
        m = g_test_mm_mask_cmp_epu8_mask_data[i].m;

        r = _mm_mask_cmp_epu8_mask(m, __X, __Y, 0);

        if (r != *expect++)
            return FALSE;
        r = _mm_mask_cmp_epu8_mask(m, __X, __Y, 1);

        if (r != *expect++)
            return FALSE;
        r = _mm_mask_cmp_epu8_mask(m, __X, __Y, 2);

        if (r != *expect++)
            return FALSE;
        r = _mm_mask_cmp_epu8_mask(m, __X, __Y, 4);

        if (r != *expect++)
            return FALSE;
        r = _mm_mask_cmp_epu8_mask(m, __X, __Y, 5);

        if (r != *expect++)
            return FALSE;
        r = _mm_mask_cmp_epu8_mask(m, __X, __Y, 6);

        if (r != *expect++)
            return FALSE;
    }
    return TRUE;
}
int test_mm256_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask32        r = 0;
    const __mmask32 *expect = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < aSizeOf(g_test_mm256_cmp_epu8_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_epu8_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_epu8_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm256_cmp_epu8_mask_data[i].expect;

        r = _mm256_cmp_epu8_mask(__X, __Y,0);

        if (r != *expect++)
            return FALSE;
        r = _mm256_cmp_epu8_mask(__X, __Y, 1);

        if (r != *expect++)
            return FALSE;
        r = _mm256_cmp_epu8_mask(__X, __Y, 2);

        if (r != *expect++)
            return FALSE;
        r = _mm256_cmp_epu8_mask(__X, __Y, 4);

        if (r != *expect++)
            return FALSE;
        r = _mm256_cmp_epu8_mask(__X, __Y, 5);

        if (r != *expect++)
            return FALSE;
        r = _mm256_cmp_epu8_mask(__X, __Y, 6);

        if (r != *expect++)
            return FALSE;
    }
    return TRUE;
}
int test_mm256_mask_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask32        r = 0;
    __mmask32        m = 0;
    const __mmask32 *expect = 0;
    __m256i __X;
    __m256i __Y;

    for (i = 0; i < aSizeOf(g_test_mm256_mask_cmp_epu8_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_mask_cmp_epu8_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_mask_cmp_epu8_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm256_mask_cmp_epu8_mask_data[i].expect;
        m = g_test_mm256_mask_cmp_epu8_mask_data[i].m;

        r = _mm256_mask_cmp_epu8_mask(m, __X, __Y,0);

        if (r != *expect++)
            return FALSE;
        r = _mm256_mask_cmp_epu8_mask(m, __X, __Y, 1);

        if (r != *expect++)
            return FALSE;
        r = _mm256_mask_cmp_epu8_mask(m, __X, __Y, 2);

        if (r != *expect++)
            return FALSE;
        r = _mm256_mask_cmp_epu8_mask(m, __X, __Y, 4);

        if (r != *expect++)
            return FALSE;
        r = _mm256_mask_cmp_epu8_mask(m, __X, __Y, 5);

        if (r != *expect++)
            return FALSE;
        r = _mm256_mask_cmp_epu8_mask(m, __X, __Y, 6);

        if (r != *expect++)
            return FALSE;
    }
    return TRUE;
}
int test_mm512_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask64        r = 0;
    const __mmask64 *expect = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < aSizeOf(g_test_mm512_cmp_epu8_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_cmp_epu8_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_cmp_epu8_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm512_cmp_epu8_mask_data[i].expect;

        r = _mm512_cmp_epu8_mask(__X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_cmp_epu8_mask(__X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_cmp_epu8_mask(__X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_cmp_epu8_mask(__X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_cmp_epu8_mask(__X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_cmp_epu8_mask(__X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}
int test_mm512_mask_cmp_epu8_mask()
{
    unsigned int            i = 0;
    __mmask64        r = 0;
    __mmask64        m = 0;
    const __mmask64 *expect = 0;
    __m512i __X;
    __m512i __Y;

    for (i = 0; i < aSizeOf(g_test_mm512_mask_cmp_epu8_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_mask_cmp_epu8_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_mask_cmp_epu8_mask_data[i].b, sizeof(__Y));
        expect = g_test_mm512_mask_cmp_epu8_mask_data[i].expect;
        m = g_test_mm512_mask_cmp_epu8_mask_data[i].m;

        r = _mm512_mask_cmp_epu8_mask(m, __X, __Y,0);
        if (r != expect[0])
            return FALSE;
        r = _mm512_mask_cmp_epu8_mask(m, __X, __Y, 1);
        if (r != expect[1])
            return FALSE;
        r = _mm512_mask_cmp_epu8_mask(m, __X, __Y, 2);
        if (r != expect[2])
            return FALSE;
        r = _mm512_mask_cmp_epu8_mask(m, __X, __Y, 4);
        if (r != expect[3])
            return FALSE;
        r = _mm512_mask_cmp_epu8_mask(m, __X, __Y, 5);
        if (r != expect[4])
            return FALSE;
        r = _mm512_mask_cmp_epu8_mask(m, __X, __Y, 6);
        if (r != expect[5])
            return FALSE;
    }
    return TRUE;
}

#define mmCmpPD(X, Y, O, I)\
    O = _mm_cmp_pd(X, Y, I);\
    if (!comp_return(&(O), &g_test_mm_cmp_pd_data[i].expect[I].e, sizeof(O)))\
        return FALSE
int test_mm_cmp_pd()
{
    unsigned int i = 0;
    __m128d __X;
    __m128d __Y;
    __m128d __O;
    for (i = 0; i < aSizeOf(g_test_mm_cmp_pd_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_pd_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_pd_data[i].b, sizeof(__Y));

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
    O = _mm256_cmp_pd(X, Y, I);\
    if (!comp_return(&(O), &g_test_mm256_cmp_pd_data[i].expect[I].e, sizeof(O)))\
        return FALSE
int test_mm256_cmp_pd()
{
    unsigned int i = 0;
    __m256d __X;
    __m256d __Y;
    __m256d __O;
    for (i = 0; i < aSizeOf(g_test_mm256_cmp_pd_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_pd_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_pd_data[i].b, sizeof(__Y));

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
    O = _mm_cmp_pd_mask(X, Y, I);\
    if (O != g_test_mm_cmp_pd_mask_data[i].expect[I])\
        return FALSE
int test_mm_cmp_pd_mask()
{
    unsigned int i = 0;
    __m128d __X;
    __m128d __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm_cmp_pd_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_pd_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_pd_mask_data[i].b, sizeof(__Y));

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
    O = _mm_mask_cmp_pd_mask(g_test_mm_mask_cmp_pd_mask_data[i].m, X, Y, I);\
    if (O != g_test_mm_mask_cmp_pd_mask_data[i].expect[I])\
        return FALSE
int test_mm_mask_cmp_pd_mask()
{
    unsigned int i = 0;
    __m128d __X;
    __m128d __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm_mask_cmp_pd_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_mask_cmp_pd_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_mask_cmp_pd_mask_data[i].b, sizeof(__Y));

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
    O = _mm256_cmp_pd_mask(X, Y, I);\
    if (O != g_test_mm256_cmp_pd_mask_data[i].expect[I])\
        return FALSE
int test_mm256_cmp_pd_mask()
{
    unsigned int i = 0;
    __m256d __X;
    __m256d __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm256_cmp_pd_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_pd_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_pd_mask_data[i].b, sizeof(__Y));

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
    O = _mm256_mask_cmp_pd_mask(g_test_mm256_mask_cmp_pd_mask_data[i].m, X, Y, I);\
    if (O != g_test_mm256_mask_cmp_pd_mask_data[i].expect[I])\
        return FALSE
int test_mm256_mask_cmp_pd_mask()
{
    unsigned int i = 0;
    __m256d __X;
    __m256d __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm256_mask_cmp_pd_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_mask_cmp_pd_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_mask_cmp_pd_mask_data[i].b, sizeof(__Y));

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
    O = _mm512_cmp_pd_mask(X, Y, I);\
    if (O != g_test_mm512_cmp_pd_mask_data[i].expect[I])\
        return FALSE
int test_mm512_cmp_pd_mask()
{
    unsigned int i = 0;
    __m512d __X;
    __m512d __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm512_cmp_pd_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_cmp_pd_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_cmp_pd_mask_data[i].b, sizeof(__Y));

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

/////////////////////////////////////
#define mmCmpPD(X, Y, O, I)\
    O = _mm512_mask_cmp_pd_mask(g_test_mm512_mask_cmp_pd_mask_data[i].m,X, Y, I);\
    if (O != g_test_mm512_mask_cmp_pd_mask_data[i].expect[I])\
        return FALSE
int test_mm512_mask_cmp_pd_mask()
{
    unsigned int i = 0;
    __m512d __X;
    __m512d __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm512_mask_cmp_pd_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_mask_cmp_pd_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_mask_cmp_pd_mask_data[i].b, sizeof(__Y));

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
    O = _mm_cmp_ps(X, Y, I);\
    if (!comp_return(&(O), &g_test_mm_cmp_ps_data[i].expect[I].e, sizeof(O)))\
        return FALSE
int test_mm_cmp_ps()
{
    unsigned int i = 0;
    __m128 __X;
    __m128 __Y;
    __m128 __O;
    for (i = 0; i < aSizeOf(g_test_mm_cmp_ps_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_ps_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_ps_data[i].b, sizeof(__Y));

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
    O.R = _mm256_cmp_ps(X, Y, I);\
    if (!comp_return(&(O), &g_test_mm256_cmp_ps_data[i].expect[I].e, sizeof(O)))\
        return FALSE
int test_mm256_cmp_ps()
{
    unsigned int i = 0;
    __m256 __X;
    __m256 __Y;
    union{__m256 R; unsigned int u32[8];} __O;
    for (i = 0; i < aSizeOf(g_test_mm256_cmp_ps_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_ps_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_ps_data[i].b, sizeof(__Y));

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
    O = _mm_cmp_ps_mask(X, Y, I);\
    if (O != g_test_mm_cmp_ps_mask_data[i].expect[I])\
        return FALSE
int test_mm_cmp_ps_mask()
{
    unsigned int i = 0;
    __m128 __X;
    __m128 __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm_cmp_ps_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_cmp_ps_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_cmp_ps_mask_data[i].b, sizeof(__Y));

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
    O = _mm_mask_cmp_ps_mask(g_test_mm_mask_cmp_ps_mask_data[i].m, X, Y, I);\
    if (O != g_test_mm_mask_cmp_ps_mask_data[i].expect[I])\
        return FALSE
int test_mm_mask_cmp_ps_mask()
{
    unsigned int i = 0;
    __m128 __X;
    __m128 __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm_mask_cmp_ps_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm_mask_cmp_ps_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm_mask_cmp_ps_mask_data[i].b, sizeof(__Y));

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
    O = _mm256_cmp_ps_mask(X, Y, I);\
    if (O != g_test_mm256_cmp_ps_mask_data[i].expect[I])\
        return FALSE
int test_mm256_cmp_ps_mask()
{
    unsigned int i = 0;
    __m256 __X;
    __m256 __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm256_cmp_ps_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_cmp_ps_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_cmp_ps_mask_data[i].b, sizeof(__Y));

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
    O = _mm256_mask_cmp_ps_mask(g_test_mm256_mask_cmp_ps_mask_data[i].m, X, Y, I);\
    if (O != g_test_mm256_mask_cmp_ps_mask_data[i].expect[I])\
        return FALSE
int test_mm256_mask_cmp_ps_mask()
{
    unsigned int i = 0;
    __m256 __X;
    __m256 __Y;
    uint8_t __O;
    for (i = 0; i < aSizeOf(g_test_mm256_mask_cmp_ps_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm256_mask_cmp_ps_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm256_mask_cmp_ps_mask_data[i].b, sizeof(__Y));

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
    O = _mm512_cmp_ps_mask(X, Y, I);\
    if (O != g_test_mm512_cmp_ps_mask_data[i].expect[I])\
        return FALSE
int test_mm512_cmp_ps_mask()
{
    unsigned int i = 0;
    __m512 __X;
    __m512 __Y;
    uint16_t __O;
    for (i = 0; i < aSizeOf(g_test_mm512_cmp_ps_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_cmp_ps_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_cmp_ps_mask_data[i].b, sizeof(__Y));

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
    O = _mm512_mask_cmp_ps_mask(g_test_mm512_mask_cmp_ps_mask_data[i].m,X, Y, I);\
    if (O != g_test_mm512_mask_cmp_ps_mask_data[i].expect[I])\
       return FALSE
int test_mm512_mask_cmp_ps_mask()
{
    unsigned int i = 0;
    __m512 __X;
    __m512 __Y;
    uint16_t __O;
    for (i = 0; i < aSizeOf(g_test_mm512_mask_cmp_ps_mask_data); ++i)
    {
        memcpy(&__X, g_test_mm512_mask_cmp_ps_mask_data[i].a, sizeof(__X));
        memcpy(&__Y, g_test_mm512_mask_cmp_ps_mask_data[i].b, sizeof(__Y));

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
