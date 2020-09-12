#ifndef MAIN_H
#define MAIN_H

#include "testdata.h"

#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64__) || \
    defined(__ia64) || defined(__ia64__)
#  ifndef SimdX86_64
#    define SimdX86_64
#  endif
#elif defined(__arm__) || defined(__TARGET_ARCH_ARM) || defined(_M_ARM)
#  ifndef SimdARM
#    define SimdARM
#  endif
#elif defined(__aarch64__) || defined(_M_ARM64)
#  ifndef SimdAArch64
#    define SimdAArch64
#  endif
#else
#  ifndef SimdSimulate
#    define SimdSimulate
#  endif
#endif

#ifndef UNUSED
#define UNUSED(param) ((void)(param))
#endif

#ifndef aSizeOf
#define aSizeOf(B) (sizeof(B) / sizeof(B[0]))
#endif

#if defined(SimdSimulate)

#ifndef __int8
#define __int8 char
#endif

#ifndef __int16
#define __int16 short
#endif

#ifndef __int32
#define __int32 int
#endif

#ifndef __int64
#define __int64 long long
#endif

#ifndef __uint8
#define __uint8 unsigned char
#endif

#ifndef __uint16
#define __uint16 unsigned short
#endif

#ifndef __uint32
#define __uint32 unsigned int
#endif

#ifndef __uint64
#define __uint64 unsigned long long
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

#ifndef _MM_CMPINT_ENUM
#define _MM_CMPINT_ENUM int
#endif

typedef long long __m128i __attribute__ ((__vector_size__ (16), __may_alias__));
typedef double __m128d __attribute__ ((__vector_size__ (16), __may_alias__));
typedef long long __m128i_u __attribute__ ((__vector_size__ (16), __may_alias__, __aligned__ (1)));
typedef double __m128d_u __attribute__ ((__vector_size__ (16), __may_alias__, __aligned__ (1)));

typedef float __m256 __attribute__ ((__vector_size__ (32), __may_alias__));
typedef long long __m256i __attribute__ ((__vector_size__ (32), __may_alias__));
typedef double __m256d __attribute__ ((__vector_size__ (32), __may_alias__));

typedef float __m256_u __attribute__ ((__vector_size__ (32),
                       __may_alias__, __aligned__ (1)));
typedef long long __m256i_u __attribute__ ((__vector_size__ (32),
                        __may_alias__, __aligned__ (1)));
typedef double __m256d_u __attribute__ ((__vector_size__ (32),
                     __may_alias__, __aligned__ (1)));

typedef float __m512 __attribute__ ((__vector_size__ (64), __may_alias__));
typedef long long __m512i __attribute__ ((__vector_size__ (64), __may_alias__));
typedef double __m512d __attribute__ ((__vector_size__ (64), __may_alias__));

/* Unaligned version of the same type.  */
typedef float __m512_u __attribute__ ((__vector_size__ (64),
                                       __may_alias__, __aligned__ (1)));
typedef long long __m512i_u __attribute__ ((__vector_size__ (64),
                                            __may_alias__, __aligned__ (1)));
typedef double __m512d_u __attribute__ ((__vector_size__ (64),
                                         __may_alias__, __aligned__ (1)));


extern int _mm_cmpestrs (__m128i a, int la, __m128i b, int lb, const int imm8);
extern int _mm_cmpestrz (__m128i a, int la, __m128i b, int lb, const int imm8);
extern int _mm_cmpistrs (__m128i a, __m128i b, const int imm8);
extern int _mm_cmpistrz (__m128i a, __m128i b, const int imm8);

extern __mmask8 _mm_cmp_epi16_mask (__m128i a, __m128i b, const int imm8);
extern __mmask8 _mm_mask_cmp_epi16_mask (__mmask8 k1, __m128i a, __m128i b, const int imm8);
extern __mmask16 _mm256_cmp_epi16_mask (__m256i a, __m256i b, const int imm8);
extern __mmask16 _mm256_mask_cmp_epi16_mask (__mmask16 k1, __m256i a, __m256i b, const int imm8);
extern __mmask32 _mm512_cmp_epi16_mask (__m512i a, __m512i b, const int imm8);
extern __mmask32 _mm512_mask_cmp_epi16_mask (__mmask32 k1, __m512i a, __m512i b, const int imm8);

