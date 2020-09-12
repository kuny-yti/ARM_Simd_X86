#include <arm_neon.h>
#include "typedef.h"
#define AARCH64

#define _MM_FROUND_TO_NEAREST_INT    0x00
#define _MM_FROUND_TO_NEG_INF        0x01
#define _MM_FROUND_TO_POS_INF        0x02
#define _MM_FROUND_TO_ZERO           0x03
#define _MM_FROUND_CUR_DIRECTION     0x04

#define _MM_FROUND_RAISE_EXC         0x00
#define _MM_FROUND_NO_EXC            0x08

#define FORCE_INLINE static inline __attribute__((always_inline))
#define likely(x)     __builtin_expect(!!(x), 1)
#define unlikely(x)   __builtin_expect(!!(x), 0)

#ifndef __int32
#define __int32 int
#endif

#ifndef __int64
#define __int64 long long
#endif

#ifndef __mmask64
#define __mmask64 unsigned long long
#endif

#ifndef __mmask32
#define __mmask32 unsigned int
#endif

#ifndef __mmask16
#define __mmask16 unsigned short
#endif

#ifndef __mmask8
#define __mmask8 unsigned char
#endif

typedef union {
    int8x8_t vect_s8;
    int16x4_t vect_s16;
    int32x2_t vect_s32;
    int64x1_t vect_s64;
    uint8x8_t vect_u8;
    uint16x4_t vect_u16;
    uint32x2_t vect_u32;
    uint64x1_t vect_u64;
}__m64;

typedef union {
    int8x16_t vect_s8;
    int16x8_t vect_s16;
    int32x4_t vect_s32;
    int64x2_t vect_s64;
    uint8x16_t vect_u8;
    uint16x8_t vect_u16;
    uint32x4_t vect_u32;
    uint64x2_t vect_u64;
}__m128i;

#ifndef float64x2_t
typedef double float64x2_t __attribute__ ((__vector_size__ (16), __may_alias__));
#endif

typedef float32x4_t __m128;
typedef float64x2_t __m128d;

static unsigned char log_table[256] = {
0, 0, 25, 1, 50, 2, 26, 198, 75, 199, 27, 104, 51, 238, 223, 3, 
100, 4, 224, 14, 52, 141, 129, 239, 76, 113, 8, 200, 248, 105, 28, 193, 
125, 194, 29, 181, 249, 185, 39, 106, 77, 228, 166, 114, 154, 201, 9, 120, 
101, 47, 138, 5, 33, 15, 225, 36, 18, 240, 130, 69, 53, 147, 218, 142, 
150, 143, 219, 189, 54, 208, 206, 148, 19, 92, 210, 241, 64, 70, 131, 56, 
102, 221, 253, 48, 191, 6, 139, 98, 179, 37, 226, 152, 34, 136, 145, 16, 
126, 110, 72, 195, 163, 182, 30, 66, 58, 107, 40, 84, 250, 133, 61, 186, 
43, 121, 10, 21, 155, 159, 94, 202, 78, 212, 172, 229, 243, 115, 167, 87, 
175, 88, 168, 80, 244, 234, 214, 116, 79, 174, 233, 213, 231, 230, 173, 232, 
44, 215, 117, 122, 235, 22, 11, 245, 89, 203, 95, 176, 156, 169, 81, 160, 
127, 12, 246, 111, 23, 196, 73, 236, 216, 67, 31, 45, 164, 118, 123, 183, 
204, 187, 62, 90, 251, 96, 177, 134, 59, 82, 161, 108, 170, 85, 41, 157, 
151, 178, 135, 144, 97, 190, 220, 252, 188, 149, 207, 205, 55, 63, 91, 209, 
83, 57, 132, 60, 65, 162, 109, 71, 20, 42, 158, 93, 86, 242, 211, 171, 
68, 17, 146, 217, 35, 32, 46, 137, 180, 124, 184, 38, 119, 153, 227, 165, 
103, 74, 237, 222, 197, 49, 254, 24, 13, 99, 140, 128, 192, 247, 112, 7};

