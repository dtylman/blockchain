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
 * File:   Node.h
 * Author: danny
 *
 * Created on January 21, 2018, 1:55 PM
 */

#ifndef NODE_H
#define NODE_H

#include <vector>

namespace BlockChain{
class Node {
public:
    typedef std::vector<Node> List;
    Node();    
    virtual ~Node();
private:

};
}

#endif /* NODE_H */

