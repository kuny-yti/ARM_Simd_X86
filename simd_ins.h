#ifndef SIMD_INS_H
#define SIMD_INS_H

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
///< 编译器屏障
#ifndef CompilerBarrier
#define CompilerBarrier() __asm__ __volatile__("": : :"memory")
#endif
#ifndef Mem512Align
#define Mem512Align __attribute__((aligned(64)))
#endif
#ifndef Mem256Align
#define Mem256Align __attribute__((aligned(32)))
#endif
#ifndef Mem128Align
#define Mem128Align __attribute__((aligned(16)))
#endif

#ifndef _MM_CMPINT_ENUM
#define _MM_CMPINT_ENUM int
#endif

#define _MM_CMPINT_EQ	    0x0
#define _MM_CMPINT_LT	    0x1
#define _MM_CMPINT_LE	    0x2
#define _MM_CMPINT_UNUSED   0x3
#define _MM_CMPINT_FALSE    0x3
#define _MM_CMPINT_NE	    0x4
#define _MM_CMPINT_NLT	    0x5
#define _MM_CMPINT_GE	    0x5
#define _MM_CMPINT_NLE	    0x6
#define _MM_CMPINT_GT	    0x6
#define _MM_CMPINT_TRUE     0x7

/* Compare */
#ifndef _CMP_EQ_OQ
# define _CMP_EQ_OQ    0x00 /* Equal (ordered, non-signaling)  */
# define _CMP_LT_OS    0x01 /* Less-than (ordered, signaling)  */
# define _CMP_LE_OS    0x02 /* Less-than-or-equal (ordered, signaling)  */
# define _CMP_UNORD_Q  0x03 /* Unordered (non-signaling)  */
# define _CMP_NEQ_UQ   0x04 /* Not-equal (unordered, non-signaling)  */
# define _CMP_NLT_US   0x05 /* Not-less-than (unordered, signaling)  */
# define _CMP_NLE_US   0x06 /* Not-less-than-or-equal (unordered, signaling)  */
# define _CMP_ORD_Q    0x07 /* Ordered (nonsignaling)   */
# define _CMP_EQ_UQ    0x08 /* Equal (unordered, non-signaling)  */
# define _CMP_NGE_US   0x09 /* Not-greater-than-or-equal (unord, signaling)  */
# define _CMP_NGT_US   0x0a /* Not-greater-than (unordered, signaling)  */
# define _CMP_FALSE_OQ 0x0b /* False (ordered, non-signaling)  */
# define _CMP_NEQ_OQ   0x0c /* Not-equal (ordered, non-signaling)  */
# define _CMP_GE_OS    0x0d /* Greater-than-or-equal (ordered, signaling)  */
# define _CMP_GT_OS    0x0e /* Greater-than (ordered, signaling)  */
# define _CMP_TRUE_UQ  0x0f /* True (unordered, non-signaling)  */
# define _CMP_EQ_OS    0x10 /* Equal (ordered, signaling)  */
# define _CMP_LT_OQ    0x11 /* Less-than (ordered, non-signaling)  */
# define _CMP_LE_OQ    0x12 /* Less-than-or-equal (ordered, non-signaling)  */
# define _CMP_UNORD_S  0x13 /* Unordered (signaling)  */
# define _CMP_NEQ_US   0x14 /* Not-equal (unordered, signaling)  */
# define _CMP_NLT_UQ   0x15 /* Not-less-than (unordered, non-signaling)  */
# define _CMP_NLE_UQ   0x16 /* Not-less-than-or-equal (unord, non-signaling)  */
# define _CMP_ORD_S    0x17 /* Ordered (signaling)  */
# define _CMP_EQ_US    0x18 /* Equal (unordered, signaling)  */
# define _CMP_NGE_UQ   0x19 /* Not-greater-than-or-equal (unord, non-sign)  */
# define _CMP_NGT_UQ   0x1a /* Not-greater-than (unordered, non-signaling)  */
# define _CMP_FALSE_OS 0x1b /* False (ordered, signaling)  */
# define _CMP_NEQ_OS   0x1c /* Not-equal (ordered, signaling)  */
# define _CMP_GE_OQ    0x1d /* Greater-than-or-equal (ordered, non-signaling)  */
# define _CMP_GT_OQ    0x1e /* Greater-than (ordered, non-signaling)  */
# define _CMP_TRUE_US  0x1f /* True (unordered, signaling)  */
#endif

/* Rounding mode macros. */
#define _MM_FROUND_TO_NEAREST_INT	0x00
#define _MM_FROUND_TO_NEG_INF		0x01
#define _MM_FROUND_TO_POS_INF		0x02
#define _MM_FROUND_TO_ZERO		    0x03
#define _MM_FROUND_CUR_DIRECTION	0x04

#define _MM_FROUND_RAISE_EXC		0x00
#define _MM_FROUND_NO_EXC		    0x08

#define _MM_FROUND_NINT		\
  (_MM_FROUND_TO_NEAREST_INT | _MM_FROUND_RAISE_EXC)
#define _MM_FROUND_FLOOR	\
  (_MM_FROUND_TO_NEG_INF | _MM_FROUND_RAISE_EXC)
#define _MM_FROUND_CEIL		\
  (_MM_FROUND_TO_POS_INF | _MM_FROUND_RAISE_EXC)
#define _MM_FROUND_TRUNC	\
  (_MM_FROUND_TO_ZERO | _MM_FROUND_RAISE_EXC)
#define _MM_FROUND_RINT		\
  (_MM_FROUND_CUR_DIRECTION | _MM_FROUND_RAISE_EXC)
#define _MM_FROUND_NEARBYINT	\
  (_MM_FROUND_CUR_DIRECTION | _MM_FROUND_NO_EXC)

#if defined(SimdAArch64)

#include "avx2neon.h"

