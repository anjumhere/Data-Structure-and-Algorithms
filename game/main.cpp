#include "raylib.h"
#include <vector>
using std::vector;

struct Brick {
  float x;
  float y;
  float width;
  float height;
  bool isAlive;
};

int main() {
  const int screenWidth = 1000;
  const int screenHeight = 700;
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

  int rows = 5;
  int cols = 13;
  float brickHeight = 20;
  float brickWidth = 70;
  float brickPadding = 5;
  float offsetX = 15;
  float offsetY = 40;

  vector<Brick> bricks;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      Brick newBrick;
      newBrick.x = offsetX + col * (brickWidth + brickPadding);
      newBrick.y = offsetY + row * (brickHeight + brickPadding);
      newBrick.height = brickHeight;
      newBrick.width = brickWidth;
      newBrick.isAlive = true;
      bricks.push_back(newBrick);
    }
  }

  bool gameOver = false;
  int score = 0;

  while (!WindowShouldClose()) {
    if (!gameOver) {
      // paddle movement
      if (IsKeyDown(KEY_LEFT))
        paddleX -= paddleSpeed;
      if (IsKeyDown(KEY_RIGHT))
        paddleX += paddleSpeed;
      if (paddleX < 0)
        paddleX = 0;
      if (paddleX + paddleWidth > screenWidth)
        paddleX = screenWidth - paddleWidth;

      // ball movement
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

      // ball vs bricks
      for (auto &box : bricks) {
        if (box.isAlive && ballX >= box.x && ballX <= box.x + box.width &&
            ballY - ballRadius <= box.y + box.height &&
            ballY + ballRadius >= box.y) {
          box.isAlive = false;
          ballSpeedY *= -1;
          score++;
        }
      }
    }

    BeginDrawing();
    ClearBackground(BLACK);

    if (gameOver) {
      DrawText("GAME OVER - Press R to Restart", 300, 300, 20, PINK);
    } else {
      DrawCircle(ballX, ballY, ballRadius, PURPLE);
      DrawRectangle(paddleX, paddleY, paddleWidth, paddleHeight, WHITE);
      DrawText(TextFormat("Score: %d", score), 50, screenHeight - 100, 20,
               BLUE);

      for (auto &box : bricks) {
        if (box.isAlive) {
          DrawRectangle(box.x, box.y, box.width, box.height, RED);
        }
      }
    }

    if (gameOver && IsKeyDown(KEY_R)) {
      gameOver = false;
      paddleX = screenWidth / 2 - paddleWidth / 2;
      paddleY = screenHeight - 40;
      ballX = screenWidth / 2;
      ballY = screenHeight / 2;
      ballSpeedX = 4;
      ballSpeedY = 4;
      score = 0;
      for (auto &box : bricks) {
        box.isAlive = true;
      }
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
