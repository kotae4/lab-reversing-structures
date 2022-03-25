#include "StructsDefinitions.h"
#include <iostream>

// TO-DO:
// output vfunc addresses and update the guide image to reflect this
// output code bytes of each constructor (use destructor as sentinel) and update the guide image to reflect this
// allow user to modify values while program is running by inputting something like <structName.fieldName = newVal> and update the guide + guide image to reflect this
// change project settings to strongly discourage inlining (release mode will inline all the constructors so there's just one massive main() function lol)

int main()
{
	// NOTE:
	// we don't want everything allocated on the stack
	// because then you might mix up the end of one struct with the beginning of another
	// so let's just 'new' them and hope the OS gives us fairly spaced out allocations
	SimpleFieldsStruct *simpleStruct = new SimpleFieldsStruct();
	PointerStruct *pointersStruct = new PointerStruct();
	StringsStruct *stringsStruct = new StringsStruct();
	DerivedStruct *derivedStruct = new DerivedStruct();
	VirtualFuncStruct *vfuncsStruct = new VirtualFuncStruct();
	DerivedVirtualStruct *derivedVFuncsStruct = new DerivedVirtualStruct();

	simpleStruct->PrintStruct();
	pointersStruct->PrintStruct();
	stringsStruct->PrintStruct();
	derivedStruct->PrintStruct();
	vfuncsStruct->PrintStruct();
	derivedVFuncsStruct->PrintStruct();

	std::cout << "Press ENTER to exit..." << std::endl;
	std::cin.clear();
	std::cin.get();

	delete simpleStruct;
	delete pointersStruct;
	delete stringsStruct;
	delete derivedStruct;
	delete vfuncsStruct;
	delete derivedVFuncsStruct;

	return 0;
}