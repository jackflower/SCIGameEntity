﻿////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2021
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

#include "Actor.hpp"
#include "../entityengine/Game.hpp"

namespace logic
{
	// Default constructor
	Actor::Actor() :
		m_movement{},
		m_velocity(0.0f),
		m_destruction{ false },
		m_health{0.0f},
		m_collision_damage{},
		m_signal_type{ EntitySignalType::SIGNAL_EMPTY }
	{
	}

	// Copy constructor
	Actor::Actor(const Actor& copy) :
		m_movement{ copy.m_movement},
		m_velocity{ copy.m_velocity },
		m_destruction{ copy.m_destruction },
		m_health{ copy.m_health },
		m_collision_damage{ copy.m_collision_damage },
		m_signal_type{ copy.m_signal_type }
	{
	}

	// Move constructor
	Actor::Actor(Actor&& other) :
		m_movement{ other.m_movement },
		m_velocity{ other.m_velocity },
		m_destruction{ other.m_destruction },
		m_health{ other.m_health },
		m_collision_damage{ other.m_collision_damage },
		m_signal_type{ other.m_signal_type }
	{
	}

	// Virtual destructor
	Actor::~Actor()
	{
		m_movement.x = 0.0f;
		m_movement.y = 0.0f;
		m_velocity = 0.0f;
		m_destruction = false;
		m_health = 0.0f;
		m_collision_damage = 0.0f;
		m_signal_type = EntitySignalType::SIGNAL_EMPTY;
	}

	// Overloaded copy assignment operator
	Actor& Actor::operator=(const Actor& copy)
	{
		if (this != &copy)
		{
			m_movement = copy.m_movement;
			m_velocity = copy.m_velocity;
			m_destruction = copy.m_destruction;
			m_health = copy.m_health;
			m_collision_damage = copy.m_collision_damage;
			m_signal_type = copy.m_signal_type;
		}
		return *this;
	}

	// Overloaded move assignment operator
	Actor& Actor::operator=(Actor&& other)
	{
		if (this != &other)
		{
			m_movement = other.m_movement;
			m_velocity = other.m_velocity;
			m_destruction = other.m_destruction;
			m_health = other.m_health;
			m_collision_damage = other.m_collision_damage;
			m_signal_type = other.m_signal_type;
		}
		return *this;
	}

	// Set the direction vector of the object
	void Actor::setMovement(const sf::Vector2f& movement)
	{
		m_movement = movement;
	}

	// Get the velocity of the object
	const float Actor::getVelocity() const
	{
		return m_velocity;
	}

	// Set the velocity of the object
	void Actor::setVelocity(float velocity)
	{
		m_velocity = velocity;
	}

	// Get object destruction flag
	const bool Actor::getDestruction() const
	{
		return m_destruction;
	}

	// Set object destruction flag
	void Actor::setDestruction(bool destruction)
	{
		m_destruction = destruction;
	}

	// Get object health
	const float Actor::getHealth() const
	{
		return m_health;
	}

	// Set object health
	void Actor::setHealth(float health)
	{
		m_health = health;
	}

	// Check if the object is within the camera area
	const bool Actor::inCamera() const
	{
		return (getPosition().x >= 0 &&
				getPosition().x <= EntityEngine::getSceneSize().x &&
				getPosition().y >= 0 &&
			    getPosition().y <= EntityEngine::getSceneSize().y);
	}

	// Method returns collision damage
	const float Actor::getCollisionDamage() const
	{
		return m_collision_damage;
	}

	// Method sets collision damage
	void Actor::setCollisionDamage(float collision_damage)
	{
		m_collision_damage = collision_damage;
	}

	// Method updates damage
	void Actor::updateDamage(float damage)
	{
		m_health -= damage;
	}

	// Method updates destruction
	void Actor::updateDestruction()
	{
		if (m_health <= 0.0f)
			m_destruction = true;
	}

	// Virtual method for updating an object
	void Actor::update(float dt)
	{
		updateDestruction();
	}

	// Virtual method returns the type of the object - enumeration value
	const EntityType Actor::getType() const
	{
		return EntityType::ACTOR;
	}

	// Virtual method returns the signal generated by the object
	const EntitySignalType Actor::getSignal() const
	{
		return m_signal_type;
	}

}//namespace logic
