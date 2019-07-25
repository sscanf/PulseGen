// ad9832Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ad9832.h"
#include "ad9832Dlg.h"
#include "tvichw32.h"
#include "nuevomandodlg.h"
#include "ListCtrlPrint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define SCLK	2
#define SDATA	3
#define	FSYNC	4

#define	OFF		TRUE
#define	ON		FALSE
#define IDDLE	TRUE
#define	HIGH	TRUE
#define	LOW		FALSE

#define NUM_COLUMNS	4
#define IDT_TIMER	1000
#define IDT_TIMER2	1001


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAd9832Dlg dialog

CAd9832Dlg::CAd9832Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAd9832Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAd9832Dlg)
	m_TimeHigh = 0;
	m_TimeLow = 0;
	m_total = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

CAd9832Dlg::~CAd9832Dlg ()
{
	CloseTVicHW32 (m_handle);
}
void CAd9832Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAd9832Dlg)
	DDX_Text(pDX, IDC_TIMEHIGHT, m_TimeHigh);
	DDX_Text(pDX, IDC_TIMELOW, m_TimeLow);
	DDX_Text(pDX, IDC_TOTAL_PULSES, m_total);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAd9832Dlg, CDialog)
	//{{AFX_MSG_MAP(CAd9832Dlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_GENERAR, OnGenerar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAd9832Dlg message handlers

BOOL CAd9832Dlg::OnInitDialog()
{
	CRect rect;
	CDialog::OnInitDialog();
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_handle=0;
	m_handle = OpenTVicHW32 (m_handle,"TVICHW32","TVICDEVICE0");
	if (!GetActiveHW(m_handle))
	{
		AfxMessageBox ("Imposible abrir el driver");
		return FALSE;
	}
	
	PinOut (SCLK,HIGH);
	PinOut (SDATA,HIGH);
	PinOut (FSYNC,HIGH);

	ResetDevice();
	return TRUE;  // return TRUE  unless you set the focus to a control
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAd9832Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAd9832Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAd9832Dlg::ResetDevice()
{
	long freq = 0x00029f17;

}


void CAd9832Dlg::PinOut (int pin, int status)
{
	SetPin (m_handle,pin,status);
}


BOOL CAd9832Dlg::DestroyWindow() 
{
	return CDialog::DestroyWindow();
}

void CAd9832Dlg::OnGenerar() 
{
	UpdateData (TRUE);
	
	for (int n=0;n<m_total;n++)
	{
		PinOut (2,1);
		Sleep (m_TimeHigh);
		PinOut (2,0);
		Sleep (m_TimeLow);
	}
}
