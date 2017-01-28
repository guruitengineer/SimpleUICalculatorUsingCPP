// GT_Calculator@GuruItEngineer.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <stdio.h>
#include <ctype.h>
// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Calculator@GuruItEngineer");

HINSTANCE hInst;
HWND hWndEdit;
float iR1,iR2,oPerator,iResult;
char buf[1000],buff[1000]="",buffer[1000];
int i;
// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+6);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Calculator@GuruItEngineer"),
            MB_OK);

        return 1;
    }

    hInst = hInstance; // Store instance handle in our global variable

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        168, 286,
        NULL,
        NULL,
        hInstance,
        NULL
    );

 if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Calculator@GuruItEngineer"),
            MB_OK);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("WELCOME!");

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        // Here your application is laid out.
        // For this introduction, we just print out "Hello, World!"
        // in the top left corner.
	    TextOut(hdc,
            43, 0,
            greeting, _tcslen(greeting));
        // End application-specific layout section.

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_MBUTTONDOWN:
		 MessageBox(NULL,
            _T("ILLEGAL COMMAND"),
            _T("MIDDLE CLICKED"),
            MB_OK);
		break;
	case WM_RBUTTONDOWN:
		 MessageBox(NULL,
            _T("ILLEGAL COMMAND"),
            _T("RIGHT CLICKED"),
			MB_OK);
		break;
	case WM_CREATE:
		{
		hWndEdit=CreateWindowEx(WS_EX_CLIENTEDGE,TEXT("Edit"), TEXT(""),
                               WS_CHILD | WS_VISIBLE , 0, 20, 160,
                               20, hWnd,(HMENU)9999,hInst, NULL);
		HWND hWndButtonAdd = CreateWindow(TEXT("button"), TEXT("+"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             0, 40, 50, 50,        
		             hWnd, (HMENU)1010, hInst, NULL);
		HWND hWndButtonSub =CreateWindow(TEXT("button"), TEXT("-"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             50, 40, 50, 50,        
		             hWnd, (HMENU)1011, hInst, NULL);
		HWND hWndButtonMul =CreateWindow(TEXT("button"), TEXT("*"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             0, 90, 50, 50,        
		             hWnd, (HMENU)1100, hInst, NULL);
		HWND hWndButtonDiv =CreateWindow(TEXT("button"), TEXT("/"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             50, 90, 50, 50,        
		             hWnd, (HMENU)1101, hInst, NULL);
		HWND hWndButtonDel =CreateWindow(TEXT("button"), TEXT("CLR"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             100, 40, 60, 50,        
		             hWnd, (HMENU)11111, hInst, NULL);
		HWND hWndButtonEqu =CreateWindow(TEXT("button"), TEXT("="),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             100, 90, 60, 50,        
		             hWnd, (HMENU)1111, hInst, NULL);
		HWND hWndButton0 =CreateWindow(TEXT("button"), TEXT("0"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             0, 140, 32, 32,        
		             hWnd, (HMENU)0000, hInst, NULL);
		HWND hWndButton1 =CreateWindow(TEXT("button"), TEXT("1"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             32, 140, 32, 32,        
		             hWnd, (HMENU)0001, hInst, NULL);
		HWND hWndButton2 =CreateWindow(TEXT("button"), TEXT("2"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             64, 140, 32, 32,        
		             hWnd, (HMENU)0010, hInst, NULL);
		HWND hWndButton3 =CreateWindow(TEXT("button"), TEXT("3"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             96, 140, 32, 32,        
		             hWnd, (HMENU)0011, hInst, NULL);
		HWND hWndButton4 =CreateWindow(TEXT("button"), TEXT("4"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             128, 140, 32, 32,        
		             hWnd, (HMENU)0100, hInst, NULL);
		HWND hWndButton5 =CreateWindow(TEXT("button"), TEXT("5"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             0, 172, 32, 32,        
		             hWnd, (HMENU)0101, hInst, NULL);
		HWND hWndButton6 =CreateWindow(TEXT("button"), TEXT("6"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             32, 172, 32, 32,        
		             hWnd, (HMENU)0110, hInst, NULL);
		HWND hWndButton7 =CreateWindow(TEXT("button"), TEXT("7"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             64, 172, 32, 32,        
		             hWnd, (HMENU)0111, hInst, NULL);
		HWND hWndButton8 =CreateWindow(TEXT("button"), TEXT("8"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             96, 172, 32, 32,        
		             hWnd, (HMENU)1000, hInst, NULL);
		HWND hWndButton9 =CreateWindow(TEXT("button"), TEXT("9"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             128, 172, 32, 32,        
		             hWnd, (HMENU)1001, hInst, NULL);
		HWND hWndButtonClr =CreateWindow(TEXT("button"), TEXT("CLEAR"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             0, 204, 160, 50,        
		             hWnd, (HMENU)999, hInst, NULL);
		
		}
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		
		case 0000:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"0"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 0001:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"1"); 
			SetWindowTextA(hWndEdit,buf);
			break;
			case 0010:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"2"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 0011:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"3"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 0100:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"4"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 0101:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"5"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 0110:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"6"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 0111:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"7"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 1000:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"8"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 1001:
			GetWindowTextA(hWndEdit,buf,1000);
			strcat_s(buf,"9"); 
			SetWindowTextA(hWndEdit,buf);
			break;
		case 1010:
			GetWindowTextA(hWndEdit,buf,1000);
			SetWindowTextA(hWndEdit,"");
			iR1=atof(buf);
			oPerator=1010;
			break;
		case 1011:
			GetWindowTextA(hWndEdit,buf,1000);
			SetWindowTextA(hWndEdit,"");
			iR1=atof(buf);
			oPerator=1011;
			break;
		case 1100:
			GetWindowTextA(hWndEdit,buf,1000);
			SetWindowTextA(hWndEdit,"");
			iR1=atof(buf);
			oPerator=1100;
			break;
		case 1101:
			GetWindowTextA(hWndEdit,buf,1000);
			SetWindowTextA(hWndEdit,"");
			iR1=atof(buf);
			oPerator=1101;
			break;
		case 1111:
			GetWindowTextA(hWndEdit,buf,1000);
			iR2=atof(buf);
			if(oPerator==1010)
			{
				iResult=iR1+iR2;
			}
			if(oPerator==1011)
			{
				iResult=iR1-iR2;
			}
			if(oPerator==1100)
			{
				iResult=iR1*iR2;
			}
			if(oPerator==1101)
			{
				if(iR1!=0)
					iResult=iR1/iR2;
				else
					iResult=0;
			}
			sprintf_s(buffer,"%f",iResult);
			SetWindowTextA(hWndEdit,buffer);
			break;
		case 11111:
			SetWindowTextA(hWndEdit,"");
			break;
		case 999:
			GetWindowTextA(hWndEdit,buf,1000);
			int a=strlen(buf);
			sprintf_s(buffer,"%d",a);
			SetWindowTextA(hWndEdit,buffer);
			break;
		   	}
	break;
	default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}
