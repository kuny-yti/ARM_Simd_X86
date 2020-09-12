#include <stdio.h>
#include <time.h>
#include "test.h"

#ifndef X86_TEST
#include <avx2neon.h>
#else
#include <immintrin.h>

#endif

///< 编译器屏障
#ifndef CompilerBarrier
#define CompilerBarrier() __asm__ __volatile__("": : :"memory")
#endif

#define LOOP_CNT	10000
#define FUNC_CNT	10

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
    unsigned int i = 0;
    for (i = 0; i < 32; i++) {
        now = GetClockBootTime();
        delta += (now - start);
        start = now;
    }
    delta >>= 5;

    return delta;
}

static struct InsCase _case_perf_func[UT_MM_MAX_COUNT] = {{0}};
struct InsCase *TestCase (InstructionTest x)
{
    return &_case_perf_func[x];
}

#define TickCmd(A, T) \
    do{\
        unsigned long long delta = 0, start = 0, end = 0;\
        delta = GetClockBootTimeDelta(); \
        start = GetClockBootTime(); \
        A ; \
        end = GetClockBootTime(); \
        T += end - start - delta; \
    }while(0)

#define CaseDefine1(INS, BIT, RET)\
    static unsigned long _test_##INS(){\
        __m##BIT X, Y; RET Z;                            \
        unsigned long long delta = 0, start = 0, end = 0;\
        unsigned long long T;\
        unsigned int i = 0;\
        delta = GetClockBootTimeDelta(); \
        for (i = 0; i < LOOP_CNT; ++i) {              \
            CompilerBarrier();                           \
            start = GetClockBootTime(); \
            Z = INS (INS_Param); \
            end = GetClockBootTime(); \
            T += end - start - delta; \
        }\
        return T / LOOP_CNT; \
    } \
    __attribute__((constructor(101))) void __##INS##_before() {\
       _case_perf_func[UT##INS].str = #INS;\
       _case_perf_func[UT##INS].func = _test_##INS;\
    }

#define CaseDefine(INS, BIT, RET)\
    static unsigned long _test_##INS(){\
        __m##BIT X, Y, Z; RET O;                            \
        unsigned long long delta = 0, start = 0, end = 0;\
        unsigned long long T;\
        unsigned int i = 0;\
        delta = GetClockBootTimeDelta(); \
        start = GetClockBootTime(); \
        for (i = 0; i < LOOP_CNT*FUNC_CNT; ++i) {              \
            CompilerBarrier();                           \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
            O = INS (INS_Param); \
        }\
        end = GetClockBootTime(); \
        T = end - start - delta; \
        return T /*/ LOOP_CNT*/; \
    } \
    __attribute__((constructor(101))) void __##INS##_before() {\
       _case_perf_func[UT##INS].str = #INS;\
       _case_perf_func[UT##INS].func = _test_##INS;\
    }

#undef INS_Param
#define INS_Param X, i, Y, i, 0
CaseDefine(_mm_cmpestrs, 128i, int)
CaseDefine(_mm_cmpestrz, 128i, int)


#undef INS_Param
#define INS_Param X, Y, 0
CaseDefine(_mm_cmpistrs, 128i, int)
CaseDefine(_mm_cmpistrz, 128i, int)

CaseDefine(_mm_cmp_epi16_mask, 128i, __mmask8)
CaseDefine(_mm256_cmp_epi16_mask, 256i, __mmask16)
CaseDefine(_mm512_cmp_epi16_mask, 512i, __mmask32)

CaseDefine(_mm_cmp_epi32_mask, 128i, __mmask8)
CaseDefine(_mm256_cmp_epi32_mask, 256i, __mmask16)
CaseDefine(_mm512_cmp_epi32_mask, 512i, __mmask16)

CaseDefine(_mm_cmp_epi64_mask, 128i, __mmask8)
CaseDefine(_mm256_cmp_epi64_mask, 256i, __mmask16)
CaseDefine(_mm512_cmp_epi64_mask, 512i, __mmask16)

CaseDefine(_mm_cmp_epu8_mask, 128i, __mmask16)
CaseDefine(_mm256_cmp_epu8_mask, 256i, __mmask32)
CaseDefine(_mm512_cmp_epu8_mask, 512i, __mmask64)

CaseDefine(_mm_cmp_pd, 128d, __m128d)
CaseDefine(_mm256_cmp_pd, 256d, __m256d)
CaseDefine(_mm_cmp_pd_mask, 128d, __mmask8)
CaseDefine(_mm256_cmp_pd_mask, 256d, __mmask8)
CaseDefine(_mm512_cmp_pd_mask, 512d, __mmask8)

CaseDefine(_mm_cmp_ps, 128, __m128)
CaseDefine(_mm256_cmp_ps, 256, __m256)
CaseDefine(_mm_cmp_ps_mask, 128, __mmask8)
CaseDefine(_mm256_cmp_ps_mask, 256, __mmask8)
CaseDefine(_mm512_cmp_ps_mask, 512, __mmask16)

CaseDefine(_mm_cmp_sd, 128d, __m128d)
CaseDefine(_mm_cmp_sd_mask, 128d, __mmask8)

CaseDefine(_mm_cmp_ss, 128, __m128)
CaseDefine(_mm_cmp_ss_mask, 128, __mmask8)


#undef INS_Param
#define INS_Param i, X, Y, 0
CaseDefine(_mm_mask_cmp_epi16_mask, 128i, __mmask8)
CaseDefine(_mm256_mask_cmp_epi16_mask, 256i, __mmask16)
CaseDefine(_mm512_mask_cmp_epi16_mask, 512i, __mmask32)

CaseDefine(_mm_mask_cmp_epi32_mask, 128i, __mmask8)
CaseDefine(_mm256_mask_cmp_epi32_mask, 256i, __mmask16)
CaseDefine(_mm512_mask_cmp_epi32_mask, 512i, __mmask32)

CaseDefine(_mm_mask_cmp_epi64_mask, 128i, __mmask8)
CaseDefine(_mm256_mask_cmp_epi64_mask, 256i, __mmask8)

CaseDefine(_mm_mask_cmp_epu8_mask, 128i, __mmask16)
CaseDefine(_mm256_mask_cmp_epu8_mask, 256i, __mmask32)
CaseDefine(_mm512_mask_cmp_epu8_mask, 512i, __mmask64)

CaseDefine(_mm_mask_cmp_pd_mask, 128d, __mmask8)
CaseDefine(_mm256_mask_cmp_pd_mask, 256d, __mmask8)
CaseDefine(_mm512_mask_cmp_pd_mask, 512d, __mmask8)

CaseDefine(_mm_mask_cmp_ps_mask, 128, __mmask8)
CaseDefine(_mm256_mask_cmp_ps_mask, 256, __mmask8)
CaseDefine(_mm512_mask_cmp_ps_mask, 512, __mmask16)

CaseDefine(_mm_mask_cmp_sd_mask, 128d, __mmask8)
CaseDefine(_mm_mask_cmp_ss_mask, 128, __mmask8)


#undef INS_Param
#define INS_Param Z, X, Y
CaseDefine(_mm_dpbusd_epi32, 128i, __m128i)
CaseDefine(_mm256_dpbusd_epi32, 256i, __m256i)
CaseDefine(_mm512_dpbusd_epi32, 512i, __m512i)
CaseDefine(_mm_dpwssd_epi32, 128i, __m128i)
CaseDefine(_mm256_dpwssd_epi32, 256i, __m256i)

#undef INS_Param
#define INS_Param Z, 0xff, X, Y
CaseDefine(_mm_mask_dpbusd_epi32, 128i, __m128i)
CaseDefine(_mm256_mask_dpbusd_epi32, 256i, __m256i)
CaseDefine(_mm512_mask_dpbusd_epi32, 512i, __m512i)
CaseDefine(_mm_mask_dpwssd_epi32, 128i, __m128i)
CaseDefine(_mm256_mask_dpwssd_epi32, 256i, __m256i)

#undef INS_Param
#define INS_Param 0xff, Z, X, Y
CaseDefine(_mm_maskz_dpbusd_epi32, 128i, __m128i)
CaseDefine(_mm256_maskz_dpbusd_epi32, 256i, __m256i)
CaseDefine(_mm512_maskz_dpbusd_epi32, 512i, __m512i)
CaseDefine(_mm_maskz_dpwssd_epi32, 128i, __m128i)
CaseDefine(_mm256_maskz_dpwssd_epi32, 256i, __m256i)
