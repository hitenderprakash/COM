//Hitender Prakash
//this project is only for learning about using and building COM objects
//sample 
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
	virtual double __stdcall devide(double num1, double num2) = 0;
	
};

// {976CE0FB-76A2-41AA-995C-CBDAC2E555C5}
static const IID IID_IComponent = { 
0x976ce0fb, 0x76a2, 0x41aa, 
{ 0x99, 0x5c, 0xcb, 0xda, 0xc2, 0xe5, 0x55, 0xc5 } 
};

class CComponent: public IComponent {
	private:
	long m_cRef; //reference count
	
	public:
	//constructor & destructor
	CComponent(){};
	~CComponent(){};
	//methods inherited from IUnknown 
	virtual HRESULT __stdcall QueryInterface(const IID& iid,void** ppv); 
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
	
	//methods specific to our interface 
	virtual double __stdcall add(double num1, double num2);
	virtual double __stdcall subtract(double num1, double num2);
	virtual double __stdcall multiply(double num1, double num2);
	virtual double __stdcall devide(double num1, double num2);
};