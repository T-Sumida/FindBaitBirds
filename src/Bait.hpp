//
//  Bait.hpp
//  FindBaitBirds
//
//  Created by T_Sumida on 2019/04/24.
//

#ifndef Bait_hpp
#define Bait_hpp

#include <stdio.h>

class Bait {
public:
    int *position;
    int size;
    
    Bait(int x, int y, int z, int size);
    
    void draw();
    
    void setPosition(int x, int y, int z);
};

#endif /* Bait_hpp */
