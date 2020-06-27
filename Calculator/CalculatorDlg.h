
// CalculatorDlg.h: 头文件
//

#pragma once
#include <memory>
#include "Calculator.h"

// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_historyText;
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonC();
private:
	bool m_errorInput = false;
	Calculator m_calculator;

	BOOL m_firstDigitEntered = FALSE;
	const CString m_outputResetString{ "0" };


	void createHistoryText();
	void addDigit(char digit);
	void doOperation(Calculator::ActionType operation, bool handleNumber = TRUE);
	void reset();
	void resetOutput();


	CFont m_font;
	CFont result_font;
	CFont history_font;
	CString m_output;
	CButton m_button0;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_button5;
	CButton m_button6;
	CButton m_button7;
	CButton m_button8;
	CButton m_button9;

	CButton m_buttonDivide;
	CButton m_buttonMultiply;
	CButton m_buttonMinus;
	CButton m_buttonPlus;
	CButton m_buttonEquals;
	CButton m_buttonC;
	CEdit m_editResult;
	CEdit m_editHistory;
	CStatic m_staticHistory;
	COLORREF m_historyBkColor;
	std::unique_ptr<CBrush> m_historyBkBrush;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
