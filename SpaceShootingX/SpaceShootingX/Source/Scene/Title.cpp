
#include "Title.hpp"

#include <DxLib.h>

#include <GameSystem/Input.hpp>
#include <GameSystem/Scene.hpp>

namespace game::scene {
    void Title::Initialize() {
    }

    void Title::Update() {
        printfDx( "CurrentScene : Title\n" );

        if ( Input::Instance()->KeyState( KEY_INPUT_SPACE ) == InputState::Pressed ) {
            Scene::Instance()->ChangeScene( "InGame" );
        }
    }

    void Title::Draw() {
    }

    void Title::Finalize() {
    }
}  // namespace game::scene
