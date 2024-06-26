#ifndef TASK_HPP
#define TASK_HPP

#include "../fileHandling/IO.hpp"
#include <iostream>
#include <sstream>
#include <string>

enum class Action { ENCRYPT, DECRYPT };

struct Task {
  std::string filePath;
  std::fstream f_stream;
  Action action;

  //& references lvalue i.e address whereas && references rvalue that are
  // temporary hence in order to move object values without creating instance of
  // referencing a combo of && as parameter and move() method is used
  Task(std::fstream &&stream, Action act, std::string filePath)
      : f_stream(std::move(stream)), action(act), filePath(filePath) {}

  // serialization
  std::string toString() {
    std::ostringstream oss;
    oss << filePath << ","
        << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");

    return oss.str();
  }

  // deserialization
  static Task fromString(const std::string &taskData) {
    std::istringstream iss(taskData);
    std::string filePath;
    std::string actionStr;

    if (std::getline(iss, filePath, ',') && std::getline(iss, actionStr)) {
      Action action =
          (actionStr == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
      IO io(filePath);
      std::fstream f_stream = std::move(io.getFileStream());

      if (f_stream.is_open()) {
        return Task(std::move(f_stream), action, filePath);
      } else {
        throw std::runtime_error("Failed to open file: " + filePath);
      }
    } else {
      throw std::runtime_error(
          taskData + " is not in correct format to be parsed and deserialized");
    }
  }
};

#endif
