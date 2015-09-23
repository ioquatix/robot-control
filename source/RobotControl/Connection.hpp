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
	class Connection
	{
	public:
		Connection(std::string network_address);
		virtual ~Connection();
		
		void send_popup(std::string message, std::string title);
		
	private:
		std::string _network_address;
		int _socket;
		
		void connect();
		void send(const std::string & buffer);
	};
}
