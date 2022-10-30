#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>
#include "abcgOpenGL.hpp"
#include "gamedata.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaint() override;
  void onPaintUI() override;
  void onEvent(SDL_Event const &event) override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override;

private:
  bool m_isDay{true};

  glm::ivec2 m_viewportSize{};

  GLuint m_VAO{};
  GLuint m_VBOPositions{};
  GLuint m_VBOColors{};
  GLuint m_program{};

  std::default_random_engine m_randomEngine;

  abcg::Timer m_timer;
  int m_delay{200};

  GameData m_gameData;

  void setupModel(int sides);

  std::array<float, 4> m_dayColor{0.15f, 0.463f, 1.0f, .0f};
  std::array<float, 4> m_nightColor{0.0f, 0.0f, 0.262f, .0f};
  int sides{4};
  int animation_frame{0};
  void restartUI();
};

#endif