////////////////////////////////////////////////////////////
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


#ifndef HPP_BULLET_ACODEMIA
#define HPP_BULLET_ACODEMIA

#include"Actor.hpp"

namespace logic
{
	///
	/// Class represents the projectile
	///
	class Bullet : public Actor
	{
	public:

		///
		/// Default constructor
		///
		Bullet();

		///
		/// Copy constructor
		///
		/// @param copy - copy source
		///
		Bullet(const Bullet& copy);

		///
		/// Move constructor
		///
		/// @param other - reference to r-value 
		///
		Bullet(Bullet&& other);

		///
		/// Virtual destructor 
		///
		virtual ~Bullet();

		///
		/// Overloaded copy assignment operator
		///
		/// @param copy - copy source
		///
		Bullet& operator=(const Bullet& copy);

		///
		/// Overloaded move assignment operator
		///
		/// @param other -  reference to r-value 
		///
		Bullet& operator=(Bullet&& other);

		///
		/// Get a time to self-destruct 
		///
		const float getTimeToDestruction();

		///
		/// Set a time to self-destruct 
		///
		/// @param time_to_destruction - time to destruction
		///
		void setTimeToDestruction(float time_to_destruction);

		///
		/// Virtual method updates the object 
		///
		/// @param dt - time
		///
		virtual void update(float dt) override;

		///
		/// Virtual method returns the type of the object - enumeration value
		///
		virtual const EntityType getType() const;

	protected:

	private:

		float m_time_to_destruction; // deferred time of projectile destruction

	};

}//namespace logic
#endif//HPP_BULLET_ACODEMIA
