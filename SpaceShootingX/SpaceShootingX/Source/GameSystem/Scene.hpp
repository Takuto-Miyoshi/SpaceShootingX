﻿
// シーンを管理

#ifndef SCENE_HPP
#define SCENE_HPP

#include <Scene/IScene.hpp>
#include <Utility/Accessor.hpp>
#include <Utility/Singleton.hpp>
#include <concepts>
#include <map>
#include <string>

namespace game {
    class Scene : public Singleton<Scene> {
       public:
        using map_type = std::pair<std::string, std::shared_ptr<IScene>>;

       public:
        Scene() = default;

        ~Scene() override = default;

       public:
        /// @brief シーンを登録
        /// @param name 登録名
        template<std::derived_from<IScene> T>
        void Regist( std::string_view name ) {
            sceneList.emplace( map_type { name, std::make_shared<T>() } );

            if ( !currentScene ) [[unlikely]] {
                currentScene = sceneList.begin()->second;
            }
        }

        /// @brief シーンを変更
        /// @param name 変更先のシーンの登録名
        void ChangeScene( std::string_view name );

        /// @brief 更新
        void Update();

       public:
        /// @brief ゲーム終了フラグ
        Accessor<bool> EndGame { endGame };

       private:
        std::map<map_type::first_type, map_type::second_type> sceneList {};
        std::shared_ptr<IScene> currentScene {};

        bool endGame { false };
    };
}  // namespace game

#endif  // !SCENE_HPP
