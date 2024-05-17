#include <iostream>
#include <string>

#include "Contact.hpp"

static inline void trim(std::string &str) {
  str.erase(0, str.find_first_not_of(" \f\n\r\t\v"));
  str.erase(str.find_last_not_of(" \f\n\r\t\v") + 1);
}

std::string prompt_string(const std::string &prompt) {
  std::cout << prompt << ": ";

  std::string result;
  std::getline(std::cin, result);
  trim(result);

  return result;
}

static bool prompt_contact_string(const std::string &prompt,
                                  std::string &result) {
  result = prompt_string(prompt);

  if (std::cin.fail())
    return false;

  if (result.length() > 0)
    return true;

  std::cout
      << "Error: You have to provide a value for this field (last chance)."
      << std::endl;
  result = prompt_string(prompt);

  if (std::cin.fail())
    return false;

  if (result.length() > 0)
    return true;

  return false;
}

// TODO: prompt for phone number?
bool prompt_contact(Contact &contact) {
  std::cout << "You are now prompted for the data of your new contact."
            << std::endl;

  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

  if (!prompt_contact_string("First Name", first_name))
    return false;
  if (!prompt_contact_string("Last Name", last_name))
    return false;
  if (!prompt_contact_string("Nickname", nickname))
    return false;
  if (!prompt_contact_string("Phone Number", phone_number))
    return false;
  if (!prompt_contact_string("Darkest Secret", darkest_secret))
    return false;

  contact.set_data(first_name, last_name, nickname, phone_number,
                   darkest_secret);

  return true;
}

// TODO: should it accept inputs like `00001`?
int prompt_contact_index(int contact_count) {
  std::string input = prompt_string("Enter an Index");

  if (std::cin.fail())
    return -1;

  int digit = input[0] - '0';
  if (input.length() != 1 || digit < 0 || digit > contact_count - 1) {
    input = prompt_string("Invalid Index. Try again (last chance)");

    if (std::cin.fail() || input.length() != 1)
      return -1;

    digit = input[0] - '0';
    if (digit < 0 || digit > contact_count - 1)
      return -1;
  }

  return digit;
}
