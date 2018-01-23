/* 
 * File:   Block.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 9:18 AM
 */

#include "Block.h"
#include "Poco/Timespan.h"
#include "Hash.h"

using namespace BlockChain;

// the genesis block
Block Block::Genesis(0,Proof(),Record(),"100");

Block::Block(Poco::UInt32 index, const Proof& proof, const Record& record, const std::string& previous_hash) : _index(index),
_proof(proof), _record(record), _previous_hash(previous_hash) {

}

Block::~Block() {
}

Poco::UInt32 Block::index() const {
    return _index;
}

const std::string& Block::prevHash() const {
    return _previous_hash;
}

const Record& Block::record() const {
    return _record;
}

const Proof& Block::proof() const {
    return _proof;
}

std::string Block::hash() const {
    Hash h;
    h.update(_index);
    h.update(_time.epochMicroseconds());
    h.update(_proof);
    h.update(_record);    
    h.update(_previous_hash);
    return h.digest();    
}

Poco::JSON::Object::Ptr Block::toJSON() const {
    Poco::JSON::Object::Ptr json = new Poco::JSON::Object();
    json->set("index", _index);
    json->set("time", _time.epochMicroseconds());
    json->set("proof", _proof.toJSON());
    json->set("record", _record.toJSON());
    json->set("prev_hash", _previous_hash);
    return json;
}



