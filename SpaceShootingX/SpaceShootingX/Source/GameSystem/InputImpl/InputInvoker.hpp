
// 特定のキーが押されたときに関数を呼び出す

#ifndef INPUT_INVOKER_HPP
#define INPUT_INVOKER_HPP

#include <map>

#include "InputDef.hpp"

namespace game {
    class InputInvoker {
       public:
        InputInvoker() = default;

        ~InputInvoker() = default;

       public:
        /// @brief キーがInputState::None以外の時に引数を伴って呼ばれる関数を登録
        /// @param name 登録名
        /// @param data 呼び出しデータ
        void Regist( std::string_view name, const input_detail::InvokeData& data );

        /// @brief キーが特定の状態の時に呼び出される関数を登録
        /// @param name 登録名
        /// @param data 呼び出しデータ
        void Regist( std::string_view name, const input_detail::InvokeSpec& data );

        /// @brief 登録した関数を削除
        /// @param name 登録名
        void Unregist( std::string_view name ) noexcept;

        /// @brief 更新
        void Exec( std::function<const InputState&( const int32_t& )> ditector );

       private:
        input_detail::invoker_datamap_type list {};
        input_detail::invoker_specmap_type listSpec {};
    };
}  // namespace game

#endif  // !INPUT_INVOKER_HPP
