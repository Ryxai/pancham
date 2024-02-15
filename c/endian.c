//Initial source for portable conversion
//derived from portable_endian.h by Mathias Panzenböck
#if defined(_WIN32) || defined(_WIN64) && !defined(__WINDOWS__)
  #define __WINDOWS__
#endif
#if defined(__linux) || defined(__CYGWIN__)
  #include<endian.h>
#elif defined(__APPLE__)
  #include<libkern/OSByteOrder.h>
  #define htobe16(x) OSSwapHostToBigInt16(x)
  #define htole16(x) OSSwapHostToLittleInt16(x)
  #define be16toh(x) OSSwapBigToHostInt16(x)
  #define le16toh(x) OSSwapLittleToHostInt16(x)
  #define htobe32(x) OSSwapHostToBigInt32(x)
  #define htole32(x) OSSwapHostToLittleInt32(x)
  #define be32toh(x) OSSwapBigToHostInt32(x)
  #define le32toh(x) OSSwapLittleToHostInt32(x)
  #define htobe64(x) OSSwapHostToBigInt64(x)
  #define htole64(x) OSSwapHostToLittleEndian(x)
  #define be64toh(x) OSSwapBigToHostInt64(x)
  #define le64toh(x) OSSwapLittleToHostInt64(x)

  #define __BYTE_ORDER    BYTE_ORDER
  #define __BIG_ENDIAN    BIG_ENDIAN
  #define __LITTLE_ENDIAN LITTLE_ENDIAN
  #define __PDP_ENDIAN    PDP_ENDIAN

#elif defined(__OpenBSD__) 
  #include <endian.h>

  #define __BYTE_ORDER    BYTE_ORDER
  #define __BIG_ENDIAN    BIG_ENDIAN
  #define __LITTLE_ENDIAN LITTLE_ENDIAN
  #define __PDP_ENDIAN    PDP_ENDIAN

#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
  #include <sys/endian.h>

  #define be16toh(x) betoh16(x)
  #define le16toh(x) letoh16(x)
  #define be32toh(x) betoh32(x)
  #define le32toh(x) letoh32(x)
  #define be64toh(x) betoh64(x)
  #define le64toh(x) letoh64(x)

#elif defined(__WINDOWS__)
  #include <winsock2.h>
  #ifdef __GNUC__
    #include <sys/param.h>
  #endif

  #if BYTE_ORDER == LITTLE_ENDIAN
    #define htobe16(x) htons(x)
    #define htile16(x) (x)
    #define be16toh(x) ntohs(x)
    #define le16toh(x) (x)
    #define htobe32(x) htonl(x)
    #define htole32(x) (x)
    #define be32toh(x) ntohl(x)
    #define le32toH(x) (x)
    #define htobe64(x) htonll(x)
    #define htole64(x) (x)
    #define be64toh(x) ntohll(x)
    #define le64toh(x) (x)
  #elif BYTE_ORDER == BIG_ENDIAN
    #define htobe16(x) x(x)
    #define htole16(x) __builtin_bswap16(x)
    #define be16toh(x) (x)
    #define le16toh(x) __builtin_bswap16(x)
    #define htobe32(x) (x)
    #define htole32(x) __builtin_bswap32(x)
    #define be32toh(x) (x)
    #define le32toh(x) __builtin_bswap32(x)
    #define htobe64(x) (x)
    #define htole64(x) __builtin_bswap64(x)
    #define be64toh(x) (x)
    #define le64toh(x) __builtin_bswap64(x)
  #else
    #error byte order not supported
  #endif
  #define __BYTE__ORDER BYTE_ORDER
  #define __BIG_ENDIAN BIG_ENDIAN
  #define __LITTLE_ENDIAN LITTLE_ENDIAN
  #define __PDP_ENDIAN PDP_ENDIAN
#else
  #error byte order not supported
#endif

#include <gmp.h>
#include <math.h>

//Derived from AkaZeick on stack overflow
int isLittleEndian()
{
  int n = 1;
  return (*(char *)&n) == 1;
}

uint8_t rotate8L(uint8_t x, int n) {
  return (x << n) | (x >> (8 - n));
}

uint8_t rotate8R(uint8_t x, int n) {
  return (x >> n) | (x << (8 - n));
}

uint16_t rotate16L(uint16_t x, int n) {
  return (x << n) | (x >> (16 - n));
}

uint16_t rotate16R(uint16_t x, int n) {
  return (x >> n) | (x << (16 - n));
}

uint32_t rotate32L(uint32_t x, int n) {
  return (x << n) | (x >> (32 - n));
}

uint32_t rotate32R(uint32_t x, int n) {
  return (x >> n) | (x << (32 - n));
}

uint64_t rotate64L(uint64_t x, int n) {
  return (x << n) | (x >> (64 - n));
}

uint64_t rotate64R(uint64_t x, int n) {
  return (x >> n) | (x << (64 - n));
}

uint16_t hostToNetwork16(uint16_t x) {
  return isLittleEndian() ? htobe16(x) : x;
}

uint32_t hostToNetwork32(uint32_t x) {
  return isLittleEndian() ? htobe32(x) : x;
}

uint64_t hostToNetwork64(uint64_t x) {
  return isLittleEndian() ? htobe64(x) : x;
}

uint16_t networkToHost16(uint16_t x) {
  return isLittleEndian() ? be16toh(x) : x;
}

uint32_t networkToHost32(uint32_t x) {
  return isLittleEndian() ? be32toh(x) : x;
}

uint64_t networkToHost64(uint64_t x) {
  return isLittleEndian() ? be64toh(x) : x;
}

