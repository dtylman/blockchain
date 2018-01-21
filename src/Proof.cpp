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

using namespace BlockChain;

Proof::Proof(int num) : _num(num){

}


Proof::~Proof() {
}

Proof Proof::Mine(const Proof& prevProof) {
    Proof p(0);
    while (!p.valid(prevProof)){
        p++;
    }
    return p;
}

bool Proof::valid(const Proof& prevProof) {
    
}

void Proof::operator++(int) {
    _num++;
}

