/* 
 * File:   Block.h
 * Author: danny
 *
 * Created on January 21, 2018, 9:18 AM
 */

#ifndef BLOCK_H
#define BLOCK_H



#include "Proof.h"
#include "Record.h"

#include "Poco/Timestamp.h"
#include "Poco/Types.h"

#include <string>

namespace BlockChain {

    class Block {
    public:
        Block(Poco::UInt32 index, const Proof& proof, const Record& record, std::string previous_hash);
        virtual ~Block();        
        
        int index() const;
        const std::string& prevHash() const;
        
        const Record& record() const;
    private:
        Poco::UInt32 _index;
        Poco::Timestamp _timestamp;
        Proof _proof;
        Record _record;
        std::string _previous_hash;
    };

}
#endif /* BLOCK_H */

