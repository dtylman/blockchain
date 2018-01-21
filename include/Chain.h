/* 
 * File:   Chain.h
 * Author: danny
 *
 * Created on January 21, 2018, 9:19 AM
 */

#ifndef CHAIN_H
#define CHAIN_H

#include "Block.h"
#include "Record.h"
#include "Node.h"

#include <vector>

namespace BlockChain {
        
class Chain {
public:
    typedef std::vector<Block> List;
    
    Chain();    
    virtual ~Chain();
    
    const Block& newBlock(const Record& record);    
    
    bool validate() const;
protected:
    bool validateProof(const Proof& lastProof, const Proof& proof) const;
private:
    List _chain;
    Node::List _nodes;
};

}
#endif /* CHAIN_H */

