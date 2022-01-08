
// 入力状態の更新

#ifndef INPUT_UPDATER_HPP
#define INPUT_UPDATER_HPP

#include <Utility/Vector2.hpp>

#include "InputDef.hpp"

namespace game {
    class InputUpdater {
       public:
        InputUpdater();

        ~InputUpdater() = default;

       public:
        /// @brief 更新
        void Exec() & noexcept;

        /// @brief キーの入力状態を取得
        [[nodiscard]] constexpr auto KeyState( const int32_t& id ) const& noexcept -> const InputState& {
            try {
                return keyList.at( id );
            }
            catch ( const std::exception& ) {
                return *keyList.begin();
            }
        }

        /// @brief マウスボタンの入力状態を取得 @n InputDef::MOUSEBUTTON_XXXX
        [[nodiscard]] constexpr auto MousebuttonState( const int32_t& id ) const& noexcept -> const InputState& {
            try {
                return mousebuttonList.at( id );
            }
            catch ( const std::exception& ) {
                return *mousebuttonList.begin();
            }
        }

        Vector2 cursorPosition {};

       private:
        [[nodiscard]] static constexpr auto ConvertState( const InputState& previous, const bool& current ) noexcept -> InputState;

        constexpr void UpdateKeyState() noexcept;

        constexpr void UpdateMousebutton() noexcept;

        void UpdateCursorPosition() noexcept;

       private:
        static constexpr int8_t DX_PRESSED { 1 };
        static constexpr uint8_t DX_NOT_PRESSED { 0 };

        input_detail::key_list_type keyList {};
        input_detail::mousebutton_list_type mousebuttonList {};
    };
}  // namespace game

#endif  // !INPUT_UPDATER_HPP
