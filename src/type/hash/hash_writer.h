#ifndef STDCHAIN_TYPE_HASH_WRITER_H
#define STDCHAIN_TYPE_HASH_WRITER_H

#include "type/blob/blob_256.h"
#include "type/hash/sha256.h"
#include "util/serialize/serialize.h"

class HashWriter {

private:
    SHA256 ctx;
    const int type;
    const int version;

public:
    HashWriter(int type, int version);
    [[nodiscard]] int getType() const;
    [[nodiscard]] int getVersion() const;
    void write(const char *pch, size_t size);
    Blob256 getHash();
    Blob256 getSHA256();
    uint64_t getCheapHash();

    template<typename T>
    HashWriter &operator<<(const T &obj);

};

template<typename T>
HashWriter &HashWriter::operator<<(const T &object) {
    util::serialize::serialize(*this, object);
    return *this;
}

#endif //STDCHAIN_TYPE_HASH_WRITER_H
