#include<iostream>

using std::cout;
using std::endl;

//单例模式：要求通过该类只能创建出一个对象

class Singleton
{

public:
    static Singleton * getInstance()
    {
        if(nullptr == _pInstance)//反着写，防止写成赋值语句
        {
            _pInstance = new Singleton();
			cout << "new Singleton" <<endl;
        //    return _pInstance;
        }
		return _pInstance;
        
    }
    //销毁也放在静态成员函数中
    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;
    }
public:
    Singleton()
    {
        cout << "constructing Singleton ..." << endl;
    }
    ~Singleton()
    {
        cout << "destructing Singleton ..." << endl;
    }
private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr; //静态成员变量要在类外进行初始化

int main(void)
{
    //Singleton * ps1 = new Singleton();
    Singleton * ps1 = Singleton::getInstance();
    Singleton * ps2 = Singleton::getInstance();

    cout<< " ps1 = " << ps1 << endl;
    cout<< " ps2 = " << ps2 << endl;
    
//	ps1->destroy();
//	ps2->destroy();
	Singleton::destroy();

    //delete ps1;//我们不希望这个语句编译通过，因为new被我们封装起来了，delete也应该封装起来
}
