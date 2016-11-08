//
//  particle.hpp
//  OF homework 2
//
//  Created by jim pinkenberg on 11/8/16.
//
//

#pragma once
#include "ofMain.h"

class particle {
public:
    // create constructors, constructors initialize classes,
    //they can take arguments but they don't have a return type,
    //because they return classes themselfes
    
    particle (ofVec2f position);
    
    void update(float multiplier);
    void draw();
    void applyForce(ofVec2f force);
    void resetForces();
    
    ofVec2f mPosition, mSpeed, mDirection;
    float mLifeSpan;
    
    
    
};