#if !defined(___Zero) || !defined (___False)
static const union
{
    uint32_t    u32[16];
    float32_t   f32[16];
    int32_t     s32[16];
    float32x4_t f32x4[4];
    uint32x4_t  u32x4[4];
    int32x4_t   s32x4[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128      f128[4];
    __m256      f256[2];
    __m512      f512;
} ____Zero32 Mem512Align = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
static const union
{
    uint64_t    u64[8];
    int64_t     s64[8];
    float64_t   f64[8];
    float64x2_t f64x2[4];
    uint64x2_t  u64x2[4];
    int64x2_t   s64x2[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____Zero Mem512Align = {{0, 0, 0, 0, 0, 0, 0, 0}};
#define ___Zero ____Zero
#define ___False ____Zero
#define ___fZero ____Zero32
#define ___fFalse ____Zero32
#endif

#if !defined(___InfP)
static const union
{
    float32_t   f32[16];
    uint32_t    u32[16];
    int32_t     s32[16];
    float32x4_t f32x4[4];
    uint32x4_t  u32x4[4];
    int32x4_t   s32x4[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____InfP32 Mem512Align = {{1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0,
                             1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0,
                             1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0,
                             1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0}};
static const union
{
    float64_t   f64[8];
    int64_t     s64[8];
    uint64_t    u64[8];
    float64x2_t f64x2[4];
    uint64x2_t  u64x2[4];
    int64x2_t   s64x2[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____InfP Mem512Align = {{1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0,
                           1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0}};
#define ___InfP ____InfP
#define ___fInfP ____InfP32
#endif

#if !defined(___InfN)
static const union
{
    float32_t   f32[16];
    uint32_t    u32[16];
    int32_t     s32[16];
    float32x4_t f32x4[4];
    uint32x4_t  u32x4[4];
    int32x4_t   s32x4[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____InfN32 Mem512Align = {{-1.0/0.0, -1.0/0.0, -1.0/0.0, -1.0/0.0,
                             -1.0/0.0, -1.0/0.0, -1.0/0.0, -1.0/0.0,
                             -1.0/0.0, -1.0/0.0, -1.0/0.0, -1.0/0.0,
                             -1.0/0.0, -1.0/0.0, -1.0/0.0, -1.0/0.0}};
static const union
{
    float64_t   f64[8];
    int64_t     s64[8];
    uint64_t    u64[8];
    float64x2_t f64x2[4];
    uint64x2_t  u64x2[4];
    int64x2_t   s64x2[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____InfN Mem512Align = {{-1.0/0.0, -1.0/0.0, -1.0/0.0, -1.0/0.0,
                           -1.0/0.0, -1.0/0.0, -1.0/0.0, -1.0/0.0}};
#define ___InfN ____InfN
#define ___fInfN ____InfN32
#endif

#if !defined(___NaNs) || !defined (___Neg)
static const union
{
    uint32_t    u32[16];
    int32_t     s32[16];
    float32_t   f32[16];
    float32x4_t f32x4[4];
    uint32x4_t  u32x4[4];
    int32x4_t   s32x4[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128      f128[4];
    __m256      f256[2];
    __m512      f512;
} ____Mone32 Mem512Align = {{-1, -1, -1, -1, -1, -1, -1, -1,
                             -1, -1, -1, -1, -1, -1, -1, -1}};
static const union
{
    uint64_t    u64[8];
    int64_t     s64[8];
    float64_t   f64[8];
    float64x2_t f64x2[4];
    uint64x2_t  u64x2[4];
    int64x2_t   s64x2[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____Mone Mem512Align = {{-1, -1, -1, -1, -1, -1, -1, -1}};
#define ___NaNs  ____Mone
#define ___Neg  ____Mone
#define ___True ____Mone
#define ___fNaNs ____Mone32
#define ___fTrue ____Mone32
#endif

#if !defined(___NaNq)
static const union
{
    float32_t   f32[16];
    uint32_t    u32[16];
    int32_t     s32[16];
    float32x4_t f32x4[4];
    uint32x4_t  u32x4[4];
    int32x4_t   s32x4[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____Nanq32 Mem512Align = {{0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0,
                             0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0,
                             0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0,
                             0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0}};
static const union
{
    float64_t   f64[8];
    uint64_t    u64[8];
    int64_t     s64[8];
    float64x2_t f64x2[4];
    uint64x2_t  u64x2[4];
    int64x2_t   s64x2[4];
    __m128i     s128[4];
    __m256i     s256[2];
    __m512i     s512;
    __m128d     f128[4];
    __m256d     f256[2];
    __m512d     f512;
} ____Nanq Mem512Align = {{0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0,
                           0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0}};
#define ___NaNq  ____Nanq
#define ___fNaNq  ____Nanq32
#endif

#define ___CombMask_64i(u16, B) (\
    (((u16)[(B)+0]) ? (0x01 << (B)) : 0) | (((u16)[(B)+1]) ? (0x02 << (B)) : 0))

#define ___CombMask_32i(u16, B) (\
    (((u16)[(B)+0]) ? (0x01 << (B)) : 0) | (((u16)[(B)+1]) ? (0x02 << (B)) : 0) | \
    (((u16)[(B)+2]) ? (0x04 << (B)) : 0) | (((u16)[(B)+3]) ? (0x08 << (B)) : 0))

#define ___CombMask_16i(u16, B) (\
    (((u16)[(B)+0]) ? (0x01 << (B)) : 0) | (((u16)[(B)+1]) ? (0x02 << (B)) : 0) | \
    (((u16)[(B)+2]) ? (0x04 << (B)) : 0) | (((u16)[(B)+3]) ? (0x08 << (B)) : 0) | \
    (((u16)[(B)+4]) ? (0x10 << (B)) : 0) | (((u16)[(B)+5]) ? (0x20 << (B)) : 0) | \
    (((u16)[(B)+6]) ? (0x40 << (B)) : 0) | (((u16)[(B)+7]) ? (0x80 << (B)) : 0))

#define ___CombMask_8i(u16, B) (\
    (((u16)[(B)+0]) ? (0x01 << (B)) : 0) | (((u16)[(B)+1]) ? (0x02 << (B)) : 0) | \
    (((u16)[(B)+2]) ? (0x04 << (B)) : 0) | (((u16)[(B)+3]) ? (0x08 << (B)) : 0) | \
    (((u16)[(B)+4]) ? (0x10 << (B)) : 0) | (((u16)[(B)+5]) ? (0x20 << (B)) : 0) | \
    (((u16)[(B)+6]) ? (0x40 << (B)) : 0) | (((u16)[(B)+7]) ? (0x80 << (B)) : 0) | \
    (((u16)[(B)+8]) ? (0x0100 << (B)) : 0) | (((u16)[(B)+9]) ? (0x0200 << (B)) : 0) | \
    (((u16)[(B)+10]) ? (0x0400 << (B)) : 0) | (((u16)[(B)+11]) ? (0x0800 << (B)) : 0) | \
    (((u16)[(B)+12]) ? (0x1000 << (B)) : 0) | (((u16)[(B)+13]) ? (0x2000 << (B)) : 0) | \
    (((u16)[(B)+14]) ? (0x4000 << (B)) : 0) | (((u16)[(B)+15]) ? (0x8000 << (B)) : 0))

// 6-10
FORCE_INLINE int _mm_cmpestrs (__m128i a, int la, __m128i b, int lb, const int imm8)
{
    UNUSED(a);
    UNUSED(b);
    UNUSED(lb);
    return (la < ((imm8 & 0x01) ? 8 : 16));
}
FORCE_INLINE int _mm_cmpestrz (__m128i a, int la, __m128i b, int lb, const int imm8)
{
    UNUSED(a);
    UNUSED(b);
    UNUSED(la);
    return (lb < ((imm8 & 0x01) ? 8 : 16));
}
FORCE_INLINE int _mm_cmpistrs (__m128i a, __m128i b, const int imm8)
{
    union
    {
        uint16x8_t u16;
        uint8x16_t u8;
        uint64_t   u64[2];
    } _T Mem128Align;

    UNUSED(b);

    if (likely(imm8 & 0x01))
        _T.u16 = vceqq_u16(vdupq_n_u16(0x0), a.vect_u16);
    else
        _T.u8 = vceqq_u8(vdupq_n_u8(0x0), a.vect_u8);
    return  (_T.u64[0] | _T.u64[1]) ? 1 : 0;
}
FORCE_INLINE int _mm_cmpistrz (__m128i a, __m128i b, const int imm8)
{
    union
    {
        uint16x8_t u16;
        uint8x16_t u8;
        uint64_t   u64[2];
    } _T Mem128Align;

    UNUSED(a);

    if (likely(imm8 & 0x01))
        _T.u16 = vceqq_u16(vdupq_n_u16(0x0), b.vect_u16);
    else
        _T.u8 = vceqq_u8(vdupq_n_u8(0x0), b.vect_u8);
    return  (_T.u64[0] | _T.u64[1]) ? 1 : 0;
}

FORCE_INLINE __mmask8 _mm_cmp_epi16_mask (__m128i a, __m128i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        int16_t u16[8];
    } _U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_s16(a.vect_s16, b.vect_s16); break;
    case 1: _U.R = vcltq_s16(a.vect_s16, b.vect_s16); break;
    case 2: _U.R = vcleq_s16(a.vect_s16, b.vect_s16); break;
    case 3: return 0x00;
    case 4: _U.R = vceqq_s16(a.vect_s16, b.vect_s16); _U.R = vmvnq_u16(_U.R);break;
    case 5: _U.R = vcgeq_s16(a.vect_s16, b.vect_s16); break;
    case 6: _U.R = vcgtq_s16(a.vect_s16, b.vect_s16); break;
    case 7: return 0xff;
    }

    return (__mmask8)(___CombMask_16i(_U.u16, 0));
}
FORCE_INLINE __mmask8 _mm_mask_cmp_epi16_mask (__mmask8 k1, __m128i a, __m128i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        int16_t u16[8];
    } _U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_s16(a.vect_s16, b.vect_s16); break;
    case 1: _U.R = vcltq_s16(a.vect_s16, b.vect_s16); break;
    case 2: _U.R = vcleq_s16(a.vect_s16, b.vect_s16); break;
    case 3: return 0x00;
    case 4: _U.R = vceqq_s16(a.vect_s16, b.vect_s16); _U.R = vmvnq_u16(_U.R);break;
    case 5: _U.R = vcgeq_s16(a.vect_s16, b.vect_s16); break;
    case 6: _U.R = vcgtq_s16(a.vect_s16, b.vect_s16); break;
    case 7: return 0xff & k1;
    }

    return (__mmask8)(___CombMask_16i(_U.u16, 0)) & k1;
}
FORCE_INLINE __mmask16 _mm256_cmp_epi16_mask (__m256i a, __m256i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        int16_t u16[8];
    } _U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 1:
        _U[0].R = vcltq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcltq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 2:
        _U[0].R = vcleq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcleq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 3: return 0x0000;

    case 4:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[0].R = vmvnq_u16(_U[0].R);
        _U[1].R = vmvnq_u16(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgeq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 6:
        _U[0].R = vcgtq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgtq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 7: return 0xffff;
    }

    return ((__mmask16)___CombMask_16i(_U[0].u16, 0)) |
            ((__mmask16)___CombMask_16i(_U[1].u16, 0) << 8);
}
FORCE_INLINE __mmask16 _mm256_mask_cmp_epi16_mask (__mmask16 k1, __m256i a, __m256i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        int16_t u16[8];
    } _U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 1:
        _U[0].R = vcltq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcltq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 2:
        _U[0].R = vcleq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcleq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 3: return 0x0000;

    case 4:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[0].R = vmvnq_u16(_U[0].R);
        _U[1].R = vmvnq_u16(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgeq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 6:
        _U[0].R = vcgtq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgtq_s16(a.vect_s16[1], b.vect_s16[1]);
        break;
    case 7: return 0xffff & k1;
    }

    return (((__mmask16)___CombMask_16i(_U[0].u16, 0)) |
            ((__mmask16)___CombMask_16i(_U[1].u16, 0) << 8)) & k1;
}
FORCE_INLINE __mmask32 _mm512_cmp_epi16_mask (__m512i a, __m512i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        int16_t u16[8];
    } _U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vceqq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vceqq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 1:
        _U[0].R = vcltq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcltq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcltq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcltq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 2:
        _U[0].R = vcleq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcleq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcleq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcleq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 3: return 0x00000000;
    case 4:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vceqq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vceqq_s16(a.vect_s16[3], b.vect_s16[3]);
        _U[0].R = vmvnq_u16(_U[0].R);
        _U[1].R = vmvnq_u16(_U[1].R);
        _U[2].R = vmvnq_u16(_U[2].R);
        _U[3].R = vmvnq_u16(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgeq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcgeq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcgeq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 6:
        _U[0].R = vcgtq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgtq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcgtq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcgtq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 7: return 0xffffffff;
    }

    return ((__mmask32)___CombMask_16i(_U[0].u16, 0)) |
            ((__mmask32)___CombMask_16i(_U[1].u16, 0) << 8)|
            ((__mmask32)___CombMask_16i(_U[2].u16, 0) << 16)|
            ((__mmask32)___CombMask_16i(_U[3].u16, 0) << 24);
}
FORCE_INLINE __mmask32 _mm512_mask_cmp_epi16_mask (__mmask32 k1, __m512i a, __m512i b, const int imm8)
{
    union
    {
        uint16x8_t R;
        int16_t u16[8];
    } _U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vceqq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vceqq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 1:
        _U[0].R = vcltq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcltq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcltq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcltq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 2:
        _U[0].R = vcleq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcleq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcleq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcleq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 3: return 0x00000000;
    case 4:
        _U[0].R = vceqq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vceqq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vceqq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vceqq_s16(a.vect_s16[3], b.vect_s16[3]);
        _U[0].R = vmvnq_u16(_U[0].R);
        _U[1].R = vmvnq_u16(_U[1].R);
        _U[2].R = vmvnq_u16(_U[2].R);
        _U[3].R = vmvnq_u16(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgeq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcgeq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcgeq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 6:
        _U[0].R = vcgtq_s16(a.vect_s16[0], b.vect_s16[0]);
        _U[1].R = vcgtq_s16(a.vect_s16[1], b.vect_s16[1]);
        _U[2].R = vcgtq_s16(a.vect_s16[2], b.vect_s16[2]);
        _U[3].R = vcgtq_s16(a.vect_s16[3], b.vect_s16[3]);
        break;
    case 7: return 0xffffffff & k1;
    }

    return (((__mmask32)___CombMask_16i(_U[0].u16, 0)) |
            ((__mmask32)___CombMask_16i(_U[1].u16, 0) << 8)|
            ((__mmask32)___CombMask_16i(_U[2].u16, 0) << 16)|
            ((__mmask32)___CombMask_16i(_U[3].u16, 0) << 24))& k1;
}

FORCE_INLINE __mmask8 _mm_cmp_epi32_mask (__m128i a, __m128i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint32x4_t R;
        int32_t u32[4];
    } _U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_s32(a.vect_s32, b.vect_s32); break;
    case 1: _U.R = vcltq_s32(a.vect_s32, b.vect_s32); break;
    case 2: _U.R = vcleq_s32(a.vect_s32, b.vect_s32); break;
    case 3: return 0x00;
    case 4: _U.R = vceqq_s32(a.vect_s32, b.vect_s32); _U.R = vmvnq_u32(_U.R); break;
    case 5: _U.R = vcgeq_s32(a.vect_s32, b.vect_s32); break;
    case 6: _U.R = vcgtq_s32(a.vect_s32, b.vect_s32); break;
    case 7: return 0x0f;
    }

    return (__mmask8)(___CombMask_32i(_U.u32, 0));
}
FORCE_INLINE __mmask8 _mm_mask_cmp_epi32_mask (__mmask8 k1, __m128i a, __m128i b, _MM_CMPINT_ENUM imm8)
{

    union
    {
        uint32x4_t R;
        int32_t u32[4];
    } _U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_s32(a.vect_s32, b.vect_s32); break;
    case 1: _U.R = vcltq_s32(a.vect_s32, b.vect_s32); break;
    case 2: _U.R = vcleq_s32(a.vect_s32, b.vect_s32); break;
    case 3: return 0x00;
    case 4: _U.R = vceqq_s32(a.vect_s32, b.vect_s32); _U.R = vmvnq_u32(_U.R); break;
    case 5: _U.R = vcgeq_s32(a.vect_s32, b.vect_s32); break;
    case 6: _U.R = vcgtq_s32(a.vect_s32, b.vect_s32); break;
    case 7: return 0x0f & k1;
    }

    return (__mmask8)(___CombMask_32i(_U.u32, 0)) & k1;
}
FORCE_INLINE __mmask8 _mm256_cmp_epi32_mask (__m256i a, __m256i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint32x4_t R;
        int32_t u32[4];
    } _U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 1:
        _U[0].R = vcltq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcltq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 2:
        _U[0].R = vcleq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcleq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 3: return 0x00;
    case 4:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[0].R = vmvnq_u32(_U[0].R);
        _U[1].R = vmvnq_u32(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgeq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 6:
        _U[0].R = vcgtq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgtq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 7: return 0xff;
    }

    return ((__mmask8)___CombMask_32i(_U[0].u32, 0)) |
            ((__mmask8)___CombMask_32i(_U[1].u32, 0) << 4);
}
FORCE_INLINE __mmask8 _mm256_mask_cmp_epi32_mask (__mmask8 k1, __m256i a, __m256i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint32x4_t R;
        int32_t u32[4];
    } _U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 1:
        _U[0].R = vcltq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcltq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 2:
        _U[0].R = vcleq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcleq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 3: return 0x00;
    case 4:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[0].R = vmvnq_u32(_U[0].R);
        _U[1].R = vmvnq_u32(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgeq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 6:
        _U[0].R = vcgtq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgtq_s32(a.vect_s32[1], b.vect_s32[1]);
        break;
    case 7: return 0xff & k1;
    }

    return (((__mmask8)___CombMask_32i(_U[0].u32, 0)) |
            ((__mmask8)___CombMask_32i(_U[1].u32, 0) << 4)) & k1;
}
FORCE_INLINE __mmask16 _mm512_cmp_epi32_mask (__m512i a, __m512i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint32x4_t R;
        int32_t u32[4];
    }_U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vceqq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vceqq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 1:
        _U[0].R = vcltq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcltq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcltq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcltq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 2:
        _U[0].R = vcleq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcleq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcleq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcleq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 3: return 0x0000;
    case 4:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vceqq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vceqq_s32(a.vect_s32[3], b.vect_s32[3]);
        _U[0].R = vmvnq_u32(_U[0].R);
        _U[1].R = vmvnq_u32(_U[1].R);
        _U[2].R = vmvnq_u32(_U[2].R);
        _U[3].R = vmvnq_u32(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgeq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcgeq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcgeq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 6:
        _U[0].R = vcgtq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgtq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcgtq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcgtq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 7: return 0xffff;
    }

    return ((__mmask16)___CombMask_32i(_U[0].u32, 0)) |
            ((__mmask16)___CombMask_32i(_U[1].u32, 0) << 4)|
            ((__mmask16)___CombMask_32i(_U[2].u32, 0) << 8)|
            ((__mmask16)___CombMask_32i(_U[3].u32, 0) << 12);
}
FORCE_INLINE __mmask16 _mm512_mask_cmp_epi32_mask (__mmask16 k1, __m512i a, __m512i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint32x4_t R;
        int32_t u32[4];
    }_U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vceqq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vceqq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 1:
        _U[0].R = vcltq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcltq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcltq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcltq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 2:
        _U[0].R = vcleq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcleq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcleq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcleq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 3: return 0x0000;
    case 4:
        _U[0].R = vceqq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vceqq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vceqq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vceqq_s32(a.vect_s32[3], b.vect_s32[3]);
        _U[0].R = vmvnq_u32(_U[0].R);
        _U[1].R = vmvnq_u32(_U[1].R);
        _U[2].R = vmvnq_u32(_U[2].R);
        _U[3].R = vmvnq_u32(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgeq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcgeq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcgeq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 6:
        _U[0].R = vcgtq_s32(a.vect_s32[0], b.vect_s32[0]);
        _U[1].R = vcgtq_s32(a.vect_s32[1], b.vect_s32[1]);
        _U[2].R = vcgtq_s32(a.vect_s32[2], b.vect_s32[2]);
        _U[3].R = vcgtq_s32(a.vect_s32[3], b.vect_s32[3]);
        break;
    case 7: return 0xffff & k1;
    }

    return (((__mmask16)___CombMask_32i(_U[0].u32, 0)) |
            ((__mmask16)___CombMask_32i(_U[1].u32, 0) << 4)|
            ((__mmask16)___CombMask_32i(_U[2].u32, 0) << 8)|
            ((__mmask16)___CombMask_32i(_U[3].u32, 0) << 12)) & k1;
}

