//
//  particleSystem.hpp
//  OF homework 2
//
//  Created by jim pinkenberg on 11/8/16.
//
//


#pragma once
#include "ofmain.h"
#include "particle.hpp"

class particleSystem {
public:
    particleSystem (ofVec2f position);
    
    void update (ofVec2f force);
    void draw ();
    
    vector<particle> mParticleList;//nameofVector, vectors are like a fancy, high-end array
    ofVec2f mPosition;
    int mEmitRate;
    bool mIsAddingParticles;
    
};
