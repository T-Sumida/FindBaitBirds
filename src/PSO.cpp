//
//  PSO.cpp
//  FindBaitBirds
//
//  Created by T_Sumida on 2019/04/24.
//

#include "PSO.hpp"
#include <math.h>
#include <random>

PSO::PSO(int dataNum, int vectorNum, int vLimit) {
    printf("%d, %d\n",dataNum, vectorNum);
    this->vLimit = vLimit;
    this->dataNum = dataNum;
    this->vectorNum = vectorNum;
    gbest =new int[vectorNum];
    
    pbest = new int*[this->dataNum];
    for(int i = 0;i < this->dataNum;i++) {
        pbest[i] = new int[this->vectorNum];
    }
    
    pbestScore = new double[dataNum];
    
}

void PSO::optimizeFirst(int index, int *pVector, int *targetVector) {
    double score = calcScore(pVector, targetVector);
    
    // 自己ベスト位置を更新
    updatePBest(index, pVector, score);
    
    // 全体ベスト位置を更新
    if(gbestScore > score) {
        updateGBest(pVector, score);
    }
}


void PSO::optimize(int index, int *pVector, int *dVector, int *targetVector) {
    double score = calcScore(pVector, targetVector);
    double r1,r2;
    // 自己ベスト位置を更新
    if(pbestScore[index] > score) {
        updatePBest(index, pVector, score);
    }
    
    // 全体ベスト位置を更新
    if(gbestScore > score) {
        updateGBest(pVector, score);
    }
    
    // 移動ベクトルの計算
    r1 = getRand();
    r2 = getRand();
    
    
    for(int i = 0;i < this->vectorNum;i++){
        dVector[i] = this->w * dVector[i] + this->c1*r1*(pbest[index][i] - pVector[i]) + this->c2*r2*(gbest[i] - pVector[i]);
        if(dVector[i] > this->vLimit) dVector[i] = this->vLimit;
        if(dVector[i] < (-1)*this->vLimit) dVector[i] = (-1)*this->vLimit;
    }
    
}

void PSO::updatePBest(int index, int *pVector, double score) {
    pbestScore[index] = score;
    for (int i = 0; i < this->vectorNum; i++) {
        pbest[index][i] = pVector[i];
    }
}

void PSO::updateGBest(int *pVector, double score) {
    gbestScore = score;
    for (int i = 0; i < this->vectorNum; i++) {
        gbest[i] = pVector[i];
    }
    
    
}

void PSO::reset() {
    gbestScore = DOUBLE_MAX;
    for(int i = 0;i < this->dataNum;i++){
        this->pbestScore[i] = DOUBLE_MAX;
    }
}

double PSO::calcScore(int *pVector, int *target) {
    double score = 0.0;
    // 現在の距離を計算
    for(int i = 0;i < this->vectorNum;i++){
        score += pow(target[i] - pVector[i],2);
    }
    score = sqrt(score);
    return score;
}


double PSO::getW() {
    return w;
}

double PSO::getC1() {
    return c1;
}

double PSO::getC2() {
    return c2;
}

int PSO::getVLimit() {
    return this->vLimit;
}

void PSO::setW(double w){
    this->w = w;
}

void PSO::setC1(double c1) {
    this->c1 = c1;
}

void PSO::setC2(double c2) {
    this->c2 = c2;
}

void PSO::setVLimit(int limit) {
    this->vLimit = limit;
}

double PSO::getRand(){
    static std::mt19937_64 mt64(0);
    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_real_distribution<double> gen_rand_uni_real( 0.0 , 1.0 );
    // 乱数を生成
    return gen_rand_uni_real(mt64);
}
