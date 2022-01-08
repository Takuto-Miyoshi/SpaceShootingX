
#include "MainLoop.hpp"

#include <DxLib.h>

#include <Definition/Exception.hpp>

// GameSystem
#include <GameSystem/Input.hpp>
#include <GameSystem/Invoker.hpp>
#include <GameSystem/Scene.hpp>
#include <GameSystem/Time.hpp>

// Scene
#include <Scene/InGame.hpp>
#include <Scene/Title.hpp>

namespace game {
    MainLoop::MainLoop( const DxLibConfig& config ) {
        DxInitialize( config );
        targetFPS = config.FrameRate;
    }

    MainLoop::~MainLoop() {
        DxFinalize();
    }

    void MainLoop::Exec() {
        auto& input { Input::Instance() };
        auto& time { Time::Instance() };
        auto& invoker { Invoker::Instance() };
        auto& scene { Scene::Instance() };
        scene->Regist<scene::Title>( "Title" );
        scene->Regist<scene::InGame>( "InGame" );

        while ( true ) {
            if ( ProcessMessage() == FAIL ) { break; }

            ClearDrawScreen();
            clsDx();

            time->Update();
            input->Update();
            invoker->Update();
            scene->Update();

            printfDx( std::format( "FPS : {} | DeltaTime : {}\n", time->FPS(), time->DeltaTime() ).c_str() );

            time->MarkFPS( targetFPS );

            ScreenFlip();
        }
    }

    void MainLoop::DxInitialize( const DxLibConfig& config ) {
        SetOutApplicationLogValidFlag( FALSE );
        ChangeWindowMode( static_cast<int32_t>( !config.EnableFullscreen ) );
        SetGraphMode( config.ScreenSize.Width, config.ScreenSize.Height, config.ColorBitDepth, config.FrameRate );
        SetMainWindowText( config.WindowName.c_str() );
        SetWaitVSyncFlag( static_cast<int32_t>( config.EnableVSync ) );

        if ( DxLib_Init() == FAIL ) {
            throw exception::InitializeError( "DxLibの初期化に失敗しました。" );
        }

        SetDrawScreen( DX_SCREEN_BACK );
    }

    void MainLoop::DxFinalize() {
        DxLib_End();
    }
}  // namespace game