FORCE_INLINE __mmask8 _mm_cmp_epi64_mask (__m128i a, __m128i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint64x2_t R;
        int64_t u64[2];
    }_U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_s64(a.vect_s64, b.vect_s64); break;
    case 1: _U.R = vcltq_s64(a.vect_s64, b.vect_s64); break;
    case 2: _U.R = vcleq_s64(a.vect_s64, b.vect_s64); break;
    case 3: return 0x00;
    case 4: _U.R = vceqq_s64(a.vect_s64, b.vect_s64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 5: _U.R = vcgeq_s64(a.vect_s64, b.vect_s64); break;
    case 6: _U.R = vcgtq_s64(a.vect_s64, b.vect_s64); break;
    case 7: return 0x03;
    }

    return (__mmask8)(___CombMask_64i(_U.u64, 0));
}

// 6-11
FORCE_INLINE __mmask8 _mm_mask_cmp_epi64_mask (__mmask8 k1, __m128i a, __m128i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint64x2_t R;
        int64_t u64[2];
    }_U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_s64(a.vect_s64, b.vect_s64); break;
    case 1: _U.R = vcltq_s64(a.vect_s64, b.vect_s64); break;
    case 2: _U.R = vcleq_s64(a.vect_s64, b.vect_s64); break;
    case 3: return 0x00;
    case 4: _U.R = vceqq_s64(a.vect_s64, b.vect_s64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 5: _U.R = vcgeq_s64(a.vect_s64, b.vect_s64); break;
    case 6: _U.R = vcgtq_s64(a.vect_s64, b.vect_s64); break;
    case 7: return 0x03 & k1;
    }

    return (__mmask8)(___CombMask_64i(_U.u64, 0)) & k1;
}
FORCE_INLINE __mmask8 _mm256_cmp_epi64_mask (__m256i a, __m256i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint64x2_t R;
        int64_t u64[2];
    }_U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vceqq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 1:
        _U[0].R = vcltq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcltq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 2:
        _U[0].R = vcleq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcleq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 3: return 0x00;
    case 4:
        _U[0].R = vceqq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vceqq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[0].R = vsubq_u64(___Neg.u64x2[0], _U[0].R);
        _U[1].R = vsubq_u64(___Neg.u64x2[0], _U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcgeq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 6:
        _U[0].R = vcgtq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcgtq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 7: return 0x0f;
    }

    return (((__mmask8)___CombMask_64i(_U[0].u64, 0)) |
            ((__mmask8)___CombMask_64i(_U[1].u64, 0) << 2));
}
FORCE_INLINE __mmask8 _mm256_mask_cmp_epi64_mask (__mmask8 k1, __m256i a, __m256i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint64x2_t R;
        int64_t u64[2];
    }_U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vceqq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 1:
        _U[0].R = vcltq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcltq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 2:
        _U[0].R = vcleq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcleq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 3: return 0x00;
    case 4:
        _U[0].R = vceqq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vceqq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[0].R = vsubq_u64(___Neg.u64x2[0], _U[0].R);
        _U[1].R = vsubq_u64(___Neg.u64x2[0], _U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcgeq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 6:
        _U[0].R = vcgtq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcgtq_s64(a.vect_s64[1], b.vect_s64[1]);
        break;
    case 7: return 0x0f & k1;
    }

    return (((__mmask8)___CombMask_64i(_U[0].u64, 0)) |
            ((__mmask8)___CombMask_64i(_U[1].u64, 0) << 2)) & k1;
}
FORCE_INLINE __mmask8 _mm512_cmp_epi64_mask (__m512i a, __m512i b, _MM_CMPINT_ENUM imm8)
{
    union
    {
        uint64x2_t R;
        int64_t u64[2];
    }_U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vceqq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[2].R = vceqq_s64(a.vect_s64[2], b.vect_s64[2]);
        _U[3].R = vceqq_s64(a.vect_s64[3], b.vect_s64[3]);
        break;
    case 1:
        _U[0].R = vcltq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcltq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[2].R = vcltq_s64(a.vect_s64[2], b.vect_s64[2]);
        _U[3].R = vcltq_s64(a.vect_s64[3], b.vect_s64[3]);
        break;
    case 2:
        _U[0].R = vcleq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcleq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[2].R = vcleq_s64(a.vect_s64[2], b.vect_s64[2]);
        _U[3].R = vcleq_s64(a.vect_s64[3], b.vect_s64[3]);
        break;
    case 3: return 0x00;
    case 4:
        _U[0].R = vceqq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vceqq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[2].R = vceqq_s64(a.vect_s64[2], b.vect_s64[2]);
        _U[3].R = vceqq_s64(a.vect_s64[3], b.vect_s64[3]);
        _U[0].R = vsubq_u64(___Neg.u64x2[0], _U[0].R);
        _U[1].R = vsubq_u64(___Neg.u64x2[0], _U[1].R);
        _U[2].R = vsubq_u64(___Neg.u64x2[0], _U[2].R);
        _U[3].R = vsubq_u64(___Neg.u64x2[0], _U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcgeq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[2].R = vcgeq_s64(a.vect_s64[2], b.vect_s64[2]);
        _U[3].R = vcgeq_s64(a.vect_s64[3], b.vect_s64[3]);
        break;
    case 6:
        _U[0].R = vcgtq_s64(a.vect_s64[0], b.vect_s64[0]);
        _U[1].R = vcgtq_s64(a.vect_s64[1], b.vect_s64[1]);
        _U[2].R = vcgtq_s64(a.vect_s64[2], b.vect_s64[2]);
        _U[3].R = vcgtq_s64(a.vect_s64[3], b.vect_s64[3]);
        break;
    case 7: return 0xff;
    }

    return ((__mmask8)___CombMask_64i(_U[0].u64, 0)) |
            ((__mmask8)___CombMask_64i(_U[1].u64, 0) << 2)|
            ((__mmask8)___CombMask_64i(_U[2].u64, 0) << 4)|
            ((__mmask8)___CombMask_64i(_U[3].u64, 0) << 6);
}

