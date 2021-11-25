#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Math Vectors - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float g_RotationSpeed{ 25.0f };

const Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_Red{ 1.0f, 0.0f, 0.0f, 1.0f };
const Color4f g_Green{ 0.0f, 1.0f, 0.0f, 1.0f };
const Color4f g_Blue{ 0.0f, 0.0f, 1.0f, 1.0f };

float g_VectorAngle{};

// Declare your own functions here
void DrawAnimatedVector();

void TestDrawVector();
void TestVectorToString();
void TestAddVector();
void TestSubtractVector();
void TestDotProduct();
void TestCrossProduct();
void TestLengthVector();
void TestScaleVector();
void TestNormaliseVector();
void TestAngleBetween();
void TestAreEqual();

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
