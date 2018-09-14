#include <iostream>
#include "unknwn.h"
#include "IComponentInterface.h"

using namespace std;

int main(){
	IUnknown* pIUnknown = CallCreateCComponentInstance("CComponentClass.dll");
	IComponent* pIComponent=NULL;
	pIUnknown->QueryInterface(IID_IComponent,(void**)&pIComponent);
	std::cout<<"\nSum of 9 and 4 is: "<< pIComponent->add(9,4);
	std::cout<<"\ndifference of 9 and 4 is: "<< pIComponent->subtract(9,4);
	pIComponent->Release();
	return 0;	
}