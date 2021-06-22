////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
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

#include "EntityEngine.hpp"
#include "../logic/Actor.hpp"
#include "../logic/Bullet.hpp"
#include "../logic/Enemy.hpp"
#include "../logic/Player.hpp"
#include <iostream>

// static

sf::Vector2u EntityEngine::m_scene_size;

// get the size of the rendering region of the window
const sf::Vector2u& EntityEngine::getSceneSize()
{
	return EntityEngine::m_scene_size;
}

// set the size of the rendering region of the window
void EntityEngine::setSceneSize(const sf::Vector2u& scene_size)
{
	m_scene_size = scene_size;
}


//Konstruktor domyślny
EntityEngine::EntityEngine() :
	m_entity{},
	m_texture{}
{
	if (!m_texture.loadFromFile("../SCIGameEntity/data/game_entity_atlas.png"))
		std::cout << "error loading texture..." << "\n";
	m_texture.setSmooth(true);

	// ultimately generator (enemyGenerator...)
	produceEnemy();
}

//Destruktor wirtualny
EntityEngine::~EntityEngine()
{
	std::vector<logic::Actor*>::iterator it;
	for (it = m_entity.begin(); it != m_entity.end(); it++)
	{
		if((*it))
			delete (*it);
	}
	m_entity.clear();
}

// The method registers pointers to Entity objects in the container
void EntityEngine::registerEntity(logic::Actor* entity)
{
	if (entity)
		m_entity.push_back(entity);
}

// The method returns the texture
const sf::Texture& EntityEngine::getTexture() const
{
	return m_texture;
}

// Container update with pointers to Entity objects
void EntityEngine::update(float dt)
{
	for (unsigned int i = 0; i < m_entity.size(); i++)
	{
		if (m_entity.at(i)->getSignal() == EntitySignalType::SIGNAL_CREATE_BULLET_PLAYER)
			produceEntity(m_entity.at(i), EntitySignalType::SIGNAL_CREATE_BULLET_PLAYER);

		if (m_entity.at(i)->getSignal() == EntitySignalType::SIGNAL_CREATE_BULLET_ENEMY)
			produceEntity(m_entity.at(i), EntitySignalType::SIGNAL_CREATE_BULLET_ENEMY);

		checkCollision(m_entity.at(i));
		m_entity.at(i)->update(dt);

		// if the object is marked for destruction
		if (m_entity.at(i)->getDestruction())
		{
			delete m_entity.at(i);// release memory
			m_entity.at(i) = nullptr; // reset the pointer
			m_entity.erase(m_entity.begin() + i); // remove the object from the vector
		}
	}
}

// Creates an Actor class object and returns a pointer to this object
logic::Actor *EntityEngine::createActor()
{
	return create<logic::Actor>();
}

// Creates an Bullet class object and returns a pointer to this object
logic::Bullet *EntityEngine::createBullet()
{
	return create<logic::Bullet>();
}

// Creates an Enemy class object and returns a pointer to this object
logic::Enemy *EntityEngine::createEnemy()
{
	return create<logic::Enemy>();
}

// Creates an Player class object and returns a pointer to this object
logic::Player *EntityEngine::createPlayer()
{
	return create<logic::Player>();
}

// Virtual object rendering method
void EntityEngine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//draw entities...
	std::vector<logic::Actor*>::const_iterator it; // iterator (const) this container
	for (it = m_entity.begin(); it != m_entity.end(); it++)
	{
		if ((*it) != nullptr)
			if (!(*it)->getDestruction())
				(*it)->draw(target, states);
	}
}

// the template of the method that creates the object
template<class T>
T* EntityEngine::create()
{
	T* obj = new T();
	m_entity.push_back(obj);
	return obj;
}

