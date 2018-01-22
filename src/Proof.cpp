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
 * File:   Proof.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 12:57 PM
 */

#include "Proof.h"
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/RandomStream.h"

#include "Hash.h"

using namespace BlockChain;

#define HASH_SUFFIX "00"
#define VALUE_SIZE 100

Proof::Proof() {
    rotate();
}

Proof::~Proof() {
}

bool Proof::valid(const Proof& prevProof) {
    Hash h;
    h.digest(_value + prevProof._value);
    return h.endsWith(HASH_SUFFIX);
}

void Proof::rotate() {
    Poco::RandomInputStream ris;
    char v[VALUE_SIZE];
    ris.read(v, VALUE_SIZE);
    _value.assign(v, VALUE_SIZE);
}

Proof Proof::findNext() const {
    Proof p;
    Hash h;
    h.digest(p._value + _value);
    while (!h.endsWith(HASH_SUFFIX)) {
        p.rotate();
        h.digest(p._value + _value);
    }
    return p;
}
