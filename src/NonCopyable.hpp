//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_NONCOPYABLE_HPP
#define PACMAN_NONCOPYABLE_HPP


/**
 * Class making derived class non-copyable.
 */
class NonCopyable
{
protected:
    NonCopyable()
    {}
    
    ~NonCopyable()
    {}

public:
    /**
     * Deleted copy constructor.
     */
    NonCopyable(const NonCopyable &) = delete;
    
    /**
     * Deleted assignment operator.
     */
    NonCopyable operator=(const NonCopyable &) = delete;
};

#endif //PACMAN_NONCOPYABLE_HPP
