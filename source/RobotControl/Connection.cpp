//
//  Connection.cpp
//  File file is part of the "Unit Test" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/9/2015.
//  Copyright, 2015, by Samuel Williams. All rights reserved.
//

#include "Connection.hpp"

#include <iostream>
#include <sstream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>

namespace RobotControl
{
	Connection::Connection(std::string network_address)
		: _network_address(network_address)
	{
		connect();
	}
	
	Connection::~Connection()
	{
	}
	
	void Connection::send_popup(std::string message, std::string title)
	{
		std::stringstream buffer;
		
		buffer << "popup(";
		buffer << "\"" << message << "\",";
		buffer << "\"" << title << "\"";
		buffer << ")\n";
		
		send(buffer.str());
	}
	
	void Connection::send_move(Vector3 position, Vector3 angle, float a, float v, float t, float r)
	{
		std::stringstream buffer;
		
		buffer << "movej(get_inverse_kin(p[";
		buffer << position.x << "," << position.y << "," << position.z << ",";
		buffer << angle.x << "," << angle.y << "," << angle.z;
		buffer << "])";
		
		//buffer << ",";
		//buffer << a << ",";
		//buffer << v << ",";
		//buffer << t << ",";
		//buffer << r;
		
		buffer << ")\n";
		
		send(buffer.str());
	}
	
	void Connection::send(const std::string & buffer)
	{
		std::cout << "Sending: " << buffer << std::endl;
		::send(_socket, buffer.data(), buffer.size(), 0);
	}
	
	void Connection::connect()
	{
		std::string port = "30002";
		
		struct addrinfo hints, *servinfo, *p;
		
		memset(&hints, 0, sizeof hints);
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		int error = getaddrinfo(_network_address.c_str(), port.c_str(), &hints, &servinfo);
		if (error != 0) {
			std::cerr << "getaddrinfo: " << gai_strerror(error) << std::endl;
			return;
		}

		// loop through all the results and connect to the first we can
		for(p = servinfo; p != NULL; p = p->ai_next) {
				_socket = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
				
				if (_socket == -1) {
						perror("client: socket");
						continue;
				}
				
				if (::connect(_socket, p->ai_addr, p->ai_addrlen) == -1) {
						close(_socket);
						perror("client: connect");
						continue;
				}
				
				break;
		}
		
		if (p == NULL) {
				std::cerr << "client: failed to connect" << std::endl;
				return;
		}
		
		freeaddrinfo(servinfo); // all done with this structure
		
		std::cout << "Connected to robot: " << _network_address << std::endl;
	}
}
