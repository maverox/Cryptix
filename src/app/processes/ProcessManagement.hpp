#ifndef PROCESSMANAGEMENT_HPP
#define PROCESSMANAGEMENT_HPP

#include "Task.hpp"
#include <memory>
#include <queue>
#include "../Cipher/Cipher.hpp"

class ProcessManagement {
public:
  ProcessManagement();
  bool submitToQueue(std::unique_ptr<Task> task);
  void executeTasks();

private:
  std::queue<std::unique_ptr<Task>> taskQueue;
};

#endif // !PROCESSMANAGEMENT_HPP
