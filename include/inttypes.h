// SPDX-License-Identifier: MIT
#pragma once

#include <stddef.h>
#include <stdint.h>

#define PRIx64 "llx"
#define PRId64 "lld"
#define PRIi64 "lli"
#define PRIo64 "llo"
#define PRIu64 "llu"
#define PRIX64 "llX"

#define PRIx32 "x"
#define PRId32 "d"
#define PRIi32 "i"
#define PRIo32 "o"
#define PRIu32 "u"
#define PRIX32 "X"

#define PRIx16 "x"
#define PRId16 "d"
#define PRIi16 "i"
#define PRIo16 "o"
#define PRIu16 "u"
#define PRIX16 "X"

#define PRIx8 "x"
#define PRId8 "d"
#define PRIi8 "i"
#define PRIo8 "o"
#define PRIu8 "u"
#define PRIX8 "X"

#define PRIxLEAST8 PRIx8
#define PRIdLEAST8 PRId8
#define PRIiLEAST8 PRIi8
#define PRIoLEAST8 PRIo8
#define PRIuLEAST8 PRIu8
#define PRIXLEAST8 PRIX8

#define PRIxLEAST16 PRIx16
#define PRIdLEAST16 PRId16
#define PRIiLEAST16 PRIi16
#define PRIoLEAST16 PRIo16
#define PRIuLEAST16 PRIu16
#define PRIXLEAST16 PRIX16

#define PRIxLEAST32 PRIx32
#define PRIdLEAST32 PRId32
#define PRIiLEAST32 PRIi32
#define PRIoLEAST32 PRIo32
#define PRIuLEAST32 PRIu32
#define PRIXLEAST32 PRIX32

#define PRIxLEAST64 PRIx64
#define PRIdLEAST64 PRId64
#define PRIiLEAST64 PRIi64
#define PRIoLEAST64 PRIo64
#define PRIuLEAST64 PRIu64
#define PRIXLEAST64 PRIX64

#define PRIxFAST8 PRIx8
#define PRIdFAST8 PRId8
#define PRIiFAST8 PRIi8
#define PRIoFAST8 PRIo8
#define PRIuFAST8 PRIu8
#define PRIXFAST8 PRIX8

#define PRIxFAST16 PRIx16
#define PRIdFAST16 PRId16
#define PRIiFAST16 PRIi16
#define PRIoFAST16 PRIo16
#define PRIuFAST16 PRIu16
#define PRIXFAST16 PRIX16

#define PRIxFAST32 PRIx32
#define PRIdFAST32 PRId32
#define PRIiFAST32 PRIi32
#define PRIoFAST32 PRIo32
#define PRIuFAST32 PRIu32
#define PRIXFAST32 PRIX32

#define PRIxFAST64 PRIx64
#define PRIdFAST64 PRId64
#define PRIiFAST64 PRIi64
#define PRIoFAST64 PRIo64
#define PRIuFAST64 PRIu64
#define PRIXFAST64 PRIX64

#define PRIxMAX PRIx64
#define PRIdMAX PRId64
#define PRIiMAX PRIi64
#define PRIoMAX PRIo64
#define PRIuMAX PRIu64
#define PRIXMAX PRIX64

#define SCNd64 PRId64
#define SCNi64 PRIi64
#define SCNo64 PRIo64
#define SCNu64 PRIu64
#define SCNx64 PRIx64

#define SCNd32 PRId32
#define SCNi32 PRIi32
#define SCNo32 PRIo32
#define SCNu32 PRIu32
#define SCNx32 PRIx32

#define SCNd16 "hd"
#define SCNi16 "hi"
#define SCNo16 "ho"
#define SCNu16 "hu"
#define SCNx16 "hx"

#define SCNd8 "hhd"
#define SCNi8 "hhi"
#define SCNo8 "hho"
#define SCNu8 "hhu"
#define SCNx8 "hhx"

#define SCNdLEAST8 SCNd8
#define SCNiLEAST8 SCNi8
#define SCNoLEAST8 SCNo8
#define SCNuLEAST8 SCNu8
#define SCNxLEAST8 SCNx8

#define SCNdLEAST16 SCNd16
#define SCNiLEAST16 SCNi16
#define SCNoLEAST16 SCNo16
#define SCNuLEAST16 SCNu16
#define SCNxLEAST16 SCNx16

#define SCNdLEAST32 SCNd32
#define SCNiLEAST32 SCNi32
#define SCNoLEAST32 SCNo32
#define SCNuLEAST32 SCNu32
#define SCNxLEAST32 SCNx32

#define SCNdLEAST64 SCNd64
#define SCNiLEAST64 SCNi64
#define SCNoLEAST64 SCNo64
#define SCNuLEAST64 SCNu64
#define SCNxLEAST64 SCNx64

#define SCNdFAST8 SCNd8
#define SCNiFAST8 SCNi8
#define SCNoFAST8 SCNo8
#define SCNuFAST8 SCNu8
#define SCNxFAST8 SCNx8

#define SCNdFAST16 SCNd16
#define SCNiFAST16 SCNi16
#define SCNoFAST16 SCNo16
#define SCNuFAST16 SCNu16
#define SCNxFAST16 SCNx16

#define SCNdFAST32 SCNd32
#define SCNiFAST32 SCNi32
#define SCNoFAST32 SCNo32
#define SCNuFAST32 SCNu32
#define SCNxFAST32 SCNx32

#define SCNdFAST64 SCNd64
#define SCNiFAST64 SCNi64
#define SCNoFAST64 SCNo64
#define SCNuFAST64 SCNu64
#define SCNxFAST64 SCNx64

#define SCNdMAX PRId64
#define SCNiMAX PRIi64
#define SCNoMAX PRIo64
#define SCNuMAX PRIu64
#define SCNxMAX PRIx64

#if __SIZEOF_POINTER__ == 8
#define PRIxPTR PRIx64
#define PRIdPTR PRId64
#define PRIiPTR PRIi64
#define PRIoPTR PRIo64
#define PRIuPTR PRIu64
#define PRIXPTR PRIX64
#define SCNdPTR PRId64
#define SCNiPTR PRIi64
#define SCNoPTR PRIo64
#define SCNuPTR PRIu64
#define SCNxPTR PRIx64
#else
#define PRIxPTR "x"
#define PRIdPTR "d"
#define PRIiPTR "i"
#define PRIoPTR "o"
#define PRIuPTR "u"
#define PRIXPTR "X"
#define SCNdPTR "d"
#define SCNiPTR "i"
#define SCNoPTR "o"
#define SCNuPTR "u"
#define SCNxPTR "x"
#endif

typedef struct {
    intmax_t quot;
    intmax_t rem;
} imaxdiv_t;

#ifdef __cplusplus
extern "C" {
#endif

intmax_t imaxabs(intmax_t j);
imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
intmax_t strtoimax(const char* nptr, char** endptr, int base);
uintmax_t strtoumax(const char* nptr, char** endptr, int base);
intmax_t wcstoimax(const wchar_t* nptr, wchar_t** endptr, int base);
uintmax_t wcstoumax(const wchar_t* nptr, wchar_t** endptr, int base);

#ifdef __cplusplus
}
#endif
