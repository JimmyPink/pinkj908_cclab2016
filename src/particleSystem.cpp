//
//  particleSystem.cpp
//  OF homework 2
//
//  Created by jim pinkenberg on 11/8/16.
//
//

#include "particleSystem.hpp"

//initilizing constructor
particleSystem::particleSystem(ofVec2f position) : mPosition(position),
mEmitRate(10), mIsAddingParticles(true) {}

void particleSystem::update (ofVec2f force) {
    if (mIsAddingParticles) {
        for(int i = 0; i < mEmitRate; i++) {
            particle particle(mPosition);
            mParticleList.push_back(particle);
        }
    }
    
    for (int i =0; i < mParticleList.size(); i++) {
        ofVec2f diff = ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x), abs(mParticleList[i].mPosition.y- mPosition.y));
        
        mParticleList[i].resetForces();
        
        //force is passed through ofapp.cpp
        mParticleList[i].applyForce(force);
        
        // apply random speed to the particle
        mParticleList[i].update(ofMap(diff.length(),100,200, 20, 1));
        
        if (diff.length() >= ofRandom(200, 400)) {
            
            // stop adding particle if diff is higher than certain number
            mIsAddingParticles = false;
            
            // erase particle if gets too far from center
            if (mParticleList.size() >10) {
                mParticleList.erase(mParticleList.begin()+i);
            }
        }
    }
}

void particleSystem::draw () {
    for(int i = 0; i< mParticleList.size(); i++) {
        mParticleList[i].draw();
        
    }
    
}
