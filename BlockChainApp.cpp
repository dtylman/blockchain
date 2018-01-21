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
 * File:   BlockChainApp.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 10:58 AM
 */

#include "BlockChainApp.h"
#include "Block.h"
#include <iostream>

int BlockChainApp::main(const std::vector<std::string>& args) {
        std::cout << "Hello, POCO C++ Libraries!" << std::endl;
        BlockChain::Block block;
        return EXIT_OK;
    }


POCO_APP_MAIN(BlockChainApp);