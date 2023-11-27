#include <Zorro.h>

class Sandbox : public Zorro::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
	

};

Zorro::Application* Zorro::CreateApplication()
{
	return new Sandbox();
}
