#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{

    private:
        Serializer();
        ~Serializer(); 
        Serializer(const Serializer& org);
        Serializer& operator=(const Serializer& org);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif