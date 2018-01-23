/*
 * Copyright (C) 2018 danny
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   Hash.h
 * Author: danny
 *
 * Created on January 21, 2018, 3:51 PM
 */

#ifndef HASH_H
#define HASH_H

#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/Timestamp.h"
#include "Poco/Types.h"
#include "Record.h"
#include "Proof.h"
#include <string> 

namespace BlockChain {

    class Hash {
    public:
        Hash();
        const std::string& digest();
        const std::string& digest(const std::string& data);
        
        bool endsWith(const std::string& suffix) const;
        
        void update(const std::string& data);
        void update(Poco::UInt32 data);
        void update(const Poco::Timestamp::TimeVal& data);
        void update(const Record& record);
        void update(const Proof& proof);
    private:
        Poco::HMACEngine<Poco::SHA1Engine> _engine;
        std::string _hash;
    };
}
#endif /* HASH_H */

