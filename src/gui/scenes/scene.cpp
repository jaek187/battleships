#include "scene.hpp"

namespace battleship {
namespace gui {
Scene::Scene(GameContext &gameContext, Texture2D &background)
    : gameContext(gameContext)
    , background(background) {
  if (!IsTextureValid(background)) {
    spdlog::warn("[GUI] background image not loaded correctly!");
    return;
  }
}

void Scene::update() {
  updateSceneRect();
}

void Scene::draw() {
  DrawTexturePro(background,
                 {0.0f, 0.0f, static_cast<float>(background.width), static_cast<float>(background.height)},
                 sceneRect,
                 {0.0f, 0.0f},
                 0.0f,
                 backgroundTint);
}

void Scene::onEveryClick() {
  PlaySound(gameContext.assetsManager.click);
}

} // namespace gui
} // namespace battleship
