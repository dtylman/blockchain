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
 * File:   BlockChainHandler.h
 * Author: danny
 *
 * Created on January 21, 2018, 3:09 PM
 */

#ifndef BLOCKCHAINHANDLER_H
#define BLOCKCHAINHANDLER_H

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

namespace BlockChain {

    class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory, 
            Poco::Net::HTTPRequestHandler {
    public:
        HandlerFactory();        
        virtual ~HandlerFactory();

    
        virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

        virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);



    };

}
#endif /* BLOCKCHAINHANDLER_H */

