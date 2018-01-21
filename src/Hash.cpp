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
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"

using namespace BlockChain;
using Poco::HMACEngine;
using Poco::SHA1Engine;

#define PASSPHRASE "secret"

std::string Hash::digest(const std::string& data) {
    HMACEngine<SHA1Engine> hmac(PASSPHRASE);    
    hmac.update(data);
    return hmac.digestToHex(hmac.digest());
}
