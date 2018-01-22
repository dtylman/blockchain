/* 
 * File:   Block.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 9:18 AM
 */

#include "Block.h"
#include "Poco/Timespan.h"

using namespace BlockChain;

Block::Block(Poco::UInt32 index, const Proof& proof, const Record& record, std::string previous_hash) : _index(index),
_proof(proof),_record(record), _previous_hash(previous_hash) {

}


Block::~Block() {
}

int Block::index() const {
    return _index;
}

const std::string& Block::prevHash() const {
    return _previous_hash;
}

const Record& Block::record() const {
    return _record;
}

