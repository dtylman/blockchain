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
 * File:   BlockChainHandler.cpp
 * Author: danny
 * 
 * Created on January 21, 2018, 3:09 PM
 */

#include "HandlerFactory.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"

using namespace BlockChain;

HandlerFactory::HandlerFactory() {

}

Poco::Net::HTTPRequestHandler* HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request) {
    return new HandlerFactory();
}

void HandlerFactory::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
    response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");

	Poco::DateTime now;
	std::string timeString(Poco::DateTimeFormatter::format(now, Poco::DateTimeFormat::SORTABLE_FORMAT));

	std::ostream& responseStream = response.send();
	responseStream << "<html><head><head><title>Simple HTTP Server</title></head>";
	responseStream << "<body><h1>Current Time</h1><p>";
	responseStream << ( timeString );
    responseStream << "</p></body></html>";
}

HandlerFactory::~HandlerFactory() {

}
