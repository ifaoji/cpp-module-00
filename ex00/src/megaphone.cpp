#include <cctype>
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

    return 0;
  }

  for (int i = 1; i < argc; i++) {
    std::string output(argv[i]);

    for (size_t j = 0; j < output.length(); j++)
      output[j] = toupper(output[j]);

    std::cout << output;
  }

  std::cout << std::endl;
}
