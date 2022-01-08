

#include "InputInvoker.hpp"

#include <ranges>

#include "InputUpdater.hpp"

namespace game {
    void InputInvoker::Regist( std::string_view name, const input_detail::InvokeData& data ) {
        list.emplace( name, data );
    }

    void InputInvoker::Regist( std::string_view name, const input_detail::InvokeSpec& data ) {
        listSpec.emplace( name, data );
    }

    void InputInvoker::Unregist( std::string_view name ) noexcept {
        list.erase( name.data() );
        listSpec.erase( name.data() );
    }

    void InputInvoker::Exec( std::function<const InputState&( const int32_t& )> ditector ) {
        for ( auto&& e : list | std::views::values ) {
            if ( auto& state { ditector( e.KeyId ) };
                 state != InputState::None ) {
                e.Method( state );
            }
        }

        for ( auto&& e : listSpec | std::views::values ) {
            if ( auto& state { ditector( e.KeyId ) };
                 state == e.State ) {
                e.Method();
            }
        }
    }
}  // namespace game
