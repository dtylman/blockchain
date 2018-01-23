/* 
 * File:   Chain.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 9:19 AM
 */

#include "Chain.h"

using namespace BlockChain;

Chain::Chain() {
    newBlock(Record());
}

Chain::~Chain() {
}

bool Chain::validate() const {
    if (_chain.empty()) {
        return true;
    }
    auto iter = _chain.end();
    while (iter != _chain.begin()) {
        const Block& nextBlock = *iter;
        iter--;
        if (iter->hash() != nextBlock.prevHash()) {
            return false;
        }
        
        if (!nextBlock.proof().valid(iter->proof())){
            return false;
        }
        
    }
    return true;
}

const Block& Chain::newBlock(const Record& record) {
    const Block& prev = lastBlock();
    Block b(_chain.size(),prev.proof().findNext(),record,prev.hash());
    _chain.push_back(b);
    return lastBlock();
}

const Block& Chain::lastBlock() const {    
    return _chain[_chain.size()-1];
}
