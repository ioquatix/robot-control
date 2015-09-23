# Teapot configuration generated at 2015-09-23 13:36:41 +1200

required_version "1.0.0"

# Build Targets

define_target "robot-control" do |target|
	target.build do
		source_root = target.package.path + 'source'
		
		copy headers: source_root.glob('RobotControl/**/*.{h,hpp}')
		
		build executable: "RobotControl", source_files: source_root.glob('RobotControl/**/*.cpp')
	end
	
	target.depends "Build/Files"
	target.depends "Build/Clang"
	
	target.depends :platform
	target.depends "Language/C++11"
	
	target.provides "Executable/RobotControl"
end

define_target "robot-control-run" do |target|
	target.depends "Executable/RobotControl"
	target.provides "Run/RobotControl"
	
	target.build do
		run executable: "RobotControl"
	end
end

define_target "robot-control-tests" do |target|
	target.build do
		test_root = target.package.path + 'test'
		
		run tests: "RobotControl", source_files: test_root.glob('RobotControl/**/*.cpp')
	end
	
	target.depends "Build/Clang"
	
	target.depends :platform
	target.depends "Language/C++11"
	target.depends "Library/UnitTest"
	
	target.provides "Test/RobotControl"
end

# Configurations

define_configuration "robot-control" do |configuration|
	configuration[:source] = "https://github.com/dream-framework"

	configuration.require "build-files"
	configuration.require "platforms"
	configuration.require "variants"
	configuration.require "language-cpp-class"
	configuration.require "unit-test"
	
	configuration.require "opencv"
end

