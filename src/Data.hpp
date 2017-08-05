//
// Created by loris on 8/5/2017.
//

#ifndef PACMAN_DATA_HPP
#define PACMAN_DATA_HPP


#include <array>
#include <fstream>
#include <algorithm>

using Byte = unsigned char;
using Short = unsigned short;
using Size = std::size_t;

template<Size SIZE>
struct Data
{
    std::array<Byte, SIZE> array;
    
    template<typename TYPE>
    TYPE get(Size pos)
    {
        assert(pos < SIZE);
        auto it = array.begin() + pos;
        std::array<Byte, sizeof(TYPE)> buffer;
        std::copy(it, it + buffer.size(), buffer.begin());
        std::reverse(buffer.begin(), buffer.end());
        return *reinterpret_cast<TYPE *>(buffer.data());
    }
    
    template<typename TYPE>
    TYPE get()
    {
        return get<TYPE>(cursor);
    }
    
    template<typename TYPE>
    TYPE next()
    {
        auto oldCursor = cursor;
        cursor += sizeof(TYPE);
        return get<TYPE>(oldCursor);
    }

private:
    Size cursor = 0;
};


#endif //PACMAN_DATA_HPP
