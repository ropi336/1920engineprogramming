#include <vector>
#include <memory>
#include <list>

class Component;
class Core;

/**
* This class stores objects for all things that the engine demo uses
*/

class Entity {
private:
	friend class Core; ///< Gives the class Entity access to all of the private and protected members of the Core class
	std::list<std::shared_ptr<Component>> components; ///< list type storage for all components for the given entity
	std::weak_ptr<Core> core; ///< points to the core
	std::weak_ptr<Entity> self; ///< saving to memory and direct access without copy
	void tick();
	void display();
public:
	const std::shared_ptr<Core> getCore();
	

	/**
	* The template creates a basis for passing important data between the component system
	*/

	template <class T> 
	std::shared_ptr<T> addComponent()
	{
	
		std::shared_ptr<T> comp = std::make_shared<T>(); ///< The component will be shared: accessible by related classes and objects
		comp->entity = self;
		std::shared_ptr<Component> baseComp = comp;
		baseComp->onInit();
		components.push_back(comp);
		return comp;
	};
};