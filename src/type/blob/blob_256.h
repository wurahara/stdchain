#ifndef STDCHAIN_TYPE_BLOB_256_H
#define STDCHAIN_TYPE_BLOB_256_H

#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "type/blob/base_blob.h"

class Blob256 : public BaseBlob<256> {

public:
    Blob256();
    explicit Blob256(uint8_t v);
    explicit Blob256(const std::vector<unsigned char>&vch);

private:
    friend class boost::serialization::access;
    template<typename Archive>
    void serialize(Archive &archive, uint32_t version);
};

template<typename Archive>
void Blob256::serialize(Archive &archive, const uint32_t version) {
    archive & boost::serialization::base_object<BaseBlob<256>>(*this);
}



#endif //STDCHAIN_TYPE_BLOB_256_H
