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

#include "Trigger.hpp"

namespace logic
{
	// Default constructor 
	Trigger::Trigger() :
		m_elapsed_time{ 0.0f },
		m_enabled{ true },
		m_frequency{ 1.0f }
	{
	}

	// Copy constructor
	Trigger::Trigger(const Trigger& copy) :
		m_elapsed_time{ copy.m_elapsed_time },
		m_enabled{ copy.m_enabled },
		m_frequency{ copy.m_frequency }
	{
	}

	// Move constructor
	Trigger::Trigger(Trigger&& other) :
		m_elapsed_time{ other.m_elapsed_time },
		m_enabled{ other.m_enabled },
		m_frequency{ other.m_frequency }
	{
	}

	// Virtual destructor
	Trigger::~Trigger()
	{
		m_elapsed_time = 0.0f;
		m_enabled = false;
		m_frequency = 0.0f;
	}

	// Overloaded copy assignment operator
	Trigger& Trigger::operator=(const Trigger& copy)
	{
		if (this != &copy)
		{
			m_elapsed_time = copy.m_elapsed_time;
			m_enabled = copy.m_enabled;
			m_frequency = copy.m_frequency;
		}
		return *this;
	}

	// Overloaded move assignment operator
	Trigger& Trigger::operator=(Trigger&& other)
	{
		if (this != &other)
		{
			m_elapsed_time = other.m_elapsed_time;
			m_enabled = other.m_enabled;
			m_frequency = other.m_frequency;
		}
		return *this;
	}

	// Method returns the availability flag
	const float Trigger::getEnabled() const
	{
		return m_enabled;
	}

	// Method sets the availability flag
	void Trigger::setEnabled(float enabled)
	{
		m_enabled = enabled;
	}

	// Method returns the frequency
	const float Trigger::getFrequency() const
	{
		return m_frequency;
	}

	// Method sets the frequency
	void Trigger::setFrequency(float frequency)
	{
		m_frequency = frequency;
	}

	// Method updates the object
	void Trigger::update(float dt)
	{
		m_elapsed_time += dt;

		if (m_elapsed_time >= m_frequency)
		{
			m_elapsed_time = 0.0f;
			m_enabled = true;
		}
	}

}//namespace logic