FORCE_INLINE __mmask16 _mm_cmp_epu8_mask (__m128i a, __m128i b, const int imm8)
{
    union
    {
        uint8x16_t R;
        uint8_t u16[16];
    }_U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_u8(a.vect_u8, b.vect_u8); break;
    case 1: _U.R = vcltq_u8(a.vect_u8, b.vect_u8); break;
    case 2: _U.R = vcleq_u8(a.vect_u8, b.vect_u8); break;
    case 3: return 0x0000;
    case 4: _U.R = vceqq_u8(a.vect_u8, b.vect_u8); _U.R = vmvnq_u8(_U.R); break;
    case 5: _U.R = vcgeq_u8(a.vect_u8, b.vect_u8); break;
    case 6: _U.R = vcgtq_u8(a.vect_u8, b.vect_u8); break;
    case 7: return 0xffff;
    }

    return (__mmask16)(___CombMask_8i(_U.u16, 0));
}
FORCE_INLINE __mmask16 _mm_mask_cmp_epu8_mask (__mmask16 k1, __m128i a, __m128i b, const int imm8)
{
    union
    {
        uint8x16_t R;
        uint8_t u16[16];
    }_U Mem128Align;
    switch (imm8 & 0x07)
    {
    case 0: _U.R = vceqq_u8(a.vect_u8, b.vect_u8); break;
    case 1: _U.R = vcltq_u8(a.vect_u8, b.vect_u8); break;
    case 2: _U.R = vcleq_u8(a.vect_u8, b.vect_u8); break;
    case 3: return 0x0000;
    case 4: _U.R = vceqq_u8(a.vect_u8, b.vect_u8); _U.R = vmvnq_u8(_U.R); break;
    case 5: _U.R = vcgeq_u8(a.vect_u8, b.vect_u8); break;
    case 6: _U.R = vcgtq_u8(a.vect_u8, b.vect_u8); break;
    case 7: return 0xffff & k1;
    }

    return (__mmask16)(___CombMask_8i(_U.u16, 0)) & k1;
}
FORCE_INLINE __mmask32 _mm256_cmp_epu8_mask (__m256i a, __m256i b, const int imm8)
{
    union
    {
        uint8x16_t R;
        uint8_t u16[16];
    }_U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 1:
        _U[0].R = vcltq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcltq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 2:
        _U[0].R = vcleq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcleq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 3: return 0x00000000;
    case 4:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[0].R = vmvnq_u8(_U[0].R);
        _U[1].R = vmvnq_u8(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgeq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 6:
        _U[0].R = vcgtq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgtq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 7: return 0xffffffff;

    }

    return ((__mmask16)___CombMask_8i(_U[0].u16, 0)) |
            ((__mmask16)___CombMask_8i(_U[1].u16, 0) << 16);
}
FORCE_INLINE __mmask32 _mm256_mask_cmp_epu8_mask (__mmask32 k1, __m256i a, __m256i b, const int imm8)
{
    union
    {
        uint8x16_t R;
        uint8_t u16[16];
    }_U[2] Mem256Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 1:
        _U[0].R = vcltq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcltq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 2:
        _U[0].R = vcleq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcleq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 3: return 0x00000000;
    case 4:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[0].R = vmvnq_u8(_U[0].R);
        _U[1].R = vmvnq_u8(_U[1].R);
        break;
    case 5:
        _U[0].R = vcgeq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgeq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 6:
        _U[0].R = vcgtq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgtq_u8(a.vect_u8[1], b.vect_u8[1]);
        break;
    case 7: return 0xffffffff & k1;

    }

    return (((__mmask16)___CombMask_8i(_U[0].u16, 0)) |
            ((__mmask16)___CombMask_8i(_U[1].u16, 0) << 16)) & k1;
}
FORCE_INLINE __mmask64 _mm512_cmp_epu8_mask (__m512i a, __m512i b, const int imm8)
{
    union
    {
        uint8x16_t R;
        uint8_t u16[16];
    }_U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vceqq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vceqq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 1:
        _U[0].R = vcltq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcltq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcltq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcltq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 2:
        _U[0].R = vcleq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcleq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcleq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcleq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 3: return 0x0000000000000000;
    case 4:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vceqq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vceqq_u8(a.vect_u8[3], b.vect_u8[3]);
        _U[0].R = vmvnq_u8(_U[0].R);
        _U[1].R = vmvnq_u8(_U[1].R);
        _U[2].R = vmvnq_u8(_U[2].R);
        _U[3].R = vmvnq_u8(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgeq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcgeq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcgeq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 6:
        _U[0].R = vcgtq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgtq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcgtq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcgtq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 7: return 0xffffffffffffffff;

    }

    return (((__mmask64)___CombMask_8i(_U[0].u16, 0)) |
            ((__mmask64)___CombMask_8i(_U[1].u16, 0) << 16)|
            ((__mmask64)___CombMask_8i(_U[2].u16, 0) << 32)|
            ((__mmask64)___CombMask_8i(_U[3].u16, 0) << 48));
}
FORCE_INLINE __mmask64 _mm512_mask_cmp_epu8_mask (__mmask64 k1, __m512i a, __m512i b, const int imm8)
{
    union
    {
        uint8x16_t R;
        uint8_t u16[16];
    }_U[4] Mem512Align;
    switch (imm8 & 0x07)
    {
    case 0:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vceqq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vceqq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 1:
        _U[0].R = vcltq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcltq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcltq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcltq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 2:
        _U[0].R = vcleq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcleq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcleq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcleq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 3: return 0x0000000000000000;
    case 4:
        _U[0].R = vceqq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vceqq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vceqq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vceqq_u8(a.vect_u8[3], b.vect_u8[3]);
        _U[0].R = vmvnq_u8(_U[0].R);
        _U[1].R = vmvnq_u8(_U[1].R);
        _U[2].R = vmvnq_u8(_U[2].R);
        _U[3].R = vmvnq_u8(_U[3].R);
        break;
    case 5:
        _U[0].R = vcgeq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgeq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcgeq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcgeq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 6:
        _U[0].R = vcgtq_u8(a.vect_u8[0], b.vect_u8[0]);
        _U[1].R = vcgtq_u8(a.vect_u8[1], b.vect_u8[1]);
        _U[2].R = vcgtq_u8(a.vect_u8[2], b.vect_u8[2]);
        _U[3].R = vcgtq_u8(a.vect_u8[3], b.vect_u8[3]);
        break;
    case 7: return 0xffffffffffffffff & k1;

    }

    return (((__mmask64)___CombMask_8i(_U[0].u16, 0)) |
            ((__mmask64)___CombMask_8i(_U[1].u16, 0) << 16)|
            ((__mmask64)___CombMask_8i(_U[2].u16, 0) << 32)|
            ((__mmask64)___CombMask_8i(_U[3].u16, 0) << 48)) & k1;
}

