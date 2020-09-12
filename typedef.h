#ifndef TYPEDEF_H
#define TYPEDEF_H

#ifdef X86_TEST
#ifndef float32_t
typedef float float32_t;
#endif
#endif

#ifndef float64_t
typedef double float64_t;
#endif

typedef enum {
	_MM_EXPADJ_NONE,
	_MM_EXPADJ_4,
	_MM_EXPADJ_5,
	_MM_EXPADJ_8,
	_MM_EXPADJ_16,
	_MM_EXPADJ_24,
	_MM_EXPADJ_31,
	_MM_EXPADJ_32,
} _MM_EXP_ADJ_ENUM;

#endif	//TYPEDEF_H
