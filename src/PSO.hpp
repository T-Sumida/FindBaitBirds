//
//  PSO.hpp
//  FindBaitBirds
//
//  Created by T_Sumida on 2019/04/24.
//

#ifndef PSO_hpp
#define PSO_hpp

#include <stdio.h>
#include <limits.h>

#define DOUBLE_MAX 1.0e+5
class PSO {
private:
    int vectorNum;
    int dataNum;
    int vLimit;
    int *gbest;
    int **pbest;
    double gbestScore = DOUBLE_MAX;
    double *pbestScore;
    
    double w = 1.;
    double c1 = 0.01;
    double c2 = 0.01;
    
    void updatePBest(int index, int* pVector, double score);
    void updateGBest(int* pVector, double score);
    double calcScore(int* pVector, int* target);
    double getRand();
    
public:
    PSO(int dataNum, int vectorNum, int vLimit);
    
    void optimize(int index, int* pVector, int* dVector, int* targetVector);
    
    void optimizeFirst(int index, int* pVector, int* targetVector);
    
    void reset();
    
    double getW();
    double getC1();
    double getC2();
    int getVLimit();
    void setW(double w);
    void setC1(double c1);
    void setC2(double c2);
    void setVLimit(int limit);
    
};

#endif /* PSO_hpp */
