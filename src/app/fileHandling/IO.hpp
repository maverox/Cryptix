#ifndef IO_HPP
#define IO_HPP

// dependencies
#include <fstream>
#include <string>

// class declarations
class IO {
public:
  IO(const std::string &file_path);
  ~IO();
  std::fstream getFileStream();

private:
  std::fstream file_stream;
};

#endif // !IO_HPP