FORCE_INLINE __m128d _mm_cmp_pd (__m128d x, __m128d y, const int imm8)
{
    union{
        uint64x2_t R;
        __m128d    O;
        uint64_t   u64[2];
    }_U Mem128Align;
    union {
        uint64x2_t  vect_u64;
        float64x2_t vect_f64;
        __m128d     in;
    }a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u64 (a.vect_u64, ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R = vceqq_u64 (a.vect_u64, ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R = vceqq_u64 (b.vect_u64, ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R = vceqq_u64 (b.vect_u64, ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        return ___False.f128[0];

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        return ___True.f128[0];

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f128[0];
        _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return ___False.f128[0];

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f128[0];
        _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return ___True.f128[0];
    }
    return _U.O;
}
FORCE_INLINE __m256d _mm256_cmp_pd (__m256d x, __m256d y, const int imm8)
{
    union{
        uint64x2_t R[2];
        __m256d    O;
        uint64_t   u64[4];
    }_U Mem256Align;
    union {
        uint64x2_t vect_u64[2];
        float64x2_t vect_f64[2];
        __m256d    in;
    }a Mem256Align, b Mem256Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        return ___False.f256[0];

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        return ___True.f256[0];

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___True.f256[0];
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return ___False.f256[0];

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___False.f256[0];
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return ___True.f256[0];
    }
    return _U.O;
}
FORCE_INLINE __mmask8 _mm_cmp_pd_mask (__m128d x, __m128d y, const int imm8)
{
    union{
        uint64x2_t R;
        __m128d    O;
        uint64_t   u64[2];
    }_U Mem128Align;
    union {
        uint64x2_t  vect_u64;
        float64x2_t vect_f64;
        __m128d     in;
    }a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u64 (a.vect_u64, ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R = vceqq_u64 (a.vect_u64, ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R = vceqq_u64 (b.vect_u64, ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R = vceqq_u64 (b.vect_u64, ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        return 0x0;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        return 0x03;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03;
        _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;;
        _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0x03;
    }
    return ___CombMask_64i(_U.u64, 0) ;
}
FORCE_INLINE __mmask8 _mm_mask_cmp_pd_mask (__mmask8 k1, __m128d x, __m128d y, const int imm8)
{
    union{
        uint64x2_t R;
        __m128d    O;
        uint64_t   u64[2];
    }_U Mem128Align;
    union {
        uint64x2_t  vect_u64;
        float64x2_t vect_f64;
        __m128d     in;
    }a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u64 (a.vect_u64, ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R = vceqq_u64 (a.vect_u64, ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R = vceqq_u64 (b.vect_u64, ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R = vceqq_u64 (b.vect_u64, ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        return 0x0;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        return 0x03 & k1;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x03 & k1;
        _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;;
        _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0x03 & k1;
    }
    return ___CombMask_64i(_U.u64, 0) & k1;
}
FORCE_INLINE __mmask8 _mm256_cmp_pd_mask (__m256d x, __m256d y, const int imm8)
{
    union{
        uint64x2_t R[2];
        __m256d    O;
        uint64_t   u64[4];
    }_U Mem256Align;
    union {
        uint64x2_t vect_u64[2];
        float64x2_t vect_f64[2];
        __m256d    in;
    }a Mem256Align, b Mem256Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        return 0x00;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        return 0x0f;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0x0f;
    }
    return ___CombMask_32i(_U.u64, 0);
}
FORCE_INLINE __mmask8 _mm256_mask_cmp_pd_mask (__mmask8 k1, __m256d x, __m256d y, const int imm8)
{
    union{
        uint64x2_t R[2];
        __m256d    O;
        uint64_t   u64[4];
    }_U Mem256Align;
    union {
        uint64x2_t vect_u64[2];
        float64x2_t vect_f64[2];
        __m256d    in;
    }a Mem256Align, b Mem256Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        return 0x00;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        return 0x0f & k1;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0x0f & k1;
    }
    return ___CombMask_32i(_U.u64, 0) & k1;
}
FORCE_INLINE __mmask8 _mm512_cmp_pd_mask (__m512d x, __m512d y, const int imm8)
{
    union{
        uint64x2_t R[4];
        __m512d    O;
        uint64_t   u64[8];
    }_U Mem512Align;
    union {
        uint64x2_t vect_u64[4];
        float64x2_t  vect_f64[4];
        __m512d    in;
    }a Mem512Align, b Mem512Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[2], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[3], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[2], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[3], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[2], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[3], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[2], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[3], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcltq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcltq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcleq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcleq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        return 0x0;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        _U.R[2] = vsubq_u64(___Neg.u64x2[2], _U.R[2]);
        _U.R[3] = vsubq_u64(___Neg.u64x2[3], _U.R[3]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgeq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgeq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgtq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgtq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        return 0xff;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcltq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcltq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcleq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcleq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x0;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        _U.R[2] = vsubq_u64(___Neg.u64x2[0], _U.R[2]);
        _U.R[3] = vsubq_u64(___Neg.u64x2[0], _U.R[3]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgeq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgeq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgtq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgtq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0xff;
    }
    return ___CombMask_16i(_U.u64, 0);
}

// 6-12
FORCE_INLINE __mmask8 _mm512_mask_cmp_pd_mask (__mmask8 k1, __m512d x, __m512d y, const int imm8)
{
    union{
        uint64x2_t R[4];
        __m512d    O;
        uint64_t   u64[8];
    }_U Mem512Align;
    union {
        uint64x2_t vect_u64[4];
        float64x2_t  vect_f64[4];
        __m512d    in;
    }a Mem512Align, b Mem512Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[2], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[3], ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (a.vect_u64[0], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[1], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[2], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (a.vect_u64[3], ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[2], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[3], ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

     _U.R[0] = vceqq_u64 (b.vect_u64[0], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[1], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[2], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];
     _U.R[0] = vceqq_u64 (b.vect_u64[3], ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0] | _U.u64[1];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcltq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcltq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcleq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcleq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        return 0x0;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        _U.R[2] = vsubq_u64(___Neg.u64x2[2], _U.R[2]);
        _U.R[3] = vsubq_u64(___Neg.u64x2[3], _U.R[3]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgeq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgeq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgtq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgtq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        return 0xff & k1;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcltq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcltq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcltq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcltq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcleq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcleq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcleq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcleq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x0;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vceqq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vceqq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vceqq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vceqq_f64(a.vect_f64[3], b.vect_f64[3]);
        _U.R[0] = vsubq_u64(___Neg.u64x2[0], _U.R[0]);
        _U.R[1] = vsubq_u64(___Neg.u64x2[0], _U.R[1]);
        _U.R[2] = vsubq_u64(___Neg.u64x2[0], _U.R[2]);
        _U.R[3] = vsubq_u64(___Neg.u64x2[0], _U.R[3]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgeq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgeq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgeq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgeq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgtq_f64(a.vect_f64[0], b.vect_f64[0]);
        _U.R[1] = vcgtq_f64(a.vect_f64[1], b.vect_f64[1]);
        _U.R[2] = vcgtq_f64(a.vect_f64[2], b.vect_f64[2]);
        _U.R[3] = vcgtq_f64(a.vect_f64[3], b.vect_f64[3]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0xff & k1;
    }
    return ___CombMask_16i(_U.u64, 0) & k1;
}

FORCE_INLINE __m128 _mm_cmp_ps (__m128 x, __m128 y, const int imm8)
{
    union{
        uint32x4_t R;
        __m128     O;
        uint32_t   u32[4];
    }  _U Mem128Align;

    union {
        uint32x4_t vect_u32;
        float32x4_t  vect_f32;
        __m128     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u32 (a.vect_u32, ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R = vceqq_u32 (a.vect_u32, ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R = vceqq_u32 (b.vect_u32, ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R = vceqq_u32 (b.vect_u32, ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        return ___fFalse.f128[0];

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        _U.R = vmvnq_u32(_U.R);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        return ___fTrue.f128[0];

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f128[0];
        _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return ___fFalse.f128[0];

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        _U.R = vmvnq_u32(_U.R);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f128[0];
        _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return ___fTrue.f128[0];
    }
    return _U.O;
}
FORCE_INLINE __m256 _mm256_cmp_ps (__m256 x, __m256 y, const int imm8)
{
    union{
        uint32x4_t R[2];
        __m256     O;
        uint32_t   u32[8];
    } _U Mem256Align;
    union {
        uint32x4_t vect_u32[4];
        float32x4_t  vect_f32[4];
        __m256     in;
    } a Mem256Align, b Mem256Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        return ___fFalse.f256[0];

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        return ___fTrue.f256[0];

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fTrue.f256[0];
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return ___fFalse.f256[0];

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return ___fFalse.f256[0];
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return ___fTrue.f256[0];
    }
    return _U.O;
}
FORCE_INLINE __mmask8 _mm_cmp_ps_mask (__m128 x, __m128 y, const int imm8)
{
    union{
        uint32x4_t R;
        __m128     O;
        uint32_t   u32[4];
    }  _U Mem128Align;

    union {
        uint32x4_t vect_u32;
        float32x4_t  vect_f32;
        __m128     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u32 (a.vect_u32, ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R = vceqq_u32 (a.vect_u32, ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R = vceqq_u32 (b.vect_u32, ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R = vceqq_u32 (b.vect_u32, ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        return 0x00;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        _U.R = vmvnq_u32(_U.R);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        return 0x0f;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f;
        _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        _U.R = vmvnq_u32(_U.R);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0x0f;
    }
    return ___CombMask_32i(_U.u32, 0);
}
FORCE_INLINE __mmask8 _mm_mask_cmp_ps_mask (__mmask8 k1, __m128 x, __m128 y, const int imm8)
{
    union{
        uint32x4_t R;
        __m128     O;
        uint32_t   u32[4];
    }  _U Mem128Align;

    union {
        uint32x4_t vect_u32;
        float32x4_t  vect_f32;
        __m128     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u32 (a.vect_u32, ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R = vceqq_u32 (a.vect_u32, ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R = vceqq_u32 (b.vect_u32, ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R = vceqq_u32 (b.vect_u32, ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        return 0x00;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        _U.R = vmvnq_u32(_U.R);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        return 0x0f & k1;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0f & k1;
        _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        _U.R = vmvnq_u32(_U.R);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0x0f & k1;
    }
    return ___CombMask_32i(_U.u32, 0) & k1;
}
FORCE_INLINE __mmask8 _mm256_cmp_ps_mask (__m256 x, __m256 y, const int imm8)
{
    union{
        uint32x4_t R[2];
        __m256     O;
        uint32_t   u32[8];
    } _U Mem256Align;
    union {
        uint32x4_t vect_u32[4];
        float32x4_t  vect_f32[4];
        __m256     in;
    } a Mem256Align, b Mem256Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        return 0x00;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        return 0xff;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0xff;
    }
    return ___CombMask_16i(_U.u32, 0);
}
FORCE_INLINE __mmask8 _mm256_mask_cmp_ps_mask (__mmask8 k1, __m256 x, __m256 y, const int imm8)
{
    union{
        uint32x4_t R[2];
        __m256     O;
        uint32_t   u32[8];
    } _U Mem256Align;
    union {
        uint32x4_t vect_u32[4];
        float32x4_t  vect_f32[4];
        __m256     in;
    } a Mem256Align, b Mem256Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        return 0x00;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x00;
        return 0xff & k1;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xff & k1;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x00;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0xff & k1;
    }
    return ___CombMask_16i(_U.u32, 0) & k1;
}
FORCE_INLINE __mmask16 _mm512_cmp_ps_mask (__m512 x, __m512 y, const int imm8)
{
    union{
        uint32x4_t R[4];
        __m512     O;
        uint32_t   u32[16];
    }Mem512Align _U;

    union {
        uint32x4_t vect_u32[4];
        float32x4_t  vect_f32[4];
        __m512     in;
    }Mem512Align a, b;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[2], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[3], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[2], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[3], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[2], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[3], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[2], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[3], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcltq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcltq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcleq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcleq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        return 0x0000;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        _U.R[2] = vmvnq_u32(_U.R[2]);
        _U.R[3] = vmvnq_u32(_U.R[3]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgeq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgeq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgtq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgtq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        return 0xffff;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcltq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcltq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcleq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcleq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x0000;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        _U.R[2] = vmvnq_u32(_U.R[2]);
        _U.R[3] = vmvnq_u32(_U.R[3]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgeq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgeq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgtq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgtq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0xffff;
    }
    return ___CombMask_8i(_U.u32, 0);
}
FORCE_INLINE __mmask16 _mm512_mask_cmp_ps_mask (__mmask16 k1, __m512 x, __m512 y, const int imm8)
{
    union{
        uint32x4_t R[4];
        __m512     O;
        uint32_t   u32[16];
    }Mem512Align _U;

    union {
        uint32x4_t vect_u32[4];
        float32x4_t  vect_f32[4];
        __m512     in;
    }Mem512Align a, b;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[2], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[3], ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[0], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[1], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[2], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (a.vect_u32[3], ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[2], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[3], ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[0], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[1], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[2], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];
     _U.R[0] = vceqq_u32 (b.vect_u32[3], ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] | _U.u32[1] | _U.u32[2] | _U.u32[3];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcltq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcltq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcleq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcleq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        return 0x0000;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        _U.R[2] = vmvnq_u32(_U.R[2]);
        _U.R[3] = vmvnq_u32(_U.R[3]);
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgeq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgeq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgtq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgtq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        return 0xffff & k1;

    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        _U.R[0] = vcltq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcltq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcltq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcltq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0xffff & k1;
        _U.R[0] = vcleq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcleq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcleq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcleq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        return 0x0000;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vceqq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vceqq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vceqq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vceqq_f32(a.vect_f32[3], b.vect_f32[3]);
        _U.R[0] = vmvnq_u32(_U.R[0]);
        _U.R[1] = vmvnq_u32(_U.R[1]);
        _U.R[2] = vmvnq_u32(_U.R[2]);
        _U.R[3] = vmvnq_u32(_U.R[3]);
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcgeq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgeq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgeq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgeq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            return 0x0000;
        _U.R[0] = vcgtq_f32(a.vect_f32[0], b.vect_f32[0]);
        _U.R[1] = vcgtq_f32(a.vect_f32[1], b.vect_f32[1]);
        _U.R[2] = vcgtq_f32(a.vect_f32[2], b.vect_f32[2]);
        _U.R[3] = vcgtq_f32(a.vect_f32[3], b.vect_f32[3]);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        return 0xffff & k1;
    }
    return ___CombMask_8i(_U.u32, 0) & k1;
}

FORCE_INLINE __m128d _mm_cmp_sd (__m128d x, __m128d y, const int imm8)
{
    union{
        uint64x2_t R;
        __m128d    O;
        uint64_t   u64[2];
        uint64x1_t R1[2];
    }Mem128Align _U ;
    union {
        uint64x2_t vect_u64;
        float64x2_t vect_f64;
        __m128d     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u64 (a.vect_u64, ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0];
     _U.R = vceqq_u64 (a.vect_u64, ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0];

     _U.R = vceqq_u64 (b.vect_u64, ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0];
     _U.R = vceqq_u64 (b.vect_u64, ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.O = ___False.f128[0];
        break;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
        {
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        }
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.O =  ___True.f128[0];
        break;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        _U.O =  ___False.f128[0];
        break;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
        {
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        }
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        _U.O =   ___True.f128[0];
        break;
    }
    _U.R1[1] = vget_high_u64(a.vect_u64);
    return _U.O;
}
FORCE_INLINE __mmask8 _mm_cmp_sd_mask (__m128d x, __m128d y, const int imm8)
{
    union{
        uint64x2_t R;
        __m128d    O;
        uint64_t   u64[2];
        uint64x1_t R1[2];
    }Mem128Align _U ;
    union {
        uint64x2_t vect_u64;
        float64x2_t vect_f64;
        __m128d     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u64 (a.vect_u64, ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0];
     _U.R = vceqq_u64 (a.vect_u64, ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0];

     _U.R = vceqq_u64 (b.vect_u64, ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0];
     _U.R = vceqq_u64 (b.vect_u64, ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.O = ___False.f128[0];
        break;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
        {
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        }
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.O =  ___True.f128[0];
        break;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        _U.O =  ___False.f128[0];
        break;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
        {
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        }
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        _U.O =   ___True.f128[0];
        break;
    }
    _U.R1[1] = vget_high_u64(a.vect_u64);
    return _U.u64[0] ? 1 : 0;
}
FORCE_INLINE __mmask8 _mm_mask_cmp_sd_mask (__mmask8 k1, __m128d x, __m128d y, const int imm8)
{
    union{
        uint64x2_t R;
        __m128d    O;
        uint64_t   u64[2];
        uint64x1_t R1[2];
    }Mem128Align _U ;
    union {
        uint64x2_t vect_u64;
        float64x2_t vect_f64;
        __m128d     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u64 (a.vect_u64, ___NaNq.u64x2[0]);
     a_is_nan |= _U.u64[0];
     _U.R = vceqq_u64 (a.vect_u64, ___NaNs.u64x2[0]);
     a_is_nan |= _U.u64[0];

     _U.R = vceqq_u64 (b.vect_u64, ___NaNq.u64x2[0]);
     b_is_nan |= _U.u64[0];
     _U.R = vceqq_u64 (b.vect_u64, ___NaNs.u64x2[0]);
     b_is_nan |= _U.u64[0];

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___False.f128[0];
        else
            _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.O = ___False.f128[0];
        break;

    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
        {
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        }
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___True.f128[0];
        else
            _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.O =  ___True.f128[0];
        break;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vcltq_f64(a.vect_f64, b.vect_f64);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___True.f128[0];
        else
            _U.R = vcleq_f64(a.vect_f64, b.vect_f64);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        _U.O =  ___False.f128[0];
        break;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
        {
            _U.R = vceqq_f64(a.vect_f64, b.vect_f64);
            _U.R = vsubq_u64(___Neg.u64x2[0], _U.R);
        }
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.R = vcgeq_f64(a.vect_f64, b.vect_f64);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O =  ___False.f128[0];
        else
            _U.R = vcgtq_f64(a.vect_f64, b.vect_f64);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        _U.O =   ___True.f128[0];
        break;
    }
    _U.R1[1] = vget_high_u64(a.vect_u64);
    return (_U.u64[0] ? 1 : 0) & k1;
}

FORCE_INLINE __m128 _mm_cmp_ss (__m128 x, __m128 y, const int imm8)
{
    union{
        uint32x4_t R;
        __m128     O;
        uint32_t   u32[4];
    }Mem128Align _U;
    union {
        uint32x4_t vect_u32;
        float32x4_t vect_f32;
        __m128     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u32 (a.vect_u32, ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] ;
     _U.R = vceqq_u32 (a.vect_u32, ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] ;

     _U.R = vceqq_u32 (b.vect_u32, ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] ;
     _U.R = vceqq_u32 (b.vect_u32, ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] ;

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.O = ___fFalse.f128[0];
        break;
    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
        {
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
            _U.R = vmvnq_u32(_U.R);
        }
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.O = ___fTrue.f128[0];
        break;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        _U.O = ___fFalse.f128[0];
        break;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
        {
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
            _U.R = vmvnq_u32(_U.R);
        }
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        _U.O = ___fTrue.f128[0];
        break;
    }
    uint32_t tmp = _U.u32[0];
    _U.O = a.in;
    _U.u32[0] = tmp;
    return _U.O;
}
FORCE_INLINE __mmask8 _mm_cmp_ss_mask (__m128 x, __m128 y, const int imm8)
{
    union{
        uint32x4_t R;
        __m128     O;
        uint32_t   u32[4];
    }Mem128Align _U;
    union {
        uint32x4_t vect_u32;
        float32x4_t vect_f32;
        __m128     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u32 (a.vect_u32, ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] ;
     _U.R = vceqq_u32 (a.vect_u32, ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] ;

     _U.R = vceqq_u32 (b.vect_u32, ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] ;
     _U.R = vceqq_u32 (b.vect_u32, ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] ;

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.O = ___fFalse.f128[0];
        break;
    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
        {
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
            _U.R = vmvnq_u32(_U.R);
        }
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.O = ___fTrue.f128[0];
        break;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        _U.O = ___fFalse.f128[0];
        break;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
        {
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
            _U.R = vmvnq_u32(_U.R);
        }
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        _U.O = ___fTrue.f128[0];
        break;
    }
    uint32_t tmp = _U.u32[0];
    _U.O = a.in;
    _U.u32[0] = tmp;
    return _U.u32[0] ? 1 : 0;
}
FORCE_INLINE __mmask8 _mm_mask_cmp_ss_mask (__mmask8 k1, __m128 x, __m128 y, const int imm8)
{
    union{
        uint32x4_t R;
        __m128     O;
        uint32_t   u32[4];
    }Mem128Align _U;
    union {
        uint32x4_t vect_u32;
        float32x4_t vect_f32;
        __m128     in;
    } a Mem128Align, b Mem128Align;
    uint8_t a_is_nan = 0;
    uint8_t b_is_nan = 0;
    a.in = x; b.in = y;

     _U.R = vceqq_u32 (a.vect_u32, ___fNaNq.u32x4[0]);
     a_is_nan |= _U.u32[0] ;
     _U.R = vceqq_u32 (a.vect_u32, ___fNaNs.u32x4[0]);
     a_is_nan |= _U.u32[0] ;

     _U.R = vceqq_u32 (b.vect_u32, ___fNaNq.u32x4[0]);
     b_is_nan |= _U.u32[0] ;
     _U.R = vceqq_u32 (b.vect_u32, ___fNaNs.u32x4[0]);
     b_is_nan |= _U.u32[0] ;

    switch (imm8 & 0x1f)
    {
    case 0: // OrderedEqualNonSignaling
    case 16:// OrderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;
    case 1:  // OrderedLessThanSignaling
    case 17: // OrderedLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 2:  // OrderedLessThanOrEqualSignaling
    case 18: // OrderedLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 3:  // UnorderedNonSignaling
    case 19: // UnorderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.O = ___fFalse.f128[0];
        break;
    case 4: // UnorderedNotEqualNonSignaling
    case 20:// UnorderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
        {
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
            _U.R = vmvnq_u32(_U.R);
        }
        break;
    case 5: // UnorderedNotLessThanSignaling
    case 21:// UnorderedNotLessThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 6: // UnorderedNotLessThanOrEqualSignaling
    case 22:// UnorderedNotLessThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 7:  // OrderedNonSignaling
    case 23: // OrderedSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.O = ___fTrue.f128[0];
        break;
    case 8: // UnorderedEqualNonSignaling
    case 24:// UnorderedEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
        break;

    case 9: // UnorderedNotGreaterThanOrEqualSignaling
    case 25:// UnorderedNotGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcltq_f32(a.vect_f32, b.vect_f32);
        break;
    case 10: // UnorderedNotGreaterThanSignaling
    case 26: // UnorderedNotGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fTrue.f128[0];
        else
            _U.R = vcleq_f32(a.vect_f32, b.vect_f32);
        break;

    case 11: // OrderedFalseNonSignaling
    case 27: // OrderedFalseSignaling
        _U.O = ___fFalse.f128[0];
        break;

    case 12: // OrderedNotEqualNonSignaling
    case 28: // OrderedNotEqualSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
        {
            _U.R = vceqq_f32(a.vect_f32, b.vect_f32);
            _U.R = vmvnq_u32(_U.R);
        }
        break;
    case 13: // OrderedGreaterThanOrEqualSignaling
    case 29: // OrderedGreaterThanOrEqualNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcgeq_f32(a.vect_f32, b.vect_f32);
        break;
    case 14: // OrderedGreaterThanSignaling
    case 30: // OrderedGreaterThanNonSignaling
        if (a_is_nan || b_is_nan)
            _U.O = ___fFalse.f128[0];
        else
            _U.R = vcgtq_f32(a.vect_f32, b.vect_f32);
        break;

    case 15: // UnorderedTrueNonSignaling
    case 31: // UnorderedTrueSignaling
        _U.O = ___fTrue.f128[0];
        break;
    }
    uint32_t tmp = _U.u32[0];
    _U.O = a.in;
    _U.u32[0] = tmp;
    return (_U.u32[0] ? 1 : 0) & k1;
}

FORCE_INLINE __m128i _mm_dpbusd_epi32 (__m128i src, __m128i a, __m128i b)
{
    __m128i O;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8)));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8)));
    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    O.vect_s32 = vaddq_s32(src.vect_s32, vpaddq_s32(s32l, s32h));
    return O;
}
FORCE_INLINE __m128i _mm_mask_dpbusd_epi32 (__m128i src, __mmask8 k, __m128i a, __m128i b)
{
    union
    {
        int32x4_t R;
        __m128i O;
        int32_t s32[4];
    } _U Mem128Align;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8)));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8)));
    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    _U.R = vaddq_s32(src.vect_s32, vpaddq_s32(s32l, s32h));

    if (!(k & 0x01)) _U.s32[0] = vgetq_lane_s32(src.vect_s32, 0);
    if (!(k & 0x02)) _U.s32[1] = vgetq_lane_s32(src.vect_s32, 1);
    if (!(k & 0x04)) _U.s32[2] = vgetq_lane_s32(src.vect_s32, 2);
    if (!(k & 0x08)) _U.s32[3] = vgetq_lane_s32(src.vect_s32, 3);

    return _U.O;
}
// 6-13
FORCE_INLINE __m128i _mm_maskz_dpbusd_epi32 (__mmask8 k, __m128i src, __m128i a, __m128i b)
{
    union
    {
        int32x4_t R;
        __m128i O;
        int32_t s32[4];
    } _U Mem128Align;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8)));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8)));
    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    _U.R = vaddq_s32(src.vect_s32, vpaddq_s32(s32l, s32h));

    if (!(k & 0x01)) _U.s32[0] = 0;
    if (!(k & 0x02)) _U.s32[1] = 0;
    if (!(k & 0x04)) _U.s32[2] = 0;
    if (!(k & 0x08)) _U.s32[3] = 0;

    return _U.O;
}

FORCE_INLINE __m256i _mm256_dpbusd_epi32 (__m256i src, __m256i a, __m256i b)
{
    __m256i O;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[0])));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[0])));
    int16x8_t a16ld = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[1])));
    int16x8_t a16hd = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[1])));
    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8[0]));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8[0]));
    int16x8_t b16ld = vmovl_s8(vget_low_s8(b.vect_s8[1]));
    int16x8_t b16hd = vmovl_s8(vget_high_s8(b.vect_s8[1]));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    int32x4_t s32ld = vpaddlq_s16(vmulq_s16(a16ld, b16ld));
    int32x4_t s32hd = vpaddlq_s16(vmulq_s16(a16hd, b16hd));
    O.vect_s32[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(s32l, s32h));
    O.vect_s32[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(s32ld, s32hd));
    return O;
}
FORCE_INLINE __m256i _mm256_mask_dpbusd_epi32 (__m256i src, __mmask8 k, __m256i a, __m256i b)
{
    union
    {
        int32x4_t R[2];
        __m256i O;
        int32_t s32[8];
    } _U Mem256Align;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[0])));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[0])));
    int16x8_t a16ld = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[1])));
    int16x8_t a16hd = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[1])));
    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8[0]));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8[0]));
    int16x8_t b16ld = vmovl_s8(vget_low_s8(b.vect_s8[1]));
    int16x8_t b16hd = vmovl_s8(vget_high_s8(b.vect_s8[1]));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    int32x4_t s32ld = vpaddlq_s16(vmulq_s16(a16ld, b16ld));
    int32x4_t s32hd = vpaddlq_s16(vmulq_s16(a16hd, b16hd));
    _U.R[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(s32l, s32h));
    _U.R[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(s32ld, s32hd));

    if (!(k & 0x01)) _U.s32[0] = vgetq_lane_s32(src.vect_s32[0], 0);
    if (!(k & 0x02)) _U.s32[1] = vgetq_lane_s32(src.vect_s32[0], 1);
    if (!(k & 0x04)) _U.s32[2] = vgetq_lane_s32(src.vect_s32[0], 2);
    if (!(k & 0x08)) _U.s32[3] = vgetq_lane_s32(src.vect_s32[0], 3);

    if (!(k & 0x10)) _U.s32[4] = vgetq_lane_s32(src.vect_s32[1], 0);
    if (!(k & 0x20)) _U.s32[5] = vgetq_lane_s32(src.vect_s32[1], 1);
    if (!(k & 0x40)) _U.s32[6] = vgetq_lane_s32(src.vect_s32[1], 2);
    if (!(k & 0x80)) _U.s32[7] = vgetq_lane_s32(src.vect_s32[1], 3);

    return _U.O;
}
FORCE_INLINE __m256i _mm256_maskz_dpbusd_epi32 (__mmask8 k, __m256i src, __m256i a, __m256i b)
{
    union
    {
        int32x4_t R[2];
        __m256i O;
        int32_t s32[8];
    } _U Mem256Align;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[0])));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[0])));
    int16x8_t a16ld = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[1])));
    int16x8_t a16hd = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[1])));
    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8[0]));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8[0]));
    int16x8_t b16ld = vmovl_s8(vget_low_s8(b.vect_s8[1]));
    int16x8_t b16hd = vmovl_s8(vget_high_s8(b.vect_s8[1]));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    int32x4_t s32ld = vpaddlq_s16(vmulq_s16(a16ld, b16ld));
    int32x4_t s32hd = vpaddlq_s16(vmulq_s16(a16hd, b16hd));
    _U.R[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(s32l, s32h));
    _U.R[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(s32ld, s32hd));

    if (!(k & 0x01)) _U.s32[0] = 0;
    if (!(k & 0x02)) _U.s32[1] = 0;
    if (!(k & 0x04)) _U.s32[2] = 0;
    if (!(k & 0x08)) _U.s32[3] = 0;

    if (!(k & 0x10)) _U.s32[4] = 0;
    if (!(k & 0x20)) _U.s32[5] = 0;
    if (!(k & 0x40)) _U.s32[6] = 0;
    if (!(k & 0x80)) _U.s32[7] = 0;

    return _U.O;
}

