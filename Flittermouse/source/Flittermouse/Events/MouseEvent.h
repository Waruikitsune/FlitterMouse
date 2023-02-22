#pragma once
#include "BaseEvent.h"
namespace FM {

	class MouseButtonPressedEvent : Event {
	public:
		MouseButtonPressedEvent(unsigned char button)
			:mButtonCode(button){};

		static EventType EventTypeStatic() { return EventType::MouseButtonPressed; };
		EventType GetEventType() const override { return EventTypeStatic(); };
		EventCategory GetEventCategory() const override { return EventCategory::MouseButtonInput; };

		inline unsigned char GetButtonCode() const { return mButtonCode; };

	private:
		unsigned char mButtonCode;
	};

	class MouseButtonReleasedEvent : Event {
	public:
		MouseButtonReleasedEvent(unsigned char button)
			:mButtonCode(button) {};

		static EventType EventTypeStatic() { return EventType::MouseButtonReleased; };
		EventType GetEventType() const override { return EventTypeStatic(); };
		EventCategory GetEventCategory() const override { return EventCategory::MouseButtonInput; };

		inline unsigned char GetButtonCode() const { return mButtonCode; };

	private:
		unsigned char mButtonCode;
	};

	class MouseMovedEvent : Event {
	public:
		MouseMovedEvent(unsigned int x, unsigned int y)
			:mMouseX(x), mMouseY(y) {};

		static EventType EventTypeStatic() { return EventType::MouseMoved; };
		EventType GetEventType() const override { return EventTypeStatic(); };
		EventCategory GetEventCategory() const override { return EventCategory::MouseMotionInput; };

		inline unsigned int GetMouseX() const { return mMouseX; };
		inline unsigned int GetMouseY() const { return mMouseY; };

	private:
		unsigned int mMouseX, mMouseY;
	};

	class MouseScrolledEvent : Event {
	public:
		MouseScrolledEvent(unsigned int xPosition, unsigned int yPosition, float distanceScrolledVertical, float distanceScrolledHorizontal)
			:mMouseX(xPosition), mMouseY(yPosition) {};

		static EventType EventTypeStatic() { return EventType::MouseScrolled; };
		EventType GetEventType() const override { return EventTypeStatic(); };
		EventCategory GetEventCategory() const override { return EventCategory::MouseButtonInput; };

		inline unsigned int GetPositionX() const { return mMouseX; };
		inline unsigned int GetPositionY() const { return mMouseY; };

		inline unsigned int GetHorizontalDistance() const { return mDistanceX; };
		inline unsigned int GetVerticalDistance() const { return mDistanceY; };

	private:
		unsigned int mMouseX, mMouseY;
		float mDistanceX, mDistanceY;
	};

}

