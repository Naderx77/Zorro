#pragma once

#include "Zorro/Core.h"

#include <string>
#include <functional>

namespace Zorro {

    // Events in Zorro are blocking.
    // Events get dispatched as soon as they occur

    enum class EventType {

        None = 0,

        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,

        AppTick,
        AppUpdate,
        AppRender,

        KeyPressed,
        KeyReleased,

        MouseButtonClick,
        MouseButtonRelease,
        MouseMove,
        MouseScolled,

    };

    enum EventCategory {

        None = 0,

        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4),
        
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(catergory) virtual int GetCategoryFlags() const override { return category; }

    class ZORRO_API Event
    {
      friend class EventDispatcher;
    public:
      virtual EventType GetEventType() const = 0;
      virtual const char* GetName() const = 0;
      virtual int GetCategoryFlags() const = 0;
      virtual std::string ToString() const { return GetName(); }

      inline bool IsInCategory(EventCategory category)
      {
        return GetCategoryFlags() & category;
      }
    protected:
      bool m_Handled = false;

    };

    class EventDispatcher
    {
      template<typename T>
      using EventFn = std::_Can_call_function_object<bool(T&)>;
    public:
      EventDispatcher(Event& event);
    };

}