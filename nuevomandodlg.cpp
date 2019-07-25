// NuevoMandoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ad9832.h"
#include "NuevoMandoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NuevoMandoDlg dialog


NuevoMandoDlg::NuevoMandoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(NuevoMandoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(NuevoMandoDlg)
	m_canal = 0;
	m_frecuencia = 0.0;
	m_tiempo = 0;
	//}}AFX_DATA_INIT
}


void NuevoMandoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NuevoMandoDlg)
	DDX_Text(pDX, IDC_CANAL, m_canal);
	DDX_Text(pDX, IDC_FRECUENCIA, m_frecuencia);
	DDX_Text(pDX, IDC_TIEMPO, m_tiempo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NuevoMandoDlg, CDialog)
	//{{AFX_MSG_MAP(NuevoMandoDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NuevoMandoDlg message handlers
