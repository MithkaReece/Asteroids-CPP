#pragma once
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.hpp"

#include <functional>
#include <map>
#include <vector>
#include <string>
#include <any>

class EventManager
{

public:
  // Allow static retrieving
  static EventManager &GetInstance()
  {
    static EventManager instance;
    return instance;
  }

private:
  std::unordered_map<std::string, std::any> events;

public:
  // Add an event with a unique name/key
  template <typename... Args>
  void addEvent(const std::string &eventName)
  { // TODO add a check if the name is unique
    events[eventName] = Event<Args...>();
  }

  // Get a reference to an existing event by its name/key
  // template <typename... Args>
  // Event<Args...> &getEvent(const std::string &eventName)
  //{
  // return std::any_cast<Event<Args...> &>(events_eventName]);
  //}
};

/*
class EventManager
{
public:
  // Define an event with specific parameters
  template <typename... Args>
  struct Event
  {
    std::string name;
    std::vector<std::function<void(Args...)>> functions;
  };

  // Add an event with specific parameters to the event manager
  template <typename... Args>
  void AddEvent(const std::string &eventName)
  {
    events.emplace(eventName, Event<Args...>{eventName});
  }

private:
  std::map<std::string, void *> events; // To be implemented in the .cpp file

public:
  static EventManager &GetInstance()
  {
    static EventManager instance;
    return instance;
  }
};*/
#endif // EVENTMANAGER_H