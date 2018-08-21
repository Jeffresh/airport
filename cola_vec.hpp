#define COLA_VEC_HPP
#include <cassert>

template <typename T>
class Cola
{

public:

	explicit Cola(int tamaMax);
	Cola(const Cola<T>& C);
	Cola<T>& operator =(const Cola<T>& C);

	bool vacia()const;
	bool llena()const;

	void pop();
	void push(const T& x);
	const T& frente()const;
	
	~Cola();

private:

	T* elementos;
	int fin;
	int Lmax;
};


template<typename T>
inline Cola<T>::Cola(int tamaMax): 
elementos(new [tamaMax+1]), 
Lmax(tamaMax+1),
fin(-1)
{}

template<typename T>
Cola<T>::Cola(const Cola<T>& C): 
elementos (new T[C.Lmax]),
fin (C.fin),	
Lmax (C.Lmax)
{
	for(int i = 0 ; i < Lmax; i++)
		elementos[i] = C.elementos[i];
}

template<typename T>
Cola<t>& Cola<T>::operator =(const Cola<T>& C)
{

	if(this!= &C) // evitar autoasignación
	{

		if( Lmax != C.Lmax)
		{
			delete [] elementos;

			elementos = new T[C.Lmax];
			Lmax = C.lmax;
		}

		fin = C.fin;
		for (int i = 0 ; i < Lmax ; i ++)
			elementos[i] = C.elementos[i];

	}

	return *this;
}

template<typename T>
inline bool Cola<T>::vacia()const { return fin == -1; }
template<typename T>
inline bool Cola<T>::llena()const{ return fin == Lmax-1;}

template<typename T>
void Cola<T>::pop()
{
	assert(!vacia());

	for(int i = 1 ; i <fin; i++)
		elementos[i-1] = elementos[i]; 

	fin--;

}


template<typename T>
inline void Cola<T>::push(const T& x)
{

	assert(!llena());
	fin++;
	elementos[fin] = x;
}


template<typename T>
inline const T& Cola<T>::frente() const{ assert(!vacia()); return *elemento;}

template<typename T>
inline Cola<T>::~Cola()
{
	delete [] elementos;
}

