#pragma once
#include "Flittermouse/EngineBase.h"
#include <functional>

namespace FM {


	//Todo: defer event processing so they don't immediately block

	class FM_PUBLIC_API Event {
	public:
		//virtual ~Event() = 0;

		enum class EventType : unsigned char {
			None = 0,
			WindowClosed, WindowResized, WindowGotFocus, WindowLostFocus, WindowMoved,
			EngineTick, EngineUpdate, EngineRender,
			KeyPressed, KeyReleased,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
			ControllerAxisMoved, ControllerButtonPressed, ControllerButtonReleased
		};

		enum class EventCategory : unsigned char {
			None = 0,
			Input				= 1 << 0,
			MouseMotionInput	= 1 << 1,
			KeyboardInput		= 1 << 2,
			MouseButtonInput	= 1 << 3,
			EngineInternal		= 1 << 4,
			Window				= 1 << 5,
			Controller			= 1 << 6,
			ControllerButton	= 1 << 7,
		};

		inline virtual EventType GetEventType() const = 0;
		inline virtual EventCategory GetEventCategory() const = 0;
		inline bool IsinCategory(EventCategory c) { return (unsigned char)c & (unsigned char)GetEventCategory(); }
		inline bool IsHandled() const {return mHandled; };
		inline void SetHandled() { mHandled = true; };

		//#ifdef FM_DEBUG
		//virtual std::string* GetName() const = 0;
		//virtual std::string* ToString() const { return this->GetName(); }
		//#endif 

	protected:
		bool mHandled = false;
	private:

	};
	class EventDispatcher{
	public:
		EventDispatcher(Event& pEvent)
			:mEvent(pEvent) {};

		template<typename T>
		bool Dispatch(std::function<bool(T&)> function) {
			if (mEvent.GetEventType() == T::GetEventTypeStatic()) {
				//why is mHandled visible here?
				if (function(mEvent)) {
					mEvent.SetHandled();
				}
				//why is the compiler not upset by this?
				mEvent.qwertyuiop = 3.14f
				return true;
			}
			return false;
		};
	private:
			Event& mEvent;
	};
}