extern __mmask8 _mm_cmp_epi32_mask (__m128i a, __m128i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm_mask_cmp_epi32_mask (__mmask8 k1, __m128i a, __m128i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm256_cmp_epi32_mask (__m256i a, __m256i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm256_mask_cmp_epi32_mask (__mmask8 k1, __m256i a, __m256i b, _MM_CMPINT_ENUM imm8);
extern __mmask16 _mm512_cmp_epi32_mask (__m512i a, __m512i b, _MM_CMPINT_ENUM imm8);
extern __mmask16 _mm512_mask_cmp_epi32_mask (__mmask16 k1, __m512i a, __m512i b, _MM_CMPINT_ENUM imm8);

extern __mmask8 _mm_cmp_epi64_mask (__m128i a, __m128i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm_mask_cmp_epi64_mask (__mmask8 k1, __m128i a, __m128i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm256_cmp_epi64_mask (__m256i a, __m256i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm256_mask_cmp_epi64_mask (__mmask8 k1, __m256i a, __m256i b, _MM_CMPINT_ENUM imm8);
extern __mmask8 _mm512_cmp_epi64_mask (__m512i a, __m512i b, _MM_CMPINT_ENUM imm8);

extern __mmask16 _mm_cmp_epu8_mask (__m128i a, __m128i b, const int imm8);
extern __mmask16 _mm_mask_cmp_epu8_mask (__mmask16 k1, __m128i a, __m128i b, const int imm8);
extern __mmask32 _mm256_cmp_epu8_mask (__m256i a, __m256i b, const int imm8);
extern __mmask32 _mm256_mask_cmp_epu8_mask (__mmask32 k1, __m256i a, __m256i b, const int imm8);
extern __mmask64 _mm512_cmp_epu8_mask (__m512i a, __m512i b, const int imm8);
extern __mmask64 _mm512_mask_cmp_epu8_mask (__mmask64 k1, __m512i a, __m512i b, const int imm8);

extern __m128d _mm_cmp_pd (__m128d a, __m128d b, const int imm8);
extern __mmask8 _mm_cmp_pd_mask (__m128d a, __m128d b, const int imm8);
extern __mmask8 _mm_mask_cmp_pd_mask (__mmask8 k1, __m128d a, __m128d b, const int imm8);
extern __m256d _mm256_cmp_pd (__m256d a, __m256d b, const int imm8);
extern __mmask8 _mm256_cmp_pd_mask (__m256d a, __m256d b, const int imm8);
extern __mmask8 _mm256_mask_cmp_pd_mask (__mmask8 k1, __m256d a, __m256d b, const int imm8);
extern __mmask8 _mm512_cmp_pd_mask (__m512d a, __m512d b, const int imm8);

// 不在需求范围内
extern __mmask8 _mm_cmp_epu16_mask (__m128i a, __m128i b, const int imm8);
extern __mmask8 _mm_mask_cmp_epu16_mask (__mmask8 k1, __m128i a, __m128i b, const int imm8);
extern __mmask16 _mm256_cmp_epu16_mask (__m256i a, __m256i b, const int imm8);
extern __mmask16 _mm256_mask_cmp_epu16_mask (__mmask16 k1, __m256i a, __m256i b, const int imm8);
extern __mmask32 _mm512_cmp_epu16_mask (__m512i a, __m512i b, const int imm8);
extern __mmask32 _mm512_mask_cmp_epu16_mask (__mmask32 k1, __m512i a, __m512i b, const int imm8);

#elif defined(SimdARM)

#elif defined(SimdAArch64)

#include "simd_ins.h"
/*
FORCE_INLINE __m256i _mm256_maskz_srlv_epi64(__mmask8 k, __m256i a, __m256i count)
{
    static int64x2_t _zero = {0};

    __m256i   O;
    if (likely(k & 0x0f))
    {
        O.vs64[0] = vshlq_s64(a.vs64[0], vsubq_s64(_zero, count.vs64[0]));
        O.vs64[1] = vshlq_s64(a.vs64[1], vsubq_s64(_zero, count.vs64[1]));
        if (!(k & 0x01))
            O.vs64[0] = vsetq_lane_s64((int64_t)0, O.vs64[0], 0);
        if (!(k & 0x02))
            O.vs64[0] = vsetq_lane_s64((int64_t)0, O.vs64[0], 1);
        if (!(k & 0x04))
            O.vs64[1] = vsetq_lane_s64((int64_t)0, O.vs64[1], 0);
        if (!(k & 0x08))
            O.vs64[1] = vsetq_lane_s64((int64_t)0, O.vs64[1], 1);
    }
    else
    {
        O.vs64[0] = vdupq_n_s64(0);
        O.vs64[1] = vdupq_n_s64(0);
    }

    return O;
}

FORCE_INLINE __m256i _mm256_mask_srlv_epi64(__m256i src, __mmask8 k, __m256i a, __m256i count)
{
    static int64x2_t _zero = {0};
    __m256i   O;
    if (likely(k & 0x0f))
    {
        O.vs64[0] = vshlq_s64(a.vs64[0], vsubq_s64(_zero, count.vs64[0]));
        O.vs64[1] = vshlq_s64(a.vs64[1], vsubq_s64(_zero, count.vs64[1]));
        if (!(k & 0x01))
            O.vs64[0] = vsetq_lane_s64(vgetq_lane_s64(src.vs64[0], 0), O.vs64[0], 0);
        if (!(k & 0x02))
            O.vs64[0] = vsetq_lane_s64(vgetq_lane_s64(src.vs64[0], 1), O.vs64[0], 1);
        if (!(k & 0x04))
            O.vs64[1] = vsetq_lane_s64(vgetq_lane_s64(src.vs64[1], 0), O.vs64[1], 0);
        if (!(k & 0x08))
            O.vs64[1] = vsetq_lane_s64(vgetq_lane_s64(src.vs64[1], 1), O.vs64[1], 1);
    }
    else
    {
        O.vs64[0] = src.vs64[0];
        O.vs64[1] = src.vs64[1];
    }

    return O;
}

FORCE_INLINE __mmask8 _mm_cmp_epu16_mask (__m128i a, __m128i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        uint16_t u16[8];
    }_U;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_u16(a.vect_u16, b.vect_u16); break;
    case 1: _U.R = vcltq_u16(a.vect_u16, b.vect_u16); break;
    case 2: _U.R = vcleq_u16(a.vect_u16, b.vect_u16); break;
    case 3: break;
    case 4: _U.R = vceqq_u16(a.vect_u16, b.vect_u16); _U.R = vmvnq_u16(_U.R); break;
    case 5: _U.R = vcgeq_u16(a.vect_u16, b.vect_u16); break;
    case 6: _U.R = vcgtq_u16(a.vect_u16, b.vect_u16); break;
    case 7: break;
    }

    return (__mmask8)(___CombMask_16i(_U.u16, 0));
}
FORCE_INLINE __mmask8 _mm_mask_cmp_epu16_mask (__mmask8 k1, __m128i a, __m128i b, const int imm8)
{
    return _mm_cmp_epu16_mask(a, b, imm8) & k1;
}
FORCE_INLINE __mmask16 _mm256_cmp_epu16_mask (__m256i a, __m256i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        uint16_t u16[8];
    }_U[2];
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vceqq_u16(a.vect_u16[1], b.vect_u16[1]);
        break;
    case 1:
        _U[0].R = vcltq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcltq_u16(a.vect_u16[1], b.vect_u16[1]);
        break;
    case 2:
        _U[0].R = vcleq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcleq_u16(a.vect_u16[1], b.vect_u16[1]);
        break;
    case 3: break;
    case 4:
        _U[0].R = vceqq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vceqq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[0].R = vmvnq_u16(_U[0].R);
        _U[1].R = vmvnq_u16(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcgeq_u16(a.vect_u16[1], b.vect_u16[1]);
        break;
    case 6:
        _U[0].R = vcgtq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcgtq_u16(a.vect_u16[1], b.vect_u16[1]);
        break;
    case 7: break;

    }

    return ((__mmask16)___CombMask_16i(_U[0].u16, 0)) |
            ((__mmask16)___CombMask_16i(_U[1].u16, 0) << 8);
}
FORCE_INLINE __mmask16 _mm256_mask_cmp_epu16_mask (__mmask16 k1, __m256i a, __m256i b, const int imm8)
{
    return _mm256_cmp_epu16_mask(a, b, imm8) & k1;
}
FORCE_INLINE __mmask32 _mm512_cmp_epu16_mask (__m512i a, __m512i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        uint16_t u16[8];
    }_U[4];
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vceqq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[2].R = vceqq_u16(a.vect_u16[2], b.vect_u16[2]);
        _U[3].R = vceqq_u16(a.vect_u16[3], b.vect_u16[3]);
        break;
    case 1:
        _U[0].R = vcltq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcltq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[2].R = vcltq_u16(a.vect_u16[2], b.vect_u16[2]);
        _U[3].R = vcltq_u16(a.vect_u16[3], b.vect_u16[3]);
        break;
    case 2:
        _U[0].R = vcleq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcleq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[2].R = vcleq_u16(a.vect_u16[2], b.vect_u16[2]);
        _U[3].R = vcleq_u16(a.vect_u16[3], b.vect_u16[3]);
        break;
    case 3: break;
    case 4:
        _U[0].R = vceqq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vceqq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[2].R = vceqq_u16(a.vect_u16[2], b.vect_u16[2]);
        _U[3].R = vceqq_u16(a.vect_u16[3], b.vect_u16[3]);
        _U[0].R = vmvnq_u16(_U[0].R);
        _U[1].R = vmvnq_u16(_U[1].R);
        _U[2].R = vmvnq_u16(_U[2].R);
        _U[3].R = vmvnq_u16(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcgeq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[2].R = vcgeq_u16(a.vect_u16[2], b.vect_u16[2]);
        _U[3].R = vcgeq_u16(a.vect_u16[3], b.vect_u16[3]);
        break;
    case 6:
        _U[0].R = vcgtq_u16(a.vect_u16[0], b.vect_u16[0]);
        _U[1].R = vcgtq_u16(a.vect_u16[1], b.vect_u16[1]);
        _U[2].R = vcgtq_u16(a.vect_u16[2], b.vect_u16[2]);
        _U[3].R = vcgtq_u16(a.vect_u16[3], b.vect_u16[3]);
        break;
    case 7: break;

    }

    return ((__mmask32)___CombMask_16i(_U[0].u16, 0)) |
            ((__mmask32)___CombMask_16i(_U[1].u16, 0) << 8)|
            ((__mmask32)___CombMask_16i(_U[2].u16, 0) << 16)|
            ((__mmask32)___CombMask_16i(_U[3].u16, 0) << 24);
}
FORCE_INLINE __mmask32 _mm512_mask_cmp_epu16_mask (__mmask32 k1, __m512i a, __m512i b, const int imm8)
{
    return _mm512_cmp_epu16_mask(a, b, imm8) & k1;
}

static const  struct
{
    unsigned char k;
    int64_t a[4];
    int64_t b[4];
    int64_t expect[4];
}
_mm2656_srlv_zdata[] =
{
{0x01,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x0f, 0x00, 0x00, 0x00}
},
{0x02,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x00, 0x0f, 0x00, 0x00}
},
{0x04,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x00, 0x00, 0x0f, 0x00}
},
{0x08,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x00, 0x00, 0x00, 0x0f}
},
{0x0f,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x0f, 0x0f, 0x0f, 0x0f}
},

{0xf0,
{0xf000000000, 0xf0000000000, 0xf00000000000, 0xf000000000000},
{4, 8, 12, 16},
{0x00, 0x00, 0x00, 0x00}
},
};

static const  struct
{
    unsigned char k;
    int64_t a[4];
    int64_t b[4];
    int64_t s[4];
    int64_t expect[4];
}
_mm2656_srlv_data[] =
{
{0x01,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x01, 0x02, 0x04, 0x08},
{0x0f, 0x02, 0x04, 0x08}
},

{0x02,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x10, 0x20, 0x40, 0x80},
{0x10, 0x0f, 0x40, 0x80}
},
{0x04,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x11, 0x21, 0x41, 0x81},
{0x11, 0x21, 0x0f, 0x81}
},
{0x08,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0x12, 0x22, 0x42, 0x82},
{0x12, 0x22, 0x42, 0x0f}
},
{0x0f,
{0xf0, 0xf00, 0xf000, 0xf0000},
{4, 8, 12, 16},
{0xf1, 0xf2, 0xf3, 0xf4},
{0x0f, 0x0f, 0x0f, 0x0f}
},

{0xf0,
{0xf000000000, 0xf0000000000, 0xf00000000000, 0xf000000000000},
{4, 8, 12, 16},
{0xf10, 0xf20, 0xf30, 0xf40},
{0xf10, 0xf20, 0xf30, 0xf40}
},
};

*/
#elif defined(SimdX86_64)

#include <immintrin.h>

#endif

#endif // MAIN_H
