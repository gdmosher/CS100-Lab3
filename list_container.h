#ifndef LIST_CONTAINER_H
#define LIST_CONTAINER_H

#include <list>
#include "strategy.h"
#include "container.h"
#include "component.h"

class ListContainer : public Container
{
	public:
		std::list<Base*> cList;
		ListContainer() {} 
		
		void add_element(Base* element) { cList.push_back(element); }
		
		void print() {
			for (std::list<Base*>::iterator it = cList.begin(); it != cList.end(); it++)
			{
				std::cout << (*it)->evaluate() << ' ';
			}
		}
		
		void set_sort_function(Sort* sort_function) { this->sort_function = sort_function; }
		
		void sort() {
			/*try {
				if (sort_function == 0)
					throw noSortFunction("You need to call the set_sort_function");
				sort_function->sort(this);
			}
			catch (const noSortFunction& e)
			{
				std::cout << e.what();
			}*/
			sort_function->sort(this);
		}
		
		void swap(int i, int j) {
			Base* temp;
			std::list<Base*>::iterator it1 = cList.begin();
			std::list<Base*>::iterator it2 = cList.begin();
			std::advance(it1, i);
			std::advance(it2, j);
			temp = *it1;
			*it1 = *it2;
			*it2 = temp;			
		}

		Base* at(int i) {
			std::list<Base*>::iterator it = cList.begin();
			std::advance(it, i);
			return *it;
		}
		
		int size() { return cList.size(); }
		
};


#endif //LIST_CONTAINER_H
