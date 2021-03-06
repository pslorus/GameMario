#include "KeyBoard.h"


CKeyBoard::CKeyBoard()
{
	KeyCode = -1;
}

bool CKeyBoard::initInput()
{
	HRESULT result;

	result = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&m_Input,
		NULL);

	if (result != D3D_OK)
	{
		MessageBox(0, L"Cannot create device input.", L"Error", MB_OK);
		return false;
	}

	//Create device use

	result = m_Input->CreateDevice(GUID_SysKeyboard, &m_Keyboard, NULL);

	if (result != D3D_OK)
	{
		MessageBox(0, L"Cannot create device keyboard.", L"Error", MB_OK);
		return false;
	}

	return true;
}

bool CKeyBoard::initKeyBoard(HWND hWnd)
{
	HRESULT result;
	// Directx understand handler with keyboard device
	result = m_Keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
		return false;
	// thiet lap quyen uu tien
	result = m_Keyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipw;

	dipw.diph.dwSize = sizeof(DIPROPDWORD);
	dipw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipw.dwData = 256;
	dipw.diph.dwHow = DIPH_DEVICE;
	dipw.diph.dwObj = 0;

	result = m_Keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipw.diph);
	if (FAILED(result))
		return false;


	m_Keyboard->Acquire();

	return true;
}

bool CKeyBoard::initialize(HWND hWnd)
{
	bool result;
	result = initInput();
	if (!result)
		return false;

	result = initKeyBoard(hWnd);
	if (!result)
		return false;

	return true;
}

bool CKeyBoard::isKeyDown(int key)
{
	if ((m_Keys[key] & 0x80) != 0)
	{
		KeyCode = key;
		return true;
	}
	return false;
}

int CKeyBoard::getKeyCode()
{
	return KeyCode;
}

void CKeyBoard::getState()
{
	memcpy(m_PreviousKeys, m_Keys, 256);
	KeyCode = -1;

	HRESULT hr = m_Keyboard->GetDeviceState(sizeof(m_Keys), (LPVOID)&m_Keys);

	if (FAILED(hr))
	{
		m_Keyboard->Acquire();
	}
}

bool CKeyBoard::isPressed(int Key)
{
	if ((m_Keys[Key] & 0x80) != 0 && (m_PreviousKeys[Key] & 0x80) == 0)
	{
		KeyCode = m_Keys[Key];
		return true;
	}
	else
		return false;
}

CKeyBoard::~CKeyBoard()
{
	if (m_Input != NULL)
		m_Input->Release();

	if (m_Keyboard != NULL)
		m_Keyboard->Release();
}
