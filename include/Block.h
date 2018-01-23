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
#include "Poco/JSON/Object.h"

#include <string>

namespace BlockChain {

    class Block {
    public:
        static Block Genesis;
        Block(Poco::UInt32 index, const Proof& proof, const Record& record, const std::string& previous_hash);
        virtual ~Block();        
        
        Poco::UInt32 index() const;
        const std::string& prevHash() const;
        std::string hash() const;
        const Record& record() const;     
        const Proof& proof() const;
                
        Poco::JSON::Object::Ptr toJSON() const;
    private:                        
        Poco::UInt32 _index;        
        Poco::Timestamp _time;
        Proof _proof;
        Record _record;
        std::string _previous_hash;
    };

}
#endif /* BLOCK_H */

