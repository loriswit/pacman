//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_NONCOPYABLE_H
#define PACMAN_NONCOPYABLE_H

class NonCopyable
{
protected:
    NonCopyable()
    {}
    
    ~NonCopyable()
    {}

public:
    NonCopyable(const NonCopyable &) = delete;
    
    NonCopyable operator=(const NonCopyable &) = delete;
};

#endif //PACMAN_NONCOPYABLE_H
