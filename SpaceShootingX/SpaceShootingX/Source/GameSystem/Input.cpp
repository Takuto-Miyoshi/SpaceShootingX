
#include "Input.hpp"

namespace game {
    void Input::Update() & noexcept {
        updater.Exec();
        invoker.Exec( [this]( const int32_t& keyId ) -> const InputState& {
            return updater.KeyState( keyId );
        } );
    }

    void Input::Regist( std::string_view name, const int32_t& keyId, const input_detail::InvokeData::func_type& method ) {
        invoker.Regist( name, { keyId, method } );
    }

    void Input::Regist( std::string_view name, const int32_t& keyId, const InputState& state, const input_detail::InvokeSpec::func_type& method ) {
        invoker.Regist( name, { keyId, state, method } );
    }

    void Input::Unregist( std::string_view name ) {
        invoker.Unregist( name );
    }
}  // namespace game
