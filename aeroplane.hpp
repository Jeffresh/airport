#ifndef AEROPLANE_HPP_
#define AEROPLANE_HPP_

#include<string>

enum States{ARRIVE,TAKEOFF,WAITING,IDLE};

class Aeroplane
{
public:
	Aeroplane(){}
	Aeroplane(std::string c, States s = IDLE):cod_{c},state_{s}{}
	void state (States s){state_ = s;}
	States state() const{ return state_;}
	States state() { return state_;}
	const std::string& cod()const{return cod_;}
	const std::string& cod(){return cod_;}

private:

	std::string cod_;
	enum States state_;
};


#endif

