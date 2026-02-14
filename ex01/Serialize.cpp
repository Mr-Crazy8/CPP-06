#include "Serialize.hpp"


Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& org) {(void)org;}

Serializer& Serializer::operator=(const Serializer& org)
{
    (void)org;
    return *this;
}


uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}