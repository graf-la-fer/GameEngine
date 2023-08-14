#include "GameEngineCore/Application.hpp"
#include "GameEngineCore/Log.hpp"
#include "GameEngineCore/Window.hpp"

#include <iostream>

namespace GameEngine {

	Application::Application()
	{
        LOG_INFO("Starting Application");
    }

	Application::~Application()
	{
		LOG_INFO("Closing Application");
	}

	int Application::start(unsigned int window_width, unsigned int window_height, const char* title)
	{
		m_pWindow = std::make_unique<Window>(title, window_width, window_height);
		m_pWindow->set_event_callback(
			[](Event& event)
			{
				LOG_INFO("[EVENT] Changed size to {0}x{1}", event.width, event.height);
			}
		);


		while (true)
		{
			m_pWindow->on_update();
			on_update();
		}


        return 0;
	}

}