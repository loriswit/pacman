//
// Created by loris on 8/1/2017.
//

#ifndef PACMAN_OUTPUT_H
#define PACMAN_OUTPUT_H


#include <vector>
#include "NonCopyable.hpp"
#include "Scene.hpp"

template<Size WIDTH, Size HEIGHT>
class Output : private NonCopyable
{
public:
    virtual void updateScene(const Scene<WIDTH, HEIGHT> & scene) = 0;
    
    virtual void updateSprites(const std::vector<Tile> & sprites) = 0;
    
    virtual float display() = 0;
};


#endif //PACMAN_OUTPUT_H
