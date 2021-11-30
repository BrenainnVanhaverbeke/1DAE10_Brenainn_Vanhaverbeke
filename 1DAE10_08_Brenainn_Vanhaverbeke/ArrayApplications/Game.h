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
// Declare your own global variables here
const int g_MaxClickedPoints{ 10 };
const int g_AmountOfPentagrams{ 5 };
const int g_AmountOfRandomStatistics{ 3 };
const int g_MaxMouseMovePoints{ 20 };
const int g_AmountOfGridCells{ 12 };
const int g_GridRows{ 3 };
const int g_GridColumns{ g_AmountOfGridCells / g_GridRows };

const float g_DefaultBorder{ 10 };
const float g_DefaultHeight{ 10 };
const float g_ClickedPointRadius{ 5.0f };
const float g_PentagramSize{ 50 };
const float g_MaxBarWidth{ 200 };
const float g_MouseMovePointRadius{ 10.0f };
const float g_SideLength{ 50 };

const Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_Red{ 1.0f, 0.0f, 0.0f, 1.0f };
const Color4f g_Green{ 0.0f, 1.0f, 0.0f, 1.0f };
const Color4f g_Blue{ 0.0f, 0.0f, 1.0f, 1.0f };
const Color4f g_Yellow{ 1.0f, 1.0f, 0.0f, 1.0f };

const Point2f g_PentagramCenter{ g_WindowWidth - g_PentagramSize - g_DefaultBorder, g_WindowHeight - g_PentagramSize - g_DefaultBorder };
const Point2f g_GridOrigin{ g_DefaultBorder, g_DefaultBorder };

int g_LastClickedPointIndex{ 0 };
int g_LastMouseMoveIndex{ 0 };

Point2f g_ClickedPoints[g_MaxClickedPoints]{};
AngleSpeed g_Pentagrams[g_AmountOfPentagrams]{};
int g_RandomStatistics[g_AmountOfRandomStatistics]{};
Texture g_RandomStatisticsText[g_AmountOfRandomStatistics]{};
Point2f g_MouseMovePoints[g_MaxMouseMovePoints]{};
bool g_CellClickState[g_AmountOfGridCells]{};

// Declare your own functions here

void InitialisePentagrams();
void InitialiseRandomStatistics();

void UpdatePentagrams(float elapsedSec);
void UpdateRandomStatistics();

void AddClickedPoint(Point2f& mousePosition);
void AddMouseMovePoint(Point2f& mousePosition);
void ToggleCell(Point2f& mousePosition);

void DrawClickedPoints();
void DrawPentagrams();
void DrawRandomStatistics();
void DrawMouseMovePoints();
void DrawGrid();

void ShoveIntoArrayLeft(Point2f* pPoints, Point2f& toShove, int lastIndex);
int Get2DIndex(int rowIndex, int columnIndex, int nrOfColumns);

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
