
#define TRUE 1
#define FALSE 0

#define INS_Enum(INS) UT##INS
typedef enum {
    UT_MM_BASE,

    INS_Enum(_mm_cmpestrs) = UT_MM_BASE,
    INS_Enum(_mm_cmpestrz),
    INS_Enum(_mm_cmpistrs),
    INS_Enum(_mm_cmpistrz),

    INS_Enum(_mm_cmp_epi16_mask),
    INS_Enum(_mm_mask_cmp_epi16_mask),
    INS_Enum(_mm256_cmp_epi16_mask),
    INS_Enum(_mm256_mask_cmp_epi16_mask),
    INS_Enum(_mm512_cmp_epi16_mask),
    INS_Enum(_mm512_mask_cmp_epi16_mask),

    INS_Enum(_mm_cmp_epi32_mask),
    INS_Enum(_mm_mask_cmp_epi32_mask),
    INS_Enum(_mm256_cmp_epi32_mask),
    INS_Enum(_mm256_mask_cmp_epi32_mask),
    INS_Enum(_mm512_cmp_epi32_mask),
    INS_Enum(_mm512_mask_cmp_epi32_mask),

    INS_Enum(_mm_cmp_epi64_mask),
    INS_Enum(_mm_mask_cmp_epi64_mask),
    INS_Enum(_mm256_cmp_epi64_mask),
    INS_Enum(_mm256_mask_cmp_epi64_mask),
    INS_Enum(_mm512_cmp_epi64_mask),

    INS_Enum(_mm_cmp_epu8_mask),
    INS_Enum(_mm_mask_cmp_epu8_mask),
    INS_Enum(_mm256_cmp_epu8_mask),
    INS_Enum(_mm256_mask_cmp_epu8_mask),
    INS_Enum(_mm512_cmp_epu8_mask),
    INS_Enum(_mm512_mask_cmp_epu8_mask),

    INS_Enum(_mm_cmp_pd),
    INS_Enum(_mm_cmp_pd_mask),
    INS_Enum(_mm_mask_cmp_pd_mask),
    INS_Enum(_mm256_cmp_pd),
    INS_Enum(_mm256_cmp_pd_mask),
    INS_Enum(_mm256_mask_cmp_pd_mask),
    INS_Enum(_mm512_cmp_pd_mask),

    INS_Enum(_mm512_mask_cmp_pd_mask),
    INS_Enum(_mm_cmp_ps),
    INS_Enum(_mm_cmp_ps_mask),
    INS_Enum(_mm_mask_cmp_ps_mask),
    INS_Enum(_mm256_cmp_ps),
    INS_Enum(_mm256_cmp_ps_mask),
    INS_Enum(_mm256_mask_cmp_ps_mask),
    INS_Enum(_mm512_cmp_ps_mask),
    INS_Enum(_mm512_mask_cmp_ps_mask),
    INS_Enum(_mm_cmp_sd),
    INS_Enum(_mm_cmp_sd_mask),
    INS_Enum(_mm_mask_cmp_sd_mask),
    INS_Enum(_mm_cmp_ss),
    INS_Enum(_mm_cmp_ss_mask),
    INS_Enum(_mm_mask_cmp_ss_mask),

    INS_Enum(_mm_dpbusd_epi32),
    INS_Enum(_mm_mask_dpbusd_epi32),
    INS_Enum(_mm_maskz_dpbusd_epi32),
    INS_Enum(_mm256_dpbusd_epi32),
    INS_Enum(_mm256_mask_dpbusd_epi32),
    INS_Enum(_mm256_maskz_dpbusd_epi32),
    INS_Enum(_mm512_dpbusd_epi32),
    INS_Enum(_mm512_mask_dpbusd_epi32),
    INS_Enum(_mm512_maskz_dpbusd_epi32),
    INS_Enum(_mm_dpwssd_epi32),
    INS_Enum(_mm_mask_dpwssd_epi32),
    INS_Enum(_mm_maskz_dpwssd_epi32),
    INS_Enum(_mm256_dpwssd_epi32),
    INS_Enum(_mm256_mask_dpwssd_epi32),
    INS_Enum(_mm256_maskz_dpwssd_epi32),

    UT_MM_MAX_COUNT
} InstructionTest;

struct InsCase
{
    const char * str;
    unsigned long (*func)();
};

extern struct InsCase *TestCase (InstructionTest);
