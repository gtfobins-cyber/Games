#include <raylib.h>
#include "game.hpp"
#include <string>

std::string formatWithLeadingZeros(int number, int width) {
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
}

int main()
{
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    // int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowHeight, windowWidth, "C++ Space Invaders");
    InitAudioDevice();

    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    SetTargetFPS(60);

    Game game;

    while (WindowShouldClose() == false) {

        UpdateMusicStream(game.music);          // Instead of UpdateAudioStream
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 680, 730}, 0.18f, 20, 2, yellow);
        DrawLineEx({10, 680}, {690, 680}, 3, yellow);
        if(game.run) {
            DrawTextEx(font, "LEVEL 01", {500, 690}, 34, 2, yellow);
        } else {
            DrawTextEx(font, "GAME OVER", {500, 690}, 34, 2, yellow);
        }

        float x = 50.0;
        for(int i = 0; i < game.lives; i++) {
            DrawTextureV(spaceshipImage, {x, 690}, WHITE);
            x += 50;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string scoreText = formatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        DrawTextEx(font, "HIGH-SCORE", {480, 15}, 34, 2, yellow);
        std::string highscoreText = formatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {570, 40}, 34, 2, yellow);

        game.Draw();
        EndDrawing();

    }

    CloseWindow();
    CloseAudioDevice();
}