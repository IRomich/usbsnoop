// SnoopyPro.h : main header file for the SNOOPYPRO application
//

#if !defined(AFX_SNOOPYPRO_H__EB709311_F763_4017_8947_4B363E7D302F__INCLUDED_)
#define AFX_SNOOPYPRO_H__EB709311_F763_4017_8947_4B363E7D302F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "Resource.h"       // main symbols

class CUSBLogDoc;

//////////////////////////////////////////////////////////////////////////
// CSnoopyProApp:
// See SnoopyPro.cpp for the implementation of this class
//

#define REGSTR_DEVICESWINDOW            "DevicesWindow"
#define REGSTR_POSITIONTOP              "PositionTop"
#define REGSTR_POSITIONLEFT             "PositionLeft"
#define REGSTR_POSITIONBOTTOM           "PositionBottom"
#define REGSTR_POSITIONRIGHT            "PositionRight"
#define REGSTR_VISIBLE                  "Visible"

#define REGSTR_EXPORTER                 "Exporter"
#define REGSTR_FILENAME                 "Filename"
#define REGSTR_EXPORTERTYPE             "ExporterType"

class CSnoopyProApp : public CWinApp
{
public:
    CSnoopyProApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSnoopyProApp)
    public:
    virtual BOOL InitInstance();
    virtual BOOL OnIdle(LONG lCount);
    //}}AFX_VIRTUAL

    void ScanForNewSnoopedDevices(void);

    BOOL m_bIsSnpysPresent;
    BOOL IsSnpysPresent(void) { return m_bIsSnpysPresent; }
    int m_nSnpysUsage;
    int SnpysUsage(void) { return m_nSnpysUsage; }
    
    CUSBLogDoc *CreateNewDocument(void);

    CList<CUSBLogDoc *, CUSBLogDoc *> m_DocsNeedingUpdate;
    void AddDocumentToIdleList(CUSBLogDoc *pDocument);
    void RemoveDocumentFromIdleList(CUSBLogDoc *pDocument);

    void SetPercent(int nPercent);

    void IncrementWorkTick(void);
    void InitializeWorkTicks(DWORD dwTotalTicks);
    void DeinitializeWorkTicks(void);

    DWORD m_dwWorkTicks;
    DWORD m_dwTotalWorkTicks;

    // contains the identifier to use when accessing the clipboard
    // and binary URBs are copied/cut/pasted...

    UINT m_uClipboardFormat;

// Implementation
    //{{AFX_MSG(CSnoopyProApp)
    afx_msg void OnAppAbout();
	afx_msg void OnHelpReadme();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

CSnoopyProApp &GetApp(void);

//////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNOOPYPRO_H__EB709311_F763_4017_8947_4B363E7D302F__INCLUDED_)