// checks for collision
bool EntityEngine::checkCollision(logic::Actor *collider)
{
	EntityType type = collider->getType();

	// we iterate over the container with pointers to Actor class objects
	for (unsigned int i = 0; i < m_entity.size(); i++)
	{
		if (m_entity.at(i) != collider)//blokujemy kolizję "sam ze sobą"
		{
			if (m_entity.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
			{
				if (type == EntityType::ENEMY)
				{
					// enemy deals damage ...
					m_entity.at(i)->updateDamage(collider->getCollisionDamage());
					// updatePosition(m_entity.at(i), collider);
					return true;
				}

				if (type == EntityType::PLAYER)
				{
					// player deals damage ...
					m_entity.at(i)->updateDamage(collider->getCollisionDamage());
					// updatePosition(m_entity.at(i), collider);
					return true;
				}

				if (type == EntityType::BULLET)
				{
					// bullet deals damage ...
					m_entity.at(i)->updateDamage(collider->getCollisionDamage());
					collider->setDestruction(true); // bullet dies ...
					return true;
				}
			}
		}
	}
	return false;
}

// produce entity
void EntityEngine::produceEntity(logic::Actor* parent, EntitySignalType entity_signal_type)
{
	switch (entity_signal_type)
	{
	case EntitySignalType::SIGNAL_CREATE_BULLET_PLAYER:
		produceBulletPlayer(parent);
		break;
	case EntitySignalType::SIGNAL_CREATE_BULLET_ENEMY:
		produceBulletEnemy(parent);
		break;
	}
}

// produce bullet player
void EntityEngine::produceBulletPlayer(logic::Actor* parent)
{
	// player missile production
	// warning: allocate memory to the pointer *)
	logic::Bullet *bullet = createBullet();
	bullet->setTexture(m_texture);
	bullet->setTextureRect(192, 0, 8, 16);
	bullet->setPosition(parent->getPosition().x, parent->getPosition().y);
	bullet->setScale(parent->getScale().x, parent->getScale().y);
	bullet->setOrigin(bullet->getLocalBounds().width * 0.5f, bullet->getLocalBounds().height * 0.5f);
	bullet->setTimeToDestruction(10);
	bullet->setVelocity(-300); // the projectile moves up
	bullet->setHealth(100.0f);
	bullet->setCollisionDamage(10);
	// warning: *) memory is released in the container

	// correction of the initial position of the generated projectile
	float shot_emiter = 0.0f;
	float parent_half_height = parent->getGlobalBounds().height * 0.5f;
	float bullet_half_height = bullet->getGlobalBounds().height * 0.5f;
	float separation_factor_height = 2.0f;
	shot_emiter = parent_half_height + bullet_half_height + separation_factor_height;
	// the projectile moves up
	bullet->setPosition(parent->getPosition().x, (parent->getPosition().y - shot_emiter));
}

// produce bullet enemy
void EntityEngine::produceBulletEnemy(logic::Actor* parent)
{
	// enemy missile production
	// warning: allocate memory to the pointer *)
	logic::Bullet *bullet = createBullet();
	bullet->setTexture(m_texture);
	bullet->setTextureRect(192, 16, 8, 16);
	bullet->setPosition(parent->getPosition().x, parent->getPosition().y);
	bullet->setScale(parent->getScale().x, parent->getScale().y);
	bullet->setOrigin(bullet->getLocalBounds().width * 0.5f, bullet->getLocalBounds().height * 0.5f);
	bullet->setTimeToDestruction(10);
	bullet->setVelocity(300); // the projectile moves up
	bullet->setHealth(100.0f);
	bullet->setCollisionDamage(10);
	// warning: *) memory is released in the container

	// correction of the initial position of the generated projectile
	float shot_emiter = 0.0f;
	float parent_half_height = parent->getGlobalBounds().height * 0.5f;
	float bullet_half_height = bullet->getGlobalBounds().height * 0.5f;
	float separation_factor_height = 2.0f;
	shot_emiter = parent_half_height + bullet_half_height + separation_factor_height;
	// the projectile moves down
	bullet->setPosition(parent->getPosition().x, (parent->getPosition().y + shot_emiter));
}

// produce enemy
void EntityEngine::produceEnemy()
{
	// E n e m y
	// warning: allocate memory to the pointer *)
	logic::Enemy *p_enemy = createEnemy();
	p_enemy->setTexture(m_texture);
	p_enemy->setTextureRect(64, 0, 64, 64);
	p_enemy->setPosition(400, -200);
	p_enemy->setScale(1, 1);
	p_enemy->setScale(p_enemy->getScale().x, -p_enemy->getScale().y); // flip about the x axis
	p_enemy->setVelocity(50);
	p_enemy->setOrigin(p_enemy->getLocalBounds().width * 0.5f, p_enemy->getLocalBounds().height * 0.5f);
	p_enemy->setRateFire(0.25f);
	p_enemy->setHealth(100.0f);
	p_enemy->setCollisionDamage(20);
	// warning: *) memory is released in the container
}

//prywatna metoda aktualizuje pozycję obiektu w wyniku kolizji
void EntityEngine::updatePosition(logic::Actor *object, logic::Actor *collider)
{
	sf::Vector2f new_object_position;
	sf::Vector2f old_object_position;
	old_object_position = object->getPosition();//zapamiętujemy pozycję

	sf::Vector2f new_collider_position;
	sf::Vector2f old_collider_position;
	old_collider_position = collider->getPosition(); // memorizing the position

	float factor = 0.25f; // separation factor

	// x
	if (object->getPosition().x <= collider->getPosition().x)
	{
		new_object_position.x = old_object_position.x - factor;
		new_collider_position.x = old_collider_position.x + factor;
	}
	else
	{
		new_object_position.x = old_object_position.x + factor;
		new_collider_position.x = old_collider_position.x - factor;
	}

	// y
	if (object->getPosition().y <= collider->getPosition().y)
	{
		new_object_position.y = old_object_position.y - factor;
		new_collider_position.y = old_collider_position.y + factor;
	}
	else
	{
		new_object_position.y = old_object_position.y + factor;
		new_collider_position.y = old_collider_position.y - factor;
	}

	object->setPosition(new_object_position);
	collider->setPosition(new_collider_position);
}
