#pragma once
#include "Core.h"

namespace Zorro {

	class ZORRO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

