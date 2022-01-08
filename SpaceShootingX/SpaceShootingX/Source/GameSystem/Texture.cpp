
#include "Texture.hpp"

#include <DxLib.h>

#include <Definition/Exception.hpp>
#include <format>

namespace game {
    void Texture::Load( std::string_view name, std::string_view file ) {
        auto handle { LoadGraph( file.data() ) };
        if ( handle == -1 ) {
            throw exception::NotFound( std::format( "{} は見つかりませんでした。", file ) );
        }

        textureList.try_emplace( name.data(), handle );
    }

    auto Texture::Get( std::string_view name ) const -> const int32_t& {
        if ( const auto& data { textureList.find( name.data() ) };
             data == textureList.end() ) {
            throw exception::NotFound( std::format( "{} は見つかりませんでした。", name ) );
        }
        else {
            return data->second;
        }
    }

    void Texture::Release() noexcept {
        for ( auto&& e : std::as_const( textureList ) ) {
            DeleteGraph( e.second );
        }

        textureList.clear();
    }

    void Texture::Release( std::string_view name ) noexcept {
        if ( const auto& data { textureList.find( name.data() ) };
             data != textureList.end() ) {
            DeleteGraph( data->second );

            textureList.erase( data->first );
        }
    }
}  // namespace game
