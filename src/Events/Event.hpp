
// Defines an event and the args of trigger & subscribers
template <typename... Args>
class Event
{
  // Define the type of subscriber function
  using SubscriberFunction = std::function<void(Args...)>;

  // Add a subscriber to the event
  void subscribe(SubscriberFunction subscriber)
  {
    subscribers.emplace_back(std::move(subscriber));
  }

  // Trigger the event with provided arguments
  void trigger(Args... args) const
  {
    for (const SubscriberFunction &subscriber : subscribers)
      subscriber(args...);
  }

private:
  std::vector<SubscriberFunction> subscribers;
};