FORCE_INLINE __m512i _mm512_dpbusd_epi32 (__m512i src, __m512i a, __m512i b)
{
    __m512i O;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[0])));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[0])));
    int16x8_t a16ld = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[1])));
    int16x8_t a16hd = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[1])));
    int16x8_t a16lq = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[2])));
    int16x8_t a16hq = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[2])));
    int16x8_t a16ll = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[3])));
    int16x8_t a16hl = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[3])));

    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8[0]));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8[0]));
    int16x8_t b16ld = vmovl_s8(vget_low_s8(b.vect_s8[1]));
    int16x8_t b16hd = vmovl_s8(vget_high_s8(b.vect_s8[1]));
    int16x8_t b16lq = vmovl_s8(vget_low_s8(b.vect_s8[2]));
    int16x8_t b16hq = vmovl_s8(vget_high_s8(b.vect_s8[2]));
    int16x8_t b16ll = vmovl_s8(vget_low_s8(b.vect_s8[3]));
    int16x8_t b16hl = vmovl_s8(vget_high_s8(b.vect_s8[3]));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    int32x4_t s32ld = vpaddlq_s16(vmulq_s16(a16ld, b16ld));
    int32x4_t s32hd = vpaddlq_s16(vmulq_s16(a16hd, b16hd));
    int32x4_t s32lq = vpaddlq_s16(vmulq_s16(a16lq, b16lq));
    int32x4_t s32hq = vpaddlq_s16(vmulq_s16(a16hq, b16hq));
    int32x4_t s32ll = vpaddlq_s16(vmulq_s16(a16ll, b16ll));
    int32x4_t s32hl = vpaddlq_s16(vmulq_s16(a16hl, b16hl));
    O.vect_s32[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(s32l, s32h));
    O.vect_s32[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(s32ld, s32hd));
    O.vect_s32[2] = vaddq_s32(src.vect_s32[2], vpaddq_s32(s32lq, s32hq));
    O.vect_s32[3] = vaddq_s32(src.vect_s32[3], vpaddq_s32(s32ll, s32hl));
    return O;
}
FORCE_INLINE __m512i _mm512_mask_dpbusd_epi32 (__m512i src, __mmask16 k, __m512i a, __m512i b)
{
    union
    {
        int32x4_t R[4];
        __m512i O;
        int32_t s32[16];
    } _U Mem512Align;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[0])));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[0])));
    int16x8_t a16ld = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[1])));
    int16x8_t a16hd = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[1])));
    int16x8_t a16lq = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[2])));
    int16x8_t a16hq = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[2])));
    int16x8_t a16ll = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[3])));
    int16x8_t a16hl = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[3])));

    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8[0]));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8[0]));
    int16x8_t b16ld = vmovl_s8(vget_low_s8(b.vect_s8[1]));
    int16x8_t b16hd = vmovl_s8(vget_high_s8(b.vect_s8[1]));
    int16x8_t b16lq = vmovl_s8(vget_low_s8(b.vect_s8[2]));
    int16x8_t b16hq = vmovl_s8(vget_high_s8(b.vect_s8[2]));
    int16x8_t b16ll = vmovl_s8(vget_low_s8(b.vect_s8[3]));
    int16x8_t b16hl = vmovl_s8(vget_high_s8(b.vect_s8[3]));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    int32x4_t s32ld = vpaddlq_s16(vmulq_s16(a16ld, b16ld));
    int32x4_t s32hd = vpaddlq_s16(vmulq_s16(a16hd, b16hd));
    int32x4_t s32lq = vpaddlq_s16(vmulq_s16(a16lq, b16lq));
    int32x4_t s32hq = vpaddlq_s16(vmulq_s16(a16hq, b16hq));
    int32x4_t s32ll = vpaddlq_s16(vmulq_s16(a16ll, b16ll));
    int32x4_t s32hl = vpaddlq_s16(vmulq_s16(a16hl, b16hl));
    _U.R[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(s32l, s32h));
    _U.R[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(s32ld, s32hd));
    _U.R[2] = vaddq_s32(src.vect_s32[2], vpaddq_s32(s32lq, s32hq));
    _U.R[3] = vaddq_s32(src.vect_s32[3], vpaddq_s32(s32ll, s32hl));

    if (!(k & 0x01)) _U.s32[0] = vgetq_lane_s32(src.vect_s32[0], 0);
    if (!(k & 0x02)) _U.s32[1] = vgetq_lane_s32(src.vect_s32[0], 1);
    if (!(k & 0x04)) _U.s32[2] = vgetq_lane_s32(src.vect_s32[0], 2);
    if (!(k & 0x08)) _U.s32[3] = vgetq_lane_s32(src.vect_s32[0], 3);

    if (!(k & 0x10)) _U.s32[4] = vgetq_lane_s32(src.vect_s32[1], 0);
    if (!(k & 0x20)) _U.s32[5] = vgetq_lane_s32(src.vect_s32[1], 1);
    if (!(k & 0x40)) _U.s32[6] = vgetq_lane_s32(src.vect_s32[1], 2);
    if (!(k & 0x80)) _U.s32[7] = vgetq_lane_s32(src.vect_s32[1], 3);

    if (!(k & 0x0100)) _U.s32[8] = vgetq_lane_s32(src.vect_s32[2], 0);
    if (!(k & 0x0200)) _U.s32[9] = vgetq_lane_s32(src.vect_s32[2], 1);
    if (!(k & 0x0400)) _U.s32[10] = vgetq_lane_s32(src.vect_s32[2], 2);
    if (!(k & 0x0800)) _U.s32[11] = vgetq_lane_s32(src.vect_s32[2], 3);

    if (!(k & 0x1000)) _U.s32[12] = vgetq_lane_s32(src.vect_s32[3], 0);
    if (!(k & 0x2000)) _U.s32[13] = vgetq_lane_s32(src.vect_s32[3], 1);
    if (!(k & 0x4000)) _U.s32[14] = vgetq_lane_s32(src.vect_s32[3], 2);
    if (!(k & 0x8000)) _U.s32[15] = vgetq_lane_s32(src.vect_s32[3], 3);

    return _U.O;
}
FORCE_INLINE __m512i _mm512_maskz_dpbusd_epi32 (__mmask16 k, __m512i src, __m512i a, __m512i b)
{
    union
    {
        int32x4_t R[4];
        __m512i O;
        int32_t s32[16];
    } _U Mem512Align;
    int16x8_t a16l = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[0])));
    int16x8_t a16h = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[0])));
    int16x8_t a16ld = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[1])));
    int16x8_t a16hd = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[1])));
    int16x8_t a16lq = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[2])));
    int16x8_t a16hq = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[2])));
    int16x8_t a16ll = vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a.vect_u8[3])));
    int16x8_t a16hl = vreinterpretq_s16_u16(vmovl_u8(vget_high_u8(a.vect_u8[3])));

    int16x8_t b16l = vmovl_s8(vget_low_s8(b.vect_s8[0]));
    int16x8_t b16h = vmovl_s8(vget_high_s8(b.vect_s8[0]));
    int16x8_t b16ld = vmovl_s8(vget_low_s8(b.vect_s8[1]));
    int16x8_t b16hd = vmovl_s8(vget_high_s8(b.vect_s8[1]));
    int16x8_t b16lq = vmovl_s8(vget_low_s8(b.vect_s8[2]));
    int16x8_t b16hq = vmovl_s8(vget_high_s8(b.vect_s8[2]));
    int16x8_t b16ll = vmovl_s8(vget_low_s8(b.vect_s8[3]));
    int16x8_t b16hl = vmovl_s8(vget_high_s8(b.vect_s8[3]));

    int32x4_t s32l = vpaddlq_s16(vmulq_s16(a16l, b16l));
    int32x4_t s32h = vpaddlq_s16(vmulq_s16(a16h, b16h));
    int32x4_t s32ld = vpaddlq_s16(vmulq_s16(a16ld, b16ld));
    int32x4_t s32hd = vpaddlq_s16(vmulq_s16(a16hd, b16hd));
    int32x4_t s32lq = vpaddlq_s16(vmulq_s16(a16lq, b16lq));
    int32x4_t s32hq = vpaddlq_s16(vmulq_s16(a16hq, b16hq));
    int32x4_t s32ll = vpaddlq_s16(vmulq_s16(a16ll, b16ll));
    int32x4_t s32hl = vpaddlq_s16(vmulq_s16(a16hl, b16hl));
    _U.R[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(s32l, s32h));
    _U.R[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(s32ld, s32hd));
    _U.R[2] = vaddq_s32(src.vect_s32[2], vpaddq_s32(s32lq, s32hq));
    _U.R[3] = vaddq_s32(src.vect_s32[3], vpaddq_s32(s32ll, s32hl));

    if (!(k & 0x01)) _U.s32[0] = 0;
    if (!(k & 0x02)) _U.s32[1] = 0;
    if (!(k & 0x04)) _U.s32[2] = 0;
    if (!(k & 0x08)) _U.s32[3] = 0;

    if (!(k & 0x10)) _U.s32[4] = 0;
    if (!(k & 0x20)) _U.s32[5] = 0;
    if (!(k & 0x40)) _U.s32[6] = 0;
    if (!(k & 0x80)) _U.s32[7] = 0;

    if (!(k & 0x0100)) _U.s32[8] = 0;
    if (!(k & 0x0200)) _U.s32[9] = 0;
    if (!(k & 0x0400)) _U.s32[10] = 0;
    if (!(k & 0x0800)) _U.s32[11] = 0;

    if (!(k & 0x1000)) _U.s32[12] = 0;
    if (!(k & 0x2000)) _U.s32[13] = 0;
    if (!(k & 0x4000)) _U.s32[14] = 0;
    if (!(k & 0x8000)) _U.s32[15] = 0;

    return _U.O;
}

