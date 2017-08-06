//
// Created by loris on 8/5/2017.
//

#ifndef PACMAN_DATA_HPP
#define PACMAN_DATA_HPP


#include <array>
#include <algorithm>

using Byte = unsigned char;
using Short = unsigned short;
using Size = std::size_t;

/**
 * Class representing size-fixed binary data.
 *
 * @tparam SIZE The size of the content
 */
template<Size SIZE>
struct Data
{
    /**
     * Array storing data content.
     */
    std::array<Byte, SIZE> array;
    
    /**
     * Casts raw data at a specific position into a specific type.
     *
     * @tparam TYPE The type used to cast data into
     * @param pos The position in data content
     * @return The value of the specified type
     */
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
    
    /**
     * Casts raw data at the cursor's position into a specific type.
     *
     * @tparam TYPE The type used to cast data into
     * @return The value of the specified type
     */
    template<typename TYPE>
    TYPE get()
    {
        return get<TYPE>(cursor);
    }
    
    /**
     * Casts raw data at the cursor's position into a specific type
     * and increment the cursor's value.
     *
     * @tparam TYPE
     * @return
     */
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
