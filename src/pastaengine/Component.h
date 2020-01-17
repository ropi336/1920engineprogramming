#ifndef pastaComponent
#define pastaComponent

#include <memory>

class Entity;
class Core;

/**
* This class contains the virtual functions that run entities and their components. 
* 
*/

class Component
{
private:
	friend class Entity; ///< Friend allows this class to access all types of class member regardless of security measures
	friend class Core; ///< Friend allows this class to access all types of class member regardless of security measures
	std::weak_ptr<Entity> entity; ///< Weak pointer to itself 
	virtual void onInit(); 
	virtual void onBegin(); 
	virtual void onTick();
	virtual void onDisplay();
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
};
#endif // !pastaComponent