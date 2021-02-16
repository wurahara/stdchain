#ifndef STDCHAIN_UTIL_HASH_COMMON_H
#define STDCHAIN_UTIL_HASH_COMMON_H

#include "util/compact/endian.h"

namespace util::hash {
    uint16_t static inline ReadLE16(const unsigned char *ptr) {
        uint16_t x;
        memcpy((char *) &x, ptr, 2);
        return util::compact::le16toh(x);
    }

    uint32_t static inline ReadLE32(const unsigned char *ptr) {
        uint32_t x;
        memcpy((char *) &x, ptr, 4);
        return util::compact::le32toh(x);
    }

    uint64_t static inline ReadLE64(const unsigned char *ptr) {
        uint64_t x;
        memcpy((char *) &x, ptr, 8);
        return util::compact::le64toh(x);
    }

    void static inline WriteLE16(unsigned char *ptr, uint16_t x) {
        uint16_t v = util::compact::htole16(x);
        memcpy(ptr, (char *) &v, 2);
    }

    void static inline WriteLE32(unsigned char *ptr, uint32_t x) {
        uint32_t v = util::compact::htole32(x);
        memcpy(ptr, (char *) &v, 4);
    }

    void static inline WriteLE64(unsigned char *ptr, uint64_t x) {
        uint64_t v = util::compact::htole64(x);
        memcpy(ptr, (char *) &v, 8);
    }

    uint16_t static inline ReadBE16(const unsigned char *ptr) {
        uint16_t x;
        memcpy((char *) &x, ptr, 2);
        return util::compact::be16toh(x);
    }

    uint32_t static inline ReadBE32(const unsigned char *ptr) {
        uint32_t x;
        memcpy((char *) &x, ptr, 4);
        return util::compact::be32toh(x);
    }

    uint64_t static inline ReadBE64(const unsigned char *ptr) {
        uint64_t x;
        memcpy((char *) &x, ptr, 8);
        return util::compact::be64toh(x);
    }

    void static inline WriteBE32(unsigned char *ptr, uint32_t x) {
        uint32_t v = util::compact::htobe32(x);
        memcpy(ptr, (char *) &v, 4);
    }

    void static inline WriteBE64(unsigned char *ptr, uint64_t x) {
        uint64_t v = util::compact::htobe64(x);
        memcpy(ptr, (char *) &v, 8);
    }

/** Return the smallest number n such that (x >> n) == 0 (or 64 if the highest bit in x is set. */
    uint64_t static inline CountBits(uint64_t x) {
        int ret = 0;
        while (x) {
            x >>= 1;
            ++ret;
        }
        return ret;
    }
} // namespace util::hash

#endif //STDCHAIN_UTIL_HASH_COMMON_H
