//Hitender Prakash
//this project is only for learning about using and building COM objects
//sample 
#ifndef _ICOMPONENT_INTERFACE_H
#define _ICOMPONENT_INTERFACE_H

#include <iostream>
#include "objbase.h"
#include "stdio.h"
#include "stdlib.h"

interface IComponent : IUnknown{
	
	//default methods inherited from Iunknown
	/*
		virtual HRESULT __stdcall QueryInterface(const IID& iid,void** ppv);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();
	*/
	virtual double __stdcall add(double num1, double num2) = 0;
	virtual double __stdcall subtract(double num1, double num2) = 0;
	virtual double __stdcall multiply(double num1, double num2) = 0;
	virtual double __stdcall divide(double num1, double num2) = 0;
	
};

extern "C"{
	extern const IID IID_IComponent;
}

class CComponent: public IComponent {
	private:
	long m_cRef; //reference count
	
	public:
	//constructor & destructor
	CComponent();
	~CComponent(){};
	//methods inherited from IUnknown 
	virtual HRESULT __stdcall QueryInterface(const IID& iid,void** ppv); 
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
	
	//methods specific to our interface 
	virtual double __stdcall add(double num1, double num2);
	virtual double __stdcall subtract(double num1, double num2);
	virtual double __stdcall multiply(double num1, double num2);
	virtual double __stdcall divide(double num1, double num2);
};

extern "C" IUnknown* CreateCComponentInstance();
IUnknown* CallCreateCComponentInstance(char* dllname);
#endif