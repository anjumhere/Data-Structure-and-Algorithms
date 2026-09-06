#include "raylib.h"

int main() {

  const int screenWidth = 800;
  const int screenHeight = 500;

  InitWindow(screenWidth, screenHeight, "Brick game");

  SetTargetFPS(60);

  float paddleWidth = 100;
  float paddleHeight = 20;
  float paddleX = screenWidth / 2 - paddleWidth / 2;
  float paddleY = screenHeight - 40;
  float paddleSpeed = 6;

  float ballX = screenWidth / 2;
  float ballY = screenHeight / 2;
  float ballRadius = 10;
  float ballSpeedX = 4;
  float ballSpeedY = 4;

  bool gameOver = false;
  // ball moving
  while (!WindowShouldClose()) {
    if (!gameOver) {

      // for paddle
      if (IsKeyDown(KEY_LEFT))
        paddleX -= paddleSpeed;
      if (IsKeyDown(KEY_RIGHT))
        paddleX += paddleSpeed;
      if (paddleX < 0)
        paddleX = 0;
      if (paddleX + paddleWidth > screenWidth)
        paddleX = screenWidth - paddleWidth;

      // for ball
      ballX += ballSpeedX;
      ballY += ballSpeedY;
      if (ballX - ballRadius <= 0 || ballX + ballRadius >= screenWidth) {
        ballSpeedX *= -1;
      }
      if (ballY - ballRadius <= 0) {
        ballSpeedY *= -1;
      }
      if (ballY + ballRadius >= screenHeight) {
        gameOver = true;
      }

      if (ballX >= paddleX && ballX <= paddleX + paddleWidth &&
          ballY + ballRadius >= paddleY) {
        ballSpeedY *= -1;
      }
    }
    BeginDrawing();
    ClearBackground(BLACK);
    if (gameOver) {
      DrawText("GAME OVER - Press R to Restart", 210, 250, 20, PINK);
    } else {
      DrawCircle(ballX, ballY, ballRadius, PURPLE);
      DrawRectangle(paddleX, paddleY, paddleWidth, paddleHeight, RED);
    }
    EndDrawing();
  }

  return 0;
}
