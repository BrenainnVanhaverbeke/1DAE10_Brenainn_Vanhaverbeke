#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations

enum class CellState
{
	UNMARKED,
	CIRCLE,
	CROSS,
	CIRCLE_WIN,
	CROSS_WIN,
	WIN_BANNER,
	END
};

// Declare your own global variables here
const int g_GridRows{ 3 };
const int g_GridColumns{ g_GridRows };
const int g_AmountOfCells{ g_GridRows * g_GridColumns };
const float g_SideLength{ 50.0f };
const float g_GutterSize{ 5.0f };
const float g_Border{ 20.0f };

const Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };

Point2f g_GridOrigin{};
Point2f g_LastClickPosition{};
CellState g_LeftPlayerSelection{ CellState::CIRCLE };
CellState g_RightPlayerSelection{ CellState::CIRCLE };
Texture g_GameTextures[(int)CellState::END];
bool g_PlayerClicked{ false };
bool g_LeftPlayerTurn{ true };
bool g_GameWon{ false };
int g_WinComboIndexes[g_GridRows]{};

CellState g_Cells[g_AmountOfCells]{};

// Declare your own functions here

void InitialiseTextures();
void SetGridOrigin();
void SetCell(Point2f& mousePosition);
void DrawGrid();
void DrawPlayerSelection();
bool CheckWin();
bool CheckHorizontal();
bool CheckVertical();
bool CheckDiagonal();
void HandleWin();
void ResetGame();

int GetLinearIndexFrom2DIndex(int rowIndex, int columnIndex, int nrOfColumns);

#pragma endregion ownDeclarations


#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
