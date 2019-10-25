#include <vector>
#include <memory>

class Component;
class Core;

class Entity {
private:
	std::vector<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;

	void tick();
	void display();
public:
	const std::shared_ptr<Core> getCore();
	
	template <class T> 
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		m_components.push_back(comp);
		return comp;
	};

	template <class T, class A>
	std::shared_ptr<T> addComponent(A _a)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a);
		m_components.push_back(comp);
		return comp;
	};

	template <class T, class A, class B>
	std::shared_ptr<T> addComponent(A _a, B _b)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b);
		m_components.push_back(comp);
		return comp;
	};

	template <class T, class A, class B, class C>
	std::shared_ptr<T> addComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b, _c);
		m_components.push_back(comp);
		return comp;
	};

};