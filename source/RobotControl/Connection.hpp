//
//  Connection.hpp
//  File file is part of the "Unit Test" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/9/2015.
//  Copyright, 2015, by Samuel Williams. All rights reserved.
//

#pragma once

#include <string>

namespace RobotControl
{
	struct Vector3
	{
		float x, y, z;
	};
	
	class Connection
	{
	public:
		Connection(std::string network_address);
		virtual ~Connection();
		
		void send_popup(std::string message, std::string title);
		
		void send_move(Vector3 position, Vector3 angle, float a = 1.2, float v = 0.3, float t = 1.0, float r = 0);
		
	private:
		std::string _network_address;
		int _socket;
		
		void connect();
		void send(const std::string & buffer);
	};
}
