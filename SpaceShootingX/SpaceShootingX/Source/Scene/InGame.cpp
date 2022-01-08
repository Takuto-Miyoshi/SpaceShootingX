
#include "InGame.hpp"

#include <DxLib.h>

#include <GameSystem/Input.hpp>
#include <GameSystem/Scene.hpp>

namespace game::scene {
    void InGame::Initialize() {
    }

    void InGame::Update() {
        printfDx( "CurrentScene : InGame\n" );

        if ( Input::Instance()->KeyState( KEY_INPUT_SPACE ) == InputState::Pressed ) {
            Scene::Instance()->ChangeScene( "Title" );
        }
    }

    void InGame::Draw() {
    }

    void InGame::Finalize() {
    }
}  // namespace game::scene
