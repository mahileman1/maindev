#pragma once
/*

 All of the microsoft examples use this one-file-include header method.
 I ran into a lot of WDF issues trying to use the headers individually,
 this works so I'm keeping it.  

*/

#include <ntddk.h>
#include <wdf.h>
// TODO: Would love to use ctypes, but stdint doesn't like vc runtime warnings? 
//#include <stdint.h>

// TODO: Find a better way to do this without using VS proj props
// Include before qemuDevice.h
#include "..\..\..\..\..\common\qemuStructs.h"

#include "callbacks.h"
#include "qemuDevice.h"

