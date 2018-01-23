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
 * File:   Record.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 1:50 PM
 */

#include "Record.h"
#include "Hash.h"

using namespace BlockChain;

Record::Record() {
}

Record::~Record() {
}

void Record::append(const std::string& data) {
    _data.append(data);
}

const std::string& Record::data() const {
    return _data;
}
