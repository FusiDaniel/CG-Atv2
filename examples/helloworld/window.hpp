#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>
#include "abcgOpenGL.hpp"
#include "gamedata.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaint() override;
  void onEvent(SDL_Event const &event) override;
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override;
  void onUpdate() override;

private:
  glm::ivec2 m_viewportSize{};

  GameData m_gameData;

  GLuint m_VAO{};
  GLuint m_VBOPositions{};
  GLuint m_VBOColors{};
  GLuint m_program{};

  std::default_random_engine m_randomEngine;

  abcg::Timer m_timer;

  int m_sides{30};
  std::array<float, 2> m_mouse_pos{.0f, .0f};
  std::array<float, 4> m_brush_color{0.15f, 0.463f, 1.0f, .0f};

  bool drawing{false};
  void setupModel(int sides);
};

#endif