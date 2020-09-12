#include <immintrin.h>

#define TRUE 1
#define FALSE 0

typedef enum {
    UT_MM_BASE,

    UT_MM_CMPESTRS = UT_MM_BASE,
    UT_MM_CMPESTRZ,
    UT_MM_CMPISTRS,
    UT_MM_CMPISTRZ,
    UT_MM_CMP_EPI16_MASK,
    UT_MM_MASK_CMP_EPI16_MASK,
    UT_MM256_CMP_EPI16_MASK,
    UT_MM256_MASK_CMP_EPI16_MASK,
    UT_MM512_CMP_EPI16_MASK,
    UT_MM512_MASK_CMP_EPI16_MASK,
    UT_MM_CMP_EPI32_MASK,
    UT_MM_MASK_CMP_EPI32_MASK,
    UT_MM256_CMP_EPI32_MASK,
    UT_MM256_MASK_CMP_EPI32_MASK,
    UT_MM512_CMP_EPI32_MASK,
    UT_MM512_MASK_CMP_EPI32_MASK,
    UT_MM_CMP_EPI64_MASK,

    UT_MM_MASK_CMP_EPI64_MASK,
    UT_MM256_CMP_EPI64_MASK,
    UT_MM256_MASK_CMP_EPI64_MASK,
    UT_MM512_CMP_EPI64_MASK,
    UT_MM_CMP_EPU8_MASK,
    UT_MM_MASK_CMP_EPU8_MASK,
    UT_MM256_CMP_EPU8_MASK,
    UT_MM256_MASK_CMP_EPU8_MASK,
    UT_MM512_CMP_EPU8_MASK,
    UT_MM512_MASK_CMP_EPU8_MASK,
    UT_MM_CMP_PD,
    UT_MM256_CMP_PD,
    UT_MM_CMP_PD_MASK,
    UT_MM_MASK_CMP_PD_MASK,
    UT_MM256_CMP_PD_MASK,
    UT_MM256_MASK_CMP_PD_MASK,
    UT_MM512_CMP_PD_MASK,

    UT_MM512_MASK_CMP_PD_MASK,
    UT_MM_CMP_PS,
    UT_MM256_CMP_PS,
    UT_MM_CMP_PS_MASK,
    UT_MM_MASK_CMP_PS_MASK,
    UT_MM256_CMP_PS_MASK,
    UT_MM256_MASK_CMP_PS_MASK,
    UT_MM512_CMP_PS_MASK,
    UT_MM512_MASK_CMP_PS_MASK,

    UT_MM_MAX_COUNT
} InstructionTest;

const char *RunTest(InstructionTest test, int *flag);

int test_mm_cmpestrs();
int test_mm_cmpestrz();
int test_mm_cmpistrs();
int test_mm_cmpistrz();

int test_mm_cmp_epi16_mask();
int test_mm_mask_cmp_epi16_mask();
int test_mm256_cmp_epi16_mask();
int test_mm256_mask_cmp_epi16_mask();
int test_mm512_cmp_epi16_mask();
int test_mm512_mask_cmp_epi16_mask();

int test_mm_cmp_epi32_mask();
int test_mm_mask_cmp_epi32_mask();
int test_mm256_cmp_epi32_mask();
int test_mm256_mask_cmp_epi32_mask();
int test_mm512_cmp_epi32_mask();
int test_mm512_mask_cmp_epi32_mask();

int test_mm_cmp_epi64_mask();
// 6-11
int test_mm_mask_cmp_epi64_mask();
int test_mm256_cmp_epi64_mask();
int test_mm256_mask_cmp_epi64_mask();
int test_mm512_cmp_epi64_mask();

int test_mm_cmp_epu8_mask();
int test_mm_mask_cmp_epu8_mask();
int test_mm256_cmp_epu8_mask();
int test_mm256_mask_cmp_epu8_mask();
int test_mm512_cmp_epu8_mask();
int test_mm512_mask_cmp_epu8_mask();
int test_mm_cmp_pd();
int test_mm256_cmp_pd();
int test_mm_cmp_pd_mask();
int test_mm_mask_cmp_pd_mask();
int test_mm256_cmp_pd_mask();
int test_mm256_mask_cmp_pd_mask();
int test_mm512_cmp_pd_mask();

// 6-12
int test_mm512_mask_cmp_pd_mask();

int test_mm_cmp_ps();
int test_mm256_cmp_ps();
int test_mm_cmp_ps_mask();
int test_mm_mask_cmp_ps_mask();
int test_mm256_cmp_ps_mask();
int test_mm256_mask_cmp_ps_mask();
int test_mm512_cmp_ps_mask();
int test_mm512_mask_cmp_ps_mask();
