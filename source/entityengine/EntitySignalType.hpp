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

#ifndef HPP_ENTITY_SIGNAL_TYPE_ACODEMIA
#define HPP_ENTITY_SIGNAL_TYPE_ACODEMIA

///
/// Enumeration of signal types
///
enum class EntitySignalType
{
	SIGNAL_EMPTY				= 0, // no signal
	SIGNAL_CREATE_BULLET_PLAYER	= 1,
	SIGNAL_CREATE_BULLET_ENEMY	= 2,
	SIGNAL_CREATE_HEALTH		= 3
};

#endif//HPP_ENTITY_SIGNAL_TYPE_ACODEMIA
