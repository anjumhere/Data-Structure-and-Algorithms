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
  // Step 1: Initialization - window, paddle, ball, and bricks setup
  const int screenWidth = 1000;
  const int screenHeight = 700;
  InitWindow(screenWidth, screenHeight, "Brick game");
  SetTargetFPS(60);

  float paddleWidth = 100;
  float paddleHeight = 10;
  float paddleX = screenWidth / 2 - paddleWidth / 2;
  float paddleY = screenHeight - 40;
  float paddleSpeed = 9;

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
  bool gameWon =
      false; // IMPROVEMENT: track win state separately from game over
  int score = 0;

  while (!WindowShouldClose()) {
    if (!gameOver && !gameWon) {
      // Step 2: Update - handle input and move paddle/ball, check collisions
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

      // IMPROVEMENT: original paddle check fired every frame once the ball
      // was anywhere below paddleY (even after passing it), sometimes causing
      // the ball to get "stuck" flipping direction repeatedly. Now it only
      // bounces when the ball is moving downward AND within the paddle's
      // vertical band, not just past its top edge.
      if (ballSpeedY > 0 && ballX >= paddleX &&
          ballX <= paddleX + paddleWidth && ballY + ballRadius >= paddleY &&
          ballY + ballRadius <= paddleY + paddleHeight) {
        ballSpeedY *= -1;
      }

      // ball vs bricks
      // IMPROVEMENT: original loop could hit multiple bricks in the same
      // frame (e.g. two adjacent bricks), flipping ballSpeedY twice and
      // canceling itself out, or scoring twice on one bounce. Break after
      // the first hit per frame.
      for (auto &box : bricks) {
        if (box.isAlive && ballX >= box.x && ballX <= box.x + box.width &&
            ballY - ballRadius <= box.y + box.height &&
            ballY + ballRadius >= box.y) {
          box.isAlive = false;
          ballSpeedY *= -1;
          score++;
          break; // only resolve one brick collision per frame
        }
      }

      // IMPROVEMENT: added a win condition - previously there was no way to
      // "win", the game would just keep running with an empty screen once
      // all bricks were destroyed.
      bool anyBrickAlive = false;
      for (auto &box : bricks) {
        if (box.isAlive) {
          anyBrickAlive = true;
          break;
        }
      }
      if (!anyBrickAlive) {
        gameWon = true;
      }
    }

    // Step 3: Draw - render game state, game over, or win screen
    BeginDrawing();
    ClearBackground(BLACK);

    if (gameOver) {
      DrawText("GAME OVER - Press R to Restart", 300, 300, 20, PINK);
    } else if (gameWon) {
      // IMPROVEMENT: win screen to go with the new win condition
      DrawText("YOU WIN! - Press R to Restart", 300, 300, 20, GREEN);
    } else {
      // IMPROVEMENT: explicit (int) casts silence implicit float->int
      // truncation when passing to raylib's Draw functions, which take ints
      DrawCircle((int)ballX, (int)ballY, ballRadius, RED);
      DrawRectangle((int)paddleX, (int)paddleY, (int)paddleWidth,
                    (int)paddleHeight, WHITE);
      DrawText(TextFormat("Score: %d", score), 50, screenHeight - 100, 20,
               BLUE);

      for (auto &box : bricks) {
        if (box.isAlive) {
          DrawRectangle((int)box.x, (int)box.y, (int)box.width, (int)box.height,
                        ORANGE);
        }
      }
    }

    // Step 4: Restart - reset game state when R is pressed after game over or
    // win
    if ((gameOver || gameWon) &&
        IsKeyDown(KEY_R)) { // IMPROVEMENT: also allow restart after winning
      gameOver = false;
      gameWon = false;
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
