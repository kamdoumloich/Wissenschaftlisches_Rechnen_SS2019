#include <iostream>
#include <exception>

//Deklaration der Klasse Ball mit der Erbschaft exception
class Ball: public std::exception
{

};

//Deklaration der Klasse P
class P
{
	public:
	P *target;
	std::string msg;
 
	// Konstrutor
	P(P *target_, std::string msg_){
		target = target_;
		msg = msg_;
	}

	// Destruktor
	~P(){
		target = nullptr;
		msg = nullptr;
	}

	// Funktion aim
	void aim(Ball *ball){
		// Exception
		try{
			throw Ball();
		}
		catch(Ball &b){
			std::cout << msg << std::endl;
			this->target->aim(&b);
		}
	}
};

int main();

int main()
{
	P *parent = new P(nullptr, "Father");
	P *child = new P(parent, "Son");
	
	parent->target = child;
	parent->aim(new Ball());
}
