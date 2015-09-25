//
//  Application.cpp
//  File file is part of the "Unit Test" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/9/2015.
//  Copyright, 2015, by Samuel Williams. All rights reserved.
//

#include "Application.hpp"
#include "Connection.hpp"

#include <iostream>
#include <cmath>
#include <unistd.h>

namespace RobotControl
{
	Application::Application()
	{
		std::cout << "Starting up Robot Control..." << std::endl;
	}
	
	Application::~Application()
	{
	}
}

int main(int argc, char ** argv) {
	RobotControl::Application application;
	RobotControl::Connection connection("192.168.1.47");
	
	connection.send_move({0, -0.19145, 1.0}, {0.0001, 2.2214, -2.2214});
	//sleep(5.0);
	//connection.send_move({0, 0.4, 0.4}, {0, 3.14, 0});
	//sleep(5.0);
	//connection.send_move({0, 0.4, 0.4}, {0, 3.14, 3.14});
}

