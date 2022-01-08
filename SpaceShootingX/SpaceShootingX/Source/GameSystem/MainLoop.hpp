
// ゲームのメインループ

#ifndef MAIN_LOOP_HPP
#define MAIN_LOOP_HPP

#include <string>

namespace game {
    class MainLoop {
       public:
        /// @brief 初期設定用
        struct DxLibConfig {
            struct {
                int32_t Width {};
                int32_t Height {};
            } ScreenSize;
            int32_t ColorBitDepth {};
            int32_t FrameRate {};
            bool EnableFullscreen {};
            std::string WindowName { "" };
            bool EnableVSync {};
        };

       public:
        MainLoop( const DxLibConfig& config );

        ~MainLoop();

       public:
        /// @brief ゲームループを実行
        void Exec();

       private:
        /// @brief DxLib初期設定
        void DxInitialize( const DxLibConfig& config );

        /// @brief DxLib終了処理
        void DxFinalize();

       private:
        /// @brief 失敗
        /// @note DxLib用
        static constexpr auto FAIL { -1 };

        int32_t targetFPS {};
    };
}  // namespace game

#endif  // !MAIN_LOOP_HPP
