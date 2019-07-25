// ad9832.h : main header file for the AD9832 application
//

#if !defined(AFX_AD9832_H__E57C820B_7902_4CAC_B7B7_C0B31F709FCD__INCLUDED_)
#define AFX_AD9832_H__E57C820B_7902_4CAC_B7B7_C0B31F709FCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAd9832App:
// See ad9832.cpp for the implementation of this class
//

class CAd9832App : public CWinApp
{
public:
	CAd9832App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAd9832App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAd9832App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AD9832_H__E57C820B_7902_4CAC_B7B7_C0B31F709FCD__INCLUDED_)
