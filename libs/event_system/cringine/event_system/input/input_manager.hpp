#pragma once

#include <cringine/event_system/input/keys.hpp>
#include <cringine/event_system/event_system.hpp>

#include <array>

namespace cringine::event_system::input
{
    class input_manager : virtual public events::cursor_focus_event, virtual public events::cursor_position_event,
                          virtual public events::keyboard_input_event, virtual public events::mouse_button_input_event,
                          virtual public events::scroll_input_event
    {
    public:
        input_manager() = default;
        virtual ~input_manager() = default;

        void bind_to_event_system(event_system_sptr event_system);

        void update_states();

        bool is_cursor_focused() const;
        std::pair<double, double> cursor_position() const;
        double cursor_position_x() const;
        double cursor_position_y() const;
        std::pair<double, double> scroll_delta() const;
        double scroll_delta_x() const;
        double scroll_delta_y() const;
        bool is_key_pressed(keys::key_t key) const;
        bool is_key_released(keys::key_t key) const;
        bool is_key_down(keys::key_t key) const;
        bool is_key_up(keys::key_t key) const;
        bool is_mouse_button_pressed(keys::key_t key) const;
        bool is_mouse_button_released(keys::key_t key) const;
        bool is_mouse_button_down(keys::key_t key) const;
        bool is_mouse_button_up(keys::key_t key) const;

    private:
        void update_key_states();
        void update_button_states();
        void update_scroll_delta();

    protected:
        bool m_cursor_focus = true;
        double m_cursor_x = 0, m_cursor_y = 0;
        double m_scroll_delta_x = 0, m_scroll_delta_y = 0;

        static constexpr auto s_MAX_KEY_AMOUNT = 512u;
        std::array<bool, s_MAX_KEY_AMOUNT> m_key_current_states{false}, m_key_previous_states{false};

        static constexpr auto s_MAX_BUTTON_AMOUNT = 8u;
        std::array<bool, s_MAX_BUTTON_AMOUNT> m_button_current_states{false}, m_button_previous_states{false};
    };

    using input_manager_sptr = std::shared_ptr<input_manager>;
} // namespace cringine::event_system::input
