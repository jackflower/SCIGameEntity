﻿////////////////////////////////////////////////////////////
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


#ifndef HPP_ENEMY_ACODEMIA
#define HPP_ENEMY_ACODEMIA

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include"Actor.hpp"
#include "Trigger.hpp"

namespace logic
{
	////////////////////////////////////////////////////////////
	/// \brief Class represents the enemy
	///
	/// Inherits from the base class Actor
	///
	/// \see Actor
	///
	////////////////////////////////////////////////////////////
	class Enemy : public Actor
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		////////////////////////////////////////////////////////////
		Enemy();

		////////////////////////////////////////////////////////////
		/// \brief Copy constructor
		///
		/// \param copy - copy source
		///
		////////////////////////////////////////////////////////////
		Enemy(const Enemy& copy);

		////////////////////////////////////////////////////////////
		/// \brief Move constructor
		///
		/// \param other - reference to r-value 
		///
		////////////////////////////////////////////////////////////
		Enemy(Enemy&& other);

		////////////////////////////////////////////////////////////
		/// \brief Virtual destructor
		////////////////////////////////////////////////////////////
		virtual ~Enemy();

		////////////////////////////////////////////////////////////
		/// \brief Overloaded copy assignment operator
		///
		/// \param copy - copy source
		///
		////////////////////////////////////////////////////////////
		Enemy& operator=(const Enemy& copy);

		////////////////////////////////////////////////////////////
		/// \brief Overloaded move assignment operator
		///
		/// \param other -  reference to r-value
		////////////////////////////////////////////////////////////
		///
		Enemy& operator=(Enemy&& other);

		////////////////////////////////////////////////////////////
		/// \brief Method returns the rate of fire
		///
		/// \return rate of fire
		///
		////////////////////////////////////////////////////////////
		const float getRateFire() const;

		////////////////////////////////////////////////////////////
		/// \brief Method sets the rate of fire
		///
		/// \param rate_fire - rate of fire
		///
		////////////////////////////////////////////////////////////
		void setRateFire(float rate_fire);

		////////////////////////////////////////////////////////////
		/// \brief Virtual method updates the object
		///
		/// \param dt - time
		///
		////////////////////////////////////////////////////////////
		virtual void update(float dt) override;

		/////////////////////////////////////////////////////////////
		/// \brief Virtual method returns the type
		/// of the object - enumeration value
		///
		/// \return Enumeration type of the object
		///
		/// \see EntityType
		///
		////////////////////////////////////////////////////////////
		virtual const EntityType getType() const;

		/////////////////////////////////////////////////////////////
		/// \brief Virtual method returns the signal
		/// generated by the object
		///
		/// \return signal generated by the object
		///
		/// \see EntitySignalType
		///
		////////////////////////////////////////////////////////////
		virtual const EntitySignalType getSignal() const;

	protected:

	private:

		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		bool m_selfdestruction_token; // self-destruction outside the camera
		Trigger m_trigger; //shooting trigger

	};

}//namespace logic
#endif//HPP_ENEMY_ACODEMIA
