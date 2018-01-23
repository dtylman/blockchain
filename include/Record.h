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
 * File:   Record.h
 * Author: danny
 *
 * Created on January 21, 2018, 1:50 PM
 */

#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>
#include "Poco/Types.h"
#include "Poco/JSON/Object.h"


namespace BlockChain {

    class Record {        
    public:         
        Record();
        virtual ~Record();        
        void append(const std::string& data);
        const std::string& data() const;
        
        Poco::JSON::Object::Ptr toJSON() const;
    private:
        std::string _data;
    };
}

#endif /* RECORD_H */

