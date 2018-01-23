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
 * File:   Hash.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 3:51 PM
 */

#include "Hash.h"
#include <iostream>
using namespace BlockChain;

#define PASSPHRASE "secret"

Hash::Hash() : _engine(PASSPHRASE) {
}

const std::string& Hash::digest(){
    _hash = _engine.digestToHex(_engine.digest());
    return _hash;
}

const std::string& Hash::digest(const std::string& data) {
    _engine.reset();
    _engine.update(data);
    return digest();
}

bool Hash::endsWith(const std::string& suffix) const {
    if (suffix.size() > _hash.size()) {
        return false;
    }
    return std::equal(suffix.rbegin(), suffix.rend(), _hash.rbegin());
}

void Hash::update(const std::string& data) {
    _engine.update(data);
}

void Hash::update(Poco::UInt32 data) {
    _engine.update(&data,sizeof(Poco::UInt32));
}

void Hash::update(const Poco::Timestamp::TimeVal& data) {
    _engine.update(&data,sizeof(Poco::Timestamp::TimeVal));
}

void Hash::update(const Record& record) {
    _engine.update(record.data());
}

void Hash::update(const Proof& proof){
    _engine.update(proof.value());
}