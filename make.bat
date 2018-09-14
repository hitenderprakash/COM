GOTO END_COMMENT
//Hitender prakash
//batch file to build the project 
//do not change the sequence of the commands
//Assume that "cl.exe" is in PATH or you are in the Visual Studio Developer Console
:END_COMMENT
cl /c /EHsc /MTd /Zi /Od /D_DEBUG guid.cpp
cl /c /EHsc /MTd /Zi /Od /D_DEBUG CComponentClass.cpp
link /DLL /DEBUG CComponentClass.obj guid.obj UUID.lib /DEF:componentDef.def
cl /c /EHsc /MTd /Zi /Od /D_DEBUG CreateCComponentInstance.cpp
cl /c /EHsc /MTd /Zi /Od /D_DEBUG Client.cpp
link Client.obj guid.obj CreateCComponentInstance.obj
