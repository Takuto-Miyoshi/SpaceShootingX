
// 入力管理クラス

#ifndef INPUT_HPP
#define INPUT_HPP

#include <Utility/Singleton.hpp>

#include "InputImpl/InputInvoker.hpp"
#include "InputImpl/InputUpdater.hpp"

namespace game {
    class Input : public Singleton<Input> {
       public:
        Input() = default;

        ~Input() override = default;

       public:
        /// @brief 更新
        void Update() & noexcept;

        /// @brief キーがInputState::None以外の時に引数を伴って呼ばれる関数を登録
        /// @param name 登録名
        /// @param keyId キーのID
        /// @param method 呼ばれる関数
        void Regist( std::string_view name, const int32_t& keyId, const input_detail::InvokeData::func_type& method );

        /// @brief キーが特定の状態の時に呼び出される関数を登録
        /// @param name 登録名
        /// @param keyId キーのID
        /// @param state 指定する入力状態
        /// @param method 呼ばれる関数
        void Regist( std::string_view name, const int32_t& keyId, const InputState& state, const input_detail::InvokeSpec::func_type& method );

        /// @brief 登録した関数を削除
        /// @param name 登録名
        void Unregist( std::string_view name );

        /// @brief キーの入力状態を取得
        [[nodiscard]] constexpr auto KeyState( const int32_t& id ) const& noexcept -> const InputState& {
            return updater.KeyState( id );
        }

        /// @brief マウスボタンの入力状態を取得 @n InputDef::MOUSEBUTTON_XXXX
        [[nodiscard]] constexpr auto MousebuttonState( const int32_t& id ) const& noexcept -> const InputState& {
            return updater.MousebuttonState( id );
        }

        /// @brief マウスカーソルの位置
        Accessor<Vector2> CursorPosition { updater.cursorPosition };

       private:
        InputUpdater updater {};
        InputInvoker invoker {};
    };
}  // namespace game

#endif  // !INPUT_HPP
