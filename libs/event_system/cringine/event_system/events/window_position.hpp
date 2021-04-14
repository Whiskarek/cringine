#pragma once

namespace cringine::event_system::events
{
    class window_position_event
    {
    public:
        virtual void window_position(int width, int height) = 0;
    };

    using window_position_event_ptr = window_position_event*;
} // namespace cringine::event_system::events
