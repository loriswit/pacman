//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_MATRIX_HPP
#define PACMAN_MATRIX_HPP


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
     * Constructs the matrix.
     */
    Matrix()
    {
        if constexpr(USES_VECTOR)
            array.resize(SIZE);
    }
    
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
    
    /**
     * Returns the internal data of the matrix.
     *
     * @return The internal data
     */
    auto data() const noexcept
    {
        return array.data();
    }
    
    /**
     * Fills the matrix with a specific value.
     *
     * @param value The value to fill the matrix with
     */
    void fill(TYPE value) noexcept
    {
        std::fill(array.begin(), array.end(), value);
    }

private:
    static constexpr Size SIZE = WIDTH * HEIGHT;
    static constexpr bool USES_VECTOR = SIZE > 1'000'000;
    
    std::conditional_t<USES_VECTOR, std::vector<TYPE>, std::array<TYPE, SIZE>> array;
};


#endif //PACMAN_MATRIX_HPP
