//
//  Bird.hpp
//  FindBaitBirds
//
//  Created by T_Sumida on 2019/04/24.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>

class Bird {
private:
    // 色情報
    int r,g,b;
    
    // 回転角
    float rotateX;
    float rotateY;
    float rotateZ;
    
    int absLimitX, absLimitY, absLimitZ;
    
    void checkLimit();
    
public:
    int *position;
    int *dVector;
    Bird(int x, int y, int z, int absLimitX, int absLimitY, int absLimitZ);
    
    void draw();
    
    void setPosition(int x, int y, int z);
    
    void move();
    
    void setColor(int r, int g, int b);
    
};

#endif /* Bird_hpp */