static unsigned char alog_table[256] = {
1, 3, 5, 15, 17, 51, 85, 255, 26, 46, 114, 150, 161, 248, 19, 53, 
95, 225, 56, 72, 216, 115, 149, 164, 247, 2, 6, 10, 30, 34, 102, 170, 
229, 52, 92, 228, 55, 89, 235, 38, 106, 190, 217, 112, 144, 171, 230, 49, 
83, 245, 4, 12, 20, 60, 68, 204, 79, 209, 104, 184, 211, 110, 178, 205, 
76, 212, 103, 169, 224, 59, 77, 215, 98, 166, 241, 8, 24, 40, 120, 136, 
131, 158, 185, 208, 107, 189, 220, 127, 129, 152, 179, 206, 73, 219, 118, 154, 
181, 196, 87, 249, 16, 48, 80, 240, 11, 29, 39, 105, 187, 214, 97, 163, 
254, 25, 43, 125, 135, 146, 173, 236, 47, 113, 147, 174, 233, 32, 96, 160, 
251, 22, 58, 78, 210, 109, 183, 194, 93, 231, 50, 86, 250, 21, 63, 65, 
195, 94, 226, 61, 71, 201, 64, 192, 91, 237, 44, 116, 156, 191, 218, 117, 
159, 186, 213, 100, 172, 239, 42, 126, 130, 157, 188, 223, 122, 142, 137, 128, 
155, 182, 193, 88, 232, 35, 101, 175, 234, 37, 111, 177, 200, 67, 197, 84, 
252, 31, 33, 99, 165, 244, 7, 9, 27, 45, 119, 153, 176, 203, 70, 202, 
69, 207, 74, 222, 121, 139, 134, 145, 168, 227, 62, 66, 198, 81, 243, 14, 
18, 54, 90, 238, 41, 123, 141, 140, 143, 138, 133, 148, 167, 242, 13, 23, 
57, 75, 221, 124, 132, 151, 162, 253, 28, 36, 108, 180, 199, 82, 246, 1};

static uint64_t g_mask_epi64[2] __attribute__((aligned(16))) = {0x01, 0x02};
static uint32_t g_mask_epi32[4] __attribute__((aligned(16))) = {0x01, 0x02, 0x04, 0x08};
static uint16_t g_mask_epi16[8] __attribute__((aligned(16))) = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
static uint8_t g_mask_epi8[16] __attribute__((aligned(16))) = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

static uint64_t g_mask_epi64_sel_low64bit[2] __attribute__((aligned(16))) = {0, 0xffffffffffffffffull};
static uint32_t g_mask_epi32_sel_low32bit[4] __attribute__((aligned(16))) = {0, 0xffffffff, 0xffffffff, 0xffffffff};

#define RANGE_PS(dst, src1, src2, imm8) \
{ \
	__m128 tmp;	\
	switch (imm8 & 0x3) {\
		case 0:\
			tmp = vminq_f32(src1, src2);\
		break;\
		case 1:\
			tmp = vmaxq_f32(src1, src2);\
		break;\
		case 2:\
			tmp = vbslq_f32(vcaleq_f32(src1, src2), src1, src2);\
		break;\
		case 3:\
			tmp = vbslq_f32(vcaleq_f32(src1, src2), src2, src1);\
		break;\
		default:\
		break;\
	}\
	switch (imm8 & 0xc) {\
		case 0:\
			dst = vbslq_f32(vdupq_n_u32(0x80000000), src1, tmp);\
		break;\
		case 4:\
			dst = tmp;\
		break;\
		case 8:\
			dst = vbslq_f32(vdupq_n_u32(0x80000000), vdupq_n_f32(1.0), tmp);\
		break;\
		case 12:\
			dst = vbslq_f32(vdupq_n_u32(0x80000000), vdupq_n_f32(-1.0), tmp);\
		break;\
		default:\
		break;\
	}\
}



FORCE_INLINE __m128i _mm_sha1rnds4_epu32(__m128i a, __m128i b, const int func)
{
#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 8) && (__GNUC_PATCHLEVEL__ == 5)
	__asm__ __volatile__("SHA1C %q[res],%s[func],%[k].4S \n\t" :[res] "+w" (a) :[func] "w" (func), [k] "w" (b));
	return a;
#else
	__m128i result_m128i;
	result_m128i.vect_u32 = vsha1cq_u32(a.vect_u32, func, b.vect_u32);
	return result_m128i;
#endif
}
