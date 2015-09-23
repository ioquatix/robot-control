//
//  Application.cpp
//  File file is part of the "Unit Test" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/9/2015.
//  Copyright, 2015, by Samuel Williams. All rights reserved.
//

#include "Application.hpp"

#include <iostream>

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
}

