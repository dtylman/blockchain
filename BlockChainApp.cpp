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
#include "Chain.h"
#include "Poco/Net/HTTPServer.h"
#include "HandlerFactory.h"
#include "Proof.h"
#include "Record.h"
#include <iostream>

int BlockChainApp::main(const std::vector<std::string>& args) {
    BlockChain::Chain c;
    BlockChain::Record r;
    r.append("danny");
    c.newBlock(r);
    r.append(("tylman"));
    c.newBlock(r);
    Poco::JSON::Stringifier::stringify(*c.toJSON(),std::cout);
    std::cout << std::endl;
    Poco::Net::HTTPServer server(new BlockChain::HandlerFactory(), 5080);
    server.start();
    logger().information("Server started...");
    waitForTerminationRequest();
    server.stopAll(true);
    return EXIT_OK;
}

POCO_SERVER_MAIN(BlockChainApp);