FORCE_INLINE __m128i _mm_dpwssd_epi32 (__m128i src, __m128i a, __m128i b)
{
    __m128i O;
    int32x4_t a16l = vmovl_s16(vget_low_s16(a.vect_s16));
    int32x4_t a16h = vmovl_s16(vget_high_s16(a.vect_s16));
    int32x4_t b16l = vmovl_s16(vget_low_s16(b.vect_s16));
    int32x4_t b16h = vmovl_s16(vget_high_s16(b.vect_s16));
    int32x4_t ls = vmulq_s32(a16l, b16l);
    int32x4_t hs = vmulq_s32(a16h, b16h);
    O.vect_s32 = vaddq_s32(src.vect_s32, vpaddq_s32(ls, hs));
    return O;
}
FORCE_INLINE __m128i _mm_mask_dpwssd_epi32 (__m128i src, __mmask8 k, __m128i a, __m128i b)
{
    union
    {
        int32x4_t R;
        __m128i O;
        int32_t s32[4];
    } _U Mem256Align;
    int32x4_t a16l = vmovl_s16(vget_low_s16(a.vect_s16));
    int32x4_t a16h = vmovl_s16(vget_high_s16(a.vect_s16));
    int32x4_t b16l = vmovl_s16(vget_low_s16(b.vect_s16));
    int32x4_t b16h = vmovl_s16(vget_high_s16(b.vect_s16));
    int32x4_t ls = vmulq_s32(a16l, b16l);
    int32x4_t hs = vmulq_s32(a16h, b16h);
    _U.R = vaddq_s32(src.vect_s32, vpaddq_s32(ls, hs));

    if (!(k & 0x01)) _U.s32[0] = vgetq_lane_s32(src.vect_s32, 0);
    if (!(k & 0x02)) _U.s32[1] = vgetq_lane_s32(src.vect_s32, 1);
    if (!(k & 0x04)) _U.s32[2] = vgetq_lane_s32(src.vect_s32, 2);
    if (!(k & 0x08)) _U.s32[3] = vgetq_lane_s32(src.vect_s32, 3);

    return _U.O;
}
FORCE_INLINE __m128i _mm_maskz_dpwssd_epi32 (__mmask8 k, __m128i src, __m128i a, __m128i b)
{
    union
    {
        int32x4_t R;
        __m128i O;
        int32_t s32[4];
    } _U Mem256Align;
    int32x4_t a16l = vmovl_s16(vget_low_s16(a.vect_s16));
    int32x4_t a16h = vmovl_s16(vget_high_s16(a.vect_s16));
    int32x4_t b16l = vmovl_s16(vget_low_s16(b.vect_s16));
    int32x4_t b16h = vmovl_s16(vget_high_s16(b.vect_s16));
    int32x4_t ls = vmulq_s32(a16l, b16l);
    int32x4_t hs = vmulq_s32(a16h, b16h);
    _U.R = vaddq_s32(src.vect_s32, vpaddq_s32(ls, hs));

    if (!(k & 0x01)) _U.s32[0] = 0;
    if (!(k & 0x02)) _U.s32[1] = 0;
    if (!(k & 0x04)) _U.s32[2] = 0;
    if (!(k & 0x08)) _U.s32[3] = 0;

    return _U.O;
}

