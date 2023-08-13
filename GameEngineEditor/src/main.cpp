#include <iostream>
#include <memory>

#include "GameEngineCore/Application.hpp"

class MyApp : public GameEngine::Application
{
	virtual void on_update() override
	{
	//	std::cout << "Update frame: " << frame++ << std::endl;
	}

	int frame = 0;
};

int main()
{
	auto myApp = std::make_unique<MyApp>();

	int returnCode = myApp->start(1024, 768, "My firtst App");

	std::cin.get();

	return returnCode;
}