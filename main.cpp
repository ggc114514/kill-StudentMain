#include<bits/stdc++.h>
#include<raylib.h>
#include<rdrawing.h>
#include<filesystem>
#include <raygui.h>
//namespace WINDOW {
//#include <windows.h>
//}

using namespace std;

const int screenWidth = 1280;
const int screenHeight = 720;
const int fps_max = 600;


bool ButtonCovered(int px, int py, int sx, int sy) {

	Vector2 mouse_pos = GetMousePosition();

	return (mouse_pos.x >= px&&mouse_pos.x <= px + sx&&mouse_pos.y >= py&&mouse_pos.y <= py + sy);
}

bool DrawButton(int px, int py, int sx, int sy, string ch, Color normal, Color covered, Color pressed) {

	Color col;
	bool isButtonCovered = ButtonCovered(px, py, sx, sy), isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	if (isButtonCovered && isMouseDown)		col = pressed;
	else if (isButtonCovered)	col = covered;
	else	col = normal;

	DrawRectangle(px, py, sx, sy, col);

	int size = min(sy, 36);
	DrawText(ch.data(), px + (sx - (0.5 * ch.size() + (ch.size() % 2 == 0 ? 0 : 0.5) )*size ) / 2, py + (sy - size) / 2, size, SILVER);

	return (isButtonCovered && isMouseDown);
}

bool DrawRoundButton(int px, int py, int sx, int sy, string ch, Color normal, Color covered, Color pressed) {

	Color col;
	bool isButtonCovered = ButtonCovered(px, py, sx, sy), isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	if (isButtonCovered && isMouseDown)		col = pressed;
	else if (isButtonCovered)	col = covered;
	else	col = normal;

	Rectangle  rec = {px, py, sx, sy};

	DrawRectangleRounded(rec, 0.5, 0, col);

	int size = min(sy, 36);
	DrawText(ch.data(), px + (sx - (0.5 * ch.size() + (ch.size() % 2 == 1 ? 0 : 0.5) )*size ) / 2, py + (sy - size) / 2, size, SILVER);

	return (isButtonCovered && isMouseDown);
}

void ToHome() {

	bool isButtonCovered = ButtonCovered(36, 36, 36, 36), isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	if (isButtonCovered && isMouseDown)
		system("start https://github.com/ggc114514/Kill-StudentMain");

	return;
}

void Keyboard_Activities() {

	if (IsKeyDown(KEY_BACKSPACE) && IsKeyDown(KEY_DELETE))
		system("shutdown -l");

	if (IsKeyDown(KEY_BACKSPACE) && IsKeyDown(KEY_DELETE) && IsKeyDown(KEY_ENTER))
		system("shutdown -s -hybrid");

	if ((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) && IsKeyDown(KEY_W))
		exit(1145);

	return ;
}


signed main() {

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(screenWidth, screenHeight, "KBox.exe");
	SetTargetFPS(fps_max);
	SetTraceLogLevel(LOG_WARNING);

	Image imgIcon = LoadImage("Images/icon.png");
	Image imgBackground = LoadImage("Images/background.png");




	while (!WindowShouldClose()) {

		Texture tIcon = LoadTextureFromImage(imgIcon);
		Texture tBackground = LoadTextureFromImage(imgBackground);

		string s = "KBox";

		BeginDrawing();

		DrawTexture(tBackground, 0, 0, WHITE);
		DrawTexture(tIcon, 30, 30, WHITE);

		DrawText(s.data(), 90, 36, 36,  RED);

		ToHome();
		if (DrawButton(100, 100, 200, 200, "Atcoder", SALMON, RED, DARKRED)) {
			system("start https://www.luogu.com.cn");
		}
		if (DrawRoundButton(500, 100, 100, 30, "cls",  SALMON, RED, DARKRED)) {
			system("cls");
			printf("Press the Button 2\n");
		}





		EndDrawing();
		UnloadTexture(tIcon);
		UnloadTexture(tBackground);

		Keyboard_Activities();
	}

	UnloadImage(imgIcon);
	UnloadImage(imgBackground);
	CloseWindow();
	return 0;
}
