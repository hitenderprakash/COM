#include <iostream>
#include "unknwn.h"
#include "IComponentInterface.h"

using namespace std;

int main(){
	IUnknown* pIUnknown = CallCreateCComponentInstance("CComponentClass.dll");
	if(pIUnknown == NULL){
		std::cout<<"\nError in loading the COM Server dll";
		return 0;
	}
	IComponent* pIComponent=NULL;
	pIUnknown->QueryInterface(IID_IComponent,(void**)&pIComponent);
	if(pIComponent == NULL){
		std::cout<<"\nError in getting the requested Interface";
		return 0;
	}
	std::cout<<"\nSum of 9 and 4 is: "<< pIComponent->add(9,4);
	std::cout<<"\ndifference of 9 and 4 is: "<< pIComponent->subtract(9,4);
	pIComponent->Release();
	return 0;	
}