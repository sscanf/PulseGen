#if !defined(AFX_NUEVOMANDODLG_H__077B8031_B01D_44B1_BB5D_FBC1346E76E4__INCLUDED_)
#define AFX_NUEVOMANDODLG_H__077B8031_B01D_44B1_BB5D_FBC1346E76E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NuevoMandoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NuevoMandoDlg dialog

class NuevoMandoDlg : public CDialog
{
// Construction
public:
	NuevoMandoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(NuevoMandoDlg)
	enum { IDD = IDD_DIALOG1 };
	UINT	m_canal;
	double	m_frecuencia;
	UINT	m_tiempo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NuevoMandoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(NuevoMandoDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUEVOMANDODLG_H__077B8031_B01D_44B1_BB5D_FBC1346E76E4__INCLUDED_)
