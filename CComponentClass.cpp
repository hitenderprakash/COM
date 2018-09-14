//Hitender Prakash
//this project is only for learning about using and building COM objects
//sample 
#include "IComponentInterface.h"


//implementation of CComponent methods 

//init m_cRef in constructor 
CComponent::CComponent(){
	m_cRef = 0;
}


ULONG __stdcall CComponent::AddRef(){
	return InterlockedIncrement(&m_cRef);
}

ULONG __stdcall CComponent::Release(){
	return InterlockedIncrement(&m_cRef);
}

HRESULT __stdcall CComponent::QueryInterface(const IID& iid,void** ppv){
	if(iid == IID_IUnknown){
		*ppv = static_cast<IComponent*>(this);
	}
	else if(iid == IID_IComponent){
		*ppv = static_cast<IComponent*>(this);
	}
	else {
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	
	reinterpret_cast<IUnknown*>(*ppv)->AddRef() ;
	return S_OK;
}


 
double __stdcall CComponent::add(double num1, double num2){
	return (num1 + num2);
}

double __stdcall CComponent::subtract(double num1, double num2){
	return (num1 - num2);
}
double __stdcall CComponent::multiply(double num1, double num2){
	return (num1 * num2);
}
double __stdcall CComponent::divide(double num1, double num2){
	if(num2 == 0.0){
		return 1.79769e+308;
	}
	return (num1 / num2);
}

//create Instance function which needs to be exported in the dll.
extern "C" IUnknown* CreateCComponentInstance(){
	IUnknown* pIUnknown = static_cast<IComponent*>(new CComponent);
	return pIUnknown;
}

//////////////////////////////////////////////////////////////////////////////////