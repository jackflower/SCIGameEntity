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

#ifndef HPP_ENTITY_ENGINE_ACODEMIA
#define HPP_ENTITY_ENGINE_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../entityengine/EntityType.hpp"
#include "../entityengine/EntitySignalType.hpp"

// forwad declarations
namespace logic
{
	class Actor;
	class Bullet;
	class Enemy;
	class Player;
}

using logic::Actor;
using logic::Bullet;
using logic::Enemy;
using logic::Player;

///
// Class represents a container for storing and managing game objects
///
class EntityEngine
{
public:

	///
	/// Default constructor
	///
	EntityEngine();

	///
	/// Virtual destructor
	///
	virtual ~EntityEngine();

	///
	/// The method registers pointers to Entity objects in the container
	///
	/// @param *entity - a pointer to an Entity object 
	///
	void registerEntity(Actor* entity);

	///
	/// The method returns the texture
	///
	const sf::Texture& getTexture() const;

	///
	/// Container update with pointers to Entity objects
	///
	/// @param dt - time
	///
	void update(float dt);

	///
	/// Creates an Actor class object and returns a pointer to this object
	///
	Actor *createActor();

	///
	/// Creates an Bullet class object and returns a pointer to this object
	///
	Bullet *createBullet();

	///
	/// Creates an Enemy class object and returns a pointer to this object
	///
	Enemy *createEnemy();

	///
	/// Creates an Player class object and returns a pointer to this object
	///
	Player *createPlayer();

	///
	/// Virtual object rendering method
	///
	/// @param target - reference to the graphic context
	///
	/// @param states - render states
	///
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	// static

	// get the size of the rendering region of the window
	static const sf::Vector2u& getSceneSize();

	// set the size of the rendering region of the window
	static void setSceneSize(const sf::Vector2u& scene_size);

private:

	// the container holds pointers to Actor objects
	std::vector<Actor* > m_entity;
	sf::Texture m_texture; // texture atlas

	// the template of the method that creates the object
	template<class T> T* create();

	// checks for collision
	bool checkCollision(Actor *collider);

	// produce entity
	void produceEntity(Actor* parent, EntitySignalType entity_signal_type);

	// produce bullet player
	void produceBulletPlayer(Actor* parent);

	// produce bullet enemy
	void produceBulletEnemy(Actor* parent);

	// produce enemy
	void produceEnemy();

	// updating the position of the object after a collision collision
	void updatePosition(Actor *object, Actor *collider);

	// static
	static sf::Vector2u m_scene_size; // size of the rendering region of the window

};
#endif//HPP_ENTITY_ENGINE_ACODEMIA
