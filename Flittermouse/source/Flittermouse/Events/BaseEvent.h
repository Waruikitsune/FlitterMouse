#pragma once
#include "Flittermouse/EngineBase.h"


namespace FM {


	//Todo: defer event processing so they don't immediately block

	class FM_PUBLIC_API Event {
	public:
		virtual ~Event() = 0;

		enum class EventType : unsigned char {
			None = 0,
			WindowClosed, WindowResized, WindowGotFocus, WindowLostFocus, WindowMoved,
			EngineTick, EngineUpdate, EngineRender,
			KeyPressed, KeyReleased,
			MouseButtonPressed, MouseButtonRelease, MouseMoved, MouseScrolled
		};

		enum EventCategory : unsigned char {
			None = 0,
			Input				= 1 << 0,
			MouseMotionInput	= 1 << 1,
			KeyboardInput		= 1 << 2,
			MouseButtonInput	= 1 << 3,
			EngineInternal		= 1 << 4,
			Window				= 1 << 5
		};

		inline virtual EventType GetEventType() const = 0;
		inline virtual EventCategory GetEventCategory() const = 0;
		inline bool IsinCategory(EventCategory c) { return c & GetEventCategory(); }


		#ifdef FM_DEBUG
		virtual const char* GetName() const = 0;
		virtual const char* ToString() const { return this->GetName(); }
		#endif 

	private:

	};
}
