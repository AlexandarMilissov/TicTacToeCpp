#include "WindowsMessageMap.h"
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>

#define UM_UAHDESTROYWINDOW 0x0090
#define UM_UAHDRAWMENU 0x0091
#define UM_UAHDRAWMENUITEM 0x0092
#define UM_UAHINITMENU 0x0093
#define UM_UAHMEASUREMENUITEM 0x0094
#define UM_UAHNCPAINTMENUPOPUP 0x0095

#define REGISTER_MESSAGE(msg){msg, #msg}

WindowsMessageMap::WindowsMessageMap()
	:
	map
	(
		{
			REGISTER_MESSAGE(WM_CREATE),
			REGISTER_MESSAGE(WM_DESTROY),
			REGISTER_MESSAGE(WM_MOVE),
			REGISTER_MESSAGE(WM_SIZE),
			REGISTER_MESSAGE(WM_ACTIVATE),
			REGISTER_MESSAGE(WM_SETFOCUS),
			REGISTER_MESSAGE(WM_KILLFOCUS),
			REGISTER_MESSAGE(WM_ENABLE),
			REGISTER_MESSAGE(WM_SETREDRAW),
			REGISTER_MESSAGE(WM_SETTEXT),
			REGISTER_MESSAGE(WM_GETTEXT),
			REGISTER_MESSAGE(WM_GETTEXTLENGTH),
			REGISTER_MESSAGE(WM_PAINT),
			REGISTER_MESSAGE(WM_CLOSE),
			REGISTER_MESSAGE(WM_QUERYENDSESSION),
			REGISTER_MESSAGE(WM_QUIT),
			REGISTER_MESSAGE(WM_QUERYOPEN),
			REGISTER_MESSAGE(WM_ERASEBKGND),
			REGISTER_MESSAGE(WM_SYSCOLORCHANGE),
			REGISTER_MESSAGE(WM_ENDSESSION),
			REGISTER_MESSAGE(WM_SHOWWINDOW),
			REGISTER_MESSAGE(WM_CTLCOLORMSGBOX),
			REGISTER_MESSAGE(WM_CTLCOLOREDIT),
			REGISTER_MESSAGE(WM_CTLCOLORLISTBOX),
			REGISTER_MESSAGE(WM_CTLCOLORBTN),
			REGISTER_MESSAGE(WM_CTLCOLORDLG),
			REGISTER_MESSAGE(WM_CTLCOLORSCROLLBAR),
			REGISTER_MESSAGE(WM_CTLCOLORSTATIC),
			REGISTER_MESSAGE(WM_WININICHANGE),
			REGISTER_MESSAGE(WM_SETTINGCHANGE),
			REGISTER_MESSAGE(WM_DEVMODECHANGE),
			REGISTER_MESSAGE(WM_ACTIVATEAPP),
			REGISTER_MESSAGE(WM_FONTCHANGE),
			REGISTER_MESSAGE(WM_TIMECHANGE),
			REGISTER_MESSAGE(WM_CANCELMODE),
			REGISTER_MESSAGE(WM_SETCURSOR),
			REGISTER_MESSAGE(WM_MOUSEACTIVATE),
			REGISTER_MESSAGE(WM_CHILDACTIVATE),
			REGISTER_MESSAGE(WM_QUEUESYNC),
			REGISTER_MESSAGE(WM_GETMINMAXINFO),
			REGISTER_MESSAGE(WM_ICONERASEBKGND),
			REGISTER_MESSAGE(WM_NEXTDLGCTL),
			REGISTER_MESSAGE(WM_SPOOLERSTATUS),
			REGISTER_MESSAGE(WM_DRAWITEM),
			REGISTER_MESSAGE(WM_MEASUREITEM),
			REGISTER_MESSAGE(WM_DELETEITEM),
			REGISTER_MESSAGE(WM_VKEYTOITEM),
			REGISTER_MESSAGE(WM_CHARTOITEM),
			REGISTER_MESSAGE(WM_SETFONT),
			REGISTER_MESSAGE(WM_GETFONT),
			REGISTER_MESSAGE(WM_QUERYDRAGICON),
			REGISTER_MESSAGE(WM_COMPAREITEM),
			REGISTER_MESSAGE(WM_NCCREATE),
			REGISTER_MESSAGE(WM_NCDESTROY),
			REGISTER_MESSAGE(WM_NCCALCSIZE),
			REGISTER_MESSAGE(WM_NCHITTEST),
			REGISTER_MESSAGE(WM_NCPAINT),
			REGISTER_MESSAGE(WM_NCACTIVATE),
			REGISTER_MESSAGE(WM_GETDLGCODE),
			REGISTER_MESSAGE(WM_NCMOUSEMOVE),
			REGISTER_MESSAGE(WM_NCLBUTTONDOWN),
			REGISTER_MESSAGE(WM_NCPAINT),



			REGISTER_MESSAGE(WM_WINDOWPOSCHANGED),
			REGISTER_MESSAGE(WM_POWER),
			REGISTER_MESSAGE(WM_COPYGLOBALDATA),
			REGISTER_MESSAGE(WM_COPYDATA),
			REGISTER_MESSAGE(WM_CANCELJOURNAL),
			REGISTER_MESSAGE(WM_NOTIFY),
			REGISTER_MESSAGE(WM_INPUTLANGCHANGEREQUEST),
			REGISTER_MESSAGE(WM_INPUTLANGCHANGE),
			REGISTER_MESSAGE(WM_TCARD),
			REGISTER_MESSAGE(WM_HELP),
			REGISTER_MESSAGE(WM_USERCHANGED),
			REGISTER_MESSAGE(WM_NOTIFYFORMAT),
			REGISTER_MESSAGE(WM_CONTEXTMENU),
			REGISTER_MESSAGE(WM_STYLECHANGING),
			REGISTER_MESSAGE(WM_STYLECHANGED),
			REGISTER_MESSAGE(WM_DISPLAYCHANGE),
		}
	)