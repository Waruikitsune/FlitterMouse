#pragma once
#include "BaseEvent.h"

namespace FM {
	class KeyPressedEvent : Event {
	public:
		KeyPressedEvent(unsigned char keyCode, unsigned int repeatCount)
			:mKeyCode(keyCode), mRepeatCount(repeatCount) {}


		static constexpr EventType GetEventTypeStatic() { return EventType::KeyPressed; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::KeyboardInput; };

		unsigned char const GetKeyCode() { return mKeyCode; };
		unsigned char const GetRepeatCount() { return mRepeatCount; };

	private:
		unsigned char mKeyCode;
		unsigned int mRepeatCount;

	};

	class KeyReleasedEvent : Event {
	public:
		KeyReleasedEvent(unsigned char keyCode, unsigned int repeatCount)
			:mKeyCode(keyCode) {}


		static constexpr EventType GetEventTypeStatic() { return EventType::KeyReleased; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::KeyboardInput; };

		unsigned char const GetKeyCode() { return mKeyCode; };
	private:
		unsigned char mKeyCode;

	};


}


