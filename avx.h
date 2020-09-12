#include <arm_neon.h>
#include "typedef.h"

typedef union {
    int8x16_t vect_s8[2];
    int16x8_t vect_s16[2];
    int32x4_t vect_s32[2];
    int64x2_t vect_s64[2];
    uint8x16_t vect_u8[2];
    uint16x8_t vect_u16[2];
    uint32x4_t vect_u32[2];
    uint64x2_t vect_u64[2];
    __m128i vect_i128[2];
}__m256i __attribute__((aligned(32)));
/*
typedef struct {
    float32x4_t vect_f32[2];
} __m256;

typedef struct {
    float64x2_t vect_f64[2];
}__m256d;*/
typedef union {
    int8x16_t vect_s8[4];
    int16x8_t vect_s16[4];
    int32x4_t vect_s32[4];
    int64x2_t vect_s64[4];
    uint8x16_t vect_u8[4];
    uint16x8_t vect_u16[4];
    uint32x4_t vect_u32[4];
    uint64x2_t vect_u64[4];
    float32x4_t  vect_f32[4];
    float64x2_t  vect_f64[4];
}__m256;
typedef union {
    int8x16_t vect_s8[2];
    int16x8_t vect_s16[2];
    int32x4_t vect_s32[2];
    int64x2_t vect_s64[2];
    uint8x16_t vect_u8[2];
    uint16x8_t vect_u16[2];
    uint32x4_t vect_u32[2];
    uint64x2_t vect_u64[2];
    float32x4_t  vect_f32[2];
    float64x2_t  vect_f64[2];
}__m256d;

FORCE_INLINE __m256i _mm256_srli_epi64(__m256i a, int imm8)
{
    __m256i result_m256i;
    
    if (likely(imm8 >= 0 && imm8 < 64)) {
        int64x2_t vect_imm = vdupq_n_s64(-imm8);
        result_m256i.vect_u64[0] = vshlq_u64(a.vect_u64[0], vect_imm);
        result_m256i.vect_u64[1] = vshlq_u64(a.vect_u64[1], vect_imm);
    } else {
        result_m256i.vect_u64[0] = vdupq_n_u64(0);
        result_m256i.vect_u64[1] = vdupq_n_u64(0);
    }
    return result_m256i;
}


