#include<iostream>
using std::cout;
using std::endl;

class Singleton
{
private:
	Singleton()
	{
		cout << " constructing Singleton ..." << endl;
	}
	~Singleton()
	{
		cout << " destructing Singleton ..." <<endl;
	}

public:
	static void destroy()
	{
		delete _pInstance;
	}

	static Singleton* getInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Singleton();
		return _pInstance;
	}

private:
	static Singleton* _pInstance;
};

Singleton* Singleton::_pInstance = nullptr;
int main(void)
{
	Singleton* ps1 = Singleton::getInstance();
	Singleton* ps2 = Singleton::getInstance();
	cout << "ps1 = " << ps1 << endl
	     << "ps2 = " << ps2 << endl;
	Singleton::destroy();
}
