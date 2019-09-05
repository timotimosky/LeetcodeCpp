#include "TempTestRun.h"
int TestTemp() {
	Stack<int> intStack;
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);

	while (!intStack.isEmpty()) {
		printf("num:%d\n", intStack.pop());
	}
	return 0;
}