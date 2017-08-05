//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_MATRIX_HPP_H
#define PACMAN_MATRIX_HPP_H


#include <array>
#include <cassert>

using Size = std::size_t;

template<typename TYPE, Size WIDTH, Size HEIGHT>
struct Matrix
{
    std::array<TYPE, WIDTH * HEIGHT> array;
    
    TYPE & operator()(Size x, Size y) noexcept
    {
        assert(x < WIDTH);
        assert(y < HEIGHT);
        
        return array[x + y * WIDTH];
    }
    
    const TYPE & operator()(Size x, Size y) const noexcept
    {
        assert(x < WIDTH);
        assert(y < HEIGHT);
        
        return array[x + y * WIDTH];
    }
    
    constexpr Size width() const noexcept
    {
        return WIDTH;
    }
    
    constexpr Size height() const noexcept
    {
        return HEIGHT;
    }
};


#endif //PACMAN_MATRIX_HPP_H
