#include "unknwn.h"
#include "IComponentInterface.h"

typedef IUnknown* (*FNCTR)();

IUnknown* CallCreateCComponentInstance(char* dllname){
	
	HMODULE hm = ::LoadLibrary(dllname);
	
	if(hm==NULL){
		std::cout<<"\nError in loading dll:"<<dllname;
		return NULL;
	}
	FNCTR pFunctr = (FNCTR)::GetProcAddress(hm, "CreateCComponentInstance");
	
	if(pFunctr == NULL){
		std::cout<<"\nError in getting function";
		return NULL;
	}
	return pFunctr();	
}