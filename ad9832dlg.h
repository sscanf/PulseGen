// ad9832Dlg.h : header file
//

#if !defined(AFX_AD9832DLG_H__39B353A0_0725_4102_8458_0ED2A24344AC__INCLUDED_)
#define AFX_AD9832DLG_H__39B353A0_0725_4102_8458_0ED2A24344AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAd9832Dlg dialog
#include <math.h>
#include <afxtempl.h>
#include "digistring.h"

class CAd9832Dlg : public CDialog
{
// Construction
public:
	void SendFreq (double freq);

	CAd9832Dlg(CWnd* pParent = NULL);	// standard constructor
	~CAd9832Dlg();

// Dialog Data
	//{{AFX_DATA(CAd9832Dlg)
	enum { IDD = IDD_AD9832_DIALOG };
	UINT	m_TimeHigh;
	UINT	m_TimeLow;
	UINT	m_total;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAd9832Dlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bFlash;
	BOOL m_bGenerar;
bool CAd9832Dlg::SortNumericItems( int nCol, BOOL bAscending,int low, int high);
	void SelectItem (int nItem, BOOL select);
	void SetImage (int nItem, UINT image);
	int m_nItem;
	BOOL m_bActivo;
	CImageList m_ImageList;
	CString m_strFileName;

	double m_freq;
	void ResetDevice (void);
	void PinOut (int pin, int status);
	HANDLE m_handle;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAd9832Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGenerar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AD9832DLG_H__39B353A0_0725_4102_8458_0ED2A24344AC__INCLUDED_)
