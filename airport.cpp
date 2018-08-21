#include "airport.hpp"


void Airport::action(const std::string& c, States s)
{

	switch(s)
	{
		case ARRIVE:
		{
			while(!hangar.llena() && !apron.vacia())
			{
				hangar.push(Aeroplane(apron.frente().cod(), IDLE));
			}

			if(hangar.llena())
				apron.push(Aeroplane(c,WAITING));
			else
			hangar.push(Aeroplane(c,IDLE));
		}
			break;

		case TAKEOFF:
		{
			if(hangar.frente().cod()!=c)
			{
				while(hangar.frente().cod()!=c && !hangar.vacia())
				{
					apron.push(hangar.frente());
					hangar.pop();
				}

				if(!hangar.vacia())
					hangar.pop();

				while(!hangar.vacia())
				{
					apron.push(hangar.frente());
					hangar.pop();
				}

				while(!apron.vacia())
				{
					hangar.push(apron.frente());
					apron.pop();
				}
			

			}

			else
				hangar.pop();

			while(!hangar.llena() && !apron.vacia())
			{
				hangar.push(Aeroplane(apron.frente().cod(), IDLE));
				apron.pop();
			}

			break;

		}
	}
}

