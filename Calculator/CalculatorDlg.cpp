
// CalculatorDlg.cpp: 实现文件
//

#include "framework.h"
#include "CalculatorApp.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <sstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_historyText(_T(""))
	, m_output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_historyBkColor = RGB(0, 0, 166);
	m_historyBkBrush = std::make_unique<CBrush>(m_historyBkColor);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_historyText);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_output);
	DDX_Control(pDX, IDC_BUTTON_0, m_button0);
	DDX_Control(pDX, IDC_BUTTON_1, m_button1);
	DDX_Control(pDX, IDC_BUTTON_2, m_button2);
	DDX_Control(pDX, IDC_BUTTON_3, m_button3);
	DDX_Control(pDX, IDC_BUTTON_4, m_button4);
	DDX_Control(pDX, IDC_BUTTON_5, m_button5);
	DDX_Control(pDX, IDC_BUTTON_6, m_button6);
	DDX_Control(pDX, IDC_BUTTON_7, m_button7);
	DDX_Control(pDX, IDC_BUTTON_8, m_button8);
	DDX_Control(pDX, IDC_BUTTON_9, m_button9);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_buttonDivide);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_buttonMultiply);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_buttonMinus);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_buttonPlus);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, m_buttonEquals);
	DDX_Control(pDX, IDC_BUTTON_C, m_buttonC);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_editResult);
	DDX_Control(pDX, IDC_EDIT_HISTORY, m_editHistory);
	DDX_Control(pDX, IDC_STATIC_HISTORY, m_staticHistory);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonC)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_font.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));
	result_font.CreateFont(50, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));
	history_font.CreateFont(18, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));
	m_button0.SetFont(&m_font);
	m_button1.SetFont(&m_font);
	m_button2.SetFont(&m_font);
	m_button3.SetFont(&m_font);
	m_button4.SetFont(&m_font);
	m_button5.SetFont(&m_font);
	m_button6.SetFont(&m_font);
	m_button7.SetFont(&m_font);
	m_button8.SetFont(&m_font);
	m_button9.SetFont(&m_font);
	m_buttonDivide.SetFont(&m_font);
	m_buttonMultiply.SetFont(&m_font);
	m_buttonMinus.SetFont(&m_font);
	m_buttonPlus.SetFont(&m_font);
	m_buttonEquals.SetFont(&m_font);
	m_buttonC.SetFont(&m_font);
	m_editResult.SetFont(&result_font);
	m_editHistory.SetFont(&history_font);
	m_staticHistory.SetFont(&history_font);

	reset();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::reset()
{
	m_calculator.reset();
	m_errorInput = false;
	m_firstDigitEntered = FALSE;
	resetOutput();
	m_historyText = "";
	UpdateData(FALSE);
}

void CCalculatorDlg::resetOutput()
{
	m_output = m_outputResetString;
}


void CCalculatorDlg::addDigit(char digit)
{
	if (m_errorInput)
		return;
	UpdateData();
	if (m_calculator.isOperation(m_calculator.getLastInput().actionType) && 
		!m_firstDigitEntered)
	{
		m_output = digit;
	}
	else
	{
		if (m_output == m_outputResetString && digit == '0')
			return;
		else if (m_output == m_outputResetString)
			m_output = digit;
		else
			m_output += digit;
	}
	m_firstDigitEntered = TRUE;
	UpdateData(FALSE);
}

void CCalculatorDlg::doOperation(Calculator::ActionType operation, bool handleNumber)
{
	if (m_errorInput)
		return;
	UpdateData();
	Calculator::Action input;
	if (handleNumber)
	{
		input.actionType = Calculator::ActionType::Number;
		input.value = _wtof(m_output);
		m_calculator.addInput(input);
	}
	input.actionType = operation;
	m_errorInput = false;
	try
	{
		if (m_calculator.addInput(input))
		{
			if (!m_calculator.hasLeftTermValue() || !m_calculator.hasLeftExpressionValue())
			{
				std::stringstream ss;
				ss << m_calculator.getCurrentResult();
				std::string curResult = ss.str();

				m_output = "";
				m_output += curResult.c_str();
				UpdateData(FALSE);
			}
		}
		else
			AfxMessageBox(_T("Error: An unknown operation."));
	}
	catch (std::exception& e)
	{
		m_output = e.what();
		m_firstDigitEntered = FALSE;
		m_errorInput = true;
	}
	createHistoryText();
	if (operation == Calculator::ActionType::Equals)
	{
		if (m_errorInput)
			m_historyText += " ";
		m_historyText += m_output;
	}
	UpdateData(FALSE);
	m_firstDigitEntered = FALSE;
}

void CCalculatorDlg::createHistoryText()
{
	m_historyText = "";
	int historySize = m_calculator.getActionsSize();
	for (int i = 0; i < historySize; ++i)
	{
		switch (m_calculator.getAction(i).actionType)
		{
		case Calculator::ActionType::Number:
		{
			CString strNumber;
			std::stringstream ss;
			ss << m_calculator.getAction(i).value;
			std::string stdNum = ss.str();

			strNumber = stdNum.c_str();
			if (m_historyText.IsEmpty())
				m_historyText += strNumber;
			else
				m_historyText += (CString(" ") + strNumber);
		}
		break;
		case Calculator::ActionType::Plus:
			m_historyText += " +";
			break;
		case Calculator::ActionType::Divide:
			m_historyText += " /";
			break;
		case Calculator::ActionType::Minus:
			m_historyText += " -";
			break;
		case Calculator::ActionType::Multiply:
			m_historyText += " x";
			break;
		case Calculator::ActionType::Equals:
			m_historyText += " =";
			break;
		case Calculator::ActionType::None:
			break;
		}
	}

}

void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('0');
}


void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('1');
}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('2');
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('3');
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('4');
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('5');
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('6');
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('7');
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('8');
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	addDigit('9');
}


void CCalculatorDlg::OnBnClickedButtonEquals()
{
	// TODO: 在此添加控件通知处理程序代码
	doOperation(Calculator::ActionType::Equals);
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: 在此添加控件通知处理程序代码
	doOperation(Calculator::ActionType::Plus);
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	doOperation(Calculator::ActionType::Minus);
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: 在此添加控件通知处理程序代码
	doOperation(Calculator::ActionType::Multiply);
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	doOperation(Calculator::ActionType::Divide);
}


void CCalculatorDlg::OnBnClickedButtonC()
{
	// TODO: 在此添加控件通知处理程序代码
	reset();
}


HBRUSH CCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	switch (nCtlColor) {
	case CTLCOLOR_EDIT:
		if (pWnd->GetDlgCtrlID() == IDC_EDIT_HISTORY) {
			pDC->SetTextColor(RGB(0, 235, 0));
			pDC->SetBkColor(m_historyBkColor);
			return static_cast<HBRUSH>(m_historyBkBrush->GetSafeHandle());
		}
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
