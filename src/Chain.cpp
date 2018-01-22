/* 
 * File:   Chain.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 9:19 AM
 */

#include "Chain.h"

using namespace BlockChain;

Chain::Chain() {
    //newBlock?
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
        if (iter->record().hash() != nextBlock.prevHash()) {
            return false;
        }
        
        
        /*
          # Check that the Proof of Work is correct
        if not self.valid_proof(last_block['proof'], block['proof']):
        return False*/

    }
    return true;
}

bool Chain::validateProof(const Proof& lastProof, const Proof& proof) const {
    ///?
    return true;
}

const Block& Chain::newBlock(const Record& record) {
    
}
