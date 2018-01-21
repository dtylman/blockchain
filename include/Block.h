/* 
 * File:   Block.h
 * Author: danny
 *
 * Created on January 21, 2018, 9:18 AM
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <string>

#include "Proof.h"
#include "Record.h"

namespace BlockChain {

    class Block {
    public:
        Block(int index, const Proof& proof, std::string previous_hash);
        virtual ~Block();        
        
        int index() const;
        const std::string& prevHash() const;
        
        const Record& record() const;
    private:
        int _index;
        uint64_t _timestamp;
        Proof _proof;
        Record _record;
        std::string _previous_hash;
    };

}
#endif /* BLOCK_H */