FORCE_INLINE __m256i _mm256_dpwssd_epi32 (__m256i src, __m256i a, __m256i b)
{
    __m256i O;
    int32x4_t a16l = vmovl_s16(vget_low_s16(a.vect_s16[0]));
    int32x4_t a16h = vmovl_s16(vget_high_s16(a.vect_s16[0]));
    int32x4_t b16l = vmovl_s16(vget_low_s16(b.vect_s16[0]));
    int32x4_t b16h = vmovl_s16(vget_high_s16(b.vect_s16[0]));
    int32x4_t a16ld = vmovl_s16(vget_low_s16(a.vect_s16[1]));
    int32x4_t a16hd = vmovl_s16(vget_high_s16(a.vect_s16[1]));
    int32x4_t b16ld = vmovl_s16(vget_low_s16(b.vect_s16[1]));
    int32x4_t b16hd = vmovl_s16(vget_high_s16(b.vect_s16[1]));
    int32x4_t ls = vmulq_s32(a16l, b16l);
    int32x4_t hs = vmulq_s32(a16h, b16h);
    int32x4_t lsd = vmulq_s32(a16ld, b16ld);
    int32x4_t hsd = vmulq_s32(a16hd, b16hd);
    O.vect_s32[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(ls, hs));
    O.vect_s32[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(lsd, hsd));
    return O;
}
FORCE_INLINE __m256i _mm256_mask_dpwssd_epi32 (__m256i src, __mmask8 k, __m256i a, __m256i b)
{
    union
    {
        int32x4_t R[2];
        __m256i O;
        int32_t s32[8];
    } _U Mem256Align;
    int32x4_t a16l = vmovl_s16(vget_low_s16(a.vect_s16[0]));
    int32x4_t a16h = vmovl_s16(vget_high_s16(a.vect_s16[0]));
    int32x4_t b16l = vmovl_s16(vget_low_s16(b.vect_s16[0]));
    int32x4_t b16h = vmovl_s16(vget_high_s16(b.vect_s16[0]));
    int32x4_t a16ld = vmovl_s16(vget_low_s16(a.vect_s16[1]));
    int32x4_t a16hd = vmovl_s16(vget_high_s16(a.vect_s16[1]));
    int32x4_t b16ld = vmovl_s16(vget_low_s16(b.vect_s16[1]));
    int32x4_t b16hd = vmovl_s16(vget_high_s16(b.vect_s16[1]));
    int32x4_t ls = vmulq_s32(a16l, b16l);
    int32x4_t hs = vmulq_s32(a16h, b16h);
    int32x4_t lsd = vmulq_s32(a16ld, b16ld);
    int32x4_t hsd = vmulq_s32(a16hd, b16hd);
    _U.R[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(ls, hs));
    _U.R[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(lsd, hsd));

    if (!(k & 0x01)) _U.s32[0] = vgetq_lane_s32(src.vect_s32[0], 0);
    if (!(k & 0x02)) _U.s32[1] = vgetq_lane_s32(src.vect_s32[0], 1);
    if (!(k & 0x04)) _U.s32[2] = vgetq_lane_s32(src.vect_s32[0], 2);
    if (!(k & 0x08)) _U.s32[3] = vgetq_lane_s32(src.vect_s32[0], 3);
    if (!(k & 0x10)) _U.s32[4] = vgetq_lane_s32(src.vect_s32[1], 0);
    if (!(k & 0x20)) _U.s32[5] = vgetq_lane_s32(src.vect_s32[1], 1);
    if (!(k & 0x40)) _U.s32[6] = vgetq_lane_s32(src.vect_s32[1], 2);
    if (!(k & 0x80)) _U.s32[7] = vgetq_lane_s32(src.vect_s32[1], 3);

    return _U.O;
}
FORCE_INLINE __m256i _mm256_maskz_dpwssd_epi32 (__mmask8 k, __m256i src, __m256i a, __m256i b)
{
    union
    {
        int32x4_t R[2];
        __m256i O;
        int32_t s32[8];
    } _U Mem256Align;
    int32x4_t a16l = vmovl_s16(vget_low_s16(a.vect_s16[0]));
    int32x4_t a16h = vmovl_s16(vget_high_s16(a.vect_s16[0]));
    int32x4_t b16l = vmovl_s16(vget_low_s16(b.vect_s16[0]));
    int32x4_t b16h = vmovl_s16(vget_high_s16(b.vect_s16[0]));
    int32x4_t a16ld = vmovl_s16(vget_low_s16(a.vect_s16[1]));
    int32x4_t a16hd = vmovl_s16(vget_high_s16(a.vect_s16[1]));
    int32x4_t b16ld = vmovl_s16(vget_low_s16(b.vect_s16[1]));
    int32x4_t b16hd = vmovl_s16(vget_high_s16(b.vect_s16[1]));
    int32x4_t ls = vmulq_s32(a16l, b16l);
    int32x4_t hs = vmulq_s32(a16h, b16h);
    int32x4_t lsd = vmulq_s32(a16ld, b16ld);
    int32x4_t hsd = vmulq_s32(a16hd, b16hd);
    _U.R[0] = vaddq_s32(src.vect_s32[0], vpaddq_s32(ls, hs));
    _U.R[1] = vaddq_s32(src.vect_s32[1], vpaddq_s32(lsd, hsd));

    if (!(k & 0x01)) _U.s32[0] = 0;
    if (!(k & 0x02)) _U.s32[1] = 0;
    if (!(k & 0x04)) _U.s32[2] = 0;
    if (!(k & 0x08)) _U.s32[3] = 0;
    if (!(k & 0x10)) _U.s32[4] = 0;
    if (!(k & 0x20)) _U.s32[5] = 0;
    if (!(k & 0x40)) _U.s32[6] = 0;
    if (!(k & 0x80)) _U.s32[7] = 0;

    return _U.O;
}

#undef ___CombMask_8i
#undef ___CombMask_16i
#undef ___CombMask_32i
#undef ___CombMask_64i

#endif

#endif
