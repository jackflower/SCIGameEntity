////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2022
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "Bullet.hpp"
#include "../entityengine/Game.hpp"
#include "../entityengine/EntityType.hpp"

namespace logic
{
	// Default constructor
	Bullet::Bullet() :
		Actor{}, // base class constructor
		m_time_to_destruction{ 0.0f }
	{
	}

	// Copy constructor
	Bullet::Bullet(const Bullet& copy) :
		Actor{ copy }, // base class copy constructor
		m_time_to_destruction{ copy.m_time_to_destruction }
	{
	}

	// Move constructor
	Bullet::Bullet(Bullet&& other) :
		Actor{ other }, // base class move constructor
		m_time_to_destruction{ other.m_time_to_destruction }
	{
	}

	// Virtual destructor
	Bullet::~Bullet()
	{
		m_time_to_destruction = 0.0f;
	}

	// Overloaded copy assignment operator
	Bullet& Bullet::operator=(const Bullet& copy)
	{
		if (this != &copy)
		{
			Actor::operator=(copy);
			m_time_to_destruction = copy.m_time_to_destruction;
		}
		return *this;
	}

	// Overloaded move assignment operator
	Bullet& Bullet::operator=(Bullet&& other)
	{
		if (this != &other)
		{
			Actor::operator=(other);
			m_time_to_destruction = other.m_time_to_destruction;
		}
		return *this;
	}

	// Get a time to self-destruct
	const float Bullet::getTimeToDestruction()
	{
		return m_time_to_destruction;
	}

	// Set a time to self-destruct
	void Bullet::setTimeToDestruction(float time_to_destruction)
	{
		m_time_to_destruction = time_to_destruction;
	}

	// Virtual method updates the object 
	void Bullet::update(float dt)
	{
		move(m_movement * m_velocity * dt); // bullet position update
	
		m_time_to_destruction -= dt; // we are counting down the time to destruction

		if (m_time_to_destruction <= 0.0f)
			setDestruction(true); // after this time, the object is lost

		if(!inCamera())
			setDestruction(true); // the object dies after leaving the screen

		// update destruction
		updateDestruction();
	}

	// Virtual method returns the type of the object - enumeration value
	const EntityType Bullet::getType() const
	{
		return EntityType::BULLET;
	}

}//namespace logic
