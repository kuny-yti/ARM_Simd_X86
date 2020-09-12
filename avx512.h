#include <arm_neon.h>
#include "typedef.h"

typedef union {
    int8x16_t vect_s8[4];
    int16x8_t vect_s16[4];
    int32x4_t vect_s32[4];
    int64x2_t vect_s64[4];
    uint8x16_t vect_u8[4];
    uint16x8_t vect_u16[4];
    uint32x4_t vect_u32[4];
    uint64x2_t vect_u64[4];
    __m256i vect_i256[2];
    __m128i vect_i128[4];
} __m512i __attribute__((aligned(64)));

typedef struct {
    float32x4_t vect_f32[4];
} __m512;

typedef struct {
    float64x2_t vect_f64[4];
} __m512d;


#if 0
FORCE_INLINE __m512i _mm512_srav_epi16(__m512i a, __m512i count)
{
    __m512i result_m512i;
	uint16x8_t vect_imm = vdupq_n_u16(16);
    uint16x8_t flag[4];
	flag[0] = vcltq_u16(count.vect_u16[0], vect_imm);
	flag[1] = vcltq_u16(count.vect_u16[1], vect_imm);
	flag[2] = vcltq_u16(count.vect_u16[2], vect_imm);
	flag[3] = vcltq_u16(count.vect_u16[3], vect_imm);

	result_m512i.vect_s16[0] = vbslq_s16(flag[0], vshlq_s16(a.vect_s16[0], vnegq_s16(count.vect_s16[0])), 
		vshrq_n_s16(a.vect_s16[0], 15));
	result_m512i.vect_s16[1] = vbslq_s16(flag[1], vshlq_s16(a.vect_s16[1], vnegq_s16(count.vect_s16[1])), 
		vshrq_n_s16(a.vect_s16[1], 15));
	result_m512i.vect_s16[2] = vbslq_s16(flag[2], vshlq_s16(a.vect_s16[2], vnegq_s16(count.vect_s16[2])), 
		vshrq_n_s16(a.vect_s16[2], 15));
	result_m512i.vect_s16[3] = vbslq_s16(flag[3], vshlq_s16(a.vect_s16[3], vnegq_s16(count.vect_s16[3])), 
		vshrq_n_s16(a.vect_s16[3], 15));
    return result_m512i;
}
#endif

