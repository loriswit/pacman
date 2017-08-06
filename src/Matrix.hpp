//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_MATRIX_HPP_HPP
#define PACMAN_MATRIX_HPP_HPP


#include <array>
#include <cassert>

using Size = std::size_t;

/**
 * Class representing a matrix.
 *
 * @tparam TYPE The type of the values
 * @tparam WIDTH The number of value per line
 * @tparam HEIGHT The number of value per row
 */
template<typename TYPE, Size WIDTH, Size HEIGHT>
struct Matrix
{
    /**
     * Array storing matrix content.
     */
    std::array<TYPE, WIDTH * HEIGHT> array;
    
    /**
     * Returns a reference to a value in the matrix.
     *
     * @param x The horizontal index of the value
     * @param y The vertical index of the value
     * @return The reference to the value
     */
    TYPE & operator()(Size x, Size y) noexcept
    {
        assert(x < WIDTH);
        assert(y < HEIGHT);
        
        return array[x + y * WIDTH];
    }
    
    /**
     * Returns a reference to a @a const value in the matrix.
     *
     * @param x The horizontal index of the value
     * @param y The vertical index of the value
     * @return The reference to the @a const value
     */
    const TYPE & operator()(Size x, Size y) const noexcept
    {
        assert(x < WIDTH);
        assert(y < HEIGHT);
        
        return array[x + y * WIDTH];
    }
    
    /**
     * Returns the matrix width.
     *
     * @return The number of value per line
     */
    constexpr Size width() const noexcept
    {
        return WIDTH;
    }
    
    /**
     * Returns the matrix height.
     *
     * @return The number of value per row
     */
    constexpr Size height() const noexcept
    {
        return HEIGHT;
    }
};


#endif //PACMAN_MATRIX_HPP_HPP
