#pragma once
#include "Flittermouse/EngineBase.h"
#include "Flittermouse/Events/BaseEvent.h"

namespace FM {

	class FM_PUBLIC_API WindowClosedEvent : Event {
	public:
		static constexpr EventType GetEventTypeStatic() { return EventType::WindowClosed; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::Window; };
	private:
	};

	class FM_PUBLIC_API WindowResizedEvent : Event {
	public:
		WindowResizedEvent(unsigned int newWidth, unsigned int newHeight)
			: mNewWidth(newWidth), mNewHeight(newHeight) {}

		inline unsigned int GetWindowNewWidth() const { return mNewWidth; };
		inline unsigned int GetWindowNewHeight() const { return mNewHeight; };


		static constexpr EventType GetEventTypeStatic() { return EventType::WindowResized; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::Window; };
	private:
		unsigned int mNewHeight, mNewWidth;
	};

	class FM_PUBLIC_API WindowGotFocus : Event {
	public:
		static constexpr EventType GetEventTypeStatic() { return EventType::WindowGotFocus; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::Window; };
	};

	class FM_PUBLIC_API WindowLostFocus : Event {
	public:
		static constexpr EventType GetEventTypeStatic() { return EventType::WindowLostFocus; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::Window; };
	};

	class FM_PUBLIC_API WindowMovedEvent : Event {
	public:
		WindowMovedEvent(unsigned int newX, unsigned int newY)
			: mNewXPosition(newX), mNewYPosition(newY) {}

		inline unsigned int GetWindowPositionNewHorizontal() const { return mNewXPosition; };
		inline unsigned int GetWindowPositionNewVertical() const { return mNewYPosition; };


		static constexpr EventType GetEventTypeStatic() { return EventType::WindowMoved; };
		EventType GetEventType() const override { return GetEventTypeStatic(); };
		virtual EventCategory GetEventCategory() const override { return EventCategory::Window; };
	private:
		unsigned int mNewXPosition, mNewYPosition;
	};
}

