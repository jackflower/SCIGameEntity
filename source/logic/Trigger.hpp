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


#ifndef HPP_TRIGGER_ACODEMIA
#define HPP_TRIGGER_ACODEMIA

#include"Actor.hpp"

namespace logic
{
	///
	/// Class represents the functionality of the trigger
	///
	class Trigger
	{
	public:

		///
		/// Default constructor
		///
		Trigger();

		///
		/// Copy constructor
		///
		/// @param copy - copy source
		///
		Trigger(const Trigger& copy);

		///
		/// Move constructor
		///
		/// @param other - reference to r-value 
		///
		Trigger(Trigger&& other);

		///
		/// Virtual destructor
		///
		virtual ~Trigger();

		///
		/// Overloaded copy assignment operator
		///
		/// @param copy - copy source
		///
		Trigger& operator=(const Trigger& copy);

		///
		/// Overloaded move assignment operator
		///
		/// @param other -  reference to r-value 
		///
		Trigger& operator=(Trigger&& other);

		///
		/// Method returns the availability flag
		///
		const float getEnabled() const;

		///
		/// Method sets the availability flag
		///
		///@param enabled - availability flag
		///
		void setEnabled(float enabled);

		///
		/// Method returns the frequency
		///
		const float getFrequency() const;

		///
		/// Method sets the frequency
		///
		///@param frequency - frequency
		///
		void setFrequency(float frequency);

		///
		/// Method updates the object
		///
		/// @param dt - time
		///
		void update(float dt);

	protected:

	private:

		float m_elapsed_time; // elapsed time
		bool m_enabled; // availability flag
		float m_frequency; // frequency
	};

}//namespace logic
#endif//HPP_TRIGGER_ACODEMIA
