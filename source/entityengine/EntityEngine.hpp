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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////
/// \brief Class represents a container for storing
/// and managing game objects
///
////////////////////////////////////////////////////////////
class EntityEngine
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Default constructor
	///
	////////////////////////////////////////////////////////////
	EntityEngine();

	////////////////////////////////////////////////////////////
	/// \brief Virtual destructor
	///
	////////////////////////////////////////////////////////////
	virtual ~EntityEngine();

	////////////////////////////////////////////////////////////
	/// \brief The method registers pointers to Entity
	/// objects in the container
	///
	/// \param *entity - a pointer to an Entity object 
	///
	////////////////////////////////////////////////////////////
	void registerEntity(logic::Actor* entity);

	////////////////////////////////////////////////////////////
	/// \brief The method returns the texture
	///
	/// \return const reference to sf::Texture
	///
	////////////////////////////////////////////////////////////
	const sf::Texture& getTexture() const;

	////////////////////////////////////////////////////////////
	/// \brief Container update with pointers to Entity objects
	///
	/// \param dt - time
	///
	////////////////////////////////////////////////////////////
	void update(float dt);

	////////////////////////////////////////////////////////////
	/// \brief Creates an Actor class object and returns
	/// a pointer to this object
	///
	/// \return Pointer to the logic::Actor object
	///
	////////////////////////////////////////////////////////////
	logic::Actor *createActor();

	////////////////////////////////////////////////////////////
	/// \brief Creates an Bullet class object and returns
	/// a pointer to this object
	///
	/// \return Pointer to the logic::Bullet object
	///
	////////////////////////////////////////////////////////////
	logic::Bullet *createBullet();

	////////////////////////////////////////////////////////////
	/// \brief Creates an Enemy class object and returns
	/// a pointer to this object
	///
	/// \return Pointer to the logic::Enemy object
	///
	////////////////////////////////////////////////////////////
	logic::Enemy *createEnemy();

	////////////////////////////////////////////////////////////
	/// \brief Creates an Player class object and returns
	/// a pointer to this object
	///
	/// \return Pointer to the logic::Player object
	///
	////////////////////////////////////////////////////////////
	logic::Player *createPlayer();

	////////////////////////////////////////////////////////////
	/// \brief Virtual object rendering method
	///
	/// \param target - reference to the graphic context
	///
	/// \param states - render states
	///
	////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	// static

	////////////////////////////////////////////////////////////
	/// \brief Get the size of the rendering region of the window
	///
	/// \return size of the window
	///
	////////////////////////////////////////////////////////////
	static const sf::Vector2u& getSceneSize();

	////////////////////////////////////////////////////////////
	/// \brief Set the size of the rendering region of the window
	///
	////////////////////////////////////////////////////////////
	static void setSceneSize(const sf::Vector2u& scene_size);

private:

	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	
	// the container holds pointers to Actor objects
	std::vector<logic::Actor* > m_entity;
	sf::Texture m_texture; // texture atlas

	// the template of the method that creates the object
	template<class T> T* create();

	// checks for collision
	bool checkCollision(logic::Actor *collider);

	// produce entity
	void produceEntity(logic::Actor* parent, EntitySignalType entity_signal_type);

	// produce bullet player
	void produceBulletPlayer(logic::Actor* parent);

	// produce bullet enemy
	void produceBulletEnemy(logic::Actor* parent);

	// produce enemy
	void produceEnemy();

	// updating the position of the object after a collision collision
	void updatePosition(logic::Actor *object, logic::Actor *collider);

	// static
	static sf::Vector2u m_scene_size; // size of the rendering region of the window

};
#endif//HPP_ENTITY_ENGINE_ACODEMIA
