
#define _CRTDBG_MAP_ALLOC
#include <DxLib.h>
#include <crtdbg.h>

#include <GameSystem/MainLoop.hpp>
#include <cstdint>

#define new ::new ( _NORMAL_BLOCK, __FILE__, __LINE__ )

auto WINAPI WinMain( [[maybe_unused]] _In_ HINSTANCE hInstance,
                     [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
                     [[maybe_unused]] _In_ LPSTR lpCmdLine,
                     [[maybe_unused]] _In_ int32_t nShowCmd ) -> int32_t {
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF );

    auto mainLoop {
        game::MainLoop( game::MainLoop::DxLibConfig { .ScreenSize {
                                                          .Width { 1920 },
                                                          .Height { 1080 } },
                                                      .ColorBitDepth { 32 },
                                                      .FrameRate { 60 },
                                                      .EnableFullscreen { false },
                                                      .WindowName { "Shooting" },
                                                      .EnableVSync { false } } )
    };

    mainLoop.Exec();

    return 0;
}
