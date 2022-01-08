
// 時間管理

#ifndef TIME_HPP
#define TIME_HPP

#include <Definition/Concepts.hpp>
#include <Utility/Accessor.hpp>
#include <Utility/Singleton.hpp>

namespace game {
    class Time : public Singleton<Time> {
       public:
        Time() = default;

        ~Time() override = default;

       public:
        /// @brief 更新
        void Update() noexcept;

        /// @brief フレームレートを目標値に調整する
        void MarkFPS( const int32_t& targetFPS );

       private:
        /// @brief 前回のフレームにかかった時間を更新
        void UpdateDeltaTime() noexcept;

        /// @brief フレームレートを更新
        void UpdateFPS() noexcept;

        /// @brief 今の時間を取得
        static auto Now() noexcept -> int64_t;

       public:
        /// @brief フレームレート
        Reader<int32_t> FPS { fps };

        /// @brief 前回のフレームにかかった時間
        Reader<double> DeltaTime { deltaTime };

       private:
        template<concepts::numeric T>
        static constexpr T MILLI_SECONDS { static_cast<T>( 1000.0 ) };

        int64_t deltaTimeRap { Now() };
        double deltaTime {};

        int64_t fpsRap { Now() };
        int32_t fps {};
        int32_t fpsCount {};
    };
}  // namespace game

#endif  // !TIME_HPP
