#ifndef AIRPORT_HPP_
#define AIRPORT_HPP_

#include "aeroplane.hpp"
#include "cola_vec.hpp"  // static queue
#include <iostream>


class Airport
{

public:

	Airport(): apron{11}, hangar{12}{}

	void action(const std::string&, States);





private:

	Cola<Aeroplane> apron;
	Cola<Aeroplane> hangar;

};


#endif
