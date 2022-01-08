
// 入力に関する定義

#ifndef INPUT_DEF_HPP
#define INPUT_DEF_HPP

#include <array>
#include <functional>
#include <map>

namespace game {
    enum class InputState;

    namespace input_detail {
        static inline constexpr uint16_t NUMBER_OF_KEY { 256 };
        static inline constexpr uint8_t NUMBER_OF_MOUSEBUTTON { 3 };

        using key_list_type = std::array<InputState, NUMBER_OF_KEY>;
        using mousebutton_list_type = std::array<InputState, NUMBER_OF_MOUSEBUTTON>;

        struct InvokeData {
            using func_type = std::function<void( const InputState& )>;

            int32_t KeyId;
            func_type Method;
        };

        struct InvokeSpec {
            using func_type = std::function<void()>;

            int32_t KeyId;
            InputState State;
            func_type Method;
        };

        using invoker_datamap_type = std::multimap<std::string, InvokeData>;
        using invoker_specmap_type = std::multimap<std::string, InvokeSpec>;
    }  // namespace input_detail

    /// @brief 入力状態
    enum class InputState {
        None,  // 入力なし
        Pressed,  // 押された瞬間
        Hold,  // 押している
        Released  // 離された瞬間
    };

    static inline constexpr uint8_t MOUSEBUTTON_LEFT { 0 };
    static inline constexpr uint8_t MOUSEBUTTON_RIGHT { 1 };
    static inline constexpr uint8_t MOUSEBUTTON_MIDDLE { 2 };

}  // namespace game

#endif  // !INPUT_DEF_HPP
