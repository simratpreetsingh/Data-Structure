#include "Queue.h"
template <typename T>
class StackQ {
	Queue<T> * primary;
	Queue<T> * secondary;

	public:
		StackQ() {
			primary = new Queue<T>();
			secondary = new Queue<T>();
		}

		bool isEmpty() {
			return primary->isEmpty();
		}

		int size() {
			return primary->size();
		}
};
