// Module:		CIS023_S2020_HW12.cpp
// Author:		Mark Berrett
// Date:		February 11, 2020
// Purpose:		Homework 12
//				Review file input into an array and a listbox.
//				Create a class definition with virtual functions.
//				Interact with virtual functions.
// Edited:      Miguel Antonio Logarta
//              March 8, 2020

#include "CIS023_S2020_HW12.h"                  // Project header

#define MAX_LOADSTRING 100
#define ARRAY_SIZE 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_ListBox;								// handle to list box
HWND hWnd_Count;								// buttons
HWND hWnd_Longest;
HWND hWnd_Shortest;
HWND hWnd_Output;								// output message

string HW20Array[ARRAY_SIZE];					// work array

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

bool LoadFile();								// loads sample data into HW20Array[];

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CIS023S2020HW12, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020HW12));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020HW12));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020HW12);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 400, 400, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case BN_CLICKED:
				if (LOWORD(lParam) == (WORD)hWnd_Count)
				{
                    TCHAR szOutput[TCHAR_SIZE];                 // Create output buffer

					// count the filled elements of the array
                    // Take the return value of Count() and put it in iCount
                    int iCount{ ListClass::Count(HW20Array, ARRAY_SIZE) };

					// convert int to TCHAR for output
                    InttoTCHAR(iCount, szOutput);               // Use IntotoTCHAR from Utilities.h, output value to szOutput

					// display value
                    SetWindowText(hWnd_Output,                  // Handle to control
                        szOutput);                              // Source TCHAR, the output buffer     

				}
				if (LOWORD(lParam) == (WORD)hWnd_Longest)
				{ 
                    TCHAR szOutput[TCHAR_SIZE];                 // Output buffer
                    string strLargest{ HW20Array[0] };          // Largest string found in array. Start at first item

					// get the longest string in the array
                    // Take the return value of Largest() and store it in iPos
                    int iPos{ ListClass::Largest(HW20Array, ARRAY_SIZE, strLargest) };

					// convert the string to a TCHAR for output
                    StringtoTCHAR(&strLargest, szOutput);       // Convert to TCHAR using this function from Utilities.h

					// display results
                    SetWindowText(hWnd_Output,                  // Handle to control
                        szOutput);                              // Source TCHAR, the output buffer

				}

				if (LOWORD(lParam) == (WORD)hWnd_Shortest)
				{ 
                    TCHAR szOutput[TCHAR_SIZE];                 // Output buffer
                    string strShortest{ HW20Array[0] };         // Shortest string found in array. Start at first item

					// get the shortest string in the array
                    // Take the return value of Shortest() and store it in iPos
                    int iPos{ ListClass::Shortest(HW20Array, ARRAY_SIZE, strShortest) };

					// convert the string to a TCHAR for output
                    StringtoTCHAR(&strShortest, szOutput);      // Convert to TCHAR using this function from Utilities.h

					// display results
                    SetWindowText(hWnd_Output,                  // Handle to control
                        szOutput);                              // Source TCHAR, the output buffer

				}
				break;

            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CREATE:

		// listbox
		hWnd_ListBox = CreateWindow(
			TEXT("LISTBOX"),								// type of object
			TEXT(""),										// starts blank (filled later)
			WS_VISIBLE | WS_CHILD |							// attributes
			WS_VSCROLL | WS_BORDER | LBS_SORT,				// sorted
			10, 10, 325, 175,								// location and size
			hWnd, NULL, NULL, NULL);						// parent window, the rest are not used here

		// buttons
		hWnd_Count = CreateWindow(TEXT("BUTTON"),
			TEXT("Count"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 200, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Longest = CreateWindow(TEXT("BUTTON"),
			TEXT("Longest"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			120, 200, 90, 30, hWnd, NULL, NULL, NULL);

		hWnd_Shortest = CreateWindow(TEXT("BUTTON"),
			TEXT("Shortest"),
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			230, 200, 90, 30, hWnd, NULL, NULL, NULL);

		// output
		hWnd_Output = CreateWindow(
		TEXT("STATIC"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		10, 260, 325, 20, hWnd, NULL, NULL, NULL);

		// load the text file into the array and the listbox
		LoadFile();						

		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// loads file into array
bool LoadFile()
{
	ifstream inFile;							// handle of text file

	inFile.open("CIS023_S2020_HW12_data.txt");	// open the file

	if (inFile.is_open())						// did the file open?
	{
		for (int i = 0; i < ARRAY_SIZE; i++)	// read the ARRAY_SIZE # of lines from the text file
		{
			getline(inFile, HW20Array[i], '\n'); // read line into array
		}

		inFile.close();							// close the file

	}
	else
		return false;							// file did not open

	TCHAR szBuffer[TCHAR_SIZE];					// output to listbox

	for (int i = 0; i < ARRAY_SIZE; i++)		// roll through the array
	{
		if (HW20Array[i].length() > 0)			// if the array element is not empty
		{
			StringtoTCHAR(&HW20Array[i], szBuffer); // convert string to TCHAR

			SendMessage(						// load the listbox
				hWnd_ListBox,					// handle to listbox
				LB_ADDSTRING,					// append TCHAR 
				NULL,							// not used
				(LPARAM)szBuffer);				// TCHAR
		}
	}

	return true;								// file opened okay

}

