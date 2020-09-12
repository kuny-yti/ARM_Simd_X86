#include "test.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "testdata.h"

#ifndef X86_TEST
#include <avx2neon.h>
#else
#include <immintrin.h>
#endif

///< 编译器屏障
#ifndef CompilerBarrier
#define CompilerBarrier() __asm__ __volatile__("": : :"memory")
#endif

static struct InsCase _case_perf_func[UT_MM_MAX_COUNT] = {{0}};
struct InsCase *TestCase (InstructionTest x)
{
    return &_case_perf_func[x];
}


#define aSizeOf(B) (sizeof(B) / sizeof(B[0]))
#define CaseCmd(INS, R, E) \
    R = INS (X, Y, 0); if (R != E[0]) return FALSE;\
    R = INS (X, Y, 1); if (R != E[1]) return FALSE;\
    R = INS (X, Y, 2); if (R != E[2]) return FALSE;\
    R = INS (X, Y, 4); if (R != E[3]) return FALSE;\
    R = INS (X, Y, 5); if (R != E[4]) return FALSE;\
    R = INS (X, Y, 6); if (R != E[5]) return FALSE

#define CaseDefine(INS, BITS, RET) \
    unsigned long _test_##INS () {\
        unsigned int i = 0; \
        __m##BITS X, Y; RET O;\
        for (i = 0; i < aSizeOf(g_test##INS##_data); ++i) {\
            memcpy(&X, g_test##INS##_data[i].a, sizeof(X)); \
            memcpy(&Y, g_test##INS##_data[i].b, sizeof(Y)); \
            CompilerBarrier(); \
            CaseCmd(INS, O, g_test##INS##_data[i].expect); \
        } \
        return TRUE; \
    } \
    __attribute__((constructor(101))) void __##INS##_before() {\
       _case_perf_func[UT##INS].str = #INS;\
       _case_perf_func[UT##INS].func = _test_##INS;\
    }


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (X, g_test##INS##_data[i].la, Y, g_test##INS##_data[i].lb, 1); \
    if (R != E) return FALSE
CaseDefine (_mm_cmpestrs, 128i, int)
CaseDefine (_mm_cmpestrz, 128i, int)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (X, Y, 1); if (R != E) return FALSE
CaseDefine (_mm_cmpistrs, 128i, int)
CaseDefine (_mm_cmpistrz, 128i, int)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (X, Y, 0); if (R != E[0]) return FALSE;\
    R = INS (X, Y, 1); if (R != E[1]) return FALSE;\
    R = INS (X, Y, 2); if (R != E[2]) return FALSE;\
    R = INS (X, Y, 4); if (R != E[3]) return FALSE;\
    R = INS (X, Y, 5); if (R != E[4]) return FALSE;\
    R = INS (X, Y, 6); if (R != E[5]) return FALSE
CaseDefine (_mm_cmp_epi16_mask, 128i, __mmask8)
CaseDefine (_mm256_cmp_epi16_mask, 256i, __mmask16)
CaseDefine (_mm512_cmp_epi16_mask, 512i, __mmask32)

CaseDefine (_mm_cmp_epi32_mask, 128i, __mmask8)
CaseDefine (_mm256_cmp_epi32_mask, 256i, __mmask8)
CaseDefine (_mm512_cmp_epi32_mask, 512i, __mmask16)

CaseDefine (_mm_cmp_epi64_mask, 128i, __mmask8)
CaseDefine (_mm256_cmp_epi64_mask, 256i, __mmask8)
CaseDefine (_mm512_cmp_epi64_mask, 512i, __mmask16)

CaseDefine (_mm_cmp_epu8_mask, 128i, __mmask16)
CaseDefine (_mm256_cmp_epu8_mask, 256i, __mmask32)
CaseDefine (_mm512_cmp_epu8_mask, 512i, __mmask64)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (g_test##INS##_data[i].mask[0], X, Y, 0); if (R != E[0]) return FALSE;\
    R = INS (g_test##INS##_data[i].mask[1], X, Y, 1); if (R != E[1]) return FALSE;\
    R = INS (g_test##INS##_data[i].mask[2], X, Y, 2); if (R != E[2]) return FALSE;\
    R = INS (g_test##INS##_data[i].mask[3], X, Y, 4); if (R != E[3]) return FALSE;\
    R = INS (g_test##INS##_data[i].mask[4], X, Y, 5); if (R != E[4]) return FALSE;\
    R = INS (g_test##INS##_data[i].mask[5], X, Y, 6); if (R != E[5]) return FALSE
CaseDefine (_mm_mask_cmp_epi16_mask, 128i, __mmask8)
CaseDefine (_mm256_mask_cmp_epi16_mask, 256i, __mmask16)
CaseDefine (_mm512_mask_cmp_epi16_mask, 512i, __mmask32)

CaseDefine (_mm_mask_cmp_epi32_mask, 128i, __mmask8)
CaseDefine (_mm256_mask_cmp_epi32_mask, 256i, __mmask8)
CaseDefine (_mm512_mask_cmp_epi32_mask, 512i, __mmask16)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (g_test##INS##_data[i].m, X, Y, 0); if (R != E[0]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 1); if (R != E[1]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 2); if (R != E[2]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 4); if (R != E[3]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 5); if (R != E[4]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 6); if (R != E[5]) return FALSE
CaseDefine (_mm_mask_cmp_epu8_mask, 128i, __mmask16)
CaseDefine (_mm256_mask_cmp_epu8_mask, 256i, __mmask32)
CaseDefine (_mm512_mask_cmp_epu8_mask, 512i, __mmask64)

CaseDefine (_mm_mask_cmp_epi64_mask, 128i, __mmask8)
CaseDefine (_mm256_mask_cmp_epi64_mask, 256i, __mmask8)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (X, Y, 0); if (0 != memcmp(&R, E[0].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 1); if (0 != memcmp(&R, E[1].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 2); if (0 != memcmp(&R, E[2].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 3); if (0 != memcmp(&R, E[3].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 4); if (0 != memcmp(&R, E[4].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 5); if (0 != memcmp(&R, E[5].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 6); if (0 != memcmp(&R, E[6].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 7); if (0 != memcmp(&R, E[7].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 8); if (0 != memcmp(&R, E[8].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 9); if (0 != memcmp(&R, E[9].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 10); if (0 != memcmp(&R, E[10].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 11); if (0 != memcmp(&R, E[11].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 12); if (0 != memcmp(&R, E[12].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 13); if (0 != memcmp(&R, E[13].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 14); if (0 != memcmp(&R, E[14].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 15); if (0 != memcmp(&R, E[15].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 16); if (0 != memcmp(&R, E[16].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 17); if (0 != memcmp(&R, E[17].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 18); if (0 != memcmp(&R, E[18].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 19); if (0 != memcmp(&R, E[19].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 20); if (0 != memcmp(&R, E[20].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 21); if (0 != memcmp(&R, E[21].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 22); if (0 != memcmp(&R, E[22].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 23); if (0 != memcmp(&R, E[23].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 24); if (0 != memcmp(&R, E[24].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 25); if (0 != memcmp(&R, E[25].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 26); if (0 != memcmp(&R, E[26].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 27); if (0 != memcmp(&R, E[27].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 28); if (0 != memcmp(&R, E[28].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 29); if (0 != memcmp(&R, E[29].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 30); if (0 != memcmp(&R, E[30].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 31); if (0 != memcmp(&R, E[31].e, sizeof(R))) return FALSE
CaseDefine (_mm_cmp_pd, 128d, __m128d)
CaseDefine (_mm256_cmp_pd, 256d, __m256d)
CaseDefine (_mm_cmp_ps, 128, __m128)
CaseDefine (_mm256_cmp_ps, 256, __m256)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (X, Y, 0); if (R != E[0]) return FALSE;\
    R = INS (X, Y, 1); if (R != E[1]) return FALSE;\
    R = INS (X, Y, 2); if (R != E[2]) return FALSE;\
    R = INS (X, Y, 3); if (R != E[3]) return FALSE;\
    R = INS (X, Y, 4); if (R != E[4]) return FALSE;\
    R = INS (X, Y, 5); if (R != E[5]) return FALSE;\
    R = INS (X, Y, 6); if (R != E[6]) return FALSE;\
    R = INS (X, Y, 7); if (R != E[7]) return FALSE;\
    R = INS (X, Y, 8); if (R != E[8]) return FALSE;\
    R = INS (X, Y, 9); if (R != E[9]) return FALSE;\
    R = INS (X, Y, 10); if (R != E[10]) return FALSE;\
    R = INS (X, Y, 11); if (R != E[11]) return FALSE;\
    R = INS (X, Y, 12); if (R != E[12]) return FALSE;\
    R = INS (X, Y, 13); if (R != E[13]) return FALSE;\
    R = INS (X, Y, 14); if (R != E[14]) return FALSE;\
    R = INS (X, Y, 15); if (R != E[15]) return FALSE;\
    R = INS (X, Y, 16); if (R != E[16]) return FALSE;\
    R = INS (X, Y, 17); if (R != E[17]) return FALSE;\
    R = INS (X, Y, 18); if (R != E[18]) return FALSE;\
    R = INS (X, Y, 19); if (R != E[19]) return FALSE;\
    R = INS (X, Y, 20); if (R != E[20]) return FALSE;\
    R = INS (X, Y, 21); if (R != E[21]) return FALSE;\
    R = INS (X, Y, 22); if (R != E[22]) return FALSE;\
    R = INS (X, Y, 23); if (R != E[23]) return FALSE;\
    R = INS (X, Y, 24); if (R != E[24]) return FALSE;\
    R = INS (X, Y, 25); if (R != E[25]) return FALSE;\
    R = INS (X, Y, 26); if (R != E[26]) return FALSE;\
    R = INS (X, Y, 27); if (R != E[27]) return FALSE;\
    R = INS (X, Y, 28); if (R != E[28]) return FALSE;\
    R = INS (X, Y, 29); if (R != E[29]) return FALSE;\
    R = INS (X, Y, 30); if (R != E[30]) return FALSE;\
    R = INS (X, Y, 31); if (R != E[31]) return FALSE
CaseDefine (_mm_cmp_pd_mask, 128d, __mmask8)
CaseDefine (_mm256_cmp_pd_mask, 256d, __mmask8)
CaseDefine (_mm512_cmp_pd_mask, 512d, __mmask8)
CaseDefine (_mm_cmp_ps_mask, 128, __mmask8)
CaseDefine (_mm256_cmp_ps_mask, 256, __mmask8)
CaseDefine (_mm512_cmp_ps_mask, 512, __mmask16)

CaseDefine (_mm_cmp_sd_mask, 128d, __mmask8)
CaseDefine (_mm_cmp_ss_mask, 128, __mmask8)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (g_test##INS##_data[i].m, X, Y, 0); if (R != E[0]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 1); if (R != E[1]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 2); if (R != E[2]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 3); if (R != E[3]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 4); if (R != E[4]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 5); if (R != E[5]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 6); if (R != E[6]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 7); if (R != E[7]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 8); if (R != E[8]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 9); if (R != E[9]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 10); if (R != E[10]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 11); if (R != E[11]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 12); if (R != E[12]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 13); if (R != E[13]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 14); if (R != E[14]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 15); if (R != E[15]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 16); if (R != E[16]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 17); if (R != E[17]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 18); if (R != E[18]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 19); if (R != E[19]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 20); if (R != E[20]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 21); if (R != E[21]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 22); if (R != E[22]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 23); if (R != E[23]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 24); if (R != E[24]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 25); if (R != E[25]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 26); if (R != E[26]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 27); if (R != E[27]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 28); if (R != E[28]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 29); if (R != E[29]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 30); if (R != E[30]) return FALSE;\
    R = INS (g_test##INS##_data[i].m, X, Y, 31); if (R != E[31]) return FALSE
CaseDefine (_mm_mask_cmp_pd_mask, 128d, __mmask8)
CaseDefine (_mm256_mask_cmp_pd_mask, 256d, __mmask8)
CaseDefine (_mm512_mask_cmp_pd_mask, 512d, __mmask8)
CaseDefine (_mm_mask_cmp_ps_mask, 128, __mmask8)
CaseDefine (_mm256_mask_cmp_ps_mask, 256, __mmask8)
CaseDefine (_mm512_mask_cmp_ps_mask, 512, __mmask16)

CaseDefine (_mm_mask_cmp_sd_mask, 128d, __mmask8)
CaseDefine (_mm_mask_cmp_ss_mask, 128, __mmask8)


#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (X, Y, 0); if (0 != memcmp(&R, &E[0].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 1); if (0 != memcmp(&R, &E[1].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 2); if (0 != memcmp(&R, &E[2].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 3); if (0 != memcmp(&R, &E[3].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 4); if (0 != memcmp(&R, &E[4].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 5); if (0 != memcmp(&R, &E[5].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 6); if (0 != memcmp(&R, &E[6].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 7); if (0 != memcmp(&R, &E[7].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 8); if (0 != memcmp(&R, &E[8].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 9); if (0 != memcmp(&R, &E[9].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 10); if (0 != memcmp(&R, &E[10].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 11); if (0 != memcmp(&R, &E[11].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 12); if (0 != memcmp(&R, &E[12].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 13); if (0 != memcmp(&R, &E[13].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 14); if (0 != memcmp(&R, &E[14].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 15); if (0 != memcmp(&R, &E[15].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 16); if (0 != memcmp(&R, &E[16].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 17); if (0 != memcmp(&R, &E[17].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 18); if (0 != memcmp(&R, &E[18].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 19); if (0 != memcmp(&R, &E[19].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 20); if (0 != memcmp(&R, &E[20].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 21); if (0 != memcmp(&R, &E[21].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 22); if (0 != memcmp(&R, &E[22].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 23); if (0 != memcmp(&R, &E[23].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 24); if (0 != memcmp(&R, &E[24].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 25); if (0 != memcmp(&R, &E[25].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 26); if (0 != memcmp(&R, &E[26].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 27); if (0 != memcmp(&R, &E[27].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 28); if (0 != memcmp(&R, &E[28].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 29); if (0 != memcmp(&R, &E[29].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 30); if (0 != memcmp(&R, &E[30].e, sizeof(R))) return FALSE;\
    R = INS (X, Y, 31); if (0 != memcmp(&R, &E[31].e, sizeof(R))) return FALSE
CaseDefine (_mm_cmp_sd, 128d, __m128d)
CaseDefine (_mm_cmp_ss, 128, __m128)

#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (Z, X, Y); if (0 != memcmp(&R, &E, sizeof(R))) return FALSE;
#undef CaseDefine
#define CaseDefine(INS, BITS, RET) \
    unsigned long _test_##INS () {\
        unsigned int i = 0; \
        __m##BITS X, Y, Z; union { RET O; unsigned int u32[16]; unsigned char u8[64]; unsigned short u16[32]}_O;\
        for (i = 0; i < aSizeOf(g_test##INS##_data); ++i) {\
            memcpy(&X, g_test##INS##_data[i].a, sizeof(X)); \
            memcpy(&Y, g_test##INS##_data[i].b, sizeof(Y)); \
            memcpy(&Z, g_test##INS##_data[i].s, sizeof(Z)); \
            CompilerBarrier(); \
            CaseCmd(INS, _O.O, g_test##INS##_data[i].expect); \
        } \
        return TRUE; \
    } \
    __attribute__((constructor(101))) void __##INS##_before() {\
       _case_perf_func[UT##INS].str = #INS;\
       _case_perf_func[UT##INS].func = _test_##INS;\
    }

CaseDefine(_mm_dpbusd_epi32, 128i, __m128i)
CaseDefine(_mm256_dpbusd_epi32, 256i, __m256i)
CaseDefine(_mm512_dpbusd_epi32, 512i, __m512i)
CaseDefine(_mm_dpwssd_epi32, 128i, __m128i)
CaseDefine(_mm256_dpwssd_epi32, 256i, __m256i)

#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (Z, g_test##INS##_data[i].m, X, Y); if (0 != memcmp(&R, &E, sizeof(R))) {\
    printf("r: %x, %x, %x, %x, %x, %x, %x, %x", R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7]); \
    return FALSE;}
CaseDefine(_mm_mask_dpbusd_epi32, 128i, __m128i)
CaseDefine(_mm256_mask_dpbusd_epi32, 256i, __m256i)
CaseDefine(_mm512_mask_dpbusd_epi32, 512i, __m512i)
CaseDefine(_mm_mask_dpwssd_epi32, 128i, __m128i)
CaseDefine(_mm256_mask_dpwssd_epi32, 256i, __m256i)

#undef CaseCmd
#define CaseCmd(INS, R, E) \
    R = INS (g_test##INS##_data[i].m, Z, X, Y); if (0 != memcmp(&R, &E, sizeof(R))) return FALSE;
CaseDefine(_mm_maskz_dpbusd_epi32, 128i, __m128i)
CaseDefine(_mm256_maskz_dpbusd_epi32, 256i, __m256i)
CaseDefine(_mm512_maskz_dpbusd_epi32, 512i, __m512i)
CaseDefine(_mm_maskz_dpwssd_epi32, 128i, __m128i)
CaseDefine(_mm256_maskz_dpwssd_epi32, 256i, __m256i